#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int bfs(vector<vector<int>>& g){
    int cnt = 0;
    bool visit[g.size()] = {0, };
    queue<int> q;
    q.push(1);
    visit[1] = 1;

    while(!q.empty()){
        if(!g[q.front()].empty()){
            for(int v : g[q.front()]){
                if(!visit[v]){
                    q.push(v);
                    visit[v] = 1;
                    ++cnt;
                }
            }
        }
        q.pop();
    }
    return cnt;
}

int main(){
    int node, link;
    cin>>node>>link;
    vector<vector<int>> graph(node+1);
    
    for(int i = 0; i < link; ++i){
        int a, b;
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for(int i = 1; i <= node; ++i){
        sort(graph[i].begin(), graph[i].end());
    }

    cout<<bfs(graph);
}