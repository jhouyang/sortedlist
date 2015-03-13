#ifndef LIST_H_
#define LIST_H_

typedef void* DataPtr;
typedef struct List {
    DataPtr data;
    List* next;
};

typedef void (ForeachFunc*)(List*) ;
void Foreach(List* list, ForeachFunc func);

void PushBack(List* list, DataPtr data);
void PushFront(List* list, DataPtr data);

typedef int (CmpFunc*)(List*, List*);
void Sort(List* list, CmpFunc func);

typedef void (DeleteDataFunc)(List*);
void FreeNode(List* list, DataPtr data, DeleteDataFunc func);
void FreeList(List* list, DeleteDataFunc func);

#endif
