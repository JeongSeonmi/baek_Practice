/* 숨바꼭질 */
// 23.07.17
// https://www.acmicpc.net/problem/1697

#include<iostream>
#include<queue>
#define MAX 100001
using namespace std;

queue<pair<int, int>> q;
bool visit[MAX] = {0, };
int N, K, time = 0;   //수빈이 위치, 동생 위치

int main(){
    cin >> N >> K;
    /*bfs*/
    visit[N] = true;
    q.push({N, 0});
    while(!q.empty()){
        int N = q.front().first;
        int time = q.front().second;
        q.pop();
        if(N == K){
            cout << time << endl;
            break;
        }
        if(N + 1 >= 0 && N + 1 < MAX && !visit[N + 1])
        {
            visit[N + 1] = true;
            q.push({N + 1, time + 1});
        }   
        if(N -1 >= 0 && !visit[N - 1]){
            visit[N - 1] = true;
            q.push({N - 1, time + 1});
        }
        if(2 * N >= 0 && 2 * N < MAX && !visit[2 * N]){
            visit[2 * N] = true;
            q.push({2 * N, time + 1});
        }
    }
    return 0;
}