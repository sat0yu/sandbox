#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<map>
#include<string>
#include<math.h>

#define MAX(x,y) ( (x)>(y) ? (x) : (y) )
#define MIN(x,y) ( (x)<(y) ? (x) : (y) )

using namespace std;

int main(int argc, char** argv){
    string name;
    cin >> name;
    int size = name.size();
    for(int i=0; i<size/2; i++){
        if(name[i] != name[size-1-i]){
            cout << "NO" << endl;;
            return 0;
        }
    }
    cout << "YES" << endl;;

    return 0;
}
