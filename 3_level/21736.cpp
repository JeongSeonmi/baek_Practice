/* 헌내기는 친구가 필요해 */
// 23.07.29
// https://www.acmicpc.net/problem/21736

#include<iostream>
#include<stack>
#define MAX 601
using namespace std;
stack<pair<int, int>> st;
char campus[MAX][MAX];
bool visited[MAX][MAX] = {0, };
int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};
int N, M, count = 0;   // y, x

void DFS(){
    while(!st.empty()){
        int curY = st.top().first;
        int curX = st.top().second;
        st.pop();
        for(int i = 0; i < 4; i++){
            int nextY = curY + dy[i];
            int nextX = curX + dx[i];
            if(0 <= nextY && nextY < N && 0 <= nextX && nextX < M && visited[nextY][nextX] == false){
                if(campus[nextY][nextX] == 'X') continue;
                if(campus[nextY][nextX] == 'P'){
                    count++;
                }
                st.push({nextY, nextX});
                visited[nextY][nextX] = true;
            }
        }
    }
}

int main(){
    cin >> N >> M;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> campus[i][j];
            if(campus[i][j] == 'I'){
                st.push({i, j});
                visited[i][j] = true;
            }
        }
    }

    DFS();

    if(count == 0){
        cout << "TT" << endl;
    }
    else{
        cout << count << endl;
    }

    return 0;
}