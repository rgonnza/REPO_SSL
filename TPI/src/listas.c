/* ============================================================================================ */
/* ================== Funciones para listas auxiliares y no reconocidos ======================== */
/* ============================================================================================ */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listas.h"

char *concatenar(const char *s1, const char *s2)
{
    char *resultado = malloc(strlen(s1) + strlen(s2) + 1); // sumo uno por null
    strcpy(resultado, s1);
    strcat(resultado, s2);
    return resultado;
}

void agregarEnLista(Lista *lista, char *nombre, char *tipo, int valor_entero)
{
    Item *aux = malloc(sizeof(Item));
    aux->siguiente = lista->cabeza;
    aux->valor_entero = valor_entero;
    aux->nombre = concatenar(nombre, "");
    aux->tipo = concatenar(tipo, "");
    lista->cabeza = aux;
}

Item *crear(Lista *lista)
{
    Item *item = (Item *)malloc(sizeof(Item));
    item->siguiente = NULL;
    return item;
}

void agregarEnListaAlFinal(Lista *lista, char *nombre, char *tipo, int valor_entero)
{
    Item *item = crear(lista);
    item->valor_entero = valor_entero;
    item->nombre = concatenar(nombre, "");
    item->tipo = concatenar(tipo, "");
    if (lista->cabeza == NULL)
    {
        lista->cabeza = item;
    }
    else
    {
        Item *puntero = lista->cabeza;
        while (puntero->siguiente)
        {
            puntero = puntero->siguiente;
        }
        puntero->siguiente = item;
    }
}

void inicializar()
{
    noReconocidos.cabeza = NULL;
}

int existeIdentificador(Lista *lista, char *nombre)
{
    Item *aux = lista->cabeza;
    while (aux != NULL)
    {
        if (strcmp(nombre, aux->nombre) == 0)
        {
            return 1;
        }
        aux = aux->siguiente;
    }
    return 0;
}

void imprimirError(Lista *lista, char *tipo)
{
    printf("\nErrores %s: \n", tipo);
    Item *aux;
    for (aux = lista->cabeza; aux != NULL; aux = aux->siguiente)
    {
        if (strcmp(aux->tipo, tipo) == 0)
        {
            printf("\t %s | Num. linea: %i \n", aux->nombre, aux->valor_entero);
        }
    }
}

void reporteErrores(Lista *lista)
{
    imprimirError(lista, ERROR_SINTACTICO);
    imprimirError(lista, ERROR_SEMANTICO);
}

int longitudLista(Lista lista)
{
    int i = 0;
    Item *aux;
    for (aux = lista.cabeza; aux != NULL; aux = aux->siguiente)
    {
        i++;
    }
    return i;
}

char *last_letter(const char *str)
{
    int len = strlen(str);
    return len > 0 ? str + len - 1 : str;
}