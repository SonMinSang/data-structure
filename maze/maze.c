#include "maze.h"
#include <stdio.h>
#include <stdlib.h>
void solve_maze(int **map, LinkedStack *pStack, StackNode start, StackNode goal)
{
    StackNode next;
    StackNode *back;

    pushLS(pStack, start);
    next.x = start.x;
    while (!isLinkedStackEmpty(pStack) && !(next.x == goal.x && next.y == goal.y))
    {

        back = popLS(pStack);
        next.x = back->x;
        next.y = back->y;
        next.direction = start.direction;

        while (next.direction < 4 && !(next.x == goal.x && next.y == goal.y))
        {
            printf("%d %d\n", next.x, next.y);
            next.x = next.x + Directions[next.direction][0];

            next.y = next.y + Directions[next.direction][1];
            if (next.x >= width || next.x < 0 || next.y >= height || next.y < 0 || map[next.y][next.x] != 0)
            {
                next.x = next.x - Directions[next.direction][0];
                next.y = next.y - Directions[next.direction][1];
                (next.direction)++;
            }
            else
            {
                map[next.y][next.x] = 2;
                pushLS(pStack, next);
                next.direction = 0;
                if (next.x == goal.x && next.y == goal.y)
                {
                    print(map);
                    return;
                }
            }
        }
    }
    if (next.x == goal.x && next.y == goal.y)
    {
        print(map);
        return;
    }
}

void print(int **map)
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            printf("%d", map[i][j]);
        }
        printf("\n");
    }
}
