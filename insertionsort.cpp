#include<bits/stdc++.h>
using namespace std;

void printarray(int arr[],int n){
    for(int  i = 0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void insertionsort(int arr[],int n)
{
    int i,j,key;
    for(i = 1;i<=n-1;i++)
    {
        key = arr[i];
        j = i;
        // if(i == n-1)
        // {
        //     cout<<"second best order";
        //     printarray(arr,n);
        // }
        while(arr[j-1]>key && j >= 1)
        {
            arr[j] = arr[j-1];
            j--;
        }
        arr[j] = key;
    }
}
int main()
{
    int n;
    cout<<"enter number of elements : ";
    cin>>n;
    int arr[n],temp[n];
    cout<<"enter elements : ";
    for(int i = 0;i<n;i++)
        cin>>arr[i];
        insertionsort(arr,n);
    printarray(arr,n);
    
    return 0;
}