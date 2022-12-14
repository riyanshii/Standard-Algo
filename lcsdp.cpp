#include<bits/stdc++.h>
using namespace std;

int LCS(string x,string y,int n,int m)
{
    int DP[n+1][m+1];
    for(int i =0;i<n+1;i++)
    {
        for(int j =0;j<m+1;j++)
        {
            if(i==0 || j ==0)
            DP[i][j] = 0;
        }
    }
    for(int i=1;i<n+1;i++)
    {
        for(int j =1;j<m+1;j++)
        {
            if(x[i-1] == y[j-1])
            {
                DP[i][j] = 1 + DP[i-1][j-1];
            }
            else
            {
                DP[i][j] = max(DP[i-1][j],DP[i][j-1]);
            }
            
        }
    }
    return DP[n][m];
}
int main()
{
    string str1,str2;
    cin>>str1>>str2;
    int n = str1.size();
    int m = str2.size();
    int ans = LCS(str1,str2,n,m);
    cout<<ans<<endl;
    return 0;
}