#include<bits/stdc++.h>
using namespace std;

void printarray(int arr[],int n){
    for(int  i = 0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int partition(int arr[], int l, int r)
{
   
    int pivot=arr[l];
    int start=l;
    int end=r;
    while(start<end)
    {
        while(arr[start]<=pivot)
        {
                start++;
        }
        while(arr[end]>pivot){
            end--;
        }
        if(start<end){
            swap(arr[start],arr[end]);
        }
    }
   swap(arr[l],arr[end]);
    return end;
}

int partition_random(int arr[],int l,int r)
{
    int random = l + rand() % (l - r);
    swap(arr[random], arr[l]);
    return partition(arr, l, r);
}

void quicksort(int a[],int l,int h)
{
    int j;
    if(l<h)
    {
        j=partition_random(a,l,h);
        quicksort(a,l,j-1);
        quicksort(a,j+1,h);
    }
}

int main(){
    int n;
    cout<<"enter number of elements : ";
    cin>>n;
    int arr[n];
    cout<<"enter elements : ";
    for(int i = 0;i<n;i++){
        cin>>arr[i];
    }
    quicksort(arr,0,n-1);
    printarray(arr,n);
    
    return 0;
}


