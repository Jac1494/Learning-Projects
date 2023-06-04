#include<iostream>
using namespace std;

// How to access 2D array
int main()
{
   int r,c,i,j,k=10;
   cout << "Enter row and column count\n";
   cin >> r >> c;
   r=c=2; 
   // Allocate memory for row
   int **p = new int *[r];

   // Allocate memory for each column
   for(i=0;i<r;i++)
   p[i] = new int[c];

   cout << "p - " << p << " | p[0] - " << p[0] << " | p[1] - " << "\n";       

   for(i=0;i<r;i++)
    for(j=0;j<c;j++)
     p[i][j] = ++k;

   for(i=0;i<r;i++)
    for(j=0;j<c;j++)
     cout << "p[" << i << "]" << "[" << j << "] => " << p[i][j]<< "\n";  
   return 0;
}