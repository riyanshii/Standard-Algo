#include <bits/stdc++.h>
using namespace std;
 
bool comp(pair<int,int> p1, pair<int,int> p2)
{
    double r1 = (double)p1.first / (double)p1.second;
    double r2 = (double)p2.first / (double)p2.second;
    return r1 > r2;
}
 
double fractionalKnapsack(int w, vector<pair<int,int>> items, int n)
{
    sort(items.begin(),items.end(),comp);
 
    int curWt = 0;
    double maxVal = 0.0;
 
    for (int i = 0; i < n; i++) 
    {

        if (curWt + items[i].second <= w) 
        {
            curWt += items[i].second;
            maxVal += items[i].first;
        }
 
        else 
        {
            maxVal += (double)(w - curWt) * ( items[i].first / (double)items[i].second);
            break;
        }
    }

    return maxVal;
}
 
int main()
{
    int w;
    cout<<"Enter the weight : ";
    cin>>w;
    int n;
    cout<<"Enter the number of items : ";
    cin>>n;

    vector<pair<int,int>> items(n,{0,0});
    for(int i=0; i<n; i++)
    {
        cout<<"value and weight for item "<<i+1<<" : ";
        cin>>items[i].first>>items[i].second;
    }

    cout <<fractionalKnapsack(w, items, n);
    return 0;
}