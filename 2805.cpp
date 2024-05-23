#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void init(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main(){
    init();
    int N, M;
    cin>>N>>M;
    vector<int>tree(N);

    for(int i = 0; i < N; ++i){
        cin>>tree[i];
    }

    int max = *max_element(tree.begin(), tree.end());
    int min = 0;
    int cut = (max + min) / 2;

    while(max >= min){
        long long sum = 0;
        for(int v : tree){
            if(v > cut){
                sum += v - cut;
            }
        }

        if(sum >= M){
            min = cut + 1;
        }
        else{
            max = cut - 1;
        }
        cut = (max + min) / 2;
    }
    cout<<max;
}