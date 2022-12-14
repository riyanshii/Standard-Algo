#include<bits/stdc++.h>
using namespace std;

int dp[1000][1000];    

int mtrxmul(int a[], int i, int j) 
{ 
    if (i == j)  
        return 0;

    if (dp[i][j] != -1)  
        return dp[i][j];

    int temp = INT_MAX;

    for (int k = i; k < j; k++)  
    { 
        temp = min(temp, mtrxmul(a, i, k) + mtrxmul(a, k + 1, j) + a[i - 1] * a[k] * a[j]); 
    }

    return dp[i][j] = temp; 
} 

int main()
{
    int n;
    cout<<"enter n : ";
    cin>>n;
    int arr[n];
    cout<<"enter elements :";

    for(int i=0; i<n; i++)
        cin>>arr[i];

    memset(dp,-1,sizeof(dp));

    
    cout<<mtrxmul(arr, 1, n-1);

    return 0;
}