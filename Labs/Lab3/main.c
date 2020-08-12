/////////////////////////////////////////////////////
///     Seth Jaksik
///     ID: 1001541359 
///     2320-004 
///     Lab 3
///
///     This program is used to take in a list of probabilities
///     and build an order preserving huffman code tree from those 
///     probabilities, then print out the huffman codes and probabilites
///     for each code, then a final expected bits per symbol.
///
///     Compilation: gcc main.c 
///     Run:    ./a.out < inputInfo.txt
/////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
double p[40];
double c[40][40];
int trace[40][40];
double bitsPerSymb[40];

/////////////////////////////////////////////////////
///     void tree(int left, int right, int indent)
///
///     Purpose: prints out the optimal huffman code tree
///             after it has been found through dynamic programming.
///             also includes the probability sum for the child trees
///
///     Inputs: int left - index of the left node
///             int right - index of the right node
///             int indent - the ammount of indent for the tree print out
///
///     Return: void return
/////////////////////////////////////////////////////
void tree(int left, int right, int indent)
{
    int i;

    if (left == right)
    {
        for (i = 0; i < indent; i++)
            printf("   ");
        printf("%d\n", left);
        return;
    }
    tree(trace[left][right] + 1, right, indent + 1);
    for (i = 0; i < indent; i++)
        printf("   ");
    printf("%d %d cost %f\n", left, right, c[left][right]);
    tree(left, trace[left][right], indent + 1);
}

/////////////////////////////////////////////////////
///     void treeBits(int left, int right, int bits, int i)
///
///     Purpose: prints out the optimal huffman code as well as the probability
///             times the number of bits of the length of that code
///
///     Inputs: int left - index of the left node
///             int right - index of the right node
///             int bits - number of bits in the huffman code
///             int i - current itteration of the loop controlling tree
///
///     Return: void return
/////////////////////////////////////////////////////
void treeBits(int left, int right, int bits, int i)
{
    if (left == right)
    {
        bitsPerSymb[left] = p[left] * bits;
        printf(" %f\n", bitsPerSymb[left]);
        return;
    }
    if (i >= trace[left][right] + 1) // going left in tree
    {
        printf("1");
        treeBits(trace[left][right] + 1, right, bits + 1, i);
    }
    else // going right in tree
    {
        printf("0");
        treeBits(left, trace[left][right], bits + 1, i);
    }
}

/////////////////////////////////////////////////////
///     double sumP(int first, int last)
///
///     Purpose: sums the probabilities in the range from
///             first to last
///
///     Inputs: int first - first index of range to sum
///             int last - last index of range to sum
///
///     Return: double to the total probability sum
/////////////////////////////////////////////////////
double sumP(int first, int last)
{
    int i;
    double total = 0;
    for (i = first; i <= last; i++)
    {
        total += p[i];
    }
    return total;
}

/////////////////////////////////////////////////////
///
///     int main()
///
/////////////////////////////////////////////////////
int main()
{
    int i, j, k;
    double work, probTotal = 0;
    char line[50];

    // read in the probabilities
    fgets(line, 50, stdin);
    int size = atoi(line);
    for (i = 0; i < size; i++)
    {
        fgets(line, 50, stdin);
        p[i] = atof(line);
        probTotal += p[i];
    }
    printf("Probabilities sum to %f\n", probTotal);
    printf("Code tree for exact:\n");

    // find optimal huffman code tree
    for (i = 0; i <= size; i++)
        c[i][i] = trace[i][i] = 0;

    for (i = 1; i < size; i++)
        for (j = 0; j <= size - i; j++)
        {
            c[j][j + i] = 999999;
            for (k = j; k < j + i; k++)
            {
                work = sumP(j, j + i) + c[j][k] + c[k + 1][j + i]; // cost function
                if (c[j][j + i] > work)
                {
                    c[j][j + i] = work;
                    trace[j][j + i] = k;
                }
            }
        }

    // print out the optimal tree
    tree(0, size - 1, 0);
    printf("\n");
    printf("Codes & prob*# of bits\n");
    float total = 0;
    // calculate the huffman codes from the tree and probability * bits for each code
    for (i = 0; i < size; i++)
    {
        printf("%d ", i);
        treeBits(0, size - 1, 0, i);
        total += bitsPerSymb[i];
    }
    printf("Expected bits per symbol %f\n", total);
}