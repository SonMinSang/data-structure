#ifndef _MAZE_
#define _MAZE_

typedef struct StackNodeType
{
    int x;
    int y;
    int direction;
    struct StackNodeType *pLink;
} StackNode;

typedef struct LinkedStackType
{
    int currentElementCount;
    StackNode *pTopElement;
} LinkedStack;

int Directions[4][2] =
    {
        {0, 1},
        {0, -1},
        {1, 0},
        {-1, 0}};

int Maze()
{
}

LinkedStack *createLinkedStack();
int pushLS(LinkedStack *pStack, StackNode element);
StackNode *popLS(LinkedStack *pStack);
StackNode *peekLS(LinkedStack *pStack);
void deleteLinkedStack(LinkedStack *pStack);
int isLinkedStackFull(LinkedStack *pStack);
int isLinkedStackEmpty(LinkedStack *pStack);
void displayLinkedStack(LinkedStack *pStack);

#endif

#ifndef _COMMON_STACK_DEF_
#define _COMMON_STACK_DEF_

#define TRUE 1
#define FALSE 0

#endif