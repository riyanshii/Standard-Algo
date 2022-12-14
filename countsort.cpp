#include<bits/stdc++.h>
using namespace std;

void printarray(int arr[],int n){
    for(int  i = 0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void countsort(int arr[],int n,int max)
{
    int temp[max];
    for(int i = 0;i<max;i++)
       temp[i] = 0;
    for(int i = 0;i<n;i++)
    {
        temp[arr[i]]++;
    }  
    int j = 0; 
    for(int i = 0;i<max;i++)
    {
        if(temp[i] != 0)
        {
            while(temp[i] !=0)
            {
                arr[j] = i;
                temp[i]--;
                j++;
            }
        }
    }

}

int main()
{
    int n;
    cout<<"enter number of elements : ";
    cin>>n;
    int max = INT_MIN;
    int arr[n],temp[n];
    cout<<"enter elements : ";
    for(int i = 0;i<n;i++)
    {
        cin>>arr[i];
        if(arr[i] > max)
          max = arr[i];
    }
    countsort(arr,n,max);
    printarray(arr,n);
    return 0;
}