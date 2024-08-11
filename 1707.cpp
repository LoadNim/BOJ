#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void init(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

bool is_bin(vector<vector<int>>&g, int* d){
    for(int i = 1; i < g.size(); ++i){
        for(int v : g[i]){
            if(d[i] % 2 == d[v] % 2){
                return false;
            }
        }
    }
    return true;
}

void bfs(int start, vector<vector<int>>& g, int* d){
    queue<int> q;
    q.push(start);
    d[start] = 1;

    while(!q.empty()){
        for(int v : g[q.front()]){
            if(!d[v]){
                q.push(v);
                d[v] = d[q.front()] + 1;
            }
        }
        q.pop();
    }
}

int main(){
    init();
    int K;
    cin>>K;
    for(int i = 0; i < K; ++i){
        int V, E;
        cin>>V>>E;
        vector<vector<int>> graph(V+1);
        int dist[V+1] = {0, };

        for(int r = 0; r < E; ++r){
            int u, v;
            cin>>u>>v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        for(int i = 1; i <= V; ++i){
            if(!dist[i]){
                bfs(i, graph, dist);
            }
        }
        
        if(is_bin(graph, dist)){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }
    }
}