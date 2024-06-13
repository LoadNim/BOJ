#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
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

    int max = 1;
    for(int i = 1; i < g.size(); ++i){
        if(max < visit[i]){
            max = visit[i];
        }
    }
    return max - 1;
}

int main(){
    int num;
    cin>>num;
    vector<vector<int>> graph(num+1);
    vector<vector<int>> score(num);
    
    int a, b;
    while(cin>>a>>b && a+b != -2){
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    int min = 50;
    for(int i = 1; i <= num; ++i){
        int point = bfs(graph, i);
        score[point].push_back(i);
        if(point < min){
            min = point;
        }
    }

    cout<<min<<' '<<score[min].size()<<endl;
    for(int v : score[min]){
        cout<<v<<' ';
    }
}