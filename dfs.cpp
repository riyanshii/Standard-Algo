#include<bits/stdc++.h>
using namespace std;

bool vis[100];

void DFS(unordered_map<int,list<int>> g, int x)
{
    vis[x] = true;
    cout<<x<<" ";

    for(auto &ng : g[x])
    {
        if(!vis[ng])
            DFS(g,ng);
    }
}

int main()
{
    int v,e;
    cout<<"Enter the number of vertices and edges : ";
    cin>>v>>e;

    unordered_map<int,list<int>> g;
    int a,b;
    cout<<"Enter edges : ";
    for(int i=0; i<e; i++)
    {
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    memset(vis,false,sizeof(vis));
    cout<<"DFS : \n";
    for(int i=0; i<v; i++)
    {
        if(!vis[i])
        {
            DFS(g,i);
        }
            
    }
}

//6 6
// 0 1
// 0 2
// 1 3
// 1 5
// 2 5
// 2 4