#include <bits/stdc++.h>
using namespace std;

bool comp(pair<int,int> p1, pair<int,int> p2)
{
    return (p1.second < p2.second);
}

void maxActivitiesSelection(vector<pair<int,int>> activity, int n)
{
    sort(activity.begin(),activity.end(),comp);
    cout<<"selected activities are : "<<endl;
    int i = 0;
    cout <<" "<< i+1<<"--> "<<activity[i].first<<" to "<<activity[i].second<<endl;
 
    for (int j = 1; j < n; j++)
    {
      if (activity[j].first >= activity[i].second)
      {
          cout <<" " << j+1<<"--> "<<activity[j].first<<" to "<<activity[j].second<<endl;
          i = j;
      }
    }
}
 
int main()
{
    int n;
    cout<<"Enter the number of elements : ";
    cin>>n;
    vector<pair<int,int>> activity(n,{0,0});
    for(int i=0; i<n; i++)
    {
        cin>>activity[i].first>>activity[i].second;
    }

    cout<<"Activities selected : \n";
    maxActivitiesSelection(activity, n);
    return 0;
}