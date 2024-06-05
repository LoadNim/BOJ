#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void bfs(vector<vector<bool>>& g, int root){
    bool visit[g.size()] = {0, };
    queue<int> q;
    q.push(root);

    while(!q.empty()){
        for(int i = 1; i < g[q.front()].size(); ++i){
            if(g[q.front()][i] && !visit[i]){
                q.push(i);
                visit[i] = 1;
            }
        }
        q.pop();
    }

    for(int i = 1; i < sizeof(visit); ++i){
        cout<<visit[i]<<' ';
    }
    cout<<endl;
}

int main(){
    int N;
    cin>>N;
    vector<vector<bool>> graph(N+1, vector<bool> (N+1));

    for(int i = 1; i <= N; ++i){
        for(int r = 1; r <= N; ++r){
            bool input;
            cin>>input;
            graph[i][r] = input;
        }
    }

    for(int i = 1; i <= N; ++i){
        bfs(graph, i);
    }
}