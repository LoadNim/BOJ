#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

void init(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void bfs(vector<vector<int>>& g, int* d){
    queue<int> q;
    q.push(1);
    d[1] = 1;

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
    int N, M;
    cin>>N>>M;
    
    vector<vector<int>> graph(N+1);
    int dist[N+1] = {0, };
    for(int i = 0; i < M; ++i){
        int A, B;
        cin>>A>>B;
        graph[A].push_back(B);
        graph[B].push_back(A);
    }

    bfs(graph, dist);
    int max = *max_element(dist, dist + N+1);
    int min = 20001;
    int cnt = 0;
    for(int i = 1; i <= N; ++i){
        if(dist[i] == max){
            if(i < min){
                min = i;
            }
            ++cnt;
        }
    }
    cout<<min<<' '<<max-1<<' '<<cnt;
}