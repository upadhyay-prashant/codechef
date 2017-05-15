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
int main(){
  int testcases;
  scanf("%d",&testcases);
  while(testcases--){
    int a,b;
    scanf("%d %d",&a,&b);
    bool check = false;
    int i=1;
    while(!check){
      if(i%2==1){
        a=a-i;
      }
      else{
        b=b-i;
      }
      if(a<0){
        check = true;
      }
      if(b<0){
        check = true;
      }
      i++;
    }
      if(a<0){
        printf("Bob\n");
      }
      else {
        printf("Limak\n");
      }
  }
  return 0;
}
