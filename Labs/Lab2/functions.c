/////////////////////////////////////////////////////
///     Seth Jaksik
///     ID: 1001541359 
///     2320-004 
///     Lab 2
///
/////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

/////////////////////////////////////////////////////
///     int compare_baskets(const void *a, const void *b)
///
///     Purpose: this function is used as the comparator
///             function for qsort to be used in sorting 
///             the baskets
///
///     Inputs: const void *a - first item to compare
///             const void *b - second item to compare
///
///     Return: returns a 0 if the values are the same,
///             a -1  if a was the lower value, or a
///             1 if b was the lower value
/////////////////////////////////////////////////////
int compare_baskets(const void *a, const void *b)
{
    Basket x = *(const Basket *)a;
    Basket y = *(const Basket *)b;
    if (x.lowestVal < y.lowestVal)
        return -1;
    else if (x.lowestVal > y.lowestVal)
        return 1;

    return 0;
}

/////////////////////////////////////////////////////
///     void readIn()
///
///     Purpose: reads in information from the text 
///     file given and inputs that data into an array
///     of Basket structs which hold information about the
///     baskets
///
///     Inputs: Basket *BasketArray - the array to store elements in
///             int size - the size of the storage array
///
///     Return: void return
/////////////////////////////////////////////////////
void readIn(Basket *BasketArray, int size)
{
    char line[50] = "";
    char *token;
    int i;

    for (i = 0; i < size; i++)
    {
        fgets(line, 50, stdin);
        token = strtok(line, " ");
        BasketArray[i].washTime = atoi(token);
        token = strtok(NULL, " \n");
        BasketArray[i].dryTime = atoi(token);
        BasketArray[i].index = i;
        if (BasketArray[i].washTime > BasketArray[i].dryTime)
        {
            BasketArray[i].lowestValType = 'd';
            BasketArray[i].lowestVal = BasketArray[i].dryTime;
        }
        else
        {
            BasketArray[i].lowestValType = 'w';
            BasketArray[i].lowestVal = BasketArray[i].washTime;
        }
    }
}

/////////////////////////////////////////////////////
///     void printMakespan(Basket *executeOrder, int numBaskets)
///
///     Purpose: prints the makespan of the baskets in the 
///             optimal order from johnsons methods
///
///     Inputs: Basket *executeOrder - array of elemts to print
///             int numBaskets - number of baskets in the array
///
///     Return: void return
/////////////////////////////////////////////////////
void printMakespan(Basket *executeOrder, int numBaskets)
{
    int washTime, dryTime, i;
    washTime = 0;
    dryTime = executeOrder[0].washTime;

    for (i = 0; i < numBaskets; i++)
    {
        ;
        if (washTime + executeOrder[i].washTime > dryTime)
        {
            printf("dryer gap from %d to %d\n", dryTime, washTime + executeOrder[i].washTime);
            dryTime = washTime + executeOrder[i].washTime;
        }
        printf("%d %d %d %d %d\n", executeOrder[i].index, executeOrder[i].washTime, executeOrder[i].dryTime, washTime, dryTime);
        washTime += executeOrder[i].washTime;
        dryTime += executeOrder[i].dryTime;
    }
    printf("makespan is: %d\n", dryTime);
}

/////////////////////////////////////////////////////
///     Basket *johnsons(Basket *basketArray, int numBaskets)
///
///     Purpose: takes the sorted basketArray from the qsort
///             and orders the baskets in the most optimal
///             fashion using johnsons method
///
///     Inputs: Basket *basketArray - the array to sort
///             int numBaskets - number of baskets in the array
///
///     Return: a pointer to the basket array made in
///             optimal order
/////////////////////////////////////////////////////
Basket *johnsons(Basket *basketArray, int numBaskets)
{
    Basket *executeOrder = (Basket *)malloc(sizeof(Basket) * numBaskets);
    int low = 0, high = numBaskets - 1;
    int i;
    for (i = 0; i < numBaskets; i++)
    {
        if (basketArray[i].lowestValType == 'w')
        {
            executeOrder[low] = basketArray[i];
            low++;
        }
        else
        {
            executeOrder[high] = basketArray[i];
            high--;
        }
    }
    return executeOrder;
}
