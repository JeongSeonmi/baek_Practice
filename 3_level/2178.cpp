/* 미로 탐색 */
// https://www.acmicpc.net/problem/2178

#include<iostream>
#include<queue>
#include<string.h>
using namespace std;
int N, M;  //세로, 가로
string arr[101];
//bool visit[101][101] = {false, };
int visit[101][101];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

void bfs(int x, int y){
    visit[x][y] = 1;
    queue <pair<int, int>> q;
    q.push(make_pair(x, y));
    while(!q.empty()){
        int x = q.front().first; //tie(x, y) = q.front();
        int y = q.front().second; 
        q.pop();
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if( nx >=0 && ny >=0 && nx < N && ny < M && arr[nx][ny] == '1' && visit[nx][ny] == 0){
                q.push(make_pair(nx, ny));
                visit[nx][ny] = visit[x][y] + 1;
                
            }
        }

    }
}

int main(){
    cin >> N >> M;
    for (int i = 0; i < N; i++){
            cin >> arr[i];
    }

    bfs(0, 0);
    cout << visit[N-1][M-1] << endl;
    return 0;
}
