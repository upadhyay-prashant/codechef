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
  long long n,k;
  scanf("%lld %lld",&n,&k);
  long long a[31];
  long long temp;
  for(int i=0;i<n;i++){
    scanf("%lld",&temp);
    a[i] = temp;
  }
  vector<long long> vec;
  vector<long long> index;
  map<long long, int> prodToIndex;
  map<long long, int> repeatedOnes;
  for(int i=0;i<n/2;i++){
    int length = vec.size();
    map<long long, int> check;
    for(int j=0;j<length;j++){
      if(vec[j]*a[i]<=k && a[i]<LLONG_MAX/vec[j]){
        long long prod = vec[j]*a[i];
        if(prodToIndex.find(prod) == prodToIndex.end()){
          prodToIndex[prod] = vec.size();
          vec.push_back(prod);
          index.push_back(index[j]);
        }
        else{
          check[prod] = index[j];
          //index[prodToIndex[prod]] = index[prodToIndex[prod]]+ index[j];
          repeatedOnes[prod] = prodToIndex[prod];
        }
      }
    }
    for(map<long long, int>::iterator it = check.begin();it != check.end(); it++){
      index[prodToIndex[it->first]]+=it->second;
    }

    if(a[i]<=k){
      if(prodToIndex.find(a[i])==prodToIndex.end()){
        prodToIndex[a[i]] = vec.size();
        vec.push_back(a[i]);
        index.push_back(1);
      }
      else{
        index[prodToIndex[a[i]]]++;
        repeatedOnes[a[i]] = prodToIndex[a[i]];
      }
    }
  }
  vector<long long> vec1;
  vector<long long> index1;
  map<long long, int> prodToIndex1;
  map<long long, int> repeatedOnes1;
  for(int i=n/2;i<n;i++){
    int length = vec.size();
    map<long long, int> check;
    for(int j=0;j<length;j++){
      if(vec1[j]*a[i]<=k && a[i]<LLONG_MAX/vec1[j]){
        long long prod = vec1[j]*a[i];
        if(prodToIndex1.find(prod) == prodToIndex1.end()){
          prodToIndex11[prod] = vec.size();
          vec.push_back(prod);
          index.push_back(index1[j]);
        }
        else{
          check[prod] = index1[j];
          //index1[prodToIndex11[prod]] = index1[prodToIndex11[prod]]+ index1[j];
          repeatedOnes[prod] = prodToIndex11[prod];
        }
      }
    }
    for(map<long long, int>::iterator it = check.begin();it != check.end(); it++){
      index1[prodToIndex11[it->first]]+=it->second;
    }

    if(a[i]<=k){
      if(prodToIndex1.find(a[i])==prodToIndex1.end()){
        prodToIndex11[a[i]] = vec.size();
        vec.push_back(a[i]);
        index.push_back(1);
      }
      else{
        index1[prodToIndex11[a[i]]]++;
        repeatedOnes[a[i]] = prodToIndex11[a[i]];
      }
    }
  }
  long long res  = vec.size();
  for(map<long long,int>::iterator it = repeatedOnes.begin(); it !=repeatedOnes.end();it++){
    res = res + index[it->second]-1;
  }
  printf("%lld\n",res);
  return 0;
}
