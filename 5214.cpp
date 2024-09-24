#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void init(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int bfs(vector<vector<int>> hts, vector<vector<int>> sth, int* vis_s, bool* vis_h, int end){
    queue<int> q;
    q.push(1);
    vis_s[1] = 1;

    while(!q.empty() && !vis_s[end]){
        for(int v : sth[q.front()]){
            if(vis_h[v]){
                continue;
            }
            vis_h[v] = 1;
            for(int s : hts[v]){
                if(vis_s[s]){
                    continue;
                }
                vis_s[s] = vis_s[q.front()] + 1;
                q.push(s);
            }
        }
        q.pop();
    }
    if(vis_s[end]){
        return vis_s[end];
    }
    else{
        return -1;
    }
}

int main(){
    init();
    int N, K, M;
    cin>>N>>K>>M;
    int visit_station[N+1] = {0, };
    bool visit_hypertube[M] = {0, };
    vector<vector<int>> hypertube_to_station(M);
    vector<vector<int>> station_to_hypertube(N+1);

    for(int i = 0; i < M; ++i){
        for(int r = 0; r < K; ++r){
            int station;
            cin>>station;
            hypertube_to_station[i].push_back(station);
            station_to_hypertube[station].push_back(i);
        }
    }
    cout<<bfs(hypertube_to_station, station_to_hypertube, visit_station, visit_hypertube, N);
}