#include<iostream>
#include<vector>
#include<queue>
#include<stdlib.h>
#include<string.h>
#include<math.h>

using namespace std;

class SmoothNumbersHard{
private:
    bool isPrime(int i){
        for(int j=2, j_end=(int)floor(sqrt(i)); j<=j_end; ++j){
            if( !(i % j) ){ return false; }
        }
        return true;
    };

public:
    int countSmoothNumbers(int N, int k){
        vector<int> primes;
        for(int i=2; (i<=k) and (i<=N); ++i){
            if( isPrime(i) ){ primes.push_back(i); }
        }

        vector<bool> memo(N+1);
        int ret = 1;
        queue<int> que;
        que.push(1);
        while( !que.empty() ){
            int i = que.front();
            que.pop();
            for(int j=0, j_end=primes.size(); j<j_end; ++j){
                unsigned int q = i * primes[j];
                if( (q <= (unsigned int)N) and !memo[q] ){
                    ++ret;
                    memo[q] = true;
                    que.push(q);
                }
            }
        }

        return ret;
    };
};

int main(){
    SmoothNumbersHard snh;
    int N, K, ans, ret;

    N = 10;
    K = 3;
    ret = snh.countSmoothNumbers(N,K);
    ans = 7;
    printf("snk.countSmoothNumbers(%d,%d) returns %d (a correct answer is %d)\n", N, K, ret, ans);

    N = 10;
    K = 4;
    ans = 7;
    ret = snh.countSmoothNumbers(N,K);
    printf("snk.countSmoothNumbers(%d,%d) returns %d (a correct answer is %d)\n", N, K, ret, ans);

    N = 15;
    K = 3;
    ans = 8;
    ret = snh.countSmoothNumbers(N,K);
    printf("snk.countSmoothNumbers(%d,%d) returns %d (a correct answer is %d)\n", N, K, ret, ans);

    N = 5;
    K = 20;
    ans = 5;
    ret = snh.countSmoothNumbers(N,K);
    printf("snk.countSmoothNumbers(%d,%d) returns %d (a correct answer is %d)\n", N, K, ret, ans);

    N = 123456;
    K = 123;
    ans = 23855;
    ret = snh.countSmoothNumbers(N,K);
    printf("snk.countSmoothNumbers(%d,%d) returns %d (a correct answer is %d)\n", N, K, ret, ans);

    N = 4000000;
    K = 33;
    ans = 33073;
    ret = snh.countSmoothNumbers(N,K);
    printf("snk.countSmoothNumbers(%d,%d) returns %d (a correct answer is %d)\n", N, K, ret, ans);

    N = 4123654;
    K = 123;
    ans = 215681;
    ret = snh.countSmoothNumbers(N,K);
    printf("snk.countSmoothNumbers(%d,%d) returns %d (a correct answer is %d)\n", N, K, ret, ans);

    N = 5000000;
    K = 1000;
    ans = 1196525;
    ret = snh.countSmoothNumbers(N,K);
    printf("snk.countSmoothNumbers(%d,%d) returns %d (a correct answer is %d)\n", N, K, ret, ans);

}
