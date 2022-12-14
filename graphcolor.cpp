#include<bits/stdc++.h>
using namespace std;

int V,E;
unordered_map<int,list<int>> g;

bool isValid(int v,int color[], int c) 
{
   for(auto &nbg : g[v])
   {
         if(color[nbg]==c)
            return false;
   }

   return true;
}

bool graphColoring(int colors, int color[], int vertex) 
{
   if (vertex == V)
      return true;

   for (int col = 1; col <= colors; col++) 
   {
      if (isValid(vertex,color, col)) 
      {
         color[vertex] = col;
         if (graphColoring (colors, color, vertex+1) == true)
            return true;
                   
         color[vertex] = 0;
      }
   }


   return false;
}

void colorsAssigned(int color[]) 
{
   cout << "Colors assigned to the vertices are: " <<endl;

   for (int i = 0; i < V; i++)
      cout << color[i] << " ";

   cout << endl;
}

int main() 
{

      int x,y;
      cout<<"Enter no of vertices and no of edges : ";
      cin>>V>>E;
      g.clear();
      
      cout<<"Enter the start and end vertices of edges : \n";
      for(int i=0; i<E; i++)
      {
            cin>>x>>y;
            g[x].push_back(y);
            g[y].push_back(x);
      }

      int *color = new int[V];


      int colors = 1;
      while(1)
      {
            memset(color,0,sizeof(color));
            if (graphColoring(colors, color, 0) == true) 
            {
                  colorsAssigned(color);
                  break;
            }
            colors++;
      }

      cout<<"\nFor the given graph, atleast "<<colors<<" are required.";
      return 0;
}