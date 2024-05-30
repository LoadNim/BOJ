#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

void dfs(vector<vector<int>>& g, int root){
    stack<int> st;
    vector<int> op;
    bool visit[g.size()] = {0, };

    st.push(root);
    op.push_back(root);
    visit[root] = 1;

    while(!st.empty()){
        bool flag = true;
        if(!g[st.top()].empty()){
            for(int i : g[st.top()]){
                if(!visit[i]){
                    st.push(i);
                    op.push_back(i);
                    visit[i] = 1;
                    flag = false;
                    break;
                }
            }
        }
        if(flag){
            st.pop();
        }
    }

    for(int i : op){
        cout<<i<<' ';
    }
    cout<<endl;
}

void bfs(vector<vector<int>>& g, int root){
    queue<int> q;
    vector<int> op;
    bool visit[g.size()] = {0, };

    q.push(root);
    op.push_back(root);
    visit[root] = 1;

    while(!q.empty()){
        if(!g[q.front()].empty()){
            for(int i : g[q.front()]){
                if(!visit[i]){
                    q.push(i);
                    op.push_back(i);
                    visit[i] = 1;
                }
            }
        }
        q.pop();
    }

    for(int i : op){
        cout<<i<<' ';
    }    
}

int main(){
    int N, M, V;
    cin>>N>>M>>V;
    vector<vector<int>> graph(N + 1);

    for(int i = 0; i < M; ++i){
        int a, b;
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for(int i = 1; i <= N; ++i){
        if(!graph[i].empty()){
            sort(graph[i].begin(), graph[i].end());
        }
    }

    dfs(graph, V);
    bfs(graph, V);
}