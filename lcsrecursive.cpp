#include<bits/stdc++.h>
using namespace std;

int DP[100][100];
int LCS(string x,string y,int n,int m)
{
    if(n ==0 || m ==0)
      return 0;
    else if(DP[n][m] != -1)
      return DP[n][m];  
    else if(x[n-1] == y[m-1])
       return DP[n][m] = (1 + LCS(x,y,n-1,m-1));
    else
      return DP[n][m] =  max(LCS(x,y,n-1,m),LCS(x,y,n,m-1));
}
int main()
{
    string str1,str2;
    cin>>str1>>str2;
    int n = str1.size();
    int m = str2.size();
    memset(DP,-1,sizeof(DP));
    int ans = LCS(str1,str2,n,m);
    cout<<ans<<endl;
    return 0;
}