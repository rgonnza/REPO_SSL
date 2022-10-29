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

void agregarEnLista(Lista *lista, char *token, char *tipo, int valor_entero)
{
    Item *aux = malloc(sizeof(Item));
    aux->siguiente = lista->cabeza;
    aux->valor_entero = valor_entero;
    aux->token = concatenar(token, "");
    aux->tipo = concatenar(tipo, "");
    lista->cabeza = aux;
}
Item *crear(Lista *lista)
{
    Item *item = (Item *)malloc(sizeof(Item));
    item->siguiente = NULL;
    return item;
}
void agregarEnListaAlFinal(Lista *lista, char *token, char *tipo, int valor_entero)
{
    Item *item = crear(lista);
    item->valor_entero = valor_entero;
    item->token = concatenar(token, "");
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

// void insertlast(int ele)    //insert at the last of linked list
// {
//     struct node *New, *temp;
//     New = (struct node*)malloc(sizeof(struct node));
//     if(New== NULL)
//     {
//         printf("Unable to allocate memory.");
//         return;
//     }
//     else
//     {
//         New->value = ele;
//         New->next = NULL;
//         temp = head;
//         while(temp->next != NULL)
//             temp = temp->next;
//         temp->next = New;
//         printf("DATA INSERTED SUCCESSFULLY\n");
//     }
// }

void inicializar()
{
    variables.cabeza = NULL;
    sentencias.cabeza = NULL;
    funciones.cabeza = NULL;
    noReconocidos.cabeza = NULL;
}

void imprimir(Lista *lista)
{
    Item *aux;
    for (aux = lista->cabeza; aux != NULL; aux = aux->siguiente)
    {
        printf("Token: %s | Tipo: %s | Num. linea: %i \n", aux->token, aux->tipo, aux->valor_entero);
    }
}
int existeIdentificador(Lista *lista, char *token)
{
    Item *aux = lista->cabeza;
    while (aux != NULL)
    {
        if (strcmp(token, aux->token) == 0)
        {
            return 1;
        }
        aux = aux->siguiente;
    }
    return 0;
}

void realizarReporte(FILE *archivo)
{
    Item *aux;
    fprintf(archivo, "-----Variables:\n");
    Lista *lista = &variables;
    for (aux = lista->cabeza; aux != NULL; aux = aux->siguiente)
    {
        fprintf(archivo, "%s | Tipo: %s | Num. linea: %i \n", aux->token, aux->tipo, aux->valor_entero);
    }

    fprintf(archivo, "\n-----Sentencias:\n");
    lista = &sentencias;
    for (aux = lista->cabeza; aux != NULL; aux = aux->siguiente)
    {
        fprintf(archivo, "%s | Num. linea: %i \n", aux->tipo, aux->valor_entero);
    }

    fprintf(archivo, "\n-----Funciones:\n");
    lista = &funciones;
    for (aux = lista->cabeza; aux != NULL; aux = aux->siguiente)
    {
        fprintf(archivo, "%s | Tipo: %s | Num. linea: %i \n", aux->token, aux->tipo, aux->valor_entero);
    }

    fprintf(archivo, "\n-----No reconocidos:\n");
    lista = &noReconocidos;
    for (aux = lista->cabeza; aux != NULL; aux = aux->siguiente)
    {
        fprintf(archivo, "%s | Num. linea: %i \n", aux->token, aux->valor_entero);
    }
}
void imprimirError(Lista *lista, char *tipo)
{
    printf("\nErrores %s: \n", tipo);
    Item *aux;
    for (aux = lista->cabeza; aux != NULL; aux = aux->siguiente)
    {
        if (strcmp(aux->tipo, tipo) == 0)
        {
            printf("\t %s | Num. linea: %i \n", aux->token, aux->valor_entero);
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