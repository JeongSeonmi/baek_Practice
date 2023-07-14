/* 연결 요소의 개수 */
// 23.07.13
// https://www.acmicpc.net/problem/11724

#include<iostream>
#include<vector>
#include<stack>
#define MAX 1001
using namespace std;
int N, M, cnt = 0 ;   //정점 개수, 간선 개수
vector<int> arr[MAX];
stack<int> s;
bool visited[MAX] = {0, };


void DFS(int x){
    visited[x] = true;
    s.push(x);
    while(!s.empty()){
        int curX = s.top();
        s.pop();
        for(int i = 0; i < arr[curX].size(); i++){
            int n = arr[curX][i];
            if(!visited[n]){
                visited[n] = true;
                s.push(n);
            }
        }    
    }
}

int main(){
    cin >> N >> M;
    for(int i = 0; i < M; i++){
        int ver1, ver2;
        cin >> ver1 >> ver2;
        arr[ver1].push_back(ver2);
        arr[ver2].push_back(ver1);

    }
    for (int i = 1; i <= N; i++)
    {
        if (visited[i] == 0)
        {
            cnt++;
            DFS(i);
        }
    }
    cout << cnt << endl;
}