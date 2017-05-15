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
  int a[100010];
  while(testcases--){
    int n;
    scanf("%d",&n);
    int temp;
    for(int i=1;i<=2*n;i++){
      scanf("%d",&temp);
      a[i] = temp;
    }
    std::sort(a+1,a+2*n+1);
    //for(int i=1;i<=2*n;i++)
    //  printf(" $%d",a[i]);
    int cnt =2;
    int res = a[2*n-(n+1)/2+1];
    for(int i=1;i<(n+1)/2;i=i+2){
      temp = a[cnt];
      a[cnt] = a[2*n-i];
      a[2*n-i] = temp;
      cnt=cnt+2;
    }
    printf("%d\n",res);
    for(int i=1;i<=2*n;i++){
      printf("%d ",a[i]);
    }
    printf("\n");
  }
  return 0;
}
