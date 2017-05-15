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
#include<deque>
using namespace std;

const int SIZE = 1000000;
int arr[SIZE];
int sums[SIZE];
int result[SIZE];
int main(){
  int n,k,p;
  scanf("%d %d %d",&n,&k,&p);
  for(int i=0;i<n;i++){
    int temp;
    scanf("%d",&temp);
    arr[i] = temp;
  }
  for(int i=n,j=0;j<n-1;i++,j++){
    arr[i] = arr[j];
  }
  int sum=0;
  for(int i=0;i<2*n-1;i++){
    if(i>k-1){
      sums[i-k] = sum;
      sum = sum - arr[i-k];
    }
    sum=sum+arr[i];
  }
/*  for(int i=0;i<2*n-1;i++){
    printf("\n++ sum[%d] = %d",i,sums[i]);
  }*/
  sums[2*n-1-k] = sum;
  std::deque<int> dq;
  int i=0;
  for(;i<=n-k;i++){
  // printf("\n++ processing %d, sums[%d]= %d",i,i,sums[i]);
    while(!dq.empty() && sums[i]>=sums[dq.back()]){
      dq.pop_back();
    }
    dq.push_back(i);
  }
  for(;i<=2*n-1-k;i++){
   /* for(std::deque<int>::iterator it = dq.begin();it!=dq.end();it++){
      printf("\n++ %d) dq-> %d",i,sums[*it]);
    }*/
    result[i-n+k-1] = sums[dq.front()];
    while(!dq.empty() && dq.front()<= i-n+k-1){
      dq.pop_front();
    }
    while(!dq.empty() && sums[i]>=sums[dq.back()]){
      dq.pop_back();
    }
    dq.push_back(i);
  }
  result[n-1] = sums[dq.front()];
 /* for(int j=0;j<2*n-k;j++){
    printf("\n++ result is %d",result[j]);
  }*/
  int c=0;
  for( i=0;i<p;i++){
    char ch = getchar_unlocked();
    while(ch!='!' && ch!='?')
      ch = getchar_unlocked();
    if(ch == '?'){
      printf("%d\n",result[c]);
    }
    else if(ch == '!'){
      c--;
      if(c==-1)
        c = n-1;
    }
  }
  return 0;
}
