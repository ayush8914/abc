#include<bits/stdc++.h>
using namespace std;

void rabin_karp_matcher(string t,string p,int d,int q){

   int n = t.length();
   int m = p.length();
   int h = pow(d,m-1);
   int p0=0;
   int t0=0;

   for(int i=0;i<m;i++){
      p0 = ( d*p0+  p[i]-'0')%q;
      t0 = ( d*t0+  t[i]-'0')%q;
   }  


   for(int i=0;i<=n-m;i++){
    if(p0 == t0){
        int j=0;
        for(;j<m;j++){
            if(t[i+j] != p[j]) break;
        }
        if(j == m)printf("pattern found at shift: %d\n",i);
    }

    if(i < n-m){
        t0 = ( (t0 - (t[i]-'0')*h)*d + (t[i+m]-'0') )%q;
    }

    while(t0 < 0){
        t0+=q;
    }

   }
}

int main(){
  
    
    int q=13;
    string text = "1234";
    string pattarn = "12";
    int d=10;
    rabin_karp_matcher(text,pattarn,d,q);

    return 0;
}