#include<bits/stdc++.h>
using namespace std;
int Matrix(int arr1[],int n) 
{
  int arr[n][n],arr2[n],min_val,count=0;
  bool var[n];
  string eq="(";

  for(int i=0;i<n;i++)
  {
    var[i]=0; 

    for(int j=0;j<n-i;j++)
    {
      arr[j][j+i]=9999; 

      for(int k=j;k<j+i;k++)
      {
        min_val=arr[j][k]+arr[k+1][j+i]+(arr1[j]*arr1[k+1]*arr1[j+i+1]); 

        if(min_val<arr[j][j+i]) 
        {
          arr[j][j+i]=min_val;
          if(j==0)
            arr2[j+i]=k;
        }
      }

      if(i==0) 
        arr[j][j+i]=0;
    }
  }

  for(int i=n-1;i>0;i--) 
  {
    var[arr2[i]+1]=1;
  }

  for(int i=1;i<n;i++) 
  {
    if(var[i]==1)
    {
      eq+="a"+to_string(i)+")";
      count++;
    }
    else
      eq+="a"+to_string(i);
  }

  for(int i=0;i<count;i++) 
  {
    eq="("+eq;
  }

  eq+="a"+to_string(n)+")"; 
  cout<<endl<<"Minimum Multiplications = "<<arr[0][n-1]<<endl;
  cout<<"The equation with minimum multiplications is "<<eq<<endl;
  return 0;   
}

int main()
{
  int N;
  cout<<"Enter the number of matrices\n";
  cin>>N;
  int arr[N][2];
  int arr1[N+1];
  cout<<"Enter the size of the matrices in order\n";
  for(int i=0;i<N;i++) //Takes in the size for all the matrices
  {
    cout<<"Matrix "<<i+1<<endl;
    cout<<"Row: ";
    cin>>arr[i][0];
    cout<<"Column: ";
    cin>>arr[i][1];
  }
  for(int i=0;i<=N;i++) //Creates an array containing d0 to dN values to be used in the main formula
  {
    if(i!=N)
      arr1[i]=arr[i][0];
    else
      arr1[i]=arr[i-1][1];
  }
  Matrix(arr1,N);
  return 0;
}
