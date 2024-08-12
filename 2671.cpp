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
    queue<int> q;
    q.push(start);
    bool visit[g.size()] = {0, };
    visit[start] = 1;

    int cnt = 0;
    while(!q.empty()){
        for(int v : g[q.front()]){
            if(!visit[v]){
                q.push(v);
                visit[v] = 1;
                ++cnt;
            }
        }
        q.pop();
    }
    return cnt;
}

int main(){
    init();
    int N, M;
    cin>>N>>M;
    vector<vector<int>> heavy(N+1);
    vector<vector<int>> light(N+1);

    for(int i = 0; i < M; ++i){
        int A, B;
        cin>>A>>B;
        light[A].push_back(B);
        heavy[B].push_back(A);
    }

    int cnt = 0;
    for(int i = 1; i <= N; ++i){
        if(bfs(i, heavy) > N/2 || bfs(i, light) > N/2){
            ++cnt;
        }
    }
    cout<<cnt;
}