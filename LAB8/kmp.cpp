#include<bits/stdc++.h>
#define vi vector<int>
using namespace std;



class KMP{

    public:
    string t;
    string p;
    int n,m;
    vi pi;

    KMP(string text,string pattarn){
       
     n = text.length();
    m = pattarn.length();
        pi.resize(m);
        this->t = text;
        this->p = pattarn;
        
        pi[0]=-1;
        int k=-1;

        for(int i=1;i<m;i++){
           while(k>-1 && p[k+1] != p[i]){
                k = pi[k];
            }

            if(p[k+1] == p[i]){
                k++;
            }
            pi[i] = k;
        }

        for(int i=0;i<m;i++){
            cout<<pi[i]<<" ";
        }
    }




    void kmp_matcher(){
      int q=-1;
      for(int i=0;i<n;i++){
          while(q>-1 && p[q+1] != t[i]){
              q = pi[q];
          }

          if(p[q+1] == t[i]){
              q++;
          }

          if(q == m-1){
              cout<<"Pattern occurs with shift "<<i-m+1<<endl;
              q = pi[q];
          }
      }
    }

};

int main(){
    
KMP kmp("ababababca","abababca");
kmp.kmp_matcher();

    return 0;
}