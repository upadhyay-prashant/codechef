#include<iostream>
#include<stdio.h>
using namespace std;
int main(){
  int testcases;
  scanf("%d",&testcases);
  //int result[1000000];
  int *p = new int[3000000];
  int *result = p;
  int *states = (p+1000000);
  int *states_result = (p+2000000);
  int o1,o2;
  int temp;
  //int states[1000000];
  //int states_result[1000000];
  while(testcases--){
    scanf("%d %d",&o1,&o2);
    int n = o1*o2;
    for(int i=0;i<n;i++){
      scanf("%d",&temp);
      result[i] = temp;
      states[i]=0;
    }
    //initialized
    for(int i=0;i<n;i++){
      states[i/o2]+=result[i];
      states_result[i/o2]=0;
      if(states[i/o2]>o2/2){
        states_result[i/o2]=1;
      }
    }
    int total=0;
    for(int i=0;i<o1;i++){
      total+=states_result[i];
    }
    int count=0;
    while(count<o2 && total<= o1/2){
      for(int i=0;i<o1;i++){
        states[i] = states[i] - result[(i*o2+count)%(n)] + result[((i+1)*o2+count)%n];
  //      //printf("-- states[%d] = states[%d]- result[%d] + result[%d] -- ",i,i,((i*o1)%n), ((i+1)*o1+count)%n);;
        if(states_result[i]!=(int)(states[i]>o2/2)){
          states_result[i] = states[i]>o2/2?1:0;
          total += states_result[i]==0?-1:1;
        }
      }
      count++;
    }
    if(total>o1/2){
      //printf("1\n");
    }
    else //printf("0\n");
  }
  return 0;
}
