#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <stdlib.h>

// Definición de la estructura Node
typedef struct Node {
    void *data;         // Datos que contiene el nodo
    struct Node *next;  // Apuntador al siguiente nodo
} Node;

// Definición de la estructura List
typedef struct List {
    Node *head;     // Primer nodo de la lista
    Node *tail;     // Último nodo de la lista
    Node *current;  // Nodo actual de la lista (para iteraciones)
    int size;       // Tamaño de la lista
} List;

// Declaración de las funciones para manejar la lista
List *list_create();  // Crea una lista vacía
void *list_first(List *L);  // Retorna el primer elemento de la lista
void *list_next(List *L);   // Mueve al siguiente elemento de la lista
void list_pushFront(List *L, void *dato);  // Inserta al inicio de la lista
void list_pushBack(List *L, void *dato);   // Inserta al final de la lista
void list_pushCurrent(List *L, void *dato);  // Inserta después del elemento actual

void *list_popFront(List *L);  // Elimina el primer elemento de la lista
void *list_popBack(List *L);   // Elimina el último elemento de la lista
void *list_popCurrent(List *L);  // Elimina el elemento actual de la lista

void list_clean(List *L);  // Elimina todos los elementos de la lista

// Función para insertar un elemento en orden usando la función lower_than
void list_sortedInsert(List *L, void *data, int (*lower_than)(void *data1, void *data2));

// Función para obtener el tamaño de la lista
int list_size(List *L);

#endif
