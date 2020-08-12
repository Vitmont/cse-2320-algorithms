/////////////////////////////////////////////////////
///     Seth Jaksik
///     ID: 1001541359 
///     2320-004 
///     Lab 1
///
/////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>

/////////////////////////////////////////////////////
///     int check_arrayA()
///
///     Purpose: checks to see if arrayA[i] is the
///     correct rank that we want to find
///
///     Inputs: int *arrayA - array A of elements
///             int *arrayB - array B of elements
///             int i - index of array A
///             int j - index of array B
///
///     Return: returns a 0 if the correct rank is
///     found (test passes) or a -1 if it was not
///     (test fails).
/////////////////////////////////////////////////////
int check_arrayA(int *arrayA, int *arrayB, int i, int j)
{
    if ((arrayB[j] < arrayA[i]) && (arrayA[i] <= arrayB[j + 1]))
    {
        return 0;
    }
    else
    {
        return -1;
    }
}

/////////////////////////////////////////////////////
///     int check_arrayB()
///
///     Purpose: checks to see if arrayB[j] is the
///     correct rank that we want to find
///
///     Inputs: int *arrayA - array A of elements
///             int *arrayB - array B of elements
///             int i - index of array A
///             int j - index of array B
///
///     Return: returns a 0 if the correct rank is
///     found (test passes) or a -1 if it was not
///     (test fails).
/////////////////////////////////////////////////////
int check_arrayB(int *arrayA, int *arrayB, int i, int j)
{
    if ((arrayA[i] <= arrayB[j]) && (arrayB[j] < arrayA[i + 1]))
    {
        return 0;
    }
    else
    {
        return -1;
    }
}

/////////////////////////////////////////////////////
///     int binSearch()
///
///     Purpose: preforms a binary search on the 
///     high and low to find the mid to use
///
///     Inputs: int low - the low of the binary search
///             int high - the high of the binary search
///
///     Return: returns the middle of the low and high
/////////////////////////////////////////////////////
int binSearch(int low, int high)
{
    return (low + high) / 2;
}

/////////////////////////////////////////////////////
///     void readIn()
///
///     Purpose: reads in information from the text 
///     file given and inputs that data into an array
///     with sentinals at 0 and n+1 where n is the size
///     of the input data given
///
///     Inputs: int *array - the array to store elements in
///             int size - the size of the storage array
///
///     Return: void return
/////////////////////////////////////////////////////
void readIn(int *array, int size)
{
    int i = 0;
    char temp[10] = "";
    array[0] = -99999;
    for (i = 1; i < size + 1; i++)
    {
        fgets(temp, 10, stdin);
        array[i] = atoi(temp);
    }
    array[i] = 99999;
}

/////////////////////////////////////////////////////
///     void readInRank()
///
///     Purpose: reads in the rank list from the text
///     file and puts it into an array to read from 
///     later
///
///     Inputs: int *array - the array to store elements in
///             int size- the size of the storage array
///
///     Return: void return
/////////////////////////////////////////////////////
void readInRank(int *array, int size)
{
    int i;
    char temp[10] = "";
    for (i = 0; i < size; i++)
    {
        fgets(temp, 10, stdin);
        array[i] = atoi(temp);
    }
}

/////////////////////////////////////////////////////
///     void findRange()
///
///     Purpose: finds the range of values to search
///     for in arrrayA given the rank and then sets
///     high and low to that range
///
///     Inputs: int sizeA - size of array A
///             int sizeB - size of array B
///             int *high - pointer to the high value
///             int *low - pointer to the low value
///             int rank - the rank to search for
///
///     Return: void return, low and high are changed 
///     as pointers
/////////////////////////////////////////////////////
void findRange(int sizeA, int sizeB, int *high, int *low, int rank)
{
    if (rank < sizeA)
    {
        *low = 0;
        *high = rank;
    }
    else if (rank < sizeB)
    {
        *low = 0;
        *high = sizeA;
    }
    else
    {
        *low = (rank - sizeB);
        *high = sizeA;
    }
}