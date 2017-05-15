#include<iostream>
using namespace std;
int main(){
  int a,b,c,d;
  int test;
  scanf("%d ",&test);
  while(test--){
    scanf("%d %d %d",&a,&b,&c);
    char ch=0;
    d=-1;
    while(ch!='\n')
    {
      ch = getchar_unlocked();
      if(ch==' ')
        continue;
      else if(ch>='0' && ch<='9'){
        if(d==-1)
          d=0;
        d=d*10+ch-'0';
      }
    }
    printf("%d %d %d %d\n",a,b,c,d);
  }
}
