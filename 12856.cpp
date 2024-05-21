#include <iostream>
#include <vector>
using namespace std;

void init(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main(){
    init();
    int N, K;
    cin>>N>>K;
    vector<pair<int, int>>input(N);
    
    for(int i = 0; i < N; ++i){
        cin>>input[i].first>>input[i].second;
    }

    int dp[N+1][K+1];
    for(int i = 0; i <= K; ++i){
        dp[0][i] = 0;
    }

    for(int i = 0; i <= N; ++i){
        dp[i][0] = 0;
    }

    for(int i = 1; i <= N; ++i){
        for(int r = 1; r <= K; ++r){
            if(input[i-1].first <= r && dp[i-1][r - input[i-1].first] + input[i-1].second > dp[i-1][r]){
                dp[i][r] = dp[i-1][r - input[i-1].first] + input[i-1].second;
            }
            else{
                dp[i][r] = dp[i-1][r];
            }
        }
    }
    cout<<dp[N][K];
}