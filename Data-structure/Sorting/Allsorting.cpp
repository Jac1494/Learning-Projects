#include<bits/stdc++.h>
using namespace std;

void printArray(int a[],int len)
{
    for(int i =0 ;i< len;i++){
        std::cout << a[i] << " ";
    }
    std::cout <<"\n";
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void bubblesort(int a[],int len){
     std::cout << "Bubblesort :- ";
    for(int i=0;i<len-1;i++){
        for(int j=0;j<len-1-i;j++){
            if(a[j]>a[j+1]){
                int t=a[j];
                a[j]=a[j+1];
                a[j+1]=t;
            }
        }
    }
} 

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void bubblesort_optimize(int a[],int len){
    int flag=0;
    std::cout << "Bubblesort_optimize :- ";
    for(int i=0;i<len-1;i++){
        for(int j=0;j<len-1-i;j++){
            if(a[j]>a[j+1]){
                int t=a[j];
                a[j]=a[j+1];
                a[j+1]=t;
                flag=1;
            }
            if(flag==0)
            break;
        }
    }
} 

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void selectionsort(int *a,int len){
    std::cout << "Selectionsort :- ";
    for(int i=0;i<len-1;i++){
        for(int j=i+1;j<len-1-i;j++){
            if(a[i]>a[j]){
                int t=a[j];
                a[j]=a[j+1];
                a[j+1]=t;
            }
        }
    }
} 

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void insertionsort(int a[],int len){
   std::cout << "Insertionsort :- ";
   int i,j,key;
   for(i=1;i<len;i++){

       key=a[i];
       j=i-1;

       while(j>=0 && a[j]>key){
            a[j+1]=a[j];
            j=j-1;
       }
       a[j+1]=key;  // Set first element value 
   }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void quicksort(int a[],int first,int last){

    int i,j,pivot,temp;
    if(first<last){
            pivot=first;
            i=first;
            j=last;
            while(i<j){
				while(a[i]<=a[pivot] && i<last){
					i++;
				}
				while(a[j]>a[pivot]){
					j--;
				}
				if(i<j){
					int t=a[i];
					a[i]=a[j];
					a[j]=a[i];
				}
            }
            temp=a[pivot];
            a[pivot]=a[j];
            a[j]=temp;
            quicksort(a,first,j-1);
            quicksort(a,j+1,last);
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void merging(int a[],int low, int mid, int high) {
   int l1, l2, i;
   int b[high-1];
   
   for(l1 = low, l2 = mid + 1, i = low; l1 <= mid && l2 <= high; i++) {
      if(a[l1] <= a[l2])
         b[i] = a[l1++];
      else
         b[i] = a[l2++];
   }
    
   while(l1 <= mid)    
      b[i++] = a[l1++];

   while(l2 <= high)   
      b[i++] = a[l2++];

   for(i = low; i <= high; i++)
      a[i] = b[i];
}

void sort(int a[],int low, int high) {
   int mid;
   
   if(low < high) {
      mid = (low + high) / 2;
      sort(a,low, mid);
      sort(a,mid+1, high);
      merging(a,low, mid, high);
   } else { 
      return;
   }   
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// To heapify a subtree rooted with node i which is 
// an index in a[]. n is size of heap 
void heapify(int a[], int n, int i) 
{ 
    int largest = i; // Initialize largest as root 
    int l = 2*i + 1; // left = 2*i + 1 
    int r = 2*i + 2; // right = 2*i + 2 
  
    // If left child is larger than root 
    if (l < n && a[l] > a[largest]) 
        largest = l; 
  
    // If right child is larger than largest so far 
    if (r < n && a[r] > a[largest]) 
        largest = r; 
  
    // If largest is not root 
    if (largest != i) 
    { 
        swap(a[i], a[largest]); 
  
        // Recursively heapify the affected sub-tree 
        heapify(a, n, largest); 
    } 
} 
  
// main function to do heap sort 
void heapSort(int a[], int n) 
{ 
    // Build heap (rearrange array) 
    for (int i = n / 2 - 1; i >= 0; i--) 
        heapify(a, n, i); 
   
    // One by one extract an element from heap 
    for (int i=n-1; i>0; i--) 
    { 
        //cout << " 1 - " ;
        //printArray(a,n);
        // Move current root to end 
        swap(a[0], a[i]); 
         //cout << " 2 - " ;
         //printArray(a,n);
        // call max heapify on the reduced heap 
        heapify(a, i, 0); 
    } 
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 
int main()
{
    int a[6]={9,10,7,8,5,6};
    int len=sizeof(a)/sizeof(a[0]);
    std::cout << "Default array :- ";
    printArray(a,len);
    bubblesort(a,len);
    printArray(a,len);
    selectionsort(a,len);
    printArray(a,len);
    bubblesort_optimize(a,len);
    printArray(a,len);
    insertionsort(a,len);
    printArray(a,len);
    cout<< "Quicksort :- " ;
    quicksort(a,0,len-1);
    printArray(a,len);
    cout<< "Mergesort :- " ;
    sort(a,0,len-1);
    printArray(a,len);
    cout<< "Heapsort :- " ;
    heapSort(a,len);
    printArray(a,len);
    return 0;
}