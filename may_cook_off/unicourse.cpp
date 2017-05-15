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
    int n;
    scanf("%d",&n);
    int longest = INT_MIN;
    int temp;
    for(int i=1;i<=n;i++){
      scanf("%d",&temp);
      if(longest < temp)
        longest = temp;
    }
    printf("%d\n",n-longest);
  }
  return 0;
}
