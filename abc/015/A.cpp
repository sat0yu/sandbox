// #include<iostream>
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
    string A,B;
    cin >> A >> B;
    if(A.size() > B.size()){
        cout << A << endl;
    }else{
        cout << B << endl;
    }
    return 0;
}
