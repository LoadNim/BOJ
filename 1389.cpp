#include <iostream>
#include <climits>
#include <vector>
#include <queue>
using namespace std;

int bfs(vector<vector<int>>& g, int root){
    int visit[g.size()] = {0, };
    queue<int> q;
    q.push(root);
    visit[root] = 1;

    while(!q.empty()){
        for(int v : g[q.front()]){
            if(!visit[v]){
                q.push(v);
                visit[v] = visit[q.front()] + 1;
            }
        }
        q.pop();
    }

    int sum = 0;
    for(int i = 1; i < g.size(); ++i){
        sum += (visit[i] - 1);
    }
    return sum;
}

int main(){
    int N, M;
    cin>>N>>M;
    vector<vector<int>> graph(N+1);
    pair<int, int> kb = {INT_MAX, 0};

    int a, b;
    for(int i = 0; i < M; ++i){
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for(int i = 1; i <= N; ++i){
        int val = bfs(graph, i);
        if(kb.first > val){
            kb.first = val;
            kb.second = i;
        }
    }

    cout<<kb.second;
}