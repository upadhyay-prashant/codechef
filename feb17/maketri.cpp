#include<iostream>
#include<stdio.h>
#include<limits.h>
using namespace std;
int main(){
  long long N,L,R;
  long long a[1000000];
  long long temp;
  scanf("%lld %lld %lld",&N,&L,&R);
  for(long long i=0;i<N;i++){
    scanf("%lld",&temp);
    a[i] = temp;
  }
  // find the biggest two elements and overlap it with given range.
  long long largest = LLONG_MIN,secondLargest = LLONG_MIN;
  for(long long i=0;i<N;i++){
    if(a[i]>largest){
      secondLargest = largest;
      largest = a[i];
    }
    else if(a[i]>secondLargest){
      secondLargest = a[i];
    }
  }
  long long minLength = largest - secondLargest + (long long)1;
  long long maxLength = largest + secondLargest - (long long)1;
  if(minLength<L)
    minLength = L;
  if(maxLength>R)
    maxLength = R;
  printf("\n%lld %lld\t",minLength,maxLength);
  printf("%lld\n",maxLength-minLength+(long long)1);
  return 0;
}
