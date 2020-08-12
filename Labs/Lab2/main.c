/////////////////////////////////////////////////////
///     Seth Jaksik
///     ID: 1001541359 
///     2320-004 
///     Lab 2
///
///     This program takes in a list of laundry baskets
///     with wash and dry times and prints out the most
///     efficient way to order the baskets as well as the
///     makespan of the wash and dry times.
///
///     Compilation: gcc main.c functions.c
/////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

int main(int argc, char **argv)
{
    int numBaskets, i;
    char line[10];
    fgets(line, 50, stdin);
    numBaskets = atoi(line);

    //read in baskets
    Basket *basketArray = malloc(sizeof(Basket) * numBaskets);
    readIn(basketArray, numBaskets);

    //sort the basket
    qsort(basketArray, numBaskets, sizeof(Basket), compare_baskets);

    // implement johnsons rule
    Basket *executeOrder = johnsons(basketArray, numBaskets);
   
    //print out the makespan
    printMakespan(executeOrder, numBaskets);
    
    // free allocated memory
    free(basketArray);
    free(executeOrder);
}