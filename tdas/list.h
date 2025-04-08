#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <stdlib.h>

// Definir la estructura Node
typedef struct Node {
    void *data;
    struct Node *next;
} Node;

// Definir la estructura List
typedef struct List {
    Node *head;
    Node *tail;
    Node *current;
    int size;
} List;

// Funciones de la lista
List* list_create();
void* list_first(List *L);
void* list_next(List *L);
void list_pushFront(List *L, void *data);
void list_pushBack(List *L, void *data);
void list_pushCurrent(List *L, void *data);
void list_sortedInsert(List *L, void *data, int (*lower_than)(void *data1, void *data2));
void* list_popFront(List *L);
void* list_popBack(List *L);
void* list_popCurrent(List *L);
int list_size(List *L);
void list_clean(List *L);

#endif // LIST_H
