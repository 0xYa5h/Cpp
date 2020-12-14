#include<iostream>
using namespace std;

int search(int n,int l, int h, int arr[])
{
  if(l <= h)
  {
  
	int mid = (l+h)/2;
	if(arr[mid] == n)
	   return 1;
	if(arr[mid] > n)
	   return search(n, l, mid-1, arr);
	return search(n, mid+1, h, arr);
  }
  else
    return 0;
  
}
int main()
{
	int a[]={10,13,15,17,19,21,23,25};
	int n = 16;
	int len = sizeof(a) / sizeof(a[0]);
	int x = search(n,0,len-1,a);
	if(x == 1)
	    cout << "Number is present" << "\n";
	else
    	cout << "Number is not present";
}
