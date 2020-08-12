void tree(int left,int right,int indent)
{
int i;

if (left==right)
{
  for (i=0;i<indent;i++)
    printf("   ");
  printf("%d\n",left);
  return;
}
tree(trace[left][right]+1,right,indent+1);
for (i=0;i<indent;i++)
  printf("   ");
printf("%d %d\n",left,right);
tree(left,trace[left][right],indent+1);
}