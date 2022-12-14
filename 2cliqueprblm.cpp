#include<bits/stdc++.h>
using namespace std;
#define V 5
bool isvalid(bool graph[V][V], int colour[])
{
    for (int i = 0; i < V; i++)
    {
      for (int j = i + 1; j < V; j++)
      {
            if (graph[i][j] && colour[j] == colour[i])
                return false;
      }
    }
    return true;

}
bool Coloring(bool graph[V][V], int m, int i,int colour[V])
{
    if (i == V)
    {
        if (isvalid(graph, colour))
        {
            return true;
        }
        return false;
    }
    for (int j = 1; j <= m; j++)
    {
        colour[i] = j;
        if (Coloring(graph, m, i + 1, colour))
            return true;

        colour[i] = 0;
    }

    return false;
}
int main()
{

    bool graph[V][V] ={{0, 1, 1, 1, 0}, 
                       {1, 0, 1, 0, 0}, 
                       {1, 1, 0, 0, 0}, 
                       {0, 1, 0, 0, 1}, 
                       {0, 0, 0, 1, 0} 
}; 
    for(int i=0;i<V;i++)
    {
    	for(int j=0;j<V;j++)
    	graph[i][j]=!graph[i][j];
	}
    int colour[V]={0};
    if (Coloring(graph, 2, 0, colour))
        cout << "it is divided into two clique ";
    else
    {
    	cout<<"No it is not";
	}
}