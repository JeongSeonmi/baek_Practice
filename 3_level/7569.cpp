/* ≈‰∏∂≈‰ */
// 23.07.26
// https://www.acmicpc.net/problem/7569

#include <iostream>
#include <queue>
using namespace std;
#define MAX 101
int tomato[MAX][MAX][MAX];
int dz[6] = {1, -1, 0, 0, 0, 0};
int dy[6] = {0, 0, 1, -1, 0, 0};
int dx[6] = {0, 0, 0, 0, 1, -1};
queue<pair<pair<int, int>, int>> ripen;
int N, M, H;

void BFS() {
    while(!ripen.empty()){
        int curY = ripen.front().first.first;
        int curX = ripen.front().first.second;
        int curZ = ripen.front().second;
        ripen.pop();
        for(int i = 0; i < 6; i++){
            int nextY = curY + dy[i];
            int nextX = curX + dx[i];
            int nextZ = curZ + dz[i];
            if(nextY >= 0 && nextY < N && nextX >= 0 && nextX < M && nextZ >= 0 && nextZ < H && tomato[nextZ][nextY][nextX] == 0){
                ripen.push({{nextY, nextX}, nextZ});
                tomato[nextZ][nextY][nextX] = tomato[curZ][curY][curX] + 1;
            }
        }
    }
}

int main() {
    cin >> M >> N >> H;

    for(int i = 0; i < H; i++){
        for(int j = 0; j < N; j++){
            for(int k = 0; k < M; k++){
                cin >> tomato[i][j][k];
                if (tomato[i][j][k] == 1){
                    ripen.push({{j, k}, i});
                }
            }
        }
    }

    BFS();

    int day = 0;
    for(int i = 0; i < H; i++){
        for(int j = 0; j < N; j++){
            for(int k = 0; k < M; k++){
                if(tomato[i][j][k] == 0){
                    cout << -1 << endl;
                    return 0;
                }

                if(day < tomato[i][j][k]){
                    day = tomato[i][j][k];
                }
            }
        }
    }

    cout << day - 1 << endl;
    return 0;
}   