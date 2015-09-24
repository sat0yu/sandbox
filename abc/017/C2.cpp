#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<string>
#include<math.h>

#define MAX(x,y) ( (x)>(y) ? (x) : (y) )
#define MIN(x,y) ( (x)<(y) ? (x) : (y) )

using namespace std;

int N, M;
vector<int> s;
vector< pair<int,int> > lr;

vector<unsigned long long> bits;
int dfs(int i, unsigned long long b, int score){
    unsigned long long mask = ( (1<<(lr[i].second - lr[i].first+1)) - 1 ) << (64-lr[i].first);
    dfs(i+1, (b | mask), score + s[i]);
    dfs(i+1, b, score);
}

int main(int argc, char** argv){
    cin >> N >> M;
    s.resize(N);
    lr.resize(N);
    for(int i=0; i<N; i++){
        cin >> lr[i].first >> lr[i].second >> s[i];
    }
    sort(lr.begin(), lr.end());

    cout << dfs(0, 0ULL, 0) << endl;

    return 0;
}
