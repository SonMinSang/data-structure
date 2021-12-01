#include "maze.h"

void solve_maze(Map map, LinkedStack *pStack, StackNode start, StackNode goal)
{
    StackNode next;
    StackNode *back;

    pushLS(pStack, start);
    next = start;
    while (!isLinkedStackEmpty(pStack) && !(next.x == goal.x && next.y == goal.y))
    {
        back = popLS(pStack);
        next.x = back->x;
        next.y = back->y;
        next.direction = start.direction;
        while (next.direction < 4 && !(next.x == goal.x && next.y == goal.y))
        {
            next.x = next.x + Directions[next.direction][0];
            next.y = next.y + Directions[next.direction][1];
            if (next.x >= width || next.x < 0 && next.y >= height || next.y < 0 || map[next.y][next.x] != 0)
                next.direction++;
            else
            {
                map[next.y][next.x] = 2;
                pushLS(pStack, next);
                next.direction = 0;
                if (next.x == goal.x && next.y == goal.y)
                {
                    print();
                    return;
                }
            }
        }
    }
    if (next.x == goal.x && next.y == goal.y)
    {
        print();
        return;
    }
}

void like_element()
{
}
