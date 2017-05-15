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
  int n;
  scanf("%d",&n);
  int a[300010];
  int sum[300010];
  int temp;
  for(int i=1;i<=n;i++){
    scanf("%d",&temp);
    a[i] = temp;
  }
  a[0] =0;
  sum[0] =0;
  for(int i=1;i<=n;i++){
    sum[i] = sum[i-1]+a[i];
  }
  int res = sum[1];
  for(int i=2;i<=n;i++){
    for(int j=1;j<=i;j++){
      int temp = sum[i] - sum[j-1];
      res  = res ^ temp;
    }
  }
  printf("%d\n",res);
  return 0;
}
