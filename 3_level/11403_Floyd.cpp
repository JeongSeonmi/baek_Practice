/* 경로 찾기 */
// 23.08.05
// https://www.acmicpc.net/problem/11403

#include<iostream>
#include<algorithm>
#define MAX 101
using namespace std;
int graph[MAX][MAX];

int main(){
    int N;
    cin >> N;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            cin >> graph[i][j];
        }
    }

    for(int k = 1; k <= N; k++){
        for(int i = 1; i <= N; i++){
            for(int j = 1; j <= N; j++){
                if(graph[i][k] && graph[k][j]){
                    graph[i][j] = 1;
                }
            }
        }
    }

    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            cout << graph[i][j] << " ";
        }
        cout << "\n";
    }

}