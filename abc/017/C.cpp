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

vector<int> s;
vector< pair<int,int> > lr;

int main(int argc, char** argv){
    int N, M;
    cin >> N >> M;
    s.resize(N);
    lr.resize(N);
    for(int i=0; i<N; i++){
        cin >> lr[i].first >> lr[i].second >> s[i];
    }
    // sort(lr.begin(), lr.end(), greater<pair<int,int> >());
    sort(lr.begin(), lr.end());

    vector<int> diff(M+1,0);
    vector<int> height(M+1,0);
    for(int i=0; i<N; i++){
        diff[ lr[i].first ]++;
        diff[ lr[i].second+1 ]--;
    }
    int minheight = (1<<20);
    for(int i=1; i<=M; i++){
        height[i] = height[i-1] + diff[i];
        minheight = (minheight < height[i]) ? minheight : height[i];
    }

    for(int i=1; i<=M; i++){
        cout << i << ":" << height[i] << endl;
        if(height[i] == minheight){
        for(int i=0; 
        }
    }


    return 0;
}
