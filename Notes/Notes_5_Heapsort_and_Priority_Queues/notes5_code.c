void maxHeapify(Item a[], int k, int N)
{
    int j;
    while (left(k) <= N)
    {
        j = left(k); // left child
        if (j < N && less(a[j], a[j + 1]))
            j = right(k); // use right child instead
        if (!less(a[k], a[j]))
            break;
        exch(a[k], a[j]); // Swap child with parent
        k = j;            // Descend
    }
}
// Convert array to maxheap, e.g. Build-Max-Heap
for (k = parent(N); k >= 1; k--)
    maxHeapify(&pq(0), k, N);