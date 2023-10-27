#include<bits/stdc++.h>

using namespace std;
#define  edge pair<int,int>
#define si set<int>
#define ff first
#define ss second

class RandmoizedMVC{
 public:
  int n;
  vector<edge> edges;
  int remaining_edges;
  si ans;  

  RandmoizedMVC(vector<edge> edges,int n){
    this->n = n;
    this->edges = edges;
    remaining_edges = edges.size();
  }
  

  void remove_incident_edges(int u,int v){
    vector<edge> temp;
    for(int i=0;i<remaining_edges;i++){
    cout<<"remaining edges :"<<remaining_edges<<" V: "<<v<<endl;

      if(edges[i].ff == v || edges[i].ss == v || edges[i].ff == u || edges[i].ss == u){
        remaining_edges--;
      }
      else{
        cout<<"pushed "<<edges[i].first<<" "<<edges[i].second<<endl;
        temp.push_back(edges[i]);
      }
    }
    edges = temp;
  }

  void find_mvc(){
    while(remaining_edges != 0){
      int i = rand()%remaining_edges;
      edge e = edges[i];
      ans.insert(e.ff);
      ans.insert(e.ss);
      remove_incident_edges(e.ff, e.ss);
      cout<<"remaining edges :"<<remaining_edges<<endl;
    }
    cout<<"MVC is :"<<endl;
    for(auto x:ans){
      cout<<x<<" ";
    }
  }
};

int main(){
   
   srand(time(NULL));
   vector<edge> edges = {{0,3},{1,3},{2,3}};
   int n =4;

   RandmoizedMVC  rmvc(edges,n);
    rmvc.find_mvc();
    return 0;
}