#include "List.h"

void Foreach(List* list, ForeachFunc func)
{
    List* ptr = NULL;
    for (ptr = list; list != NULL; ptr = ptr->next)
    {
        func(ptr);
    }
}

void PushBack(List* list, DataPtr data)
{
    List* newNode = new List();
    newNode->data = data;
    newNode->next = NULL;

    if (list == NULL)
    {
        list = newNode;
        return;
    }

    List* end = list;
    while (end->next != NULL)
    {
        end = end->next;
    }
    end->next = newNode;
}

void PushFront(List* list, DataPtr data)
{
    List* newNode = new List();
    newNode->data = data;
    newNode->next = list;
}

List* MergeSort(List* la, List* lb, CmpFunc func)
{
    if (!la) return lb;
    if (!lb) return la;

    List* l = new List(); // new list
    List* head = l; // head->next always point to valid list

    l = head;
    while (la && lb)
    {
        if (func(la->data, lb->data))
        {
            // l move to next
            l->next = la;
            l = la;

            // la move to next
            la = la->next;
        }
        else
        {
            l->next = lb;
            l = lb;

            lb = lb->next;
        }
    }

    // merge left nodes
    l->next = (la ? la : lb);
    return head->next;
}

List* Sort(List* list, CmpFunc func)
{
    if (!list || !list->data) return list;

    // split into two lists
    List* la = list;
    List* lb = list->next;

    while (lb && lb->next)
    {
        la = la->next;
        lb = lb->next->next;
    }
    lb = la->next;
    la->next = NULL;

    return MergeSort(la, lb, func);
}

void FreeNode(List* list, DataPtr data, DeleteDataFunc func)
{
    if (list->data == data)
    {
        List* node = list;
        func(data);
        list = list->next;
        node->next = NULL;
        delete node;
        return;
    }

    List* next = list->next;
    List* current = list;
    while (next)
    {
        if (next->data == data)
        {
            List* deleteNode = next;
            current->next = next->next;

            deleteNode->next = NULL;
            func(data);
            delete deleteNode;
            return;
        }
        next = next->next;
        current = current->next;
    }
}

void FreeList(List* list, DeleteDataFunc func)
{
    List* deleteNode = NULL;
    while (list)
    {
        deleteNode = list;
        list = list->next;
        deleteNode->next = NULL;

        func(deleteNode->data);
        delete deleteNode;
    }
}


