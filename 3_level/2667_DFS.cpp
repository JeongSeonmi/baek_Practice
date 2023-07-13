/* 단지번호 붙이기 */
// 23.07.13
// https://www.acmicpc.net/problem/2667

#include<iostream>
#include<algorithm>
#include<stack>
#define MAX 26
using namespace std;
string arr[MAX];
stack<pair<int, int>> s;
bool visited[MAX][MAX] ={0, };
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int N, cnt = 0; //지도의 크기

/*
void DFS(int x, int y){
    visited[x][y] = true;
    cnt++;
    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(0 <= nx && 0 <= ny && nx < N && ny < N && visited[nx][ny] == false && arr[nx][ny] == '1'){
            DFS(nx ,ny);
        }
    }
}
*/

void DFS(int x, int y){
    visited[x][y] = true;
    s.push({x, y});
    cnt++;
    while(!s.empty()){
        int curX = s.top().first;
        int curY = s.top().second;
        s.pop();
        for(int i = 0; i < 4; i++){
            int nx = curX + dx[i];
            int ny = curY + dy[i];
            if(0 <= nx && 0 <= ny && nx < N && ny < N && visited[nx][ny] == false && arr[nx][ny] == '1'){
                s.push({nx, ny});
                visited[nx][ny] = true;
                cnt++;
            }
        }    
    }
}

int main(){
    int s = 0;
    int complex[625] = {0, };
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(visited[i][j] == false && arr[i][j] == '1'){
                cnt = 0;
                DFS(i, j);
                complex[s++] = cnt;
            }
        }
    }

    sort(complex, complex + s);

    printf("%d\n", s);
    for(int i = 0; i < s; i++){
        printf("%d\n", complex[i]);
    }
}