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

using namespace std;
int main(){
  int testcases;
  scanf("%d",&testcases);
  char str[100010];
  long long as[100010];
  while(testcases--){
    int n;
    long long k;
    scanf("%d %lld",&n,&k);
    scanf("%s",str);
// find all abs in the string and then apply logic for k times
    long long initial_count =0;
    as[0]= str[0]=='a'?1:0;
    long long bs= str[0] == 'b'?1:0;
    for(int i=1;i<n;i++){
      if(str[i] == 'a'){
        as[i] = as[i-1]+1;
      }
      else if(str[i] == 'b'){
        initial_count = initial_count + as[i-1];
        as[i] = as[i-1];
        bs++;
      }
      else{
        as[i] = as[i-1];
      }
    }
    long long sum =0;
    long long total_as = as[n-1];
    long long t1 = (k-1)*(k)/2;
    long long t2 = k;
    sum = initial_count * t2 + bs * t1 * total_as;
    /*for(int i=0;i<k;i++){
      long long t1 = i;
      long long initial_as = total_as* t1;
      sum = sum + initial_count + initial_as*bs;
    }*/
    printf("%lld\n",sum);
  }
  return 0;
}
