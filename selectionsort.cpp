#include<iostream>
using namespace std;

void selection(int arr[], int n)
{
    for(int i=0; i<n-1; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            int min = i;
            if(arr[j] < arr[min])
            {
              min = j;
            }
            swap(arr[i],arr[min]);
        }    
    }
}

int main()
{
    int n;
    cout <<"Enter the number of elements :" <<" ";
    cin >>n;

    int arr[n];
    cout <<"Enter the elements of the array :" <<" ";
    for(int i=0; i<n; i++)
    {
       cin >>arr[i];
    }
    cout <<" " <<endl;

    selection(arr,n);

    cout <<"The sorted array is :" <<" ";
    for(int i=0; i<n; i++)
    {
       cout <<arr[i] <<" ";
    }
    cout <<endl;

    return 0;
}


