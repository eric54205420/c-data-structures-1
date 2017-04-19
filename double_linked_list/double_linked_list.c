#include <stdio.h>
#include <stdlib.h>

#include "double_linked_list.h"

/**
 *
 */
DoubleLinkedList create(const int data)
{
    DoubleLinkedListNode* node = malloc(sizeof(DoubleLinkedListNode));
    node->data = data;
    node->next = NULL;
    node->previous = NULL;

    DoubleLinkedList list;
    list.head = node;
    list.tail = node;
    list.size = 1;

    return list;
}

/**
 *
 */
void insertAtTheEnd(DoubleLinkedList* list, const int data)
{
    DoubleLinkedListNode* node = list->tail;

    node->next = malloc(sizeof(DoubleLinkedListNode));
    node->next->data = data;
    node->next->next = NULL;
    node->next->previous = node;

    list->size++;
    list->tail = node->next;
}

/**
 *
 */
void insertAtTheBeginning(DoubleLinkedList* list, const int data)
{
    DoubleLinkedListNode* node = list->head;

    node->previous = malloc(sizeof(DoubleLinkedListNode));
    node->previous->data = data;
    node->previous->next = node;
    node->previous->previous = NULL;

    list->size++;
    list->head = node->previous;
}

/**
 *
 */
const int at(DoubleLinkedList* list, const unsigned int index)
{
    DoubleLinkedListNode* node = list->head;

    /* TODO: #42 the at() method should browse the list
     * from the tail to the head */

    for (
        unsigned int i = 0;
        i != index;
        i++
    )
    {
        node = node->next;
    }

    return node->data;
}

/**
 *
 */
const unsigned int size(DoubleLinkedList* list)
{
    return list->size;
}

/**
 *
 */
int* all(DoubleLinkedList* list)
{
    DoubleLinkedListNode* node = list->head;

    int* datas = (int*) malloc(list->size * sizeof(int));

    unsigned int i = 0;
    while(node != NULL)
    {
        datas[i] = node->data;

        node = node->next;
        i++;
    }

    return datas;
}

/**
 *
 */
void insertAfter(DoubleLinkedList* list, const unsigned int index, const int data)
{
    DoubleLinkedListNode* node = list->head;
    DoubleLinkedListNode* currentNext = node->next;

    for (
        unsigned int i = 0;
        i < index;
        i++
    )
    {
        node = node->next;
        currentNext = node->next;
    }

    DoubleLinkedListNode* newNode = malloc(sizeof(DoubleLinkedListNode));
    newNode->data = data;
    newNode->next = currentNext;

    node->next = newNode;
}
