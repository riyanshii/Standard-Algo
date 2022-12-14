#include<bits/stdc++.h>
using namespace std;

int sum(int freq[], int i, int j)  
{  
    int s = 0;  
    for (int k = i; k <= j; k++)  
    s += freq[k];  
    return s;  
}  

int BSTDP(int keys[],int freq[],int n)
{
    int optimalcost[n][n];  

    for (int i = 0; i < n; i++)  
        optimalcost[i][i] = freq[i];  
  
    for (int k = 2; k <= n; k++)  
    {  
        for (int i = 0; i <= n-k+1; i++)  
        {  
            int j = i+k-1;  
            optimalcost[i][j] = INT_MAX;  
  
            for (int r = i; r <= j; r++)  
            {   
            int c = ((r > i)? optimalcost[i][r-1]:0) +  
                    ((r < j)? optimalcost[r+1][j]:0) +  
                    sum(freq, i, j);  
            if (c < optimalcost[i][j])  
                optimalcost[i][j] = c;  
            }  
        }  
    }  

    // for(int i =0 ;i<n;i++)
    // {
    //     for(int j = 0;j<n;j++)
    //     {
    //         cout<<optimalcost[i][j];
    //     }
    //     cout<<endl;
    // }
    return optimalcost[0][n-1];  
}
int main()
{
    int n;
    cout<<"enter size of tree : ";
    cin>>n;
    int keys[n];
    int freq[n];
    cout<<"enter keys : ";
    for(int i =0;i<n;i++)
       cin>>keys[i];
    cout<<"enter freq : ";   
    for(int i =0;i<n;i++)
       cin>>freq[i];
    
    cout<<"optimalCost is : "<<BSTDP(keys,freq,n);
    return 0;
}