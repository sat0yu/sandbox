#include<iostream>
#include<vector>
#include<iterator>
#include<numeric>
#include<algorithm>

using namespace std;

class BridgeCrossing{
private:
    vector< vector<int> > combination(vector<int> target, int k){
        vector< vector<int> > combs;
        for(unsigned char i = (1 << target.size()) - 1; i > 0; --i){
            int num=0;
            for(int mask=1; mask != 0; mask = mask << 1){
                if(i & mask){ ++num; }
            }
            if( num == k ){
                vector<int> comb;
                for(int j=0, size=target.size(); j<size; ++j){
                    if( i & (1 << j) ){ comb.push_back(j); }
                }
                combs.push_back(comb);
            }
        }
        return combs;
    };

    int search(vector<int> S, vector<int> T, int spent_time, int lower_bound){
        if(!(S.size() > 0)){
            return spent_time;
        }else if(S.size() == 1){
            return spent_time + S[0];
        }

        //if(spent_time > lower_bound){ return spent_time; }

        vector< vector<int> > combs = combination(S, 2);
        vector< vector<int> >::iterator comb=combs.begin(), end_comb=combs.end();
        vector<int> times;
        for(; comb!=end_comb; ++comb){
            vector<int> _T(T.size()), _S(S.size());
            copy(S.begin(), S.end(), _S.begin());
            copy(T.begin(), T.end(), _T.begin());

            int go_way = max(_S[ (*comb)[0] ], _S[ (*comb)[1] ]);

            // ADD TO 'T'
            _T.push_back(_S[ (*comb)[0] ]);
            _T.push_back(_S[ (*comb)[1] ]);

            // REMOVE FROM 'S'
            // we have to erase elements using indiced stored in (*comb) from back
            // otherwise, indices get out of right posizions
            for(vector<int>::reverse_iterator idx=(*comb).rbegin(); idx!=(*comb).rend(); ++idx){
                vector<int>::iterator it = _S.begin();
                advance(it, *idx);
                _S.erase(it);
            }

            if(_S.size() > 0){
                for(int j=0, end_j=_T.size(); j<end_j; ++j){
                    vector<int> __T(_T.size()), __S(_S.size());
                    copy(_S.begin(), _S.end(), __S.begin());
                    copy(_T.begin(), _T.end(), __T.begin());

                    __S.push_back(_T[j]);
                    vector<int>::iterator it = __T.begin();
                    advance(it, j);
                    __T.erase(it);

                    times.push_back( search(__S, __T, (spent_time + go_way + _T[j]), lower_bound) );
                }
            }else{
                times.push_back( search(_S, _T, (spent_time + go_way), lower_bound) );
            }
        }

        return *min_element(times.begin(), times.end());
    };

public:
    int minTime(vector<int> times){
        int min_time;

        // culc. naive case
        min_time = ( *min_element(times.begin(), times.end()) ) * (times.size() - 2);
        min_time += accumulate(times.begin(), times.end(), 0);
        min_time -= *min_element(times.begin(), times.end());

        vector<int> T;
        return search(times, T, 0, min_time);
    };
};

int main(){
    BridgeCrossing bc = BridgeCrossing();
    vector<int> times;

    // case 1, ans: 17
    times.clear();
    times.push_back(1);
    times.push_back(2);
    times.push_back(5);
    times.push_back(10);
    cout << bc.minTime(times) << endl;

    // case 2, ans: 16
    times.clear();
    times.push_back(1);
    times.push_back(2);
    times.push_back(3);
    times.push_back(4);
    times.push_back(5);
    cout << bc.minTime(times) << endl;

    // case 3, ans: 162
    times.clear();
    times.push_back(1);
    times.push_back(2);
    times.push_back(3);
    times.push_back(50);
    times.push_back(99);
    times.push_back(100);
    cout << bc.minTime(times) << endl;

    // case 4, ans: 100
    times.clear();
    times.push_back(100);
    cout << bc.minTime(times) << endl;

}
