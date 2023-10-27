#include<bits/stdc++.h>
using namespace std;

#define mapci map<char,int>

int HP(string t,string p){
   
   int n = t.length();
    int m = p.length();

    mapci shift_table;
    for(int i=0;i<=m-2;i++){
        shift_table[p[i]] = m-i-1;
    }

    int i=0;

    while(i+m<=n){
       if(t[i+m-1] == p[m-1]){
        int j= m-2;

        while(j>=0 && t[i+j] == p[j]){
            j--;
        }


        if(j == -1){
            return i;
        }

       }
    
       if(shift_table[t[i+m-1]]) i+= shift_table[t[i+m-1]];
       else i+=m;
    }
}

int main(){

    string t= "ayush";
    string p = "y";


    if(HP >=0){
        cout<<"pattern found at shift: "<<HP<<"\n";
    }
    else 
        cout<<"pattern not found\n";
}