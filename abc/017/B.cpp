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

string S;

bool isChock(int i){
    if(i>=S.size()){
        return true;
    }else if(S[i] == 'o'){
        return isChock(i+1);
    }else if(S[i] == 'k'){
        return isChock(i+1);
    }else if(S[i] == 'u'){
        return isChock(i+1);
    }else if(S[i] == 'c' and ( ( i+1 < S.size() ) and S[i+1] == 'h')){
        return isChock(i+2);
    }else{
        return false;
    }
}

int main(int argc, char** argv){
    cin >> S;
    if(isChock(0)){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
    return 0;
}
