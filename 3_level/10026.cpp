/* 적록색약 */
// 23.07.25
// https://www.acmicpc.net/problem/10026

#include<iostream>
#include<stack>
#define MAX 101
using namespace std;
string RGB[MAX];
bool visited[MAX][MAX] = {0, };
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int N;



void DFS(int y, int x){
    stack<pair<int, int>> color;
    visited[y][x] = true;
    color.push({y, x});

    while(!color.empty()){
        int curY = color.top().first;
        int curX = color.top().second;
        color.pop();

        for(int i = 0; i < 4; i++){
            int nextY = curY + dy[i];
            int nextX = curX + dx[i];
            if (nextX < 0 || nextX >= N || nextY < 0 || nextY >= N){
                continue;
            }

            if(visited[nextY][nextX] == false && RGB[nextY][nextX] == RGB[y][x]){
                visited[nextY][nextX] = true;
                color.push({nextY, nextX});
            }
        }    
    }
}


int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> RGB[i];
    }

    int common_cnt = 0;
    for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (visited[i][j] == false) {
				DFS(i, j);
                common_cnt++;
			}
		}
	}

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (RGB[i][j] == 'G'){
                RGB[i][j] = 'R';
            }
            visited[i][j] = {0, };
        }
    }

    int redgreen_cnt = 0;
    for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (visited[i][j] == false) {
				DFS(i, j);
                redgreen_cnt++;
			}
		}
	}

    cout << common_cnt <<"\n" << redgreen_cnt << endl;
}