#ifndef CALC_H
#define CALC_H
#define TYP_VAR 0
#define TYP_FNCT 1
#include "listas.h"

enum
{
  cod_entero = 0,
  cod_caracter = 0,
  cod_literal_cadena = 1,
  cod_real = 0,
  cod_void = 3
};

typedef struct ts
{
  char *nombre;     // identificador de la variable o funcion
  char esVar;       // 'V' si es variable, 'F' si es funcion
  char *tipo_dato;  // Tipo de dato de la funcion o variable
  int cod_asociado; // Para simplificar las validaciones. Por ej, a entero y float se los asigna el mismo codigo para operarlos
  Lista argumentos;
  struct ts *siguiente;
} ts;

extern ts *tabla_simbolos;

ts *agregarEnTabla(char const *, char, char const *, int);
ts *obtenerDeTabla(char const *, char);
void agregarArgumento(Lista *, char const *, char const *, int);
int cantidadArgumentos(ts *);

#endif