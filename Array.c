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
