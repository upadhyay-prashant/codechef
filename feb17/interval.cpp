#include<iostream>
#include<stdio.h>
using namespace std;
long long a[1000000];
long long sum[1000000];
int b[1000000];
long long results[1000000];
int main(){
  int testcases;
  int N,M;
  int temp=0;
  scanf("%d",&testcases);
  while(testcases--){
    a[0] = 0;
    scanf("%d %d",&N,&M);
    for(int i=1;i<=N;i++){
      scanf("%d",&temp);
      a[i] = temp;
    }
    sum[0] = 0;
    for(int i=1;i<=N;i++){
      sum[i] = a[i] + sum[i-1];
    }
    long long res = 0;
    for(int i=0;i<M;i++){
      scanf("%d",&temp);
      b[i] = temp;
    }
    //printf("\na[]\tsum");
    for(int i=0;i<=N;i++){
      //printf("\n\t%d\t\t%lld\t\t%lld",i,a[i],sum[i]);
    }
    int start = 0, end = b[0];
    long long largest = sum[b[0]];
    for(int i=1;i<=N-b[0]+1;i++){
      if(sum[i+b[0]-1] - sum[i-1] > largest){
        start =i-1;
        end = i+b[0]-1;
      }
    }
    //printf("\n\t end=%d , start=%d, sum[end]=%lld sum[start]=%lld , sum[end]-sum[start]=%lld",end,start,sum[end],sum[start],sum[end]-sum[start]);
    res += (sum[end] -sum[start]);
    int sign =1;
    for(int i =1 ; i<M;i++){
      start++;
      temp = end-1;
      end = start+b[i];
      largest = sum[start+b[i]] - sum[start];
      sign*=-1;
      //printf("\n\t looping for b now..... largest = %lld, start= %d, end = %d",largest,start,end);
      for(int j=1;j<=temp-start-b[i];j++){
        //printf("\n\t++ for start = %d, end= %d, sum= %lld ",start+j, start+b[i]+j,sum[start+b[i]+j]-sum[start+j] );
        if(largest< sum[ start + b[i] + j ] - sum[ start + j ]){
          //printf("\t start end updated");
          end = start+ b[i] + j;
          start = start + j;
        }
      }
  //    //printf("\t res = %lld , sign = %d , range(%d,%d)=(%lld,%lld)=(%lld)\n",res,sign,start,end,sum[start],sum[end],sum[end]-sum[start]);
      //printf("\t result is updated from %lld to %lld",res, res+sign*(sum[end]-sum[start]));
      res += sign*(sum[end] - sum[start]);
    }
    printf("%lld\n",res);
  }
  return 0;
}
