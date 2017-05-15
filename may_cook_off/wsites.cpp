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
bool comp(pair<string,bool> &a, pair<string,bool> &b){
  return strcmp(b.first.c_str(),a.first.c_str())>=0;
}
struct node{
  char ch;
  int pos;
  node* path[26];
  bool filterEnd;
  int filterIndex;
  node(){
    for(int i=0;i<26;i++)
      path[i] = NULL;
    pos =0;
    filterEnd = false;
    filterIndex = -1;
  }
}nodes[3*100000];

int node_count=1;
node *head= &nodes[0];

void insert(char arr[]){
  int length = strlen(arr);
  node* temp = head;
  for(int i=0;i<length;i++){
    if(temp->path[arr[i]-'a']==NULL){
      nodes[node_count].ch=arr[i];
      nodes[node_count].pos++;
      temp->path[arr[i]-'a'] = &nodes[node_count];
      temp = &nodes[node_count];
      node_count++;
    }
    else{
      temp->pos++;
      temp = temp->path[arr[i]-'a'];
    }
  }
}

int filterCount=0;
std::vector<string> res;
bool notPossible=false;

void insert1(string str){
  int length = str.length();
  node* temp = head;
  int len=0;
  int tempFilterCount=-1;
  bool filterFound = false;
  //printf("\n+++ inserting %s",str.c_str());
  for(int i=0;i<length && !notPossible;i++){
    if(temp->path[str[i]-'a']==NULL){
      //printf("\n+++ found end for - %c",str[i]);
      nodes[node_count].ch=str[i];
      temp->path[str[i]-'a'] = &nodes[node_count];
      temp = &nodes[node_count];
      temp->pos--;
      node_count++;
      if(tempFilterCount==-1){
        tempFilterCount = filterCount;
        filterCount++;
        temp->filterIndex = tempFilterCount;
      }
      if(temp->filterIndex ==-1){
        temp->filterIndex=tempFilterCount;
      }
      if(!filterFound){
        //printf("\n++++ inserting %s into result", str.substr(0,len+1).c_str());
        temp->filterEnd = true;
        res.push_back(str.substr(0,len+1));
        filterFound = true;
      }
    }
    else{
      temp = temp->path[str[i]-'a'];
      //printf("\n++++ character %c already exists , filterEnd = %d , filterIndex = %d",str[i],temp->filterEnd, temp->filterIndex);
      if(tempFilterCount==-1){
        if(temp->filterIndex!=-1){
          tempFilterCount=temp->filterIndex;
        }
        else{
          tempFilterCount = filterCount;
          filterCount++;
          temp->filterIndex = tempFilterCount;
        }
      }
      if(temp->filterEnd == true){
        filterFound = true;
      }
      if(i==length-1 && temp->pos>0){
        notPossible = true;
      }
    }
    len++;
  }
}

int main(){
  int number;
  scanf("%d",&number);
  vector<string> vec;
  while(number--){
    char str[200010];
    char ch;
    scanf("\n%c %s",&ch,str);
    if(ch=='+'){
      insert(str);
    }
    else{
      string st = str;
      vec.push_back(st);
    }
  }
  std::sort(vec.begin(), vec.end());
  for(int i=0;i<vec.size() && !notPossible;i++){
    insert1(vec[i]);
  }
  if(notPossible){
    printf("-1");
    return 0;
  }
  printf("%lu\n",res.size());
  for(int i=0;i<res.size();i++){
    printf("%s\n",res[i].c_str());
  }
  return 0;
}
