#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void init(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int bfs(int start, vector<vector<int>>& g){
    queue<int>q;
    q.push(start);
    bool visit[g.size()]= {0, };
    visit[start] = 1;

    int num = 0;
    while (!q.empty()){
        for(int v : g[q.front()]){
            if(!visit[v]){
                q.push(v);
                visit[v] = 1;
            }
        }
        q.pop();
        ++num;
    }
    return num;
}

int main(){
    init();
    int N, M;
    cin>>N>>M;

    vector<vector<int>> graph(N+1);
    for(int i = 0; i < M; ++i){
        int A, B;
        cin>>A>>B;
        graph[B].push_back(A);
    }

    vector<pair<int, int>> ans;
    ans.push_back({0, 0});
    for(int i = 1; i <= N; ++i){
        int num = bfs(i, graph);
        if(num > ans[0].second){
            ans.clear();
            ans.push_back({i, num});
        }
        else if(num == ans[0].second){
            ans.push_back({i, num});
        }
    }
    
    for(pair<int, int> i : ans){
        cout<<i.first<<' ';
    }
}