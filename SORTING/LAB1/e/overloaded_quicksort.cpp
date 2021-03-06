#include <iostream>
#include <stdlib.h> 
#include <bits/stdc++.h>
using namespace std ;
int n;
int* arr;
class sort_class
{
    public:
    sort_class(int val)
    {
        n=val;
        arr=new int[n];
    }
    
    void putdata()
    {
    for(int i=0;i<n;i++)
    {
        arr[i]=rand()%1000 + 1;
    }
        
    }
    void display(int arr[],int n)
{
   
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}
///////////////LOW PIVOT///////////////////////
int partition(int *arr,int low,int high,int m)
{
    int pivot=arr[low];
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
 void quick_sort(int *arr,int low,int high,int a)
 {
      if (low < high)
    {
        int pi = partition(arr, low, high,1);
        quick_sort(arr, low, pi - 1,1);
        quick_sort(arr, pi + 1, high,1);
    }
 }
 
 //////////HIGH PIVOT//////////////////
 int partition(int *arr,int low,int high,double m)
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
 void quick_sort(int *arr,int low,int high,double a)
 {
      if (low < high)
    {
        int pi = partition(arr, low, high,1.0);
        quick_sort(arr, low, pi - 1,1.0);
        quick_sort(arr, pi + 1, high,1.0);
    }
 }
 ///////////MIDDLE PIVOT////////////////////
 int partition(int *arr,int low,int high,char m)
{
    int pivot=arr[(low+high)/2];
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

 void quick_sort(int *arr,int low,int high,char a)
 {
      if (low < high)
    {
        int pi = partition(arr, low, high,'a');
        quick_sort(arr, low, pi - 1,'a');
        quick_sort(arr, pi + 1, high,'a');
    }
 }
    
};

int main()
{
    cout<<"CODE BY ADITI MAHABOLE 20103023"<<endl;
    int n=rand() % 10 + 1;
    int n1=rand() % 10 + 1;
    int n2=rand() % 10 + 1;
    sort_class s(n);
    sort_class s1(n1);
    sort_class s2(n2);
    cout<<"------------------------"<<endl;
    cout<<"Array 1 : "<<endl;
    s.putdata();
    s.display(arr,n);
    cout<<endl;
    cout<<"Low as pivot"<<endl;
    s.quick_sort(arr,0,n - 1,1);
    s.display(arr,n);
    cout<<endl;
    cout<<"------------------------"<<endl;
    cout<<"Array 2 : "<<endl;
    s1.putdata();
    s1.display(arr,n);
    cout<<endl;
    cout<<"High as pivot"<<endl;
    s1.quick_sort(arr,0,n - 1,'a');
    s1.display(arr,n);
    cout<<endl;
    cout<<"------------------------"<<endl;
    cout<<"Array 3 : "<<endl;
    s2.putdata();
    s2.display(arr,n);
    cout<<endl;
    cout<<"Middle as pivot"<<endl;
    s2.quick_sort(arr,0,n - 1,1.0);
    s2.display(arr,n);
    cout<<endl;
    cout<<"------------------------"<<endl;
    cout<<"CODE BY ADITI MAHABOLE 20103023"<<endl;
    
    return 0;
}

/* 
OUTPUT 
CODE BY ADITI MAHABOLE 20103023
------------------------
Array 1 : 
916 794 336 387 
Low as pivot
336 794 387 916 
------------------------
Array 2 : 
28 691 60 764 
High as pivot
60 28 764 691 
------------------------
Array 3 : 
737 212 369 568 
Middle as pivot
212 369 568 737 
------------------------
CODE BY ADITI MAHABOLE 20103023
*/
