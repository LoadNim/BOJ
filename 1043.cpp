#include <iostream>
#include <set>
#include <vector>
#include <queue>
using namespace std;

void bfs(int start, vector<set<int>>& g, bool* v){
    if(!v[start]){
        queue<int> q;
        q.push(start);
        v[start] = 1;

        while(!q.empty()){
            for(int i : g[q.front()]){
                if(!v[i]){
                    q.push(i);
                    v[i] = 1;
                }
            }
            q.pop();
        }
    }
}

int main(){
    int N, M;
    cin>>N>>M;
    vector<set<int>> graph(N+1);
    vector<vector<int>> guest(M);
    bool visit[N+1] = {0, };

    int T;
    cin>>T;
    vector<int> know;
    for(int i = 0; i < T; ++i){
        int k;
        cin>>k;
        know.push_back(k);
    }

    for(int i = 0; i < M; ++i){
        int num;
        cin>>num;
        for(int r = 0; r < num; ++r){
            int g;
            cin>>g;
            guest[i].push_back(g);
        }

        for(int x = 0; x < num; ++x){
            for(int y = 0; y < num; ++y){
                if(x != y){
                    graph[guest[i][x]].insert(guest[i][y]);
                }
            }
        }
    }

    for(int start : know){
        bfs(start, graph, visit);
    }

    int ans = 0;
    for(int i = 0; i < M; ++i){
        bool flag = 0;
        for(int v : guest[i]){
            if(visit[v]){
                flag = 1;
                break;
            }
        }
        if(!flag){
            ++ans;
        }
    }

    cout<<ans;
}