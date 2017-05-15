#include<iostream>
#include<vector>
#include<stdio.h>
#include<map>
#include<algorithm>
#include<bitset>
#include<cstring>
#include<limits.h>
#include<queue>
using namespace std;
const int maxS = 1000000;
std::vector<bool> arr;
std::vector<long long> primes;
std::map<long long,long long> myMap;

void sieve(){
  for(int i=0;i<maxS+1;i++)
    arr.push_back(false);
  arr[0] = true;
  arr[1] = true;
  for(int i=2;i<maxS;i++){
    if(arr[i] == false){
      int k = i+i;
      while(k < maxS){
        arr[k] = true;
        k=k+i;
      }
    }
  }
  for(int i=2;i<maxS;i++){
    if(arr[i]==false){
      primes.push_back(i);
      myMap[(long long)i] = 1;
    }
  }
}

/*
 1) find all prime factors of a number
 2) find out the degree of the node
 3) find the factor with maximum degree
 4) add its score and degree of the number
 5) update and move on
 
 */
long long calc(long long num,int correction =1 ){
  if(myMap.find(num)!=myMap.end())
    return myMap[num] + correction;
  std::vector<long long> factors;
  std::map<long long, long long> mp;
  //printf("\n**** calculating for %lld **** ",num);
  long long res =0;
  long long larg = LLONG_MIN;
  long long num_copy = num;
  for(int i=0;primes[i]<= num;i++){
    if(num%primes[i]==0){
      mp[primes[i]]++;
      num = num/primes[i];
      i--;
    }
  }
  long long deg = 1;
  long long larg_count=LLONG_MIN;;
  for ( std::map<long long, long long>::iterator iter = mp.begin(); iter!=mp.end();iter++){
    deg = deg * (iter->second+1);
    //printf(" (%lld)^%lld X ",iter->first, iter->second);
    if(larg_count < iter->second){
      larg = iter->first;
      larg_count = iter->second;
    }
  }
  deg = deg -1;
  //printf("   $$$ degree is %lld",deg);
  long long fact = num_copy/larg;
  long long temp = calc(fact);
  //printf(" for %lld  ; res = %lld + (hash[%lld])%lld",num_copy, deg, fact, temp);
  res = deg + temp;
  myMap[num_copy] = res;
  return res+ correction;
}
int main(){
  long long  A, B;
  scanf("%lld %lld",&A, &B);
  sieve();
  myMap[1] = 1;
  long long res=0;
  for(long long  i=A;i<=B;i++){
    //printf("\n+++ %lld  = %lld ",i,calc(i));
    res= res+calc(i,0);
  }
  printf("%lld\n",res);

  return 0;
}
