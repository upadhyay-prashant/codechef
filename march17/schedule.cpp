#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
struct myObj{
  int length;
  int first;
  int second;
};
//TODO 
//1 ) chaing comparator
//2 ) change equal to 2 condition check if it works
//const int SIZE = 1000000;
const int SIZE = 10;
myObj mem[SIZE];

struct comp{
  bool operator()(const myObj &a, const myObj &b){
    if(a.length < b.length)
      return true;
    else if(a.length == b.length){
      return a.first> b.first;
    }
    return false;
  }
};
int mem_count=-1;
myObj getPair(){
  return mem[++mem_count];
}
void reset_mem(){
  mem_count =-1;
}
void insert(int last, int first, std::vector<int> &vec, std::vector<myObj> &vec2){
  myObj t = getPair();
  t.length = last - first +1;
  t.first = first;
  t.second = last;
  vec[first] = mem_count;
  vec2.push_back(t);
}
char*  pvec(std::vector<myObj> &vec){
  char *str=new char[100];
  int len=0;
  for(int i=0;i<vec.size();i++){
    len+=sprintf(str+len,"(%d %d %d)",vec[i].length, vec[i].first, vec[i].second);
  }
  return str;
}
int main(){
  int testcases;
  scanf("%d",&testcases);
  int arr[SIZE];
  int temp;
  int n,k;
  int smallest;
  while(testcases--){
    reset_mem();
    std::vector<myObj > vec;
    std::vector<int> hash(SIZE, -1);
    smallest = INT_MAX;
    scanf("%d %d",&n,&k);
    getchar_unlocked();
    for(int i=0;i<n;i++){
      char ch;
      ch = getchar_unlocked();
      arr[i] = ch=='0'?0:1;
    }
    int first=0, last=0;
    for(int i=1;i<n;i++){
      if(arr[i]!=arr[i-1]){
        insert(last, first, hash,vec);
        first = i;
        last = i;
      }
      else{
        last++;
      }
    }
    insert(last, first, hash,vec);
    std::make_heap(vec.begin(),vec.end(),comp());
    while(!vec.empty() && k>0){
      myObj t = vec.front();
      k--;
      std::pop_heap(vec.begin(), vec.end(),comp());
      vec.pop_back();
      if(smallest>t.length){
        smallest = t.length;
      }
      if(t.length>2){
        //divide the segment into 2 
        int temp_last  = t.second;
        t.length = t.length/2;
        t.second = t.first+t.length -1 ;
        vec.push_back(t);
        std::push_heap(vec.begin(),vec.end(),comp());
        insert(temp_last, t.first+2, hash, vec);
        std::push_heap(vec.begin(),vec.end(),comp());
        insert(t.second+1, t.second+1, hash, vec);
        std::push_heap(vec.begin(),vec.end(),comp());
        arr[t.second+1] = arr[t.second+1]==1?0:1;
      }
      else if(t.length == 2){
        // check if the length is under constraints
        if(t.second == n-1){
          // just flip the second and move without putting into the heap ?
          // putting it back is a good idea as it is full proof
          arr[t.second] = arr[t.second] ==0? 1:0;
          t.length =1;
          t.second = t.first;
          vec.push_back(t);
          std::push_heap(vec.begin(),vec.end(),comp());
          insert(t.second, t.second, hash, vec);
          std::push_heap(vec.begin(),vec.end(),comp());
        }
        else if(t.second<n-1 ){
          if(arr[t.second]!=arr[t.second+1]){
            //case for flipping first element
            // if first element is also not helping , fucking break from here
            // also check for boundary
            if(t.first ==0 || arr[t.first]!=arr[t.first-1]){
              arr[t.first] = arr[t.first]==0?1:0;
              int temp_last = t.second;
              t.second = t.first;
              t.length = 1;
              vec.push_back(t);
              std::push_heap(vec.begin(),vec.end(),comp());
              insert(temp_last, temp_last, hash, vec);
              std::push_heap(vec.begin(),vec.end(),comp());
            }
            else{
              //flipping is not going to help bitch  , fucking break
              break;
            }
          }
        }
      }
      else {
        break;
      }
    }
    myObj t = vec.front();
    if(t.length> smallest)
      t.length = smallest;
    printf("%d\n",t.length);
  }
  return 0;
}
