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
    // ex; N=3,C=7 then, (N+1)>>1 is 2, and C-(N>>1) is 6
    // ex; N=5,C=7 then, (N+1)>>1 is 3, and C-(N>>1) is 5
    for(int i=(C-(N>>1)); i>=((N+1)>>1); i--){
        priority_queue<int, vector<int>, greater<int> > greaters, smallers;
        int sum_smallers=0, sum_greaters=0;
        vector<int> temp(N>>1);
        for(int j=i-1; j>=1; j--){
            smallers.push(cow[j].second);
            if( smallers.size() < (N>>1) ){continue;}
            for(int k=0; k<(N>>1); k++){
                sum_smallers += smallers.top();
                temp[k] = smallers.top();
                smallers.pop();
            }
            if(cow[i].second + sum_smallers > F){break;}
            for(int k=0; k<(N>>1); k++){ smallers.push(temp[k]); }
            sum_smallers = 0;
        }
        for(int j=i+1; j<=C; j++){
            greaters.push(cow[j].second);
            if( greaters.size() < (N>>1) ){continue;}
            for(int k=0; k<(N>>1); k++){
                sum_greaters += greaters.top();
                temp[k] = greaters.top();
                greaters.pop();
            }
            if(cow[i].second + sum_greaters > F){break;}
            for(int k=0; k<(N>>1); k++){ greaters.push(temp[k]); }
            sum_greaters = 0;
        }

        if(cow[i].second + sum_greaters + sum_smallers <= F){
            cout << cow[i].first << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}

