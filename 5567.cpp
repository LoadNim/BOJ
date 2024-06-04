#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int bfs(vector<vector<int>>& g){
    int cnt = 0;
    int visit[g.size()] = {0, };
    queue<int> q;
    q.push(1);
    visit[1] = 1;

    while(!q.empty()){
        if(!g[q.front()].empty()){
            for(int v : g[q.front()]){
                if(!visit[v] && visit[q.front()] <= 2){
                    q.push(v);
                    visit[v] = visit[q.front()] + 1;
                    ++cnt;
                }
            }
        }
        q.pop();
    }
    return cnt;
}

int main(){
    int people, link;
    cin>>people>>link;
    vector<vector<int>> graph(people+1);

    for(int i = 0; i < link; ++i){
        int a, b;
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for(int i = 1; i <= people; ++i){
        sort(graph[i].begin(), graph[i].end());
    }

    cout<<bfs(graph);
}