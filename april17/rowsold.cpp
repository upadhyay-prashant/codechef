#include<iostream>
#include<vector>
#include<stdio.h>
#include<cstring>
using namespace std;
int main(){
  int testcases;
  scanf("%d",&testcases);
  char str[100000];
  while(testcases--){
    scanf("%s",str);
    int length = strlen(str);
    std::vector<long long> vec;
    for(int i=0;i<length;i++){
      if(str[i] == '1'){
        vec.push_back(i);
      }
    }
    vec.push_back(length);
    long long res=0;
    long long count = 1 ;
    for(int i=0; i < vec.size()-1;i++){
      long long dist = vec[i+1] - vec[i] -1;
      if(dist){
        res = res + count*dist ;
        res = res + count;
      }
      count++;
    }
    printf("%lld\n",res);
  }
  return 0;
}
