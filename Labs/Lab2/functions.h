typedef struct basket
{
    int washTime, dryTime, lowestVal, index;
    char lowestValType;
}Basket;
int compare_baskets(const void *a, const void *b);
void readIn(Basket *BasketArray, int size);
void printMakespan(Basket* executeOrder, int numBaskets);
Basket* johnsons(Basket* basketArray, int numBaskets);