#include<iostream>
#include<vector>
#include<stdio.h>
#include<map>
#include<algorithm>
#include<bitset>
#include<cstring>
#include<limits.h>
#include<queue>
#include<vector>
#include<unordered_map>
#include<deque>
#include<cassert>

const int SIZE = 10000; // change the size as per requirements
using namespace std;
int main(){
  int n ,k,p;
  scanf("%d %d %d",&n,&k,&p);
  int arr[1000];
  for(int i=0;i<n;i++){
    int temp;
    scanf("%d ",&temp);
    arr[i] = temp;
  }
  for(int i =0; i< p ;i++){
    char ch = getchar_unlocked();
    if(ch=='?'){
      int sum=0;
      int largest = INT_MIN;
      for(int j=0;j<n;j++){
        if(j>=k){
          if(largest<sum){
            largest = sum;
          }
          sum-=arr[j-k];
        }
        sum+=arr[j];
      }
      if(largest<sum)
        largest = sum;
      printf("%d\n",largest);
    }
    else if(ch=='!'){
      int temp = arr[0];
      int last;
      for(int i =1;i<n;i++){
        last = arr[i];
        arr[i] = temp;
        temp = last;
      }
      arr[0] = temp;
    }
  }
  return 0;
}
