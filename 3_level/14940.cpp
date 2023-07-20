/* 쉬운 최단거리 */
// 23.07.20
// https://www.acmicpc.net/problem/14940

#include<iostream>
#include<queue>
#define MAX 1001
using namespace std;
queue<pair<int, int>> q;
int map[MAX][MAX];
int count[MAX][MAX] = {0, };
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int n, m;   //n : 세로, m : 가로

void BFS(){
    while(!q.empty()){
        int curY = q.front().first;
        int curX = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++){
            int nextY = curY + dx[i];
            int nextX = curX + dy[i];
            if(0 <= nextY && 0 <= nextX && nextY < n && nextX < m && map[nextY][nextX] == 1 && count[nextY][nextX] == 0){
                q.push({nextY, nextX});
                count[nextY][nextX] = count[curY][curX] + 1;
            }
        }
    }
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> map[i][j];
            if(map[i][j] == 2){
                q.push({i, j});
            }
        }
    }
    BFS();

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(map[i][j] == 1 && count[i][j] == 0){
                cout << "-1 ";
            }
            else cout << count[i][j] << " ";
        }
        cout << "\n";
    }
}