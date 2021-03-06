//code by ADITI MAHABOLE 20103023
#include <iostream>
#include <stdlib.h> 
#include <bits/stdc++.h>
using namespace std;

void display(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" , ";
    }
    cout<<endl;
}
/////////////////BUBBLE_SORT//////////////////
int bubble_sort(int *arr,int n,int end,bool swapped,int count,int tcount)
{  
    
    if(end ==0)
    { 
        cout<<"total count = "<<tcount<<endl;
        return count;
        
    }
    for(int i=0;i<end;i++)
    {
        if(arr[i]>arr[i + 1])
        {
            swap(arr[i],arr[i+1]);
            count++;
            swapped=true;
        }
    }
    if(swapped==false)
    {
        return count ;
    }
    tcount++;
    bubble_sort(arr,n,end - 1,swapped,count,tcount);
    
    
}
///////////////SELECTION_SORT//////////////////
int selection_sort(int *arr,int n,int count,int tcount)
{
   int min_index; 
   for(int i=0;i<n;i++)
   {
       min_index=i;
      for(int j=i+1;j<n;j++)
      {
          if(arr[j]<arr[i])
          {
              min_index=j;
              count++;
          }
      }
      swap(arr[min_index], arr[i]);
   }
    return count;
}
/////////////////MERGE_SORT///////////////////////
int merge_sort_compile(int *arr,int start,int mid,int end,int count)
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
        count++;
        if (arr1[i1]<=arr2[i2])
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
    
    while (i1 < size_arr1) 
    {
        count++;
        arr[im] = arr1[i1];
        i1++;
        im++;
    }
    while (i2 < size_arr2) 
    {
        count++;
        arr[im] = arr2[i2];
        i2++;
        im++;
    }
    return count;
}
int merge_sort_breakdown(int arr[],int start,int end,int count)
{
    int mid=start + (end - start)/2;
    if (start >= end)
    {
        return count;
    }
    else 
    {
    merge_sort_breakdown(arr,start,mid,count);
    
    merge_sort_breakdown(arr,mid + 1,end,count);
    
    count=merge_sort_compile(arr,start,mid,end,count);
    }
    return count;
 }
 /////////////////INSERTION_SORT//////////////////
int insertion_sort(int *arr,int n,int count)
 {
     int i,j,key;
     for(int i=1;i<n;i++)
     {
         key=arr[i];
         j=i-1;
         
         while(j>=0 && arr[j]>key)
         {
             arr[j+1]=arr[j];
             j--;
             count++;
         }
         arr[j+1]=key;
     }
     return count;
 }
 
 /////////////////QUICK_SORT//////////////////////
 int partition(int *arr,int low,int high)
{
    int pivot = arr[high]; 
    int i = (low - 1); 
 
    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++; 
            swap(arr[i],arr[j]);
          
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}
 void quick_sort(int *arr,int low,int high)
 {
      if (low < high)
    {
        int pi = partition(arr, low, high);
        quick_sort(arr, low, pi - 1);
        quick_sort(arr, pi + 1, high);
    }
 }
//////////////////INT_MAIN////////////////////////
int main() {
    // int n=rand() % 20 + 1;
    // int arr[n];
    // for(int i=0;i<n;i++)
    // {
    //     arr[i]=rand()%100 + 1;
    // }
    int arr[]={13,24,555,64,98,67,22,90,100 };
    // int arr[]={1,2,3,4,5,6,7 };
    // int arr[]={7,1,6,2,5,3,4};
    int n=sizeof(arr)/sizeof(arr[0]);
    display(arr,n);
    cout<<endl;
    cout<<"-------OPTIONS-------"<<endl;
    cout<<"1. BUBBLE SORT"<<endl;
    cout<<"2. SELECTION SORT"<<endl;
    cout<<"3. MERGE SORT"<<endl;
    cout<<"4. INSERTION SORT"<<endl;
    cout<<"5. QUICK SORT"<<endl;
    cout<<"---------------------"<<endl;
    int choice ;
    bool swapped=false;
    int count=0;
    int tcount=0;
        cout<<"---ENTER_CHOICE--- "<<endl;
        cin>>choice;
        switch(choice)
        {
        case 1:
        cout<<"COUNTS : "<<endl;
        cout<<bubble_sort(arr,n,n - 1,swapped,count,tcount)<<endl;
        display(arr,n);
        break;
        case 2:
        cout<<"COUNTS : "<<endl;
        cout<<selection_sort(arr,n,count,tcount)<<endl;
        display(arr,n);
        break;
        case 3:
        cout<<"COUNTS : "<<endl;
        cout<<merge_sort_breakdown(arr,0,n - 1,count)<<endl;
        display(arr,n);
        break;
        case 4:
        cout<<"COUNTS : "<<endl;
        cout<<insertion_sort(arr,n,count)<<endl;
        display(arr,n);
        break;
        case 5:
        quick_sort(arr,0, n - 1);
        display(arr,n);
        break;
        }
    return 0;
}

/*
OUTPUT 
/tmp/QHQc7Gp1vG.o
13 , 24 , 555 , 64 , 98 , 67 , 22 , 90 , 100 , 
-------OPTIONS-------
1. BUBBLE SORT
2. SELECTION SORT
3. MERGE SORT
4. INSERTION SORT
5. QUICK SORT
---------------------
---ENTER_CHOICE--- 
2
COUNTS OF SELECTION SORT : 
12
13 , 22 , 100 , 24 , 90 , 64 , 67 , 98 , 555 , 
*/
