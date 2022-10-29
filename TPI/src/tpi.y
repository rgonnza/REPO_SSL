%{
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "ts.h"
#define YYDEBUG 1

enum errores{
        centinela,
        lvalue        
}cod_error;

int flag_error=0;
char* tipo;
char* identificador;
char* tipoSentencia;
int flag_tipo;
int flag_tipoAsignado;
int flag_retorno;
char* array ="array de ";
char* pointer="puntero a ";
int yylex();
int esArray=0;
int esInicializado=0;
int esPuntero=0;
Lista auxVariables;
Lista auxParametros;
FILE *yyin;
ts *aux;
char *identificador;


int yywrap(){
	return(1);
}
extern int yylineno;

void yyerror (char *s) {
   
   printf("%s \nError sintactico ");
}

%}

%union {
struct yylval_struct{
        char cadena[30];
        int entero;
        int tipo;
        char caracter;
        float real
}mystruct;
}

%token <mystruct> ENTERO
%token <mystruct> REAL
%token <mystruct> ID
%token <mystruct> TIPO_DATO
%token <mystruct> IF
%token <mystruct> ELSE
%token <mystruct> SWITCH
%token <mystruct> WHILE
%token <mystruct> DO
%token <mystruct> FOR
%token <mystruct> error
%token <mystruct> MAYOR_O_IGUAL
%token <mystruct> MENOR_O_IGUAL
%token <mystruct> IGUAL_O_DISTINTO
%token <mystruct> INCREMENTO_O_DECREMENTO
%token <mystruct> AND
%token <mystruct> OR
%token <mystruct> SIZEOF 
%token <mystruct> RETURN
%token <mystruct> OPERADOR_ASIGNACION
%token <mystruct> VOID 
%token <mystruct> CARACTER 
%token <mystruct> LITERAL_CADENA 


%type <mystruct> declaracion declaracionDeFuncion declaracionVarSimples argsFuncion argumentoA finDeclaracionVariable tipoDato
%type <mystruct> listaVarSimples unaVarSimple inicializacion arreglo puntero expresion expAsignacion operAsignacion expCondicional expOr
%type <mystruct> expAnd expIgualdad expRelacional expAditiva expMultiplicativa expUnaria operUnario expPostFijo listaArgumentos expPrimaria 
%type <mystruct> usoDeFuncion listaParametros constante sentencia sentenciaCompuesta sentencias_y_declaraciones listaSentencias listaDeclaraciones 
%type <mystruct> sentenciaDeExpresion sentenciaDeControl sentenciaDeIteracion aperturaParentesis cierreParentesis sentenciaDeSalto

%left ','
%right '=' OPERADOR_ASIGNACION
%left OR
%left AND
%left IGUAL_O_DISTINTO
%left MAYOR_O_IGUAL MENOR_O_IGUAL
%left '+' '-'
%left '*' '/' '%'
%right INCREMENTO_O_DECREMENTO '&' '!' SIZEOF


%% /* A continuacion las reglas gramaticales y las acciones */

input:  /* vacio */
        | input line
;

line:   /* vacio */  
        | declaracion
        | sentencia
;

/* ---------- Declaraciones */

declaracion:       declaracionDeFuncion {
 
}
                   | declaracionVarSimples
;             

declaracionDeFuncion:           VOID ID '(' argsFuncion ')' ';' { printf("Se encontro una funcion \n");
                                        if(!flag_error){
                                                Item *item;
                                                aux = agregarEnTabla(strdup($<mystruct>2.cadena), 'F', strdup("void"));
                                                for (item = auxVariables.cabeza; item != NULL; item = item->siguiente)
                                                {
                                                        agregarArgumento(&aux->argumentos, strdup($<mystruct>2.cadena), strdup(item->tipo), item->valor_entero);
                                                }
                                                auxVariables.cabeza=NULL;
                                        }
                                }
                                | tipoDato ID '(' argsFuncion ')' ';' { printf("Se encontro una funcion \n");
                                        if(!flag_error){
                                                Item *item;
                                                aux = agregarEnTabla(strdup($<mystruct>2.cadena), 'F', strdup(tipo));
                                                for (item = auxVariables.cabeza; item != NULL; item = item->siguiente)
                                                {
                                                        agregarArgumento(&aux->argumentos, strdup($<mystruct>2.cadena), strdup(item->tipo), item->valor_entero);
                                                }
                                                auxVariables.cabeza=NULL;
                                        }   
                                }
                                | VOID ID '(' argsFuncion ')' sentenciaCompuesta { printf("Se encontro una funcion \n");
                                        if(!flag_error){
                                                Item *item;
                                                aux = agregarEnTabla(strdup($<mystruct>2.cadena), 'F', strdup("void"));
                                                for (item = auxVariables.cabeza; item != NULL; item = item->siguiente)
                                                {
                                                        agregarArgumento(&aux->argumentos, strdup($<mystruct>2.cadena), strdup(item->tipo), item->valor_entero);
                                                }
                                                auxVariables.cabeza=NULL;
                                        }
                                }
                                | tipoDato ID '(' argsFuncion ')' sentenciaCompuesta { printf("Se encontro una funcion \n");
                                        char *tipoRetorno = $<mystruct>1.cadena;
                                        if(!flag_error){
                                                Item *item;
                                                aux = agregarEnTabla(strdup($<mystruct>2.cadena), 'F', strdup(tipoRetorno));
                                                for (item = auxVariables.cabeza; item != NULL; item = item->siguiente)
                                                {
                                                        agregarArgumento(&aux->argumentos, strdup($<mystruct>2.cadena), strdup(item->tipo), item->valor_entero);
                                                }
                                                auxVariables.cabeza=NULL;
                                        }
                                        if(flag_retorno != $<mystruct>1.tipo){
                                                agregarEnLista(&noReconocidos, concatenar("No coincide el retorno con el tipo de dato de la funcion ", $<mystruct>2.cadena), ERROR_SEMANTICO, yylineno);
                                        }
                                }
;


argsFuncion:                    argumentoA 
                                | argumentoA ',' argsFuncion
;
argumentoA:			/* vacio */
                                | TIPO_DATO ID {
                                        agregarEnListaAlFinal(&auxVariables, $<mystruct>2.cadena, $<mystruct>1.cadena,$<mystruct>1.tipo); // $<mystruct>1.tipo es el flag_tipo
                                }
                                | TIPO_DATO 
;
declaracionVarSimples: 	        tipoDato listaVarSimples finDeclaracionVariable
;

finDeclaracionVariable:                 ';' {
                                        Item *item;
                                        
                                        for (item = auxVariables.cabeza; item != NULL; item = item->siguiente)
                                        {
                                                aux=obtenerDeTabla(item->token, 'V');
                                                if(aux){
                                                        agregarEnLista(&noReconocidos, concatenar("Ya se encuentra definida la variable ", item->token), ERROR_SEMANTICO , yylineno );
                                                }else{
                                                        aux = agregarEnTabla(strdup(item->token), 'V', strdup(tipo));                                                         
                                                }
                                        }
                                        auxVariables.cabeza=NULL;
                                }
                                | error {flag_error=1 ;agregarEnLista(&noReconocidos, "Falta ;", "", yylineno);}
;

tipoDato:                       TIPO_DATO puntero {tipo = $<mystruct>1.cadena; flag_tipo=$<mystruct>1.tipo;}
                                | error {printf("Falta tipo de dato en linea \n", yylineno);}
;
listaVarSimples: 		unaVarSimple
                                | listaVarSimples ',' unaVarSimple
;

unaVarSimple:                   ID arreglo inicializacion {
                                        if(!flag_error){
                                                if(esArray&&esPuntero){
                                                        agregarEnLista(&noReconocidos, "No puede ser puntero y array a la vez", "", yylineno);
                                                } else{
                                                if(esPuntero){tipo=concatenar(pointer,tipo); flag_tipo=1;}
                                                if(esArray){tipo=concatenar(array,tipo); flag_tipo=1;}                 
                                                if(esInicializado){
                                                        if(flag_tipo == flag_tipoAsignado){ 
                                                                printf("los tipos coinciden\n");
                                                                printf("Var: %s de tipo %s \n", $<mystruct>1.cadena, tipo );
                                                                agregarEnLista(&auxVariables, $<mystruct>1.cadena, tipo,yylineno);
                                                        }else{
                                                                printf("No coinciden los tipos de datos\n");
                                                                agregarEnLista(&noReconocidos, "No coinciden los tipos de datos", "", yylineno);
                                                                flag_error = 0;                                                        
                                                        }
                                                } else {
                                                        printf("Var: %s de tipo %s \n", $<mystruct>1.cadena, tipo );
                                                        agregarEnLista(&auxVariables, $<mystruct>1.cadena, tipo,yylineno);
                                                }
                                                } 
                                                esArray=0;
                                                esInicializado=0;
                                                esPuntero=0;
                                        }
                                }
                                | error {
                                        if(!flag_error){
                                                printf("Falta identificador \n");
                                                agregarEnLista(&noReconocidos, "Falta identificador", "", yylineno);       
                                                flag_error = 1;
                                        }
                                }
;

inicializacion:         /* vacio */
                        |'=' expresion {esInicializado=1;flag_tipoAsignado=$<mystruct>2.tipo}
;
arreglo:                /* vacio */
                        | arreglo '[' constante ']' {esArray=1;}
;                         
puntero:                /* vacio */
                        | puntero '*' {esPuntero=1;} // 1 para literal cadena


/* ---------- Expresiones */
expresion:			expAsignacion
                                | error {
                                        printf("No se pudo conocer la expresion en linea %i", yylineno);
                                        agregarEnLista(&noReconocidos, "Expresion no reconocida", "", yylineno);
                                        flag_error = 0;
                                }
;
expAsignacion: 			expCondicional 
                                | expUnaria operAsignacion expAsignacion {
                                        if($<mystruct>1.tipo != 4){
                                                agregarEnLista(&noReconocidos, "Se requiere un lvalue modificable como operando izquierdo de una asignación", "", yylineno);
                                                flag_error = 1;
                                        }
                                }      
;

operAsignacion:			'='
                                |OPERADOR_ASIGNACION
;

expCondicional:			expOr 
                                | expOr '?' expresion ':' expCondicional
;

expOr:				expAnd
				| expOr OR expAnd
;
expAnd:				expIgualdad
				| expAnd AND expIgualdad
;
expIgualdad:			expRelacional
				| expIgualdad IGUAL_O_DISTINTO expRelacional			
;
expRelacional:			expAditiva
                                | expRelacional MAYOR_O_IGUAL expAditiva
                                | expRelacional MENOR_O_IGUAL expAditiva                                
;
expAditiva:			expMultiplicativa
                                | expAditiva '+' expMultiplicativa
                                | expAditiva '-' expMultiplicativa
;
expMultiplicativa: 		expUnaria
                                | expMultiplicativa '*' expUnaria
                                | expMultiplicativa '/' expUnaria  
                                | expMultiplicativa '%' expUnaria
;

expUnaria: 			expPostFijo
                                | INCREMENTO_O_DECREMENTO expUnaria
                                | expUnaria INCREMENTO_O_DECREMENTO
                                | operUnario expUnaria
                                | SIZEOF aperturaParentesis TIPO_DATO cierreParentesis
;
operUnario:                     '&' | '*' | '-' | '!'
;

expPostFijo:			expPrimaria
		             	| expPostFijo '[' expresion ']'
                                | expPostFijo aperturaParentesis listaArgumentos cierreParentesis
;

listaArgumentos:                expAsignacion
                                | listaArgumentos ',' expAsignacion
;
expPrimaria:                    ID {
                                        aux = obtenerDeTabla(strdup($<mystruct>1.cadena), 'V');
                                        if(!aux){
                                                agregarEnLista(&noReconocidos, concatenar("No existe el identificador ", $<mystruct>1.cadena), "", yylineno);
                                                flag_error = 1;
                                        }
                                        $<mystruct>$.tipo = aux->tipo_dato;
                                }
                               | constante 
                               | LITERAL_CADENA {$<mystruct>$.tipo=$<mystruct>1.tipo;}
                               | aperturaParentesis expresion cierreParentesis
                               | usoDeFuncion
                               | error {
                                        if(flag_error){
                                                agregarEnLista(&noReconocidos, "No se asigno valor a un lvalue", "", yylineno);
                                        }
                               }
;
usoDeFuncion:                   ID aperturaParentesis listaParametros cierreParentesis {
                                int errorArg = 0;
                                Item *param;
                                aux = obtenerDeTabla(strdup($<mystruct>1.cadena), 'F');                                
                                Item *auxArgumento;
                                Lista *lista = &aux->argumentos;
                                param = auxParametros.cabeza;                                
                                auxArgumento = lista->cabeza;
                        
                                if(longitudLista(aux->argumentos) != longitudLista(auxParametros)){
                                        errorArg = 1; // no coinciden la cantidad de argumentos
                                }else{
                                        while((param != NULL)){
                                                printf("Valor entero de param: %i\n", param->valor_entero);
                                                printf("Valor entero de auxArgumento: %i\n", auxArgumento->valor_entero);
                                                if(param->valor_entero != auxArgumento->valor_entero){
                                                        errorArg = 1;
                                                }
                                                param = param->siguiente;
                                                auxArgumento = auxArgumento->siguiente;
                                        }
                                }
                                if(errorArg == 1){ // hay error en el paso de parametros
                                        agregarEnLista(&noReconocidos, concatenar("Error en el paso de argumentos de la funcion ", $<mystruct>1.cadena) ,ERROR_SEMANTICO, yylineno);
                                }
}
;                               

listaParametros:                /* vacio */
                                | parametro
                                | parametro ',' listaParametros
;
parametro:                      constante {flag_tipoAsignado=$<mystruct>1.tipo; agregarEnLista(&auxParametros, "", "", flag_tipoAsignado);}
                                | LITERAL_CADENA {flag_tipoAsignado=$<mystruct>1.tipo; agregarEnLista(&auxParametros, "", "", flag_tipoAsignado);}
;
constante:			 CARACTER {$<mystruct>$.tipo=$<mystruct>1.tipo;}
                                | ENTERO {$<mystruct>$.tipo=$<mystruct>1.tipo;}
                                | REAL {$<mystruct>$.tipo=$<mystruct>1.tipo;}
;
 
/* ---------- Sentencias */

sentencia:			sentenciaCompuesta
                                | sentenciaDeExpresion
                                | sentenciaDeControl {
                                        char* msg = concatenar("De control ", tipoSentencia);
                                        if(!flag_error){
                                                agregarEnLista(&sentencias, "Sentencia", msg, yylineno);
                                                printf("Se encontro una sentencia de control \n");
                                        }
                                }
                                | sentenciaDeIteracion{
                                        char* msg = concatenar("De iteracion ", tipoSentencia);
                                        if(flag_error==0){
                                                agregarEnLista(&sentencias, "Sentencia", msg, yylineno);        
                                                printf("Se encontro una sentencia de iteracion \n");
                                        }
                                }        
                                | sentenciaDeSalto                   
;

sentenciaCompuesta:              '{' sentencias_y_declaraciones '}'
;
sentencias_y_declaraciones:     /*vacio*/
                                | listaDeclaraciones sentencias_y_declaraciones
                                | listaSentencias sentencias_y_declaraciones
;

listaSentencias:                sentencia
                                | listaSentencias sentencia
;
listaDeclaraciones:              declaracionVarSimples
                                | listaDeclaraciones declaracionVarSimples
;

sentenciaDeExpresion:		expresion ';' {
                                        if(!flag_error){
                                                agregarEnLista(&sentencias, "Sentencia", "De expresion", yylineno);
                                        }else{
                                        if(cod_error==lvalue){
                                        agregarEnLista(&noReconocidos, "Se requiere un lvalue modificable como operando izquierdo de una asignación", "", yylineno);        
                                                }
                                        }
                                        flag_error=0;
                                }
                                | ';'
                                | error ';'{
                                        if(!flag_error){
                                                agregarEnLista(&noReconocidos, "Secuencia de tokens no reconocida", "", yylineno);      
                                        }
                                }
                                | error {
                                        if(!flag_error){
                                                agregarEnLista(&noReconocidos, "Falta ;", "", yylineno);                                
                                        }
                                }
;

sentenciaDeControl: 	        IF aperturaParentesis expresion cierreParentesis sentencia {tipoSentencia="if";}      
                                | IF aperturaParentesis expresion cierreParentesis sentencia ELSE sentencia {tipoSentencia="if-else";}
                                | SWITCH aperturaParentesis expresion cierreParentesis sentencia {tipoSentencia="switch";}
;

sentenciaDeIteracion:          WHILE aperturaParentesis expresion cierreParentesis sentencia {tipoSentencia = "while";}
                                | DO sentencia WHILE aperturaParentesis expresion cierreParentesis ';' {tipoSentencia="do-while"}
                                | FOR aperturaParentesis unaVarSimple ';' expresion ';' expresion cierreParentesis sentencia {tipoSentencia = "for"}
;
aperturaParentesis:             '('                                
;
cierreParentesis:               ')'                               
;

sentenciaDeSalto:              RETURN ';'
                               | RETURN expresion ';' {flag_retorno=$<mystruct>2.tipo}
;

%%

ts *tabla_simbolos;

int main (){


        printf("> ");
        inicializar(); //inicializo las listas
        auxVariables.cabeza = NULL;
        auxParametros.cabeza = NULL;
        FILE *f = fopen("salida.txt", "w");        
        yyin=fopen("entrada.c", "r");
        if(!yyparse()){
                printf("\n***Parser completado***\n\n");
                mostrarReporte();
                reporteErrores(&noReconocidos);
                realizarReporte(f);
        }else{
                printf("\nEL parser fallo\n");
        }

        fclose(yyin);
        fclose(f);
        
        
        /* return yyparse(); */
}