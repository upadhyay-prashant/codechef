#include<cstring>
#include<sstream>
#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
int main(){
  int testcases;
  scanf("%d",&testcases);
  const char *similar = "similar";
  const char *dissimilar = "dissimilar";
  while(testcases--){
    string first[4];
    string second[4];
    char inp[15];
    for(int i=0;i<2;i++){
      for(int j=0;j<4;j++){
        scanf("%s",inp);
        if(i==0){
          first[j] = inp;
        }
        else{
          second[j] = inp;
        }
      }
    }
    sort(first,first+4);
    sort(second,second+4);
    int count =0;
    int ptr1=0,ptr2=0;
    while(ptr1<4 && ptr2<4){
      int res = first[ptr1].compare(second[ptr2]);
 //     printf(" comparing %s == %s ",first[ptr1].c_str(),second[ptr2].c_str());
      if(res==0){
        ptr1++;
        ptr2++;
        count++;
      }
      else if(res>0){
        ptr2++;
      }
      else {
        ptr1++;
      }
    }
    if(count<2){
      printf("%s\n",dissimilar);
    }
    else{
      printf("%s\n",similar);
    }
  }
  return 0;
}
