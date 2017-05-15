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
  char ch[3];
  ch[0]='C';
  ch[1]='E';
  ch[2]='S';
  while(testcases--){
    scanf("%s",str);
    int length = strlen(str);
    int j=0;
    for(int i=0;i<length;i++){
        while(str[i]!=ch[j] && j<3)
          j++;
        if(j==3){
          break;
        }
    }
    if(j==3)
      printf("no\n");
    else printf("yes\n");
  }
  return 0;
}
