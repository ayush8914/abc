#include<bits/stdc++.h>
using namespace std;
 

void string_matcher(string t,string p){
    int n = t.length();
    int m = p.length();


    for(int i=0;i<=n-m;i++){
        int j=0;
        for(;j<m;j++){
            if(t[i+j] != p[j]) break;
        }

        if(j == m)printf("pattern found at shift: %d\n",i);
    } 

}

int main(){

    string t = "ayush";
    string p = "y";

    string_matcher(t,p);
}