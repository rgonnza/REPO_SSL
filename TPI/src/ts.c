/* ============================================================================================ */
/* ======================== Funciones para el tratamiento de la TS ============================= */
/* ============================================================================================ */

#include "ts.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

ts *agregarEnTabla(char const *nombreId, char varOfn, char const *tipoDato, int cod_asociado)
{
  ts *ptr = (ts *)malloc(sizeof(ts));
  ptr->nombre = (char *)malloc(strlen(nombreId) + 1);
  strcpy(ptr->nombre, nombreId);
  ptr->tipo_dato = (char *)malloc(strlen(tipoDato) + 1);
  strcpy(ptr->tipo_dato, tipoDato);
  ptr->esVar = varOfn;
  ptr->cod_asociado = cod_asociado;
  (ptr->argumentos).cabeza = NULL;
  ptr->siguiente = (struct ts *)tabla_simbolos;
  tabla_simbolos = ptr;
  return ptr;
}

ts *obtenerDeTabla(char const *nombreId, char varOfn)
{
  ts *ptr;
  for (ptr = tabla_simbolos; ptr != (ts *)0;
       ptr = (ts *)ptr->siguiente)
    if (strcmp(ptr->nombre, nombreId) == 0 && ptr->esVar == varOfn)
      return ptr;
  return 0;
}

void agregarArgumento(Lista *lista, char const *nombre, char const *tipo, int flag_tipo)
{
  Item *aux = malloc(sizeof(Item));
  aux->siguiente = lista->cabeza;
  aux->nombre = (char *)malloc(strlen(nombre) + 1);
  strcpy(aux->nombre, nombre);
  aux->tipo = (char *)malloc(strlen(tipo) + 1);
  aux->valor_entero = flag_tipo;
  strcpy(aux->tipo, tipo);
  lista->cabeza = aux;
}

int cantidadArgumentos(ts *t)
{
  int i = 0;
  Item *aux;
  Lista *lista = &t->argumentos;
  for (aux = lista->cabeza; aux != NULL; aux = aux->siguiente)
  {
    i++;
  }
  return i;
}

void mostrarReporte()
{
  reporteVariables();
  reporteFunciones();
  reporteErrores(&noReconocidos);
}

void imprimirArgumentos(ts *t)
{
  Item *aux;
  Lista *lista = &t->argumentos;
  printf("\t\tTipos de argumentos: ");
  for (aux = lista->cabeza; aux != NULL; aux = aux->siguiente)
  {
    printf("%s ", aux->tipo);
  }
  printf("\n");
}

void reporteFunciones()
{
  ts *ptr;
  printf("\nFunciones declaradas: \n");
  for (ptr = tabla_simbolos; ptr != (ts *)0; ptr = (ts *)ptr->siguiente)
  {
    if (ptr->esVar == 'F')
    {
      int cantidad = cantidadArgumentos(ptr);
      printf("\tIdentificador: %s | Tipo de dato de la funcion: %s | Cantidad de args: %i \n", ptr->nombre, ptr->tipo_dato, cantidad);
      imprimirArgumentos(ptr);
    }
  }
}

void reporteVariables()
{
  ts *ptr;
  printf("\nVariables declaradas: \n");
  for (ptr = tabla_simbolos; ptr != (ts *)0; ptr = (ts *)ptr->siguiente)
  {
    if (ptr->esVar == 'V')
    {
      printf("\tIdentificador: %s | Tipo de dato: %s \n", ptr->nombre, ptr->tipo_dato);
    }
  }
}