#include<iostream>
#include<stdio.h>
#include<limits.h>
#include<map>
using namespace std;
long long min2(long long a, long long b){
  if(a<b)
    return a;
  return b;
}
long long min1(long long a, long long b, long long c=LLONG_MAX){
  return min2(min2(a,b), min2(b,c));
}
int main(){
  int testcases;
  scanf("%d",&testcases);
  int n;
  int temp;
  long long result;
  long long distances[100000];
  //long long **hash;
  //hash = new long long*[100000];
  //for(int i=0;i<100000;i++)
  //  hash[i] = new long long[100000];
  while(testcases--){
    std::map<int,int> hash[100000];
    //long long hash[100000][100000];
    scanf("%d",&n);
    result=0;
    for(int i=0;i<n-1;i++){
      scanf("%d",&temp);
      hash[i][i+1] = temp;
      result+=temp;
    }
    for(int i=0;i<n-2;i++){
      scanf("%d",&temp);
      hash[i][i+2] = min1(hash[i][i+1]+hash[i+1][i+2], temp);
      result+=hash[i][i+2];
    }
    for(int i=0;i<n-3;i++){
      scanf("%d",&temp);
      hash[i][i+3] = min1(hash[i][i+1]+hash[i+1][i+3], hash[i][i+2]+hash[i+2][i+3], temp);
      result+=hash[i][i+3];
    }
    for(int i=4; i< n;i++){
      for(int j=0; j < n-i;j++){
        long long minimum = LLONG_MAX;
        for(int k = 1; k<i; k++){
          long long dist = hash[j][j+k]+hash[j+k][j+i];
          if(minimum>dist)
            minimum = dist;
        }
        hash[j][j+i] = minimum;
        result+=minimum;
      }
    }
    printf("%lld\n",result);
  }
}
