#include<iostream>
#include<stdio.h>
#include<map>
using namespace std;
int main(){
  int a[100000];
  int N,M;
  int tmp=0;
  int count=-1;
  std::map<int,pair<int, int> > hash;
  int b[100000];
  scanf("%d %d",&N,&M);
  for(int i=0;i<N;i++){
    scanf("%d",&tmp);
    a[i] = tmp;
  }
  int last=-1;
  int last_ind=-1;
  for(int i=0;i<N;i++){
    if(a[i]!=last){
      count++;
      //printf("\n++ %d %d %d",last,last_ind,i-1);
      hash.insert(make_pair<int,pair<int,int> >(count-1,make_pair<int,int>(last_ind,i-1)));
      last_ind = i;
      last = a[i];
    }
    b[i] = count;
  }
  if(a[N-1] == a[N-2]){
    //printf("\n+++ %d %d %d",last,last_ind, N-1);
    hash.insert(make_pair<int,pair<int,int> >(count,make_pair<int,int>(last_ind,N)));
  }
  int l,r,k;
  for(int i=0;i<M;i++){
    scanf("%d %d %d",&l,&r,&k);
    int ind = (r+l)/2 -1 ;
    int ind_count = b[ind]; 
    int ind_length=0;
    //printf("\n a[l+r/2] = %d : b[ind]= %d : hash[b[ind]]= %d %d", a[ind], b[ind], hash[b[ind]].first, hash[b[ind]].second);
    if(hash[ind_count].second>r-1){
      ind_length =  r-1;
      //printf("\t 1 ind= %d",ind_length);
    }
    else{
      ind_length = hash[ind_count].second ;
      //printf("\t 2 ind= %d",ind_length);
    }
    if(hash[ind_count].first<l-1){
      ind_length-=l-1;
      //printf("\t 3 ind= %d",ind_length);
    }
    else{
      ind_length-=hash[ind_count].first;
      //printf("\t 4 ind= %d",ind_length);
    }
    ind_length++;
    //printf("\n+++= length is %d",ind_length);
    if(ind_length>=k){
      printf("%d\n",a[ind]);
    }
    else{
      printf("-1\n");
    }
  }
  return 0;
}
