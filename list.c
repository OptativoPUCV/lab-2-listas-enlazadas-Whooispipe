#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"

typedef struct Node Node;

struct Node {
    void * data;
    Node * next;
    Node * prev;
};

struct List {
    Node * head;
    Node * tail;
    Node * current;
};

typedef List List;

Node * createNode(void * data) {
    Node * new = (Node *)malloc(sizeof(Node));
    assert(new != NULL);
    new->data = data;
    new->prev = NULL;
    new->next = NULL;
    return new;
}

List * createList() {
    List  *list= (List*)malloc(sizeof(List));
    list->head = NULL;
    list->tail = NULL;
    list->current = NULL;
    return list;
}

void * firstList(List * list) {
    if (list->head != NULL) 
    {
        list->current = list->head;
        return list->current->data;
    }
    return NULL;
}

void * nextList(List * list) {
    if(list->current != NULL) {
        list->current = list->current->next;
        if (list->current != NULL) {
            return list->current->data;
        }
    }
    return NULL;
}

void * lastList(List * list) {
    if (list->tail != NULL) 
    {
        list->current = list->tail;
        return list->current->data;
    }
    return NULL;
}

void * prevList(List * list) {
    if(list->current != NULL) {
        list->current = list->current->prev;
        if (list->current != NULL) {
            return list->current->data;
        }
    }
    return NULL;
}

void pushFront(List * list, void * data) {
    Node *nuevo= createNode(data);
    if(list->head==NULL)
    {
        list->head=nuevo;
        list->tail=nuevo;


    }
    else
    {
        nuevo->next=list->head;
        list->head->prev=NULL;
        list->head=nuevo;


    }


    
}

void pushBack(List * list, void * data) {
    list->current = list->tail;
    pushCurrent(list,data);
}

void pushCurrent(List * list, void * data) {
    Node * nuevo= createNode(data);
    if(list->current==NULL)
    {
        list->head=nuevo;
        list->tail=nuevo;


    }
    else
    {
        nuevo->next=list->current->next;
        nuevo->prev=list->current;
        list->current->next=nuevo;
        if(nuevo->next!=NULL)
        {
            nuevo->next->prev=nuevo;
        }
        else
        {
            list->tail=nuevo;
        }


    }
}

void * popFront(List * list) {
    list->current = list->head;
    return popCurrent(list);
}

void * popBack(List * list) {
    list->current = list->tail;
    return popCurrent(list);
}

void * popCurrent(List * list) {
    if(list->current !=NULL)
    {
        Node *aux=list->current;
        void * data=aux->data;
        if(aux->prev!=NULL)
        {
            aux->prev->next=aux->next;
        }
        else
        {
            list->head=aux->next;
        }
        if(aux->next!=NULL)
        {
            aux->next->prev=aux->prev;
        }
        else
        {
            list->tail=aux->prev;
        }
        return data;



    }
    return NULL;

}

void cleanList(List * list) {
    while (list->head != NULL) {
        popFront(list);
    }
}