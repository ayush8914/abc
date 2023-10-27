#include<bits/stdc++.h>
using namespace std;

#define N 4
#define pb push_back
int g[N][N] = {
    {0,1,1,1},
    {1,0,0,1},
    {1,0,0,1},
    {1,1,1,0}
};


class edge{
   public:
    int x,y;
    edge(int u,int v){
        this->x = u;
        this->y = v;
    }
};

class mincut{
 public:
   int * parent;
   int * rank;

   mincut(){
    parent = new int[N];
    rank = new int[N];
    for(int i=0;i<N;i++){
        parent[i]= i;
        rank[i] = 1;
    }

   }

   int find(int v){
    if(v == parent[v]) return v;
    else parent[v] = find(parent[v]);
   }

   void unionset(int u,int v){
     u= find(u);
     v = find(v);


     if(u != v){
        parent[v] = u;
     }
   }

    int find_mincut(int m,vector<edge> &edges){
       int minsize=INT_MAX;
       int t= 100*N*N;
       while(t--){
         for(int i=0;i<N;i++){
          parent[i]= i;
          rank[i] = 1;
         }
       int n =N;
       while(n>2){
         int r = rand()%m;
         int u = edges[r].x;
         int v = edges[r].y;

         if(find(u) != find(v)){
            cout<<"edge contracted : "<<u<<"----"<<v<<"\n";
            n--;
            unionset(u,v);
       }


   }
       int ans=0;
       for(int i=0;i<m;i++){
        if(find(edges[i].x) != find(edges[i].y)){
            ans++;
          
        }
       }
       minsize = min(minsize,ans);
    }
    return minsize;
   }
};



int main(){
    srand(time(NULL));
    int m=0; // no of edges
    vector<edge> edges;
    
    for(int i=0;i<N;i++){
        for(int j=i+1;j<N;j++){
            if(g[i][j] == 1){
               m++;
             edges.pb(*(new edge(i,j)));
            }
        }
    }
    mincut *cut= new mincut();
  
    cout<<"Mincut size : "<<(*cut).find_mincut(m,edges);
    
    return 0;
}

