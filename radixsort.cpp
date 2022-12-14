#include<bits/stdc++.h>
using namespace std;

void countsort(int arr[],int n,int place)
{
        int i,freq[10]={0}; 
        int temp[n];
        for(i=0;i<n;i++)
            freq[(arr[i]/place)%10]++;
        for(i=1;i<10;i++)
            freq[i]+=freq[i-1]; 
        for(i=n-1;i>=0;i--)
        {
            temp[freq[(arr[i]/place)%10]-1]=arr[i];
            freq[(arr[i]/place)%10]--;
        }
        
        for(i=0;i<n;i++)
        {
            arr[i]=temp[i];
        }
}

void radixsort(int arr[],int n,int max)
{
        int mul=1;

        while(max)
        {
                countsort(arr,n,mul);
                mul*=10;
                max/=10;
        }
}

int main()
{
    int n;
    cout<<"Enter the total number of elements : ";
    cin>>n;
    int max = INT_MIN;
    int arr[n];
    cout<<"Enter elements : ";
    for(int i = 0;i<n;i++)
    {
        cin>>arr[i];
        if(arr[i] > max)
          max = arr[i];
    }

    radixsort(arr,n,max);
    cout<<"Sorted array is : ";
    for(int  i = 0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }

    return 0;
}