/* ������ȣ ���̱� */
// 23.07.13
// https://www.acmicpc.net/problem/2667

#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#define MAX 26
using namespace std;
string arr[MAX];
bool visited[MAX][MAX] ={0, };
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
vector<int>complex;
queue<pair<int, int>> q;
int N, cnt = 0; //������ ũ��

void BFS(int x, int y){
    visited[x][y] = true;
    q.push({x, y}); //�߰�ȣ�� make_pair ��ü ����
    cnt++;
    while(!q.empty()){
        int curX = q.front().first;
        int curY = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++){
            int nx = curX + dx[i];
            int ny = curY + dy[i];
            if(0 <= nx && 0 <= ny && nx < N && ny < N && visited[nx][ny] == false && arr[nx][ny] == '1'){
                q.push({nx, ny});
                visited[nx][ny] = true;
                cnt++;
            }
        }
    }
}

int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(visited[i][j] == false && arr[i][j] == '1'){
                cnt = 0;
                BFS(i, j);
                complex.push_back(cnt);
            }
        }
    }

    sort(complex.begin(), complex.end());

    cout << complex.size() << endl;
    for(int i = 0; i < complex.size(); i++){
        cout << complex[i] << endl;
    }

}