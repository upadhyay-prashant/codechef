
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
  int n,queries;
  scanf("%d %d",&n,&queries);
  printf("%d %d",n,queries);
  int temp1,temp2;
  int temp3;
  scanf("%d %d",&temp1,&temp2);
  printf("\n%d %d",temp1,temp2);
  for(int i=0;i<n-1;i++){
    scanf("%d %d %d",&temp1,&temp2,&temp3);
    printf("\n%d %d %d",temp1,temp2,temp3);
  }
  int last =0;
  for(int i=0;i<queries;i++){
    int temp4,temp5;
    scanf("%d %d %d %d %d",&temp1,&temp2,&temp3,&temp4,&temp5);
    printf("\n%d %d %d",temp1^last,temp2^last,temp3^last);
    last = temp4^temp5;
  }
  return 0;
}
