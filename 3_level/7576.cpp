/* �丶�� */
// 23.07.18
// https://www.acmicpc.net/problem/7576

#include<iostream>
#include<queue>
#define MAX 1001
using namespace std;
queue <pair<int, int>> q;
int tomato[MAX][MAX];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int M, N, day = 0;  //����, ����, ��¥

void bfs(){    //��ī��Ʈ ��ǥ���� ����� ǥ��
    while(!q.empty()){
        int curY = q.front().first;
        int curX = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++){
            int nextY = curY + dx[i];
            int nextX = curX + dy[i];
            if(0 <= nextY && 0 <= nextX && nextY < N && nextX < M && tomato[nextY][nextX] == 0){
                q.push({nextY, nextX});
                tomato[nextY][nextX] = tomato[curY][curX] + 1;
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

    bfs();  //���� �Ŀ� bfs ������ -> ���� �丶��(1)���� �����ϱ� ����

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(tomato[i][j] == 0){  //������ �丶�䰡 ������ -1���
                cout << -1 << endl;
                return 0;
            }
            if (day < tomato[i][j]){
                day = tomato[i][j];
            }
        }
    }
    cout << day - 1 << endl;    //tomato�� ������ ��� ���� 1�̾��� �� + 1 �Ͽ� ����� ���̹Ƿ� -1
}

