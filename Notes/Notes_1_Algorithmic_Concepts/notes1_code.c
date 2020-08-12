// ell is start of sort range, r is end of sort range
// outer loop controls what needs to be sorted, inside does sort
void selection(Item a[], int ell, int r) // NOT stable
{
  int i, j;
  for (i=ell; i<r; i++)
  {
    int min = i;
    for (j= i+1; j<=r; j++)
      if (less(a[j], a[min]))
        min = j;
    exch(a[i], a[min]);
  }
}

// should run twice as fast as selectino sort, n^2/4
void insertionSort(Item *a,int N) // Guaranteed stable
{
  int i,j;
  Item v;
  for (i=1; i<N; i++)
  {
    v=a[i];
    j=i;
    while (j>=1 && less(v,a[j-1]))
    {
      a[j]=a[j-1];
      j--;
    }
    a[j]=v;
  }
}

// this is not stable in this implementation, could be stable by
// replacing the < with a <=
int merge(int *in1,int *in2,int *out1,int in1Size,int in2Size)
{
  int i,j,k;
  i=j=k=0;
  while (i<in1Size && j<in2Size)
    if (in1[i]<in2[j])
      out1[k++]=in1[i++];
    else
      out1[k++]=in2[j++];
  if (i<in1Size)
    for ( ;i<in1Size;i++)
      out1[k++]=in1[i];
  else
    for ( ;j<in2Size;j++)
      out1[k++]=in2[j];
 return k;
}

// not the best with duplicates
int binSearch(int *a,int n,int key)
// Input: int array a[] with n elements in ascending order.
// int key to find.
// Output: Returns some subscript of a where key is found.
// Returns -1 if not found.
// Processing: Binary search.
{
 int low,high,mid;
 low=0;
 high=n-1;
// subscripts between low and high are in search range.
// size of range halves in each iteration.
 while (low<=high)
 {
   mid=(low+high)/2;
   if (a[mid]==key)
      return mid; // key found
  if (a[mid]<key)
      low=mid+1;
  else
      high=mid-1;
 }
 return (-1); // key does not appear
}

//*****Multiple occurences of keys *****
// Table found at: http://ranger.uta.edu/~weems/NOTES2320/binarySearchRange.c
// *** These searches do not have a condition for if a[mid] == key

//Find i such that a[i-1] < key <= a[i] aka the first occurence of the key
int binSearchFirst(int *a,int n,int key)
// Input: int array a[] with n elements in ascending order.
// int key to find.
// Output: Returns subscript of the first a element >= key.
// Returns n if key>a[n-1].
// Processing: Binary search.
{
 int low,high,mid;
 low=0;
 high=n-1;
// Subscripts between low and high are in search range.
// Size of range halves in each iteration.
// When low>high, low==high+1 and a[high]<key and a[low]>=key.
 while (low<=high)
 {
   mid=(low+high)/2;
   if (a[mid]<key) // changed here
      low=mid+1;
    else
      high=mid-1;
 }
 return low;
}

//Find i such that a[i] <= key < a[i+1] aka the last occurence of the key
int binSearchLast(int *a,int n,int key)
{
// Input: int array a[] with n elements in ascending order.
// int key to find.
// Output: Returns subscript of the last a element <= key.
// Returns -1 if key<a[0].
// Processing: Binary search.
 int low,high,mid;
 low=0;
 high=n-1;
// subscripts between low and high are in search range.
// size of range halves in each iteration.
// When low>high, low==high+1 and a[high]<=key and a[low]>key.
 while (low<=high)
 {
   mid=(low+high)/2;
   if (a[mid]<=key) //changed here
      low=mid+1;
  else
      high=mid-1;
 }
 return high;
}
