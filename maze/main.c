#include "maze.h"
#include <stdlib.h>
#include <stdio.h>

int main(void)
{
    int **map;
    LinkedStack *pStack;
    StackNode start;
    StackNode goal;

    printf("input width and height");
    scanf("%d %d", &width, &height);
    printf("start point x: y:");
    scanf("%d %d", &(start.x), &(start.y));
    printf("start point x: y:");
    scanf("%d %d", &(goal.x), &(goal.y));
    start.direction = 0;
    goal.direction = 0;
    map = (int **)malloc(sizeof(int *) * height);
    for (int i = 0; i < height; i++)
        map[i] = (int *)malloc(sizeof(int) * width);
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
            scanf("%d", &map[i][j]);
    }
    pStack = createLinkedStack();
    solve_maze(map, pStack, start, goal);
}