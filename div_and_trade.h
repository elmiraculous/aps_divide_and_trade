#ifndef ITIS_DIV_AND_TRADE_H
#define ITIS_DIV_AND_TRADE_H

#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 100
#define MAX_WEIGHT 1000


//структура для предметов 
typedef struct {
    int weight;
    int value;
} Item;

int max(int a, int b);
int divideAndTrade(Item items[], int n, int capacity);

#endif
