#include <bits/stdc++.h>
using namespace std;


#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int,int>
#define qpii queue<pii>
#define ff first
#define ss second

#define V 4

// Lab 3 : Implementation of Ford-Fulkerson Algorithm to Find Maximum Flow in a S-T Flow Graph.
// Time Complexity : O(maxflow * complexity of BFS)


int  bfs(vvi &rg, int s,int t,vi &parent){
    fill(parent.begin(),parent.end(),-1);
    parent[s] = -2;

    qpii q;

    q.push({s,INT_MAX});
    int bottleneck = INT_MAX;

    while(!q.empty()){
        int u = q.front().ff;
        int cap = q.front().ss;

        q.pop();

        for(int av =0;av<V;av++){

            if(av != u &&  parent[av] == -1 && rg[u][av] >0){
                parent[av] = u;
                bottleneck = min(bottleneck,rg[u][av]);
                if(av == t)return bottleneck;
                q.push({av,bottleneck});
            }
        }
    }
    return 0;
}


int ford_fulkerson(vvi &graph , int s, int t){
   
   vi parent(V,-1);
   vvi rgraph = graph;
   int max_flow = 0, min_cap=0;

   while((min_cap = bfs(rgraph,s,t,parent))){
      
      max_flow += min_cap;
      int v = t;

      while(v != s){
        int u = parent[v];
        rgraph[u][v] -= min_cap;
        rgraph[v][u] += min_cap;
        v = parent[v];
      }

   }
    
   return max_flow;
}

void addEdge(vvi &g,int u,int v,int w){
   g[u][v]= w;    
}

int main() {
	vvi graph(V,vi(V,0));
    
    addEdge(graph,0,1,3);
    addEdge(graph,0,2,2);
    addEdge(graph,1,2,5);
    addEdge(graph,1,3,2);
    addEdge(graph,2,3,3);

    int source =0 , sink = 3;

    cout<<"Maximum Flow : "<<ford_fulkerson(graph,source,sink);

	// your code goes here
	return 0;
}

