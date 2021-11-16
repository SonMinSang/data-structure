ifndef __ARRAY_H__
    define __ARRAY_H__

    typedef struct ArrayListNode
{
    int data;
} ArrayListNode;

typedef struct ArrayList
{
    int maxElementCount;
    int currentElementCount;
    ArrayListNode *pElement;
} ArrayList;

ArrayList *createArrayList(int maxElementCount);
int deleteArrayList(int index);
int isArrayListFull(ArrayList al);
int removeAlElement(ArrayList al);
int displayArrayList(int index, ArrayList al);
clearArrayList(ArrayList al);
getArrayListLength(ArrayList al);

endif __ARRAY_H__