/* �丶�� */
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
int M, N, day = 0;  //����, ����, ��¥

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
                q.push({i, j});  //���� �丶��(1)�� ������ queue�� ���� ����
            }
        }
    }

    bfs();  //���� �Ŀ� bfs ������ -> ���� �丶��(1)���� �����ϱ� ����?

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(tomato[i][j] == 0){  //������ �丶�䰡 ������ -1���
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