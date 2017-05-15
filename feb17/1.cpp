#include<iostream>
#include<stdio.h>
using namespace std;
int main(){
  int testcases=0;
  int arr[100010];
  scanf("%d",&testcases);
  while(testcases--){
    int N;
    scanf("%d",&N);
    int count = 0;
    long long res = 0;
    int temp;
    for(int i=0;i<N;i++){
      scanf("%d",&temp);
      arr[i] = temp;
    }
    for(int i=0;i<N;i++){
      if(arr[i]==1){
        if(count!=i){
          res+=100;
        }
        count++;
      }
    }
    res = res + 1100*(N-count);
    printf("%lld\n",res);
  }
  return 0;
}
