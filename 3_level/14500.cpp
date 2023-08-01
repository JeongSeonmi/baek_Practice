/* ��Ʈ�ι̳� */
// 23.08.01
// https://www.acmicpc.net/problem/14500

#include<iostream>
#include<algorithm>
#define MAX 501
using namespace std;
int arr[MAX][MAX];
bool visited[MAX][MAX] ={0, };
int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};
int N, M, result = 0;

void DFS(int y, int x, int cnt, int sum){
    if(cnt == 3){
       if(result < sum){
        result = sum; 
       }
        return;
    }
    for(int i = 0; i < 4; i++){
        int nextY = y + dy[i];
        int nextX = x + dx[i];
        if(nextY < 0 || nextY > N || nextX < 0 || nextX > M) continue;
        if(visited[nextY][nextX]) continue;
        visited[nextY][nextX] = true;
        DFS(nextY, nextX, cnt + 1, sum + arr[nextY][nextX]); // �ִ밪�� �Ǵ� ����� �ǵ���
        visited[nextY][nextX] = false;
    }

    /* ����� ���߾ �ä��Ǥ̶� ���ؼ� ���� ū ��� ���� */
    if(y - 1 >= 0 && y + 1 < N && x - 1 >= 0){ //��
        result = max(result, (arr[y-1][x] + arr[y][x] + arr[y][x-1] + arr[y+1][x]));
    }
    if(y - 1 >= 0 && y + 1 < N && x + 1 < M){ //��
        result = max(result, (arr[y-1][x] + arr[y][x] + arr[y][x+1] + arr[y+1][x]));
    }
    if(y - 1 >= 0 && x - 1 >= 0 && x + 1 < M){ //��
        result = max(result, (arr[y-1][x] + arr[y][x] + arr[y][x-1] + arr[y][x+1]));
    }
    if(y + 1 < N && x - 1 >= 0 && x + 1 < M){ //��
        result = max(result, (arr[y][x-1] + arr[y][x] + arr[y][x+1] + arr[y+1][x]));
    }
}

int main(){
    cin >> N >> M;  // ���� ����
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> arr[i][j];
        }
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(visited[i][j] == 0){
                visited[i][j] = true;
                DFS(i, j, 0, arr[i][j]);    //���� ����� ����
                visited[i][j] = false;
            }
        }
    }

    cout << result << endl;

    return 0;
}