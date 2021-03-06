// Online C++ compiler to run C++ program online
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
/////////////////////////MERGE IN DESCEND/////////////////////////
void merge_sort_compile_descend(int *arr,int start,int mid,int end)
{
    int size_arr1=mid-start + 1;
    int size_arr2=end-mid;
    int arr1[size_arr1];
    int arr2[size_arr2];
    for(int i=0;i<size_arr1;i++)
    {
        arr1[i]=arr[start + i];
    }
    for(int j=0;j<size_arr2;j++)
    {
        arr2[j]=arr[mid + 1 + j];
    }
    int i1=0;
    int i2=0;
    int im=start;
    while(i1<size_arr1 && i2<size_arr2)
    {
       
        if (arr1[i1]>=arr2[i2])
        {
            arr[im]=arr1[i1];
            i1++;
        }
        else
        {
            arr[im]=arr2[i2];
            i2++;
        }
        im++;
    }
    while (i2 < size_arr2) 
    {
        
        arr[im] = arr2[i2];
        i2++;
        im++;
    }
    while (i1 < size_arr1) 
    {
        arr[im] = arr1[i1];
        i1++;
        im++;
    }
}
void merge_sort_breakdown_descend(int arr[],int start,int end)
{
    int mid=start + (end - start)/2;
    if (start >= end)
    {
        return ;
    }
    else 
    {
    merge_sort_breakdown_descend(arr,start,mid);
    
    merge_sort_breakdown_descend(arr,mid + 1,end);
    
    merge_sort_compile_descend(arr,start,mid,end);
    }
   
 }


int main() {
    int arr[]={1,2,3,4,5,6,7 };
    // int arr[]={7,1,6,2,5,3,4};
    int n=sizeof(arr)/sizeof(arr[0]);
    display(arr,n);
    cout<<endl;
    merge_sort_breakdown_descend (arr,0,n - 1);
    display(arr,n);
    return 0;
}
