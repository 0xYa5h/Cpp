#include <iostream>
using namespace std;
  
void swap(int* a, int* b) 
{ 
    int t = *a; 
    *a = *b; 
    *b = t; 
} 
   
int partition(int arr[], int low, int high) 
{ 
    int pivot = arr[high];
    int i = (low - 1);  
    for (int j = low; j <= high- 1; j++) 
    { 
        if (arr[j] <= pivot) 
        { 
            i++;   
            swap(&arr[i], &arr[j]); 
        } 
    } 
    swap(&arr[i + 1], &arr[high]);
    return (i + 1); 
} 

void qsort(int arr[], int low, int high) 
{ 
    if (low < high) 
    {
        int p = partition(arr, low, high);  
        qsort(arr, low, p - 1); 
        qsort(arr, p + 1, high); 
    } 
} 
   
void display(int arr[], int size) 
{ 
    int i; 
    for (i=0; i < size; i++) 
        cout<<arr[i]<<"\t"; 
      
} 
   
int main() 
{ 
    int arr[] = {10,80,30,90,40,50,70}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    cout<<"Input array:"<<endl;
    display(arr,n);
    cout<<endl;
    qsort(arr, 0, n-1); 
    cout<<"Sorted Array: "<<endl; 
    display(arr,n); 
    return 0; 
}
