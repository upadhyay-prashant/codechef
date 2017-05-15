#include<iostream>
#include<stdio.h>
using namespace std;
int main(){
  int testcases;
  scanf("%d",&testcases);
  long long xen[100000], yana[100000];
  int n;
  long long temp;
  while(testcases--){
    scanf("%d",&n);
    long long sum1 = 0, sum2 = 0;
    for(int i=0;i<n;i++){
      scanf("%lld",&temp);
      xen[i] = temp;
    }
    for(int i=0;i<n;i++){
      scanf("%lld",&temp);
      yana[i] = temp;
    }
    for(int i=0;i<n;i++){
      if(i%2==0){
        sum1 = sum1 + xen[i];
        sum2 = sum2 + yana[i];
      }
      else{
        sum1 = sum1 + yana[i];
        sum2 = sum2 + xen[i];
      }
    }
    printf("%lld\n",sum1<sum2?sum1:sum2);
  }
  return 0;
}
