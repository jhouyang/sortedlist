#include "SkipList.h"


SkiplistNode* FindNode(SkipList* list, DataType data, CmpFunc func)
{
    if (!list) return NULL;
    SkiplistNode* pNode = list->head;
    if (!pNode) return NULL;

    for (int i = list->maxLevel - 1; i >= 0; --i)
    {
        // if Null or larger than (or equal) data, continue
        while (pNode->levels[i].forward && func(pNode->levels[i].forward, data) < 0)
        {
            pNode = pNode->levels[i].forward;
        }
        pNode = pNode->levels[0].forward;
        if (node && !func(pNode, data)) // found
        {
            return pNode;
        }
        return NULL;
    }
}
