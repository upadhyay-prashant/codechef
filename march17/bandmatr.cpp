#include<iostream>
#include<stdio.h>
using namespace std;
int main(){
  int testcases;
  scanf("%d",&testcases);
  int n;
  int temp;
  while(testcases--){
    scanf("%d",&n);
    int count=0;
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
        scanf("%d",&temp);
        if(temp ==0)
          count++;
      }
    }
    int res_inverse=2;
    while(count>0){
      count=count-res_inverse;
      res_inverse+=2;
    }
    int res = n - res_inverse/2;
    if(count<0)
      res++;
    if(res<0)
      res =0;
    printf("%d\n",res);
  }
  return 0;
}
