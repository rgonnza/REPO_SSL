#ifndef CALC_H
#define CALC_H
#define TYP_VAR 0
#define TYP_FNCT 1
#include "listas.h"

enum
{
  cod_entero,
  cod_literal_cadena,
  cod_caracter,
  cod_real,
  cod_id
};

typedef struct ts
{
  char *nombre; // identificador de la variable o funcion
  char esVar;   // 'V' si es variable, 'F' si es funcion
  char *tipo_dato;
  Lista argumentos;
  struct ts *siguiente;
} ts;

extern ts *tabla_simbolos;

// Declaración de la función putsym para agregar símbolo a la TS
ts *agregarEnTabla(char const *, char, char const *); //(identificador, tipo)
// Declaración de la función getsym para tomar un símbolo de la TS
ts *obtenerDeTabla(char const *, char); // identificador
// void *agregarArgumento(ts *, char const *, char const *);
void realizarReporte();

#endif
