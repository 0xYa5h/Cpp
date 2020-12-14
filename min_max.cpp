#include<iostream>
#include <climits>
using namespace std;
void min_max(int arr[], int low, int high, int& min, int& max)
{
    if(low == high)                                
           {
              if(arr[low] > max)   
                  max = arr[low];
              if(arr[high] < min)    
                  min = arr[high];
              return;
           }
   if(high-low == 1)                    
      {
          if(arr[low] < arr[high])        
             {
                 if(min > arr[low])     
                   min = arr[low];
                 if(max < arr[high])   
                   max = arr[high];
             }

          else
            {
               if(min > arr[high])    
                 min = arr[high];
               if(max < arr[low])    
                 max = arr[low];
            }
          return;
      }
    int mid = (low + high) / 2;
    min_max(arr, low, mid, min, max);          
    min_max(arr, mid + 1, high, min, max);

}
int main()
{
    int arr[] = {22,10,15,9,3,11,5,17};
    int n = sizeof(arr) / sizeof(arr[0]);
    int max = INT_MIN, min = INT_MAX;
    min_max(arr, 0, n - 1, min, max);
    cout << "The minimum is " << min << "\n";
    cout << "The maximum is " << max;
    return 0;
}

