// Fractional knapsack and Non-Fractional knapsack problem with max profit using greedy algorithm with optimal solution

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef struct
{
   int v;
   int w;
   float d;
} Item;
void input(Item items[], int sizeOfItems)
{
   cout << "Enter total " << sizeOfItems << " item's values and weight" << endl;
   for (int i = 0; i < sizeOfItems; i++)
   {
      cout << "Enter " << i + 1 << " V ";
      cin >> items[i].v;
      cout << "Enter " << i + 1 << " W ";
      cin >> items[i].w;
   }
}
void display(Item items[], int sizeOfItems)
{
   int i;
   cout << "values: ";
   for (i = 0; i < sizeOfItems; i++)
   {
      cout << items[i].v << "\t";
   }
   cout << endl
        << "weight: ";
   for (i = 0; i < sizeOfItems; i++)
   {
      cout << items[i].w << "\t";
   }
   cout << endl;
}

bool compare(Item i1, Item i2)
{
   return (i1.d > i2.d);
}
float knapsack(Item items[], int sizeOfItems, int W)
{
   int i, j;
   float totalValue = 0, totalWeight = 0;
   for (i = 0; i < sizeOfItems; i++)
   {
      items[i].d = (float)items[i].v / items[i].w;
   }
   sort(items, items + sizeOfItems, compare);
   cout << "values : ";
   for (i = 0; i < sizeOfItems; i++)
   {
      cout << items[i].v << "\t";
   }
   cout << endl
        << "weights: ";
   for (i = 0; i < sizeOfItems; i++)
   {
      cout << items[i].w << "\t";
   }
   cout << endl
        << "ratio  : ";
   for (i = 0; i < sizeOfItems; i++)
   {
      cout << items[i].d << "\t";
   }
   cout << endl;
   for (i = 0; i < sizeOfItems; i++)
   {
      if (totalWeight + items[i].w <= W)
      {
         totalValue += items[i].v;
         totalWeight += items[i].w;
      }
      else
      {
         int wt = W - totalWeight;
         totalValue += (wt * items[i].d);
         totalWeight += wt;
         break;
      }
   }
   return totalValue;
}
int nonFractionalKnapsack(Item items[], int sizeOfItems, int W)
{
   int i, j;
   int totalValue = 0, totalWeight = 0;
   for (i = 0; i < sizeOfItems; i++)
   {
      items[i].d = (float)items[i].v / items[i].w;
   }
   sort(items, items + sizeOfItems, compare);
   cout << "values : ";
   for (i = 0; i < sizeOfItems; i++)
   {
      cout << items[i].v << "\t";
   }
   cout << endl
        << "weights: ";
   for (i = 0; i < sizeOfItems; i++)
   {
      cout << items[i].w << "\t";
   }
   cout << endl
        << "ratio  : ";
   for (i = 0; i < sizeOfItems; i++)
   {
      cout << items[i].d << "\t";
   }
   cout << endl;
   for (i = 0; i < sizeOfItems; i++)
   {
      if (totalWeight + items[i].w <= W)
      {
         totalValue += items[i].v;
         totalWeight += items[i].w;
      }
   }
   return totalValue;
}
int main()
{
   printf("20051828,robin\n");
   clock_t start, end;
   start = clock();
   int W, sizeOfItems;
   cout << "Enter size of items ";
   cin >> sizeOfItems;
   Item items[sizeOfItems];
   input(items, sizeOfItems);
   cout << "Entered data \n";
   display(items, sizeOfItems);
   cout << "Enter Knapsack weight \n";
   cin >> W;
   float mxVal = knapsack(items, sizeOfItems, W);
   int mxVal2 = nonFractionalKnapsack(items, sizeOfItems, W);

   cout << "Select choice" << endl;
   cout << "1. Fractional Knapsack" << endl;
   cout << "2. Non Fractional Knapsack" << endl;
   int choice;
   cin >> choice;
   switch (choice)
   {
   case 1:
      cout << "Maximum value we can obtain = " << mxVal << endl;
      break;
   case 2:
      cout << "Maximum value we can obtain = " << mxVal2 << endl;
      break;
   default:
      cout << "Invalid choice" << endl;
   }

   end = clock();
   double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
   cout << "Time taken by program is : " << fixed << time_taken << setprecision(5);
   cout << " sec " << endl;
   return 0;
}