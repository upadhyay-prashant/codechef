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
const int maxS = 100010;
bool visited[maxS];

struct node{
  long long dist;
  int num;
  node(){
    dist = LLONG_MAX;
  }
  void reset(){
    dist = LLONG_MAX;
  }
}nodes[maxS];

std::vector<int> paths[maxS];
std::vector<long long> length[maxS];
int N, K , X, M , S;

struct comparator{
  bool operator()(node a , node b){
    return a.dist>b.dist;
  }
};

std::vector<node> mh;

bool putin[maxS];

void reset(){
  for(int i=1;i<maxS;i++){
    nodes[i].reset();
    nodes[i].num = i;
    visited[i] = false;
    putin[i] = false;
  }
}

void DJKSTR(int gol){
  nodes[gol].dist = 0;
  int count =0;
  std::map<int,int> hash;
  for(int i=1;i<=K;i++)
    hash[i]=0;
  do{
    visited[gol] = true;
    if(gol <= K)
      hash.erase(gol);
    for(int i=0;i<paths[gol].size();i++){
      int next = paths[gol][i];
      if(nodes[next].dist > nodes[gol].dist+(long long)length[gol][i]){
        nodes[next].dist = nodes[gol].dist + (long long)length[gol][i];
      }
      if(putin[next] == false){
        putin[next] = true;
        mh.push_back(nodes[next]);
      }
    }
    if(gol<=K){
      for(std::map<int,int>::iterator iter= hash.begin();iter!=hash.end(); iter++){
        int i = iter->first;
        if(gol == i)
          continue;
        if(nodes[i].dist > nodes[gol].dist + (long long) X){
          nodes[i].dist = nodes[gol].dist + (long long)X;
          if(putin[i] == false){
            putin[i] = true;
            mh.push_back(nodes[i]);
          }
        }
      }
    }
    //heapify()
    std::make_heap(mh.begin(),mh.end(),comparator());
    std::pop_heap(mh.begin(),mh.end(),comparator());
    gol = mh.back().num;
    mh.pop_back();
    count++;
  }
  while(count<N);
}

void getSum(){
  for(int i=1;i<=N;i++){
   printf("%lld ",nodes[i].dist);
  }
  printf("\n");
}

int main(){
  int testcases;
  scanf("%d",&testcases);
  while(testcases--){
    reset();
    scanf("%d %d %d %d %d",&N,&K,&X,&M,&S);
    int a,b,c;
    for(int i=0;i<M;i++){
      scanf("%d %d %d",&a,&b,&c);
      paths[a].push_back(b);
      length[a].push_back(c);
      paths[b].push_back(a);
      length[b].push_back(c);
    }
    DJKSTR(S);
    getSum();
  }
  return 0;
}
