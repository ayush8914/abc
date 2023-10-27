#include<bits/stdc++.h>

using namespace std;

class TwoSAT {
public:
    int n;
    vector<vector<int>> implicationGraph;
    vector<vector<int>> reversedGraph;
    vector<bool> visited;
    stack<int> order;
    vector<int> component;

public:
    TwoSAT(int n) : n(n), implicationGraph(2 * n), reversedGraph(2 * n), visited(2 * n, false) {}

    void addClause(int u, int v) {
        // Add edges to the implication graph
        implicationGraph[~u].push_back(v);
        implicationGraph[~v].push_back(u);

        // Add edges to the reversed graph
        reversedGraph[u].push_back(~v);
        reversedGraph[v].push_back(~u);
    }

    void dfs1(int v) {
        visited[v] = true;
        for (int u : implicationGraph[v]) {
            if (!visited[u]) {
                dfs1(u);
            }
        }
        order.push(v);
    }

    void dfs2(int v, int color) {
        visited[v] = true;
        component[v] = color;
        for (int u : reversedGraph[v]) {
            if (!visited[u]) {
                dfs2(u, color);
            }
        }
    }

    bool solve() {
        for (int v = 1; v <= 2 * n; v++) {
            if (!visited[v]) {
                dfs1(v);
            }
        }

        fill(visited.begin(), visited.end(), false);

        int color = 0;
        while (!order.empty()) {
            int v = order.top();
            order.pop();

            if (!visited[v]) {
                color++;
                dfs2(v, color);
            }
        }

        for (int i = 1; i <= n; i++) {
            if (component[i] == component[~i]) {
                return false; // Unsatisfiable
            }
        }

        return true; // Satisfiable
    }
};

int main() {
    int n, m; // Number of variables and clauses
    cin >> n >> m;
    TwoSAT twoSat(n);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        twoSat.addClause(u, v);
    }

 

    return 0;
}
