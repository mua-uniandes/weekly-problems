#include <bits/stdc++.h>
#include <cmath>
#define INF 0xffffff

using namespace std;

double adjmatrix[210][210];

void preprocess(){
    for(int i = 0; i < 210; i++){
        for(int j = 0; j < 210; j++){
            adjmatrix[i][j] = INF;
        }
    }
}

struct point{
    int x, y;  
};

double dist(point a, point b){
    double answer;
    int deltax = abs(a.x - b.x);
    int deltay = abs(a.y - b.y);
    int newdx = pow(deltax, 2);
    int newdy = pow(deltay, 2);
    answer = (double)newdx + (double)newdy;
    return sqrt(answer);
}

int main(){
    int numstones;
    point aux;
    int caso = 1;
    while(true){
        scanf("%d", &numstones);
        if(numstones == 0){
            break;
        }
        preprocess();
        vector<point> pedras;
        for(int i = 0; i < numstones; i++){
            scanf("%d %d", &aux.x, &aux.y);
            pedras.push_back(aux);
        }
        //agora tem que montar a matrix de adjacencia nessa misera
        for(int i = 0; i < (int)pedras.size() - 1; i++){
            for(int j = i + 1; j < (int)pedras.size(); j++){
                adjmatrix[i][j] = min(adjmatrix[i][j], dist(pedras[i], pedras[j]));
                adjmatrix[j][i] = adjmatrix[i][j];
            }
        }
        for(int k = 0; k < numstones; k++){
            for(int i = 0; i < numstones; i++){
                for(int j = 0; j < numstones; j++){
                    adjmatrix[i][j] = min(adjmatrix[i][j], max(adjmatrix[i][k], adjmatrix[k][j]));
                }
            }
        }
        printf("Scenario #%d\n", caso);
        printf("Frog Distance = %.3lf\n", adjmatrix[0][1]);
        caso++;
        printf("\n");
    }
    
    return 0;
}