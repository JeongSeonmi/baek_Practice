/* 경로 찾기 */
// 23.08.05
// https://www.acmicpc.net/problem/11403


#include<iostream>
#include<stack>
#define MAX 101
using namespace std;
int graph[MAX][MAX];
int path[MAX][MAX];
int visited[MAX];

void DFS(int start, int N){
    stack<int> s;
    for(int i = 1; i <= N; i++){
        visited[i] = 0;
    }
    s.push(start);

    while(!s.empty()){
        int cur = s.top();
        s.pop();
         for(int i = 1; i <= N; i++){
            if(graph[cur][i] == 0 || visited[i] == 1)
                continue;
            s.push(i);
            path[start][i] = 1;
            visited[i] = 1;
        }
    }
}

int main(){
    int N;
    cin >> N;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            cin >> graph[i][j];    
        }
    }

    for(int i = 1; i <= N; i++){
        DFS(i, N);
    }

    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            cout << path[i][j] << " ";
        }
        cout << "\n";
    }
}