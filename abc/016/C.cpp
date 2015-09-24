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

int main(int argc, char** argv){
    int n,m,a,b;
    scanf("%d %d", &n, &m);
    vector< set<int> > G(n+1);
    for(int i=1; i<=n; i++){
        G[i].insert(i);
    }
    for(int i=0; i<m; i++){
        scanf("%d %d", &a, &b);
        G[a].insert(b);
        G[b].insert(a);
    }

    for(int i=1; i<=n; i++){
        set<int>::iterator it = G[i].begin(), it_end = G[i].end();
        for(; it != it_end; it++){
            cout << *it << " ";
        }
        cout << endl;
    }


    for(int i=1; i<=n; i++){
        set<int>::iterator it = G[i].begin(), it_end = G[i].end();
        int ret=0;
        set<int> temp;
        for(; it != it_end; it++){
            set_intersection(
                    G[*it].begin(), G[*it].end(),
                    temp.begin(), temp.end(),
                    // G[i].begin(), G[i].end(),
                    back_inserter(temp));
        }
        cout << ret << endl;
    }

    return 0;
}
