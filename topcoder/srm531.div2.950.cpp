#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<string>

using namespace std;

typedef map<pair<int,int>,int> container;
typedef pair<pair<int,int>,int> value_type;

struct second_order {
    bool operator()(const value_type& x, const value_type& y) const {
        return x.second > y.second;
    }
};

class KingdomReorganization{
private:
    map<char,int> char2int;

public:
    KingdomReorganization(){
        for(int i=0; i<26; ++i){
            char2int['A' + i] = i;
            char2int['a' + i] = i + 26;
        }
    };

    int getCost(vector <string> kingdom, vector <string> build, vector <string> destroy){
        int N = kingdom.size();
        vector< vector<int> > graph(N);
        vector< vector<int> > costs(N);
        map<pair<int,int>, int> edges;

        // calc. costs
        for(int i=0; i<N; ++i){
            graph[i] = vector<int>(N);
            costs[i] = vector<int>(N);
            const char *i_neighbors = kingdom[i].c_str(),
                  *i_build = build[i].c_str(),
                  *i_destroy = destroy[i].c_str();
            for(int j=0; j<N; ++j){
                costs[i][j] = 0;
                if( i != j ){
                    if( i_neighbors[j] == '0' ){
                        costs[i][j] += char2int[ i_build[j] ];
                        graph[i][j] = 0;
                    }else{
                        costs[i][j] += -char2int[ i_destroy[j] ];
                        graph[i][j] = 1;
                    }
                }
            }
        }
        // debug print
        for(int i=0; i<N; ++i){
            for(int j=0; j<N; ++j){ cout << costs[i][j] << "\t"; }
            cout << endl;
        }

        // construct edges
        for(int i=0; i<N; ++i){
            for(int j=i+1; j<N; ++j){
                edges[ pair<int,int>(i,j) ] = costs[i][j];
            }
        }

        // initialize components set
        set<unsigned long long> components;
        for(int i=0; i<N; ++i){ components.insert( (1 << i) ); }

        // calc. minimum spanning tree
        int result = 0;
        priority_queue<value_type, vector<value_type>, second_order> que;
        for(container::iterator i = edges.begin(); i!=edges.end(); ++i){ que.push(*i); }
        while ( !( que.empty() ) ){
            value_type e = que.top();
            que.pop();

            int vi = (e.first).first, vj = (e.first).second;
            unsigned long long i = (1 << vi), j = (1 << vj);

            set<unsigned long long>::iterator c = components.begin(), i_comp, j_comp;
            i_comp = j_comp = components.end();
            bool flg=true;
            for(; c!=components.end(); ++c){
                if( *c & i ){ i_comp = c; }
                if( *c & j ){ j_comp = c; }
                if( (*c & i) and (*c & j) ){ flg=false; }
            }
            if( flg and (i_comp != components.end()) and (j_comp != components.end()) ){
                components.insert( (*i_comp) | (*j_comp) );
                components.erase(i_comp);
                components.erase(j_comp);

                //debug
                cout << "used edge: " << vi << "-" << vj << endl;
                if( graph[ vi ][ vj ] == 0 ){
                    result += e.second;
                }

            }else if( graph[ vi ][ vj ] == 1 ){
                    result -= e.second;
            }
        }

        return result;
    };
};

int main(){
    vector<string> kingdom, build, destroy;
    KingdomReorganization kr;
    int ret;

    kingdom.clear();
    build.clear();
    destroy.clear();
    kingdom.push_back("000");
    kingdom.push_back("000");
    kingdom.push_back("000");
    build.push_back("ABD");
    build.push_back("BAC");
    build.push_back("DCA");
    destroy.push_back("ABD");
    destroy.push_back("BAC");
    destroy.push_back("DCA");
    ret = kr.getCost(kingdom, build, destroy);
    cout << "return: " << ret << endl;

    kingdom.clear();
    build.clear();
    destroy.clear();
    kingdom.push_back("011");
    kingdom.push_back("101");
    kingdom.push_back("110");
    build.push_back("ABD");
    build.push_back("BAC");
    build.push_back("DCA");
    destroy.push_back("ABD");
    destroy.push_back("BAC");
    destroy.push_back("DCA");
    ret = kr.getCost(kingdom, build, destroy);
    cout << "return: " << ret << endl;

    kingdom.clear();
    build.clear();
    destroy.clear();
    kingdom.push_back("011000");
    kingdom.push_back("101000");
    kingdom.push_back("110000");
    kingdom.push_back("000011");
    kingdom.push_back("000101");
    kingdom.push_back("000110");
    build.push_back("ABDFFF");
    build.push_back("BACFFF");
    build.push_back("DCAFFF");
    build.push_back("FFFABD");
    build.push_back("FFFBAC");
    build.push_back("FFFDCA");
    destroy.push_back("ABDFFF");
    destroy.push_back("BACFFF");
    destroy.push_back("DCAFFF");
    destroy.push_back("FFFABD");
    destroy.push_back("FFFBAC");
    destroy.push_back("FFFDCA");
    ret = kr.getCost(kingdom, build, destroy);
    cout << "return: " << ret << endl;

    kingdom.clear();
    build.clear();
    destroy.clear();
    kingdom.push_back("0000000000");
    kingdom.push_back("0000000011");
    kingdom.push_back("0001010000");
    kingdom.push_back("0010010000");
    kingdom.push_back("0000001000");
    kingdom.push_back("0011000000");
    kingdom.push_back("0000100000");
    kingdom.push_back("0000000011");
    kingdom.push_back("0100000101");
    kingdom.push_back("0100000110");
    build.push_back("AhPEqkSFMM");
    build.push_back("hAfKPtsDad");
    build.push_back("PfAyGQkaqN");
    build.push_back("EKyAeLpRpm");
    build.push_back("qPGeASfNwo");
    build.push_back("ktQLSAnCAK");
    build.push_back("SskpfnAdJS");
    build.push_back("FDaRNCdAZz");
    build.push_back("MaqpwAJZAn");
    build.push_back("MdNmoKSznA");
    destroy.push_back("AgTqWWxEYH");
    destroy.push_back("gAXPgjzIRA");
    destroy.push_back("TXAleTmWvT");
    destroy.push_back("qPlAQkwxRO");
    destroy.push_back("WgeQAqgbJJ");
    destroy.push_back("WjTkqAiTzl");
    destroy.push_back("xzmwgiAuHb");
    destroy.push_back("EIWxbTuAwk");
    destroy.push_back("YRvRJzHwAn");
    destroy.push_back("HATOJlbknA");
    ret = kr.getCost(kingdom, build, destroy);
    cout << "return: " << ret << endl;
}
