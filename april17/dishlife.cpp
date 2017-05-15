#include<iostream>
#include<stdio.h>
#include<map>
using namespace std;
int size = 100000;
int main(){
  int arr[size],testcases;
  scanf("%d",&testcases);
  while(testcases--){
    int N,K;
    scanf("%d %d",&N,&K);
    std::map<int,int> maps[size];
    for(int i=1;i<=K;i++) arr[i] = 0;
    int temp,temp2;
    for(int i=0;i<N;i++){
      scanf("%d",&temp);
      for(int j=0;j<temp;j++){
          scanf("%d",&temp2);
          maps[i][temp2] =1;
          arr[temp2]++;
      }
    }
    bool check = true;
    for(int i=1;i<=K && check;i++){
      if(arr[i] ==0) check = false;
    }
    if(check){
      for(int i=0;i<N ;i++){
        check = false;
        for(std::map<int,int>::iterator iter = maps[i].begin(); iter != maps[i].end() && !check; iter++){
          if(arr[iter->first] == 1) check = true;
        }
        if(!check)  break;
      }
      if(check) printf("all\n");
      else printf("some\n");
    }
    else printf("sad\n");
  }
  return 0;
}
