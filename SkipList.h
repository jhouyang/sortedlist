#ifndef SKIPLIST_H_
#define SKIPLIST_H_

typedef void* DataType;
typedef MAX_LEVEL 10;

// return >0 : pNode->data > data
typedef int (CmpFunc*)(SkiplistNode*, DataType*);

typedef struct SkiplistNode {
    DataType data;
    // keep next of each level
    struct LevelArray {
        struct SkiplistNode* next;
    } levels[];
} SkiplistNode;

typedef struct Skiplist {
    struct SkiplistNode *head, *tail;
    int length;
    int maxLevel;
} Skiplist;


SkiplistNode* FindNode(SkipList* list, DataType data, CmpFunc func);
#endif

