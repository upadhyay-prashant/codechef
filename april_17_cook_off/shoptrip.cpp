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
  while(testcases--){
    long long n,k;
    std::vector< pair<long long,long long> > points ;
    scanf("%lld %lld",&n,&k);
    for(int i=0;i<(int)n;i++){
      int t1,t2;
      scanf("%d %d",&t1,&t2);
      points.push_back(std::make_pair<long long, long long>(t1,t2));
    }

  }
  return 0;
}
