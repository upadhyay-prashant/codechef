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
#include<unordered_map>
#include<cassert>
using namespace std;

const int SIZE = 10000000;
const int SIZE_T = 300010;
int pathNodeCount = 1;
int count_node=1;
int keys[SIZE_T];
int myindex=1;
unordered_map<int,int> myHash;
vector<int> paths[SIZE_T];
bool visited[SIZE_T];
int chains[SIZE_T];
int chainTrieHead[SIZE_T];
int parentInNextChain[SIZE_T];
int chainCount=0;
int subTreeSize[SIZE_T];
bool specialChild[SIZE_T];
int depth[SIZE_T];
int r;
int us[200010];
int ks[200010];
int lk=0;

struct node{
  node* next[2];
  int depth;
  node(){
    reset();
  }
  void reset(){
    next[0] = NULL;
    next[1] = NULL;
    depth = -1;
  }
}nodes[SIZE];

struct PathNode{
  signed char path[32];
  PathNode(){
    reset();
  }
  void reset(){
    for(int i=0;i<32;i++)
      path[i] = -1;
  }
}pathNode[300011];
PathNode* pathNodes[300011];
void init(){
  for(int i=0;i<300001;i++)
    pathNodes[i] = &pathNode[i];
}

void insert1(int key,int ind){
  int i=31;
  node* temp = &nodes[chainTrieHead[chains[ind]]];
  node* last = NULL;
  while(i>=0){
    int res = key&(1<<i);
    res = res==0?0:1;
    if(temp->next[res]==NULL){
      temp->next[res] = &nodes[count_node++];
    }
    last = temp;
    temp = temp->next[res];
    if(temp->depth==-1){
      temp->depth = depth[ind];
    }
    i--;
  }
}

void insertPath(int key, int to, int from=0){
  int i =31;
  while(i>=0){
    if(key&(1<<i)){
      switch(pathNodes[from]->path[i]){
        case -1: pathNodes[to]->path[i] = 1; break;
        case 0: pathNodes[to]->path[i] = 2; break;
        case 1: pathNodes[to]->path[i] = 1; break;
        case 2: pathNodes[to]->path[i] = 2; break;
      }
    }
    else{
      switch(pathNodes[from]->path[i]){
        case -1: pathNodes[to]->path[i] = 0; break;
        case 0: pathNodes[to]->path[i] = 0; break;
        case 1: pathNodes[to]->path[i] = 2; break;
        case 2: pathNodes[to]->path[i] = 2; break;
      }
    }
    i--;
  }
}

void myFill(int ind, int from){
  from = myHash[from];
  insert1(keys[ind],ind);
  insertPath(keys[ind], ind, from);
}
void DFS(int station, int from=0,int chain=0,int parentAboveChain=0){
  int ind = myHash[station];
  if(visited[ind] == true)
    return;
  chains[ind] = chain;
  int from_temp = from;
  if(chainTrieHead[chain]==-1){
    chainTrieHead[chain]=count_node++;
    from_temp =0;
  }
  parentInNextChain[ind] = parentAboveChain;
  myFill(ind, from_temp);
  visited[ind] = true;
  for(int i=0;i< paths[ind].size();i++){
     if(paths[ind].at(i)==from)
	continue;
    if(specialChild[myHash[paths[ind].at(i)]]==true){
      DFS(paths[ind].at(i),station,chain,parentAboveChain);
    }
    else{
      DFS(paths[ind].at(i),station,++chainCount,ind);
    }
  }
}

void DFS_SIZE(int station, int parent =-1,int deep=0){
  int ind= myHash[station];
  if(visited[ind] == true){
    return;
  }
  depth[ind]=deep;
  visited[ind] = true;
  if(paths[ind].size()==1){
    subTreeSize[ind] =0;
    return;
  }
  int sum =0;
  int largest=INT_MIN, largest_ind =-1;
  deep++;
  for(int i=0;i<paths[ind].size();i++){
    if(paths[ind].at(i) == parent)
      continue;
    DFS_SIZE(paths[ind].at(i),station,deep);
    if(largest == INT_MIN || largest < subTreeSize[myHash[paths[ind].at(i)]]){
      largest  = subTreeSize[myHash[paths[ind].at(i)]];
      largest_ind = myHash[paths[ind].at(i)];
    }
    sum+=subTreeSize[myHash[paths[ind].at(i)]]+1;
  }
  specialChild[largest_ind] = true;
  subTreeSize[ind] = sum;
}

int reset =0;
int largest_iter_count = INT_MIN;
int query(int from, int msg){
  int smallest_final=INT_MAX,largest_final=INT_MIN;
  int iterCount=0;
  while(from!=0){
    int i=31;
    iterCount++;
    int smallest=0, largest =0;
    PathNode* ptr = pathNodes[from];
    node* temp= &nodes[chainTrieHead[chains[from]]];
    node* temp1 = temp;
    while(i>=0){
      int res = (msg & (1<<i))==0?0:1;
      bool increase = false;
      bool increase1 = false;
      if(ptr->path[i]==2){
        if(res==1){
          if(temp->next[0]!=NULL && temp->next[0]->depth<=depth[from]){
            increase = true;
            temp = temp->next[0];
          }
          else{
            temp = temp->next[1];
          }
          if(temp1->next[1]!=NULL && temp1->next[1]->depth<=depth[from]){
            temp1=temp1->next[1];
          }
          else{
            temp1=temp1->next[0];
            increase1= true;
          }
        }
        else{
          if(temp->next[1]!=NULL && temp->next[1]->depth<=depth[from]){
            increase = true;
            temp = temp->next[1];
          }
          else temp = temp->next[0];
          if(temp1->next[0]!=NULL && temp1->next[0]->depth<=depth[from]){
            temp1=temp1->next[0];
          }
          else{
            temp1=temp1->next[1];
            increase1=true;
          }
        }
      }
      else if(ptr->path[i] == 0){
        if(res ==1){
          increase = true;
          increase1 = true;
        }
        temp = temp->next[0];
        temp1 = temp1->next[0];
      }
      else if(ptr->path[i] == 1){
        if(res==0){
          increase = true;
          increase1 = true;
        }
        temp = temp->next[1];
        temp1 = temp1->next[1];
      }
      if(increase)
        largest = (largest | (1<<i));
      if(increase1)
        smallest = (smallest | (1<<i));
      i--;
    }
    if(smallest<smallest_final)
      smallest_final = smallest;
    if(largest_final< largest)
      largest_final = largest;
    from = parentInNextChain[from];
  }
  assert(iterCount<100);
  if(largest_iter_count<iterCount){
    largest_iter_count = iterCount;
  }
  printf("%d %d\n",smallest_final, largest_final);
  return smallest_final^largest_final;
}
void rebuild(){
  for(int i=0;i<count_node;i++){
    nodes[i].reset();
  }
  //printf("\n++ nodes rest");
  count_node=1;
  for(int i=0;i<pathNodeCount;i++){
    pathNode[i].reset();
  }
  //printf("\n++ path reset");
  pathNodeCount =1;
  for(int i=0;i<SIZE_T;i++){
    visited[i] = false;
    chains[i] = -1;
    subTreeSize[i] = 0;
    specialChild[i] = false;
    chainTrieHead[i] = -1;
    parentInNextChain[i] =-1;
  }
  //printf("\n++ done with resetting");
  chainCount=0;
  //printf("\n++ going to run first DFS");
  DFS_SIZE(r);
  //printf("DFS_SIZE done\n");
  for(int i=0;i<myindex;i++)
    visited[i] = false;
  DFS(r);
  reset=0;
}
int main(){
  init();
  int n,q;
  scanf("%d %d",&n,&q);
  int k;
  scanf("%d %d",&r,&k);
  myHash[r] = myindex;
  keys[myindex++] = k;

  for(int i=0;i<n-1;i++){
    int from,to,key;
    scanf("%d %d %d",&from,&to,&key);
    if(myHash.find(from) == myHash.end()){
      myHash[from] = myindex++;
    }
    int ind = myHash[from];
    paths[ind].push_back(to);
    keys[ind] = key;
    if(myHash.find(to)==myHash.end()){
      myHash[to] = myindex++;
    }
    ind = myHash[to];
    paths[ind].push_back(from);
  }
  for(int i=0;i<q;i++){
    int t,u,v,k1;
    scanf("%d %d %d",&t,&u,&v);
    char ch=0;
    k1 = -1;
    while(ch!='\n'){
      ch = getchar_unlocked();
      if(ch==' ')
        continue;
      else if(ch>='0' && ch<='9'){
        if(k1==-1)
          k1=0;
        k1=k1*10+ch-'0';
      }
    }
    if(k1==-1){
      us[lk] = u;
      ks[lk] = v;
      lk++;
    }
    else{
      u=u^t;
      k1=k1^t;
      v=v^t;
      int ind = myindex++;
      myHash[v] = ind;
      paths[ind].push_back(u);
      paths[myHash[u]].push_back(v);
      keys[ind] = k1;
    }
  }
  rebuild();
  int last_answer =0;
  for(int i=0;i<lk;i++){
      int u=us[i] ^ last_answer;
      int k1 = ks[i]^last_answer;
    last_answer = query(myHash[u],k1);
  }
  return 0;
}
