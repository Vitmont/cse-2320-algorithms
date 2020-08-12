// Huffman code using a preprocessing quicksort and two (conceptual) queues.

// This is a prototype for demonstration purposes only.

#include <stdio.h>
#include <stdlib.h>

double *probLink; // For qsort

int compare(const void *xin,const void *yin)
{
// Sorts a permutation array based on elements being subscripts
// to indirect to an array of doubles.
double work;
int x,y;

x= *((int*) xin);
y= *((int*) yin);
work=probLink[x] - probLink[y];
if (work==0.0)
  return 0;
if (work<0)
  return -1;
return 1;
}

int main()
{
int n,m,i,j,val;
double *prob,probSum,expected;
int *left,*right;  // Links for Huffman code tree, root is subscript m-1
int *parent;       // For printing the codes
int *length;
char *outString;

int *orderedInput; // Permutation to reorder input probabilities
int inputHead,mergedHead;

printf("Enter alphabet size\n");
scanf("%d",&n);
m=2*n-1;  // Number of nodes in tree
prob=(double*) malloc(m*sizeof(double));
orderedInput=(int*) malloc(n*sizeof(int));
left=(int*) malloc(m*sizeof(int));
right=(int*) malloc(m*sizeof(int));
parent=(int*) malloc(m*sizeof(int));
outString=(char*) malloc((n+1)*sizeof(char));
length=(int*) malloc(m*sizeof(int));
if (!prob || ! orderedInput || !left || !right || !parent
|| !outString || !length)
{
  printf("malloc problem %d\n",__LINE__);
  exit(0);
}

// Read alphabet symbols' probabilities.
probSum=0.0;
for (i=0;i<n;i++)
{
  scanf("%lf",prob+i);
  probSum+=prob[i];
  left[i]=right[i]=(-1);
}
printf("Probabilities sum to %f\n",probSum);

// Quicksort to initialize first queue
for (i=0;i<n;i++)
  orderedInput[i]=i;
// sorts so prob[orderedInput[i]]<=prob[orderedInput[i+1]] for 0<=i<n-1
probLink=prob;
qsort((void*) orderedInput,n,sizeof(int),compare);

// Huffman code tree construction
inputHead=0;   // tail for input is fixed at n
mergedHead=n;  // Merged tree queue has tail at i
for (i=n;i<m;i++)
{
  // Each round combines two subtrees for subtree root i
  if (mergedHead==i)   // Generated trees temporarily exhausted?
  {
    left[i]=orderedInput[inputHead++];
    right[i]=orderedInput[inputHead++];
  }
  else if (inputHead==n) // Input has been exhausted (permanently)?
  {
    left[i]=mergedHead++;
    right[i]=mergedHead++;
  }
  else
  {
    // Both queues have an element
    left[i]=(prob[orderedInput[inputHead]]<=prob[mergedHead]) ?
              orderedInput[inputHead++] : mergedHead++;
    right[i]=(mergedHead==i || (inputHead<n &&
                                prob[orderedInput[inputHead]]<=prob[mergedHead]))
               ? orderedInput[inputHead++]
               : mergedHead++;
  }

if (left[i]<0)
  printf("ctc bonk 100\n");
if (left[i]>=m)
  printf("ctc bonk 200\n");
if (right[i]<0)
  printf("ctc bonk 300\n");
if (right[i]>=m)
  printf("ctc bonk 400\n");

  parent[left[i]]=parent[right[i]]=i;
  prob[i]=prob[left[i]]+prob[right[i]];
}

parent[m-1]=(-1);

// Goes breadth-first from root to compute length of prefix bit codes.
length[m-1]=0;
for (i=m-1;i>=n;i--)
  length[left[i]]=length[right[i]]=length[i]+1;

// Print the leaves, i.e. for the alphabet symbols
printf("   i  prob  parent  bits product  code\n");
for (i=0;i<n;i++)
{
  outString[length[i]]='\0';
  // Crawl up the tree to get prefix code
  for (j=i;j!=m-1;j=parent[j])
    outString[length[j]-1]=(left[parent[j]]==j) ? '0' : '1';
  printf("%5d %5.3f %5d %5d   %5.3f  %s\n",
    i,prob[i],parent[i],length[i],prob[i]*length[i],outString);
  expected+=prob[i]*length[i];
}
printf("Expected bits per symbol: %f\n",expected);

// Print the internal nodes
printf("   i  prob    left right parent\n");
for (i=n;i<m;i++)
  printf("%5d %5.3f %5d %5d  %5d\n",i,prob[i],left[i],right[i],parent[i]);

free(prob);
free(orderedInput);
free(left);
free(right);
free(parent);
free(outString);
free(length);
}