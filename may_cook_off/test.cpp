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
  int n,q;
  scanf("%d %d",&n,&q);
  int r,k;
  scanf("%d %d",&r,&k);
  //printf("%d %d\n%d %d",n,q,r,k);
  int keys[100001];
  int path[100001];
  map<int,int> hash;
  path[0] = -1;
  int index =2;;
  hash[r] =1;
  path[1] =0;
  keys[1] = k;
  for(int i=0;i<n-1;i++){
    int from,to,key;
    scanf("%d %d %d",&from,&to,&key);
    //printf("\n%d %d %d",from,to,key);
    keys[index] = key;
    path[index] = to;
    hash[from] = index;
    index++;
  }
  int last_answer =0;
  for(int i=0;i<q;i++){
    int smallest = INT_MAX;
    int largest = INT_MIN;
    int t,u,v,k1;
    scanf("%d",&t);
    t=t^last_answer;
    if(t==0){
      scanf("%d %d %d",&u,&v,&k1);
      u=u^last_answer;
      v=v^last_answer;
      k1 = k1^last_answer;
      hash[v] = index;
      keys[index] = k1;
      path[index] = u;
      index++;
    }
    else if(t==1){
      scanf("%d %d",&u,&k1);
      u=u^last_answer;
      k1 = k1^last_answer;
     // printf("\n1 %d %d",u,k1);
      while(path[hash[u]]!=-1){
        int res = k1^keys[hash[u]];
        if(res>largest)
          largest = res;
        if(res< smallest)
          smallest = res;
        u=path[hash[u]];
      }
      printf("\n%d %d",smallest,largest);
      last_answer = smallest^ largest;
      //printf("%d %d\n",smallest,largest);
    }
  }
  return 0;
}
