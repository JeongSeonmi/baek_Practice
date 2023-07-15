/* 토마토 */
// 23.07.15
// https://www.acmicpc.net/problem/7576

#include<iostream>
#include<queue>
#define MAX 1001
using namespace std;
queue <pair<int, int>> q;
int tomato[MAX][MAX];
int visit[MAX][MAX] = {0, };
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int M, N, day = 0;  //가로, 세로, 날짜

void bfs(){
    while(!q.empty()){
        int curX = q.front().first;
        int curY = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++){
            int nextX = curX + dx[i];
            int nextY = curY + dy[i];
            if(0 <= nextX && 0 <= nextY && nextX < N && nextY < M && visit[nextX][nextY] == 0 && tomato[nextX][nextY] == 0){
                q.push({nextX, nextY});
                visit[nextX][nextY] = visit[curX][curY] + 1;
                tomato[nextX][nextY] = 1;
            }
        }    
    }
} 

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    cin >> M >> N; 
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> tomato[i][j];
            if(tomato[i][j] == 1){
                q.push({i, j});  //익은 토마토(1)가 있으면 queue에 먼저 저장
            }
        }
    }

    bfs();  //저장 후에 bfs 돌리기 -> 익은 토마토(1)에서 시작하기 위해?

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(tomato[i][j] == 0){  //안익은 토마토가 있으면 -1출력
                cout << -1 << endl;
                return 0;
            }
            if (day < visit[i][j]){
                day = visit[i][j];
            }
        }
    }
    cout << day << endl;
}