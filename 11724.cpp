#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

void bfs(vector<vector<int>>& g, int root, bool* visit){
    queue<int> q;
    q.push(root);
    visit[root] = 1;

    while (!q.empty()){
        if(!g[q.front()].empty()){
            for(int i : g[q.front()]){
                if(!visit[i]){
                    q.push(i);
                    visit[i] = 1;
                }
            }
        }
        q.pop();
    }
}

int check_visit(bool* visit, int size){
    for(int i = 1; i <= size; ++i){
        if(!visit[i]){
            return i;
        }
    }
    return 0;
}

int count(vector<vector<int>>& g){
    int cnt = 0;
    bool visit[g.size()] = {0, };
    while (int root = check_visit(visit, g.size() - 1)){
        ++cnt;
        bfs(g, root, visit);
    }
    return cnt;
}

int main(){
    int N, M;
    cin>>N>>M;
    vector<vector<int>> graph(N+1);

    for(int i = 0; i < M; ++i){
        int a, b;
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for(int i = 1; i <= N; ++i){
        sort(graph[i].begin(), graph[i].end());
    }

    int ans = count(graph);
    cout<<ans;
}