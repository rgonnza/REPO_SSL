%{
#include <stdio.h> 
#include <ctype.h>
#include <string.h>

#include "ts.h"
#define YYDEBUG 1

char* tipo;
char* identificador;
char* tipoSentencia;

int flag_error = 0;
int flag_tipo;
int flag_tipoAsignado;
int flag_retorno;

int esArray = 0;
int esInicializado = 0;
int esPuntero = 0;

Lista auxVariables;
Lista auxParametros;
Lista argumentosDeclaracion;
ts *aux;

FILE *yyin;
extern int yylineno;
int yylex();

int yywrap(){
        return(1);
}

void yyerror (char *s) {
   printf("%s Error sintactico \n");
}

%}

%union {
struct yylval_struct{
        char cadena[30];
        int entero;
        int tipo;
        char caracter;
        float real;
        int esVar;
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
%type <mystruct> listaVarSimples unaVarSimple inicializacion arreglo_op puntero_op expresion expAsignacion operAsignacion expCondicional expOr
%type <mystruct> expAnd expIgualdad expRelacional expAditiva expMultiplicativa expUnaria operUnario expPostFijo listaArgumentos expPrimaria 
%type <mystruct> usoDeFuncion listaParametros constante sentencia sentenciaCompuesta sentencias_y_declaraciones listaSentencias listaDeclaraciones 
%type <mystruct> sentenciaDeExpresion sentenciaDeControl sentenciaDeIteracion sentenciaDeSalto

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

declaracion:       declaracionDeFuncion {flag_error=0;}
                   | declaracionVarSimples
;             

declaracionDeFuncion:           VOID ID '(' argsFuncion ')' ';' {
                                        if(!flag_error){
                                                Item *item;
                                                aux = agregarEnTabla(strdup($<mystruct>2.cadena), 'F', strdup("void"), cod_void);
                                                for (item = argumentosDeclaracion.cabeza; item != NULL; item = item->siguiente)
                                                {
                                                        agregarArgumento(&aux->argumentos, strdup($<mystruct>2.cadena), strdup(item->tipo), item->valor_entero);
                                                }
                                                argumentosDeclaracion.cabeza=NULL;
                                        }
                                }
                                | tipoDato ID '(' argsFuncion ')' ';' { 
                                        if(!flag_error){
                                                
                                                Item *item;
                                                aux = agregarEnTabla(strdup($<mystruct>2.cadena), 'F', strdup(tipo), $<mystruct>1.tipo);
                                                
                                                for (item = argumentosDeclaracion.cabeza; item != NULL; item = item->siguiente)
                                                {
                                                        agregarArgumento(&aux->argumentos, strdup($<mystruct>2.cadena), strdup(item->tipo), item->valor_entero);
                                                }

                                                argumentosDeclaracion.cabeza=NULL;
                                        }   
                                }
                                | VOID ID '(' argsFuncion ')' sentenciaCompuesta {
                                        if(!flag_error){
                                                Item *item;
                                                aux = agregarEnTabla(strdup($<mystruct>2.cadena), 'F', strdup("void"), cod_void);
                                                for (item = auxVariables.cabeza; item != NULL; item = item->siguiente)
                                                {
                                                        agregarArgumento(&aux->argumentos, strdup($<mystruct>2.cadena), strdup(item->tipo), item->valor_entero);        
                                                }
                                                auxVariables.cabeza=NULL;
                                        }
                                }
                                | tipoDato ID '(' argsFuncion ')' sentenciaCompuesta {
                                        char *tipoRetorno = $<mystruct>1.cadena;
                                        if(!flag_error){
                                                Item *item;
                                                aux = agregarEnTabla(strdup($<mystruct>2.cadena), 'F', strdup(tipoRetorno), $<mystruct>1.tipo);
                                                for (item = argumentosDeclaracion.cabeza; item != NULL; item = item->siguiente)
                                                {      
                                                        agregarArgumento(&aux->argumentos, strdup($<mystruct>2.cadena), strdup(item->tipo), item->valor_entero);
                                                }
                                                argumentosDeclaracion.cabeza=NULL;
                                                if(flag_retorno != aux->cod_asociado){
                                                agregarEnLista(&noReconocidos, concatenar("No coincide el retorno con el tipo de dato de la funcion ", $<mystruct>2.cadena), ERROR_SEMANTICO, yylineno);
                                                }
                                        }
                                }
                                |tipoDato ID error argsFuncion ')' sentenciaCompuesta {
                                }
                                |tipoDato ID '(' argsFuncion error sentenciaCompuesta {
                                        agregarEnLista(&noReconocidos, "No hubo cierre de parentesis en funcion", ERROR_SINTACTICO, yylineno);
                                }
                                |tipoDato ID error argsFuncion error sentenciaCompuesta {
                                        agregarEnLista(&noReconocidos, "Faltan parentesis en funcion", ERROR_SINTACTICO, yylineno);
                                }
;

argsFuncion:                    argumentoA 
                                | argumentoA ',' argsFuncion
;

argumentoA:			/* vacio */
                                | TIPO_DATO ID {
                                        agregarEnListaAlFinal(&argumentosDeclaracion, $<mystruct>2.cadena, $<mystruct>1.cadena,$<mystruct>1.tipo); // $<mystruct>1.tipo es el flag_tipo
                                        agregarEnTabla(strdup($<mystruct>2.cadena), 'V', strdup($<mystruct>1.cadena), $<mystruct>1.tipo);
                                }
                                | TIPO_DATO {
                                        agregarEnListaAlFinal(&argumentosDeclaracion, "", $<mystruct>1.cadena,$<mystruct>1.tipo); // $<mystruct>1.tipo es el flag_tipo
                                }
                                | error {flag_error=1;agregarEnLista(&noReconocidos, "Uno de los argumentos no es una expresion valida", ERROR_SINTACTICO, yylineno);}
;

declaracionVarSimples: 	        tipoDato listaVarSimples finDeclaracionVariable
                                | tipoDato error finDeclaracionVariable {
                                        agregarEnLista(&noReconocidos, "No se asigno la expresion a un lvalue", ERROR_SINTACTICO, yylineno);
                                        flag_error = 1;
                                }
                                | tipoDato listaVarSimples error {
                                        if(!flag_error){
                                                agregarEnLista(&noReconocidos, "Secuencia no reconocida", ERROR_SINTACTICO, yylineno);
                                                
                                        }
                                        // flag_error = 0;
                                }
;

finDeclaracionVariable:                 ';' {
                                        Item *item;
                                        for (item = auxVariables.cabeza; item != NULL; item = item->siguiente)
                                        {
                                                aux=obtenerDeTabla(item->nombre, 'V');
                                                if(aux){
                                                        agregarEnLista(&noReconocidos, concatenar("Ya se encuentra definida la variable ", item->nombre), ERROR_SEMANTICO , yylineno );
                                                }else{
                                                        aux = agregarEnTabla(strdup(item->nombre), 'V', strdup(tipo),flag_tipo);                                                            
                                                }
                                        }
                                        auxVariables.cabeza=NULL;
                                }       
;

tipoDato:                       TIPO_DATO puntero_op {tipo = $<mystruct>1.cadena; flag_tipo=$<mystruct>1.tipo;}
                                | error {printf("Falta tipo de dato en linea %d \n", yylineno);}
;

listaVarSimples: 		unaVarSimple
                                | listaVarSimples ',' unaVarSimple
;

unaVarSimple:                   ID arreglo_op inicializacion {
                                        if(!flag_error){
                                                if(esArray&&esPuntero){
                                                        agregarEnLista(&noReconocidos, "No puede ser puntero y array a la vez", "", yylineno);
                                                } else{
                                                if(esPuntero){tipo=concatenar(tipo,"*"); flag_tipo=cod_literal_cadena;}
                                                if(esArray){tipo=concatenar(tipo,"*"); flag_tipo=cod_literal_cadena;}
                                                if(esInicializado){
                                                        if(flag_tipo == flag_tipoAsignado){ 
                                                                agregarEnLista(&auxVariables, $<mystruct>1.cadena, tipo,yylineno);
                                                        }else{
                                                                printf("No coinciden los tipos de datos\n");                                                      
                                                                agregarEnLista(&noReconocidos, "No coinciden los tipos de datos", ERROR_SEMANTICO, yylineno);
                                                                flag_error = 0;                                                        
                                                        }
                                                } else {
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
                                                agregarEnLista(&noReconocidos, "No se reconoce identificador", ERROR_SINTACTICO, yylineno);       
                                                flag_error = 1;
                                        }
                                }
;

inicializacion:         /* vacio */
                        |'=' expresion {esInicializado=1;flag_tipoAsignado=$<mystruct>2.tipo}
;

arreglo_op:                /* vacio */
                        | arreglo_op '[' constante ']' {esArray=1;}
;                 
        
puntero_op:                /* vacio */
                        | puntero_op '*' {esPuntero=1;} // 1 para literal cadena
;

/* ---------- Expresiones */
expresion:			expAsignacion                               
;

expAsignacion: 			expCondicional 
                                | asignacionEnVariable // separo para el error              
;

asignacionEnVariable:            ID arreglo_op operAsignacion expAsignacion{
                                        aux = obtenerDeTabla($<mystruct>1.cadena, 'V');
                                        if(!existeVariable($<mystruct>1.cadena)){
                                                agregarEnLista(&noReconocidos, concatenar("No se declaro el identificador ", $<mystruct>1.cadena), ERROR_SEMANTICO, yylineno);
                                        }else{
                                                if(aux->cod_asociado != $<mystruct>4.tipo){
                                                        agregarEnLista(&noReconocidos, "Los tipos de datos no coinciden", ERROR_SEMANTICO, yylineno);
                                                }
                                        }
                                        
                                }
                                | error arreglo_op operAsignacion expAsignacion{
                                        agregarEnLista(&noReconocidos, "No se asigno la expresion a un lvalue", ERROR_SINTACTICO, yylineno);
                                        flag_error = 1;                                
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

expAditiva:			  expMultiplicativa
                                | expAditiva '+' expMultiplicativa {   
                                        ts *aux2;
                                        int codAsociadoAux =  0; //si no hay variable, se asume valor 0, que es el neutro para el OR
                                        int codAsociadoAux2 = 0; 
                                        int boolExpresion;

                                        if(!$<mystruct>1.esVar && $<mystruct>3.esVar){
                                                
                                                aux = obtenerDeTabla($<mystruct>3.cadena, 'V');
                                                codAsociadoAux = aux->cod_asociado;
                                                boolExpresion = $<mystruct>1.tipo == cod_literal_cadena 
                                                                || aux->cod_asociado;
                                        }
                                        else if($<mystruct>1.esVar && !$<mystruct>3.esVar){
                                                aux2 = obtenerDeTabla($<mystruct>1.cadena, 'V');
                                                codAsociadoAux2 = aux2->cod_asociado;
                                                boolExpresion = $<mystruct>3.tipo == cod_literal_cadena 
                                                                || aux2->cod_asociado;
                                        }
                                        else if($<mystruct>1.esVar && $<mystruct>3.esVar){
                                                aux2 = obtenerDeTabla($<mystruct>1.cadena, 'V');
                                                aux = obtenerDeTabla($<mystruct>3.cadena, 'V');
                                                boolExpresion = aux->cod_asociado
                                                                || aux2->cod_asociado;
                                        }
                                        else if(!$<mystruct>1.esVar && !$<mystruct>3.esVar){
                                                boolExpresion = $<mystruct>3.tipo == cod_literal_cadena 
                                                                || $<mystruct>1.tipo == cod_literal_cadena;
                                        }
                                        
                                        if(boolExpresion){
                                                agregarEnLista(&noReconocidos, "Operacion no valida para la +", ERROR_SEMANTICO, yylineno);
                                                $<mystruct>$.tipo = -1;
                                        }else{
                                                $<mystruct>$.tipo = cod_entero;
                                                
                                        }
                                }
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
                                | SIZEOF '(' TIPO_DATO ')'
;

operUnario:                     '&' | '*' | '-' | '!'
;

expPostFijo:			expPrimaria
		             	| expPostFijo '[' expresion ']'
                                | expPostFijo '(' listaArgumentos ')'
;

listaArgumentos:                expAsignacion
                                | listaArgumentos ',' expAsignacion
;

expPrimaria:                    ID {
                                        aux = obtenerDeTabla(strdup($<mystruct>1.cadena), 'V');
                                        if(!existeVariable($<mystruct>1.cadena)){
                                                agregarEnLista(&noReconocidos, concatenar("No existe el identificador ", $<mystruct>1.cadena), ERROR_SEMANTICO, yylineno);
                                                $<mystruct>$.esVar = 0;         
                                        }else{
                                                flag_retorno=aux->cod_asociado;
                                                $<mystruct>$.tipo = aux->cod_asociado;
                                                $<mystruct>$.esVar = 1;
                                                strcpy($<mystruct>1.cadena,aux->nombre);
                                        }                  
                                }
                               | constante {flag_retorno=$<mystruct>1.tipo}
                               | LITERAL_CADENA {$<mystruct>$.tipo=$<mystruct>1.tipo; flag_retorno=$<mystruct>1.tipo}
                               | '(' expresion ')'
                               | usoDeFuncion
                               | error {
                                        if(flag_error){
                                                agregarEnLista(&noReconocidos, "No se asigno valor a un lvalue", "", yylineno);
                                        }
                               }
;

usoDeFuncion:                   ID '(' listaParametros ')' {
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

sentencia:		          sentenciaCompuesta
                                | sentenciaDeExpresion
                                | sentenciaDeControl
                                | sentenciaDeIteracion
                                | sentenciaDeSalto 
                                                  
;

sentenciaCompuesta:              '{' sentencias_y_declaraciones '}'
;

sentencias_y_declaraciones:     /* vacio */
                                | listaDeclaraciones sentencias_y_declaraciones
                                | listaSentencias sentencias_y_declaraciones
;

listaSentencias:                sentencia
                                | listaSentencias sentencia
;

listaDeclaraciones:              declaracionVarSimples
                                | listaDeclaraciones declaracionVarSimples
;

sentenciaDeExpresion:		expresion ';'
                                | ';'
;

sentenciaDeControl: 	        IF '(' expresion ')' sentencia {tipoSentencia="if";}
                                | IF '(' expresion ')' sentencia ELSE sentencia {tipoSentencia="if-else";}
                                | SWITCH '(' expresion ')' sentencia {tipoSentencia="switch";}                                
;

sentenciaDeIteracion:          WHILE '(' expresion ')' sentencia {tipoSentencia = "while";}
                                | DO sentencia WHILE '(' expresion ')' ';' {tipoSentencia="do-while";}
                                | FOR '(' declaracionVarSimples  expresionFor ';' expresionFor ')' sentencia {tipoSentencia = "for";}
                                | FOR '(' expresionFor  expresionFor ';' expresionFor ')' sentencia {tipoSentencia = "for";}          
;
     
expresionFor:                   /*vacio */
                                | expresion
;

sentenciaDeSalto:              RETURN ';'
                               | RETURN expresion ';'
                               | RETURN error {agregarEnLista(&noReconocidos, "Falta ; antes del }", ERROR_SINTACTICO, yylineno);}
%%

ts *tabla_simbolos;

int existeVariable(char *identificador){
        aux = obtenerDeTabla(identificador, 'V');
        Lista *lista = &argumentosDeclaracion;
        if(aux){
                return 1;
        }else{
                Item *item = lista->cabeza;
                while (item != NULL)
                {
                        if (strcmp(identificador, item->nombre) == 0)
                        {
                                return 1;
                        }
                        item = item->siguiente;
                }
        }
        return 0; // no existe
}

int main (){

        inicializar(); //inicializo las listas
        auxVariables.cabeza = NULL;
        auxParametros.cabeza = NULL;
        argumentosDeclaracion.cabeza=NULL;
        FILE *f = fopen("salida.txt", "w");        
        yyin=fopen("entrada.c", "r");
        if(!yyparse()){
                printf("\n***Parser completado***\n\n");
                mostrarReporte();
        }else{
                printf("\nEL parser fallo\n");
        }

        fclose(yyin);
        fclose(f);
}