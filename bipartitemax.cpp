#include<bits/stdc++.h>
using namespace std;
int Check(int arr[][5],int a[],bool b[], int c) 
{
  for(int i=0;i<5;i++)
  {
    if(arr[c][i] && !b[i])
    {
      b[i]=true;
      if(a[i]<0 || Check(arr,a,b,a[i]))
      {
        a[i]=c;
        return 1;
      }
    }
  }
  return 0;
}

int find(int arr[][5],int set[])
{
    int ans=0;
    bool check[5]; 

    for(int i=0;i<5;i++)
    {
      set[i]=-1;
    }

    for(int i=0;i<5;i++) \
    {
      for(int j=0;j<5;j++)
        check[j]=false;

      if(Check(arr,set,check,i)==1)
        ans++;
    }
    return ans;
}
int main()
{
    int arr[5][5],set[5]; 
    cout<<"Enter the adjacency matrix "<<endl;
    for(int i=0;i<5;i++)
    {
        cout<<"enter the row "<<i+1<<" of the matrix "<<endl;
        for(int j=0;j<5;j++)
        {
            cin>>arr[i][j];
        }
    }
    cout<<endl<<"The maximum matching numbers are "<<find(arr,set)<<endl;
    for(int i=0;i<5;i++)
    {
      if(set[i]!=-1)
        cout<<set[i]<<"matched to "<<i<<endl;
    }
    return 0;
}
