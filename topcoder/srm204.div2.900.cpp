#include<iostream>
#include<vector>
#include<map>
#include<math.h>

using namespace std;

class Apothecary{
public:
    vector<int> balance(int W){
        //// (1) check about how many objects are needed to measure the weight
        // proposition:
        //   x can be represented just by {i_1, ..., i_n}
        //    s.t \sum_{i=1}^{n-1}3^i < x <= \sum_{i=1}^{n}3^i
        int sum=0, N=0;
        while(sum < W){ sum += (int)pow(3, N++); }

        //// (2) create dictionary
        // key: \sum_{i=0}^{n}(3^i * \delta(bits[i]=1))
        //      s.t. \delta takes 1 if given condition would satisfied, or takes 0.
        // value: a condition of bits
        map<int,int> dict;
        for(int i=0; i < (1 << N); ++i){
            int sum = 0;
            for(int j=0; j<=N; ++j){
                if( i & (1 << j) ){ sum += pow(3, j); }
            }
            dict[ sum ] = i;
        }

        //// (3) balance the apothecary
        // these two variables represent the presences of items using N-bits (from right)
        int pLeft = 0, pRight = 0;
        // these two variables represent the weight of a side, respectivily
        int wLeft = W, wRight = 0;
        // using reverse_iterator,
        // scan dictionary from the recode having largest key to the one having smallest key
        map<int,int>::reverse_iterator i = dict.rbegin();
        while( wLeft != wRight ){
            if( wLeft < wRight ){
                // proceeeding until left side has more weight than right side
                for(; i->first + wLeft >= wRight && i != dict.rend(); ++i){}
                i--;
                // ##### why can we know that the bits used by i->first haven't used yet ?? #####
                wLeft += i->first;
                pLeft |= i->second;
            }else{
                for(; i->first + wRight >= wLeft && i != dict.rend(); ++i){}
                i--;
                // ##### why can we know that the bits used by i->first haven't used yet ?? #####
                wRight += i->first;
                pRight |= i->second;
            }
        }

        //// (3) create a vector representing items
        vector<int> items;
        for(int i=N-1; i>=0; --i){
            if( pLeft & (1<<i) ){ items.push_back( -(int)pow(3,i) ); }
        }
        for(int i=0; i<N; ++i){
            if( pRight & (1<<i) ){ items.push_back( (int)pow(3,i) ); }
        }

        return items;
    };
};

int main(){
    Apothecary ap = Apothecary();
    for(int i=0; i<100; ++i){
        vector<int> items = ap.balance(i);
        printf("%d:\t", i);
        int right=0, left=i;
        for(int j=0; j<items.size(); ++j){
            printf("%d, ", items[j]);
            if(items[j]>0){
                right += items[j];
            }else{
                left -= items[j];
            }
        }
        printf("\t::%d=%d\n", left, right);
    }
}
