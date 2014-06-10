#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<math.h>

#define N 12
#define min(a,b) (a > b ? b : a)

using namespace std;

class TableSeating{
public:
    double getExpected(int numTables, vector<int> probs){
        double expect[N+1] = {0,};

        int sum=0;
        for(int i=0; i < probs.size(); ++i){ sum += probs[i]; }
        if(sum != 100){ printf("warning: incorrect probs.\n"); }

        for(int t=1; t <= numTables; ++t){
            for(int c = min(t, probs.size()); c > 0; --c){
                int nPat = t - c + 1;
                double p = (probs[c - 1] / 100.0) * (1. / nPat);
                for(int i = 0; i <= t - c; ++i){
                    expect[t] += p * ( expect[i] + c + expect[ t - ( i + c ) ] );
                }
            }
        }

        for(int i=1; i<=numTables; ++i) printf("%lf ", expect[i]);
        cout << endl;

        return expect[numTables];
    };
};

int main(){
    TableSeating ts = TableSeating();
    vector<int> probs;

    probs.clear();
    probs.push_back(100);
    cout << ts.getExpected(4, probs) << endl;

    probs.clear();
    probs.push_back(0);
    probs.push_back(100);
    cout << ts.getExpected(4, probs) << endl;

    probs.clear();
    probs.push_back(0);
    probs.push_back(0);
    probs.push_back(0);
    probs.push_back(0);
    probs.push_back(0);
    probs.push_back(50);
    probs.push_back(50);
    cout << ts.getExpected(5, probs) << endl;

    probs.clear();
    probs.push_back(9);
    probs.push_back(9);
    probs.push_back(9);
    probs.push_back(9);
    probs.push_back(9);
    probs.push_back(9);
    probs.push_back(9);
    probs.push_back(9);
    probs.push_back(9);
    probs.push_back(9);
    probs.push_back(10);
    cout << ts.getExpected(12, probs) << endl;
}
