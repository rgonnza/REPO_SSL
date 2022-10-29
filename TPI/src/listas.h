#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ERROR_SEMANTICO "semanticos"
#define ERROR_SINTACTICO "sintacticos"
#define ERROR_LEXICO "lexicos"

typedef struct Item
{
    int valor_entero; // para guardar el numLinea si hay error, o el codigo asociado
    char *token;      /* token: setencia | tipo : control */
    char *nombre;
    char *tipo;
    struct Item *siguiente;
} Item;

typedef struct lista
{
    Item *cabeza;
} Lista;

Lista variables;
Lista sentencias;
Lista funciones;
Lista noReconocidos;
