// CODE BY ADITI MAHABOLE 20103023
#include <iostream>
#include <stdlib.h> 
#include <bits/stdc++.h>
using namespace std;
void display(int arr[],int n)
{
   for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}
//////////////////INSERTION SORT DESCENDING///////////////////
void insertion_sort(int *arr,int n)
 {
     int i,j,key;
     for(int i=1;i<n;i++)
     {
         key=arr[i];
         j=i-1;
         
         while(j>=0 && arr[j]<key)
         {
             arr[j+1]=arr[j];
             j--;
           
         }
         arr[j+1]=key;
     }
   
 }
int main() {
    // int arr[]={1,2,3,4,5,6,7 };
    int arr[]={7,1,6,2,5,3,4};
    int n=sizeof(arr)/sizeof(arr[0]);
    display(arr,n);
    cout<<endl;
    insertion_sort(arr,n);
    display(arr,n);
    return 0;
}
