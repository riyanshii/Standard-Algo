#include<iostream>
using namespace std;

void insertion(int a[], int n)
{
    for(int i=1; i<n; i++)
    {
        int k = a[i];
        int j = i-1;
        while(j >= 0 && a[j]>k)
        {
            a[j+1] = a[j];
            j = j-1;
        }
        a[j+1] = k;
    }
}

int main()
{
    int n;
    cout <<"Enter number of elements: ";
    cin >>n;

    int a[n];
    cout <<"Enter elements to sort: ";
    for(int i=0; i<n; i++)
        cin >>a[i];
        
    insertion(a,n);
    
    cout <<"Sorted array is: ";
    for(int i=0; i<n; i++)
        cout <<a[i] <<" ";
    cout <<endl;
    
    return 0;
}

