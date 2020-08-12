//////////////////////////////////////////////////////
///
///   Seth Jaksik
///   1001541359
///   Lab 4
///
///   Compilattion: gcc lab4driver.c RB.lab4.c RB.lab4.h
//////////////////////////////////////////////////////


// Reads a string for a serialized RB tree, deserializes it,
// performs some insertions, then serializes the revised tree.
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "RB.lab4.h"

int main()
{
int inputBytes;
char* inputString,*outputString;
char formatString[100];
int insertKeys,i,key;

scanf("%d",&inputBytes);
inputString=(char*) malloc(inputBytes+1);
if (!inputString) {
  printf("malloc failed %d\n",__LINE__);
  exit(0);
  }
sprintf(formatString,"%%%ds",inputBytes);
scanf(formatString,inputString);
//printf("%s", inputString);
STinit();
checkLength(inputBytes, inputString);
STdeserialize(inputString);
free(inputString);
//STprintTree();
scanf("%d",&insertKeys);
for (i=0;i<insertKeys;i++) {
  scanf("%d",&key);
  //printf("inserting %d\n", key);
  STinsert(key);
  }
//STprintTree();
outputString=STserialize();
printf("%lu %s\n",strlen(outputString)+1,outputString);
free(outputString);
}