#include<bits/stdc++.h>
using namespace std;
#define vmii vector<map<int,int>>
#define si set<int>

class stringMatching{
   public:
   vmii transition_table;
   si characters;
   string text,pattern;
    int n,m;

   stringMatching(string text,string pattarn){
        transition_table.resize(pattern.length()+1);
        this->text = text;
        this->pattern = pattern;
        this->n = text.length();
        this->m = pattern.length();
        for(int i=0;i<m;i++){
            characters.insert(pattern[i]);
        }

   } 

   void generateTransitionTable(){
       
   }   

   void findMatches(){
    generateTransitionTable();
    int q=0;
    for(int i=0;i<n;i++){
        q = transition_table[q][text[i]];
        if(q == m){
            cout<<"pattern found at shift: "<<i-m+1<<"\n";
        }
    }
   } 

};


int main(){
   
   string text,pattern;
    cin>>text>>pattern;

    stringMatching sm(text,pattern);
    sm.findMatches();
    return 0;
}