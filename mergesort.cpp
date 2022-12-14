#include<bits/stdc++.h>
#include<time.h>
using namespace std;

void printarray(int arr[],int n){
    for(int  i = 0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void merge(int arr[],int left,int mid,int right){
   
    int pos1 = mid-left+1;
    int pos2 = right - mid;
    int temp1[pos1];
    int temp2[pos2];
    for(int i = 0;i<pos1;i++)
    {
        temp1[i] = arr[left+i];
    }
    for(int i = 0;i<pos2;i++)
    {
        temp2[i] = arr[mid +1+i];
    }
    int i =0,j = 0,k =left ;
    while(i<pos1 && j<pos2)
    {
        if(temp1[i]< temp2[j])
        {
            arr[k++] = temp1[i++];
        }
        else
        {
            arr[k++] = temp2[j++];
        }
    }
    while(i<pos1)
    {
        arr[k++] = temp1[i++];
    }
    while(j<pos2)
    {
         arr[k++] = temp2[j++];
    }
   
}
 void mergesort(int arr[],int left,int right,int r)
 {
     int mid;
     if(left<right){
         mid = (left + right)/r;
         mergesort(arr,left,mid,r);
         mergesort(arr,mid+1,right,r);
         merge(arr,left,mid,right);
     }
 }

int main(){
    int n;
    cout<<"enter number of elements : ";
    cin>>n;
    int arr[n],temp[n];
    cout<<"enter elements : ";
    for(int i = 0;i<n;i++){
        cin>>arr[i];
    }
    srand(time(NULL));
    int r = abs(rand()%n + 1);
    mergesort(arr,0,n-1,r);
    printarray(arr,n);
    
    return 0;
}


