#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<map>
#include<string>
#include<string.h>
#include<math.h>
#include<queue>

#define MAX(x,y) ( (x)>(y) ? (x) : (y) )
#define MIN(x,y) ( (x)<(y) ? (x) : (y) )

using namespace std;

int N,C,F;

bool comp(pair<int, int>& a, pair<int, int>& b){
    return a.first < b.first;
}
int main(int argc, char** argv){
    cin >> N >> C >> F;
    vector<pair<int, int> > cow(C+1);
    for(int i=1; i<=C; i++){
        cin >> cow[i].first >> cow[i].second;
    }

    // The main strategy;
    // examine the cows from the one that has most greater CSAR
    // to the one having the smaller score

    // At first, sort cows in CSAT order
    sort(cow.begin()+1, cow.end(), comp);

    // Second; construct an array that stores the minimum value of
    // summations of (N>>1) greater(or smaller) values than cow[i].second,
    vector<int> sum_greaters(C+1), sum_smallers(C+1), temp(N>>1);
    priority_queue<int, vector<int>, greater<int> > greaters, smallers;
    // cout << "-----------" << endl;
    for(int i=1; i<=C; i++){
        smallers.push(cow[i].second);
        if(smallers.size() < (N>>1)){ continue; }
        for(int j=0; j<(N>>1); j++){
            temp[j] = smallers.top();
            sum_smallers[i] += smallers.top();
            smallers.pop();
        }
        for(int j=0; j<(N>>1); j++){ smallers.push(temp[j]); }
        // cout << sum_smallers[i] << endl;
    }
    // cout << "-----------" << endl;
    for(int i=C; i>=1; i--){
        greaters.push(cow[i].second);
        if(greaters.size() < (N>>1)){ continue; }
        for(int j=0; j<(N>>1); j++){
            temp[j] = greaters.top();
            sum_greaters[i] += greaters.top();
            greaters.pop();
        }
        for(int j=0; j<(N>>1); j++){ greaters.push(temp[j]); }
        // cout << sum_greaters[i] << endl;
    }
    // cout << "-----------" << endl;

    // ex; N=3,C=7 then, (N+1)>>1 is 2, and C-(N>>1) is 6
    // ex; N=5,C=7 then, (N+1)>>1 is 3, and C-(N>>1) is 5
    for(int i=(C-(N>>1)); i>=((N+1)>>1); i--){
        if(cow[i].second + sum_greaters[i+1] + sum_smallers[i-1] <= F){
            cout << cow[i].first << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}

