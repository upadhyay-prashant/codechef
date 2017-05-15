#include<iostream>
#include<stdio.h>
#include<climits>
using namespace std;
int main(){
  int testcases;
  scanf("%d",&testcases);
  long long arr[100000];
  long long temp;
  while(testcases--){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
      scanf("%lld",&temp);
      arr[i]= temp;
    }
    long long res=0;
    long long smallest_1 = LLONG_MAX, smallest_2 = LLONG_MAX;
    for(int i=0;i<n;i++){
      if(arr[i]<smallest_1){
        smallest_2 = smallest_1;
        smallest_1 = arr[i];
      }
      else if(arr[i] < smallest_2){
        smallest_2 = arr[i];
      }
      res+=arr[i];
    }
    if(smallest_2-smallest_1 !=1){
      printf("%lld\n",smallest_1);
    }
    else{
      printf("%lld\n",res - ((n-1) * (2*smallest_1 + n-2))/2);
    }
  }
  return 0;
}
