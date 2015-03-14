#ifndef SKIPLIST_H_
#define SKIPLIST_H_

typedef void* DataType;
typedef MAX_LEVEL 10;

typedef int (CmpFunc*)(SkiplistNode*, SkiplistNode*);

typedef struct SkiplistNode {
    DataType data;
    struct LevelArray {
        struct SkiplistNode* next;
    } levels[];
} SkiplistNode;

typedef struct Skiplist {
    struct SkiplistNode *heard, *tail;
    int length;
    int maxLevel;
} Skiplist;

#endif
