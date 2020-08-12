/////////////////////////////////////////////////////
///     Seth Jaksik
///     ID: 1001541359 
///     2320-004 
///     Lab 1
///
///     This program takes in two ascending integer
///     sequences and a rank of arrays and calculates
///     which element of which sequence has the desired
///     rank.
///
///     Compilation: gcc main.c functions.c
/////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

int main(int argc, char **argv)
{
    int rankCounter, i, j;
    int *high = malloc(sizeof(int));
    int *low = malloc(sizeof(int));

    // read in the number of elements in each array
    char temp[20] = "";
    fgets(temp, 20, stdin);
    char *token = strtok(temp, " ");


    // allocate size for each array
    int sizeA = atoi(token);
    int *arrayA = (int *)malloc(sizeof(int) * sizeA + 2*sizeof(int));

    token = strtok(NULL, " ");
    int sizeB = atoi(token);
    int *arrayB = (int *)malloc(sizeof(int) * sizeB + 2*sizeof(int));

    token = strtok(NULL, " \n");
    int sizeRank = atoi(token);
    int *rankArray = (int *)malloc(sizeof(int) * sizeRank);

    readIn(arrayA, sizeA);
    readIn(arrayB, sizeB);
    readInRank(rankArray, sizeRank);

    rankCounter = 0;

    // this loop will run until every rank has been found
    while(rankCounter <= (sizeRank - 1)) 
    {
        *high = *low = 0;
        int foundValue = -1;
        findRange(sizeA, sizeB, high, low, rankArray[rankCounter]);
        
        while(foundValue != 0) // while the rank has not been found
        {
            i = binSearch(*low, *high);
            j = rankArray[rankCounter] - i;

            if (arrayA[i] > arrayB[j]) // check arrayA[i] if it is the correct rank
            {
                printf("low %d high %d i %d j %d b[%d]=%d a[%d]=%d b[%d]=%d\n",*low, *high, i, j, j, arrayB[j], i, arrayA[i], j+1, arrayB[j+1]);
                foundValue = check_arrayA(arrayA, arrayB, i, j);
                *high = i-1;
                if(foundValue == 0)
                {
                    printf("a[%d]=%d has rank %d\n", i, arrayA[i], rankArray[rankCounter]);
                }

                *high = i-1;
            }
            else // check arrayB[i] if it is the correct rank
            {
                printf("low %d high %d i %d j %d a[%d]=%d b[%d]=%d a[%d]=%d\n",*low, *high, i, j, i, arrayA[i], j, arrayB[j], i+1, arrayA[i+1]);
                foundValue = check_arrayB(arrayA, arrayB, i, j);
                *low = i+1;
                if(foundValue == 0)
                {
                    printf("b[%d]=%d has rank %d\n", j, arrayB[j], rankArray[rankCounter]);
                }

                *low = i+1;
            }
        }
        rankCounter++;
    }
    free(high);
    free(low);
    free(arrayA);
    free(arrayB);
    free(rankArray);
}