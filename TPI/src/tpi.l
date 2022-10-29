%{

#include "tpi.tab.h"
#include "ts.h"
#include <stdio.h>
#include <string.h>



%}

DIGITO_DECIMAL [0-9] 
DIGITO_OCTAL [0-7] 
DIGITO_HEXADECIMAL [a-fA-F0-9]
CTE_DECIMAL [1-9]{DIGITO_DECIMAL}*
CTE_OCTAL 0{DIGITO_OCTAL}*
CTE_HEXADECIMAL 0[xX]{DIGITO_HEXADECIMAL}+
CTE_REAL [0-9]*\.[0-9]+([Ee](\+|\-)?[0-9]*)?
CTE_CARACTER \'[\x00-\x80]\'
LITERAL_CADENA \".*\"
COMENTARIO_LINEA_SIMPLE \/\/.*
COMENTARIO_LINEAS_MULTIPLES [/][*][^*]*[*]+([^*/][^*]*[*]+)*[/] 
PRINTF "printf"\(.*\)  

%option noyywrap
%option yylineno

%%

{CTE_CARACTER} {yylval.mystruct.caracter = yytext; yylval.mystruct.tipo=cod_caracter; return CARACTER;}
{CTE_DECIMAL}|{CTE_OCTAL}|{CTE_HEXADECIMAL} {yylval.mystruct.entero = atoi(yytext); yylval.mystruct.tipo= cod_entero; return ENTERO;}
{CTE_REAL} {yylval.mystruct.real = atof(yytext); yylval.mystruct.tipo=cod_real; return REAL;}
{LITERAL_CADENA} {strcpy(yylval.mystruct.cadena,yytext); yylval.mystruct.tipo=cod_literal_cadena; return LITERAL_CADENA;}
["unsigned "|"short "|"signed "]*int {strcpy(yylval.mystruct.cadena,yytext); yylval.mystruct.tipo=cod_entero; return TIPO_DATO;}            
["long "]?double|float {strcpy(yylval.mystruct.cadena,yytext); yylval.mystruct.tipo=cod_real; return TIPO_DATO;}            
char {strcpy(yylval.mystruct.cadena,yytext); yylval.mystruct.tipo= cod_caracter; return TIPO_DATO;}
void {strcpy(yylval.mystruct.cadena,yytext); return VOID;}
if {strcpy(yylval.mystruct.cadena,yytext); return IF;}
else {strcpy(yylval.mystruct.cadena,yytext); return ELSE;}
switch {strcpy(yylval.mystruct.cadena,yytext); return SWITCH;}
do {strcpy(yylval.mystruct.cadena,yytext); return DO;}
while {strcpy(yylval.mystruct.cadena,yytext); return WHILE;}
for {strcpy(yylval.mystruct.cadena,yytext); return FOR;}
sizeof {strcpy(yylval.mystruct.cadena,yytext); return SIZEOF;}
return {strcpy(yylval.mystruct.cadena,yytext); return RETURN;}
"=="|"!=" {strcpy(yylval.mystruct.cadena,yytext); return IGUAL_O_DISTINTO;}
">"|">=" {strcpy(yylval.mystruct.cadena,yytext); return MAYOR_O_IGUAL;}
"<"|"<=" {strcpy(yylval.mystruct.cadena,yytext); return MENOR_O_IGUAL;}
"++"|"--" {strcpy(yylval.mystruct.cadena,yytext); return INCREMENTO_O_DECREMENTO;}
"&&" {strcpy(yylval.mystruct.cadena,yytext); return AND;}
"||" {strcpy(yylval.mystruct.cadena,yytext); return OR;}
[A-Za-z_][A-Za-z_0-9]* {strcpy(yylval.mystruct.cadena,yytext);yylval.mystruct.tipo=cod_id; return ID;}
"+="|"-=" {strcpy(yylval.mystruct.cadena,yytext); return OPERADOR_ASIGNACION;}
"="     {return '=';}
","     {return ',';}
";"     {return ';';}
"{"     {return '{';}
"}"     {return '}';}
"("     {return '(';}
")"     {return ')';}
":"     {return ':';}
"?"     {return '?';}
"&"     {return '&';}
"+"     {return '+';}
"-"     {return '-';}
"*"     {return '*';}
"/"     {return '/';}
"%"     {return '%';}
"!"     {return '!';}
"["     {return '[';}
"]"     {return ']';}
[ \t\n]+ /* se ignoran tabulaciones y saltos de línea */
{COMENTARIO_LINEA_SIMPLE} /* se ignoran comentarios */
{PRINTF}
{COMENTARIO_LINEAS_MULTIPLES}
%%