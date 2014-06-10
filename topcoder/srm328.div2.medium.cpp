#include<iostream>
#include<vector>
#include<queue>
#include<string>
#include<string.h>
#include<stdlib.h>

using namespace std;

class LightsCube{
public:
    struct Light{ int x, y, z, color; };
    vector <int> count(int N, vector <string> lights){
        vector<int> colors;
        queue<Light> edge;
        bool ***cube;

        // initialize cube that storing the statuses of lights
        cube = (bool***)malloc(sizeof(bool**) * N);
        for(int i=0; i<N; ++i){
            cube[i] = (bool**)malloc(sizeof(bool*) * N);
            for(int j=0; j<N; ++j){
                cube[i][j] = (bool*)malloc(sizeof(bool) * N);
                memset(cube[i][j], false, sizeof(cube[i][j]));
            }
        }

        // turn on the lights given as an argument,
        // push them into queue named edge
        // and count thiers color
        for(int i=0, M=(int)lights.size(); i<M; ++i){
            const char* pos = lights[i].c_str();
            int x = atoi(&pos[0]),
                y = atoi(&pos[2]),
                z = atoi(&pos[4]);
            cube[x][y][z] = true;
            Light l = {x, y, z, i};
            edge.push(l);
            colors.push_back(1);
        }

        // search w/ queue
        while( !edge.empty() ){
            Light l = edge.front();
            edge.pop();
            if(l.x+1 < N && !cube[l.x+1][l.y][l.z]){
                cube[l.x+1][l.y][l.z] = true;
                Light nl = {l.x+1, l.y, l.z, l.color};
                ++colors[l.color];
                edge.push(nl);
            }
            if(0 <= l.x-1 && !cube[l.x-1][l.y][l.z]){
                cube[l.x-1][l.y][l.z] = true;
                Light nl = {l.x-1, l.y, l.z, l.color};
                ++colors[l.color];
                edge.push(nl);
            }
            if(l.y+1 < N && !cube[l.x][l.y+1][l.z]){
                cube[l.x][l.y+1][l.z] = true;
                Light nl = {l.x, l.y+1, l.z, l.color};
                ++colors[l.color];
                edge.push(nl);
            }
            if(0 <= l.y-1 && !cube[l.x][l.y-1][l.z]){
                cube[l.x][l.y-1][l.z] = true;
                Light nl = {l.x, l.y-1, l.z, l.color};
                ++colors[l.color];
                edge.push(nl);
            }
            if(l.z+1 < N && !cube[l.x][l.y][l.z+1]){
                cube[l.x][l.y][l.z+1] = true;
                Light nl = {l.x, l.y, l.z+1, l.color};
                ++colors[l.color];
                edge.push(nl);
            }
            if(0 <= l.z-1 && !cube[l.x][l.y][l.z-1]){
                cube[l.x][l.y][l.z-1] = true;
                Light nl = {l.x, l.y, l.z-1, l.color};
                ++colors[l.color];
                edge.push(nl);
            }
        }

        return colors;
    };
};

int main(){
    LightsCube lb = LightsCube();
    const char* pos[] = {"0 2 4", "2 0 0", "3 4 4", "4 1 2"};
    vector<string> posstr(pos, pos + (int) sizeof(pos) / sizeof(char*));
    vector<int> colors = lb.count(5, posstr);
    for(int i=0,M=(int)colors.size(); i<M; ++i) cout << colors[i] << " ";
    cout << endl;
}
