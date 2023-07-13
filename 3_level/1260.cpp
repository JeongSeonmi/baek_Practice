/* DFS와 BFS */
// https://www.acmicpc.net/problem/1260

#include<iostream>
#include<vector>
#include<queue>
#include <algorithm>
using namespace std;
vector <int> arr[1001];
bool visited[1001];
queue <int> q;

//양방향 그래프, DFS와 BFS 구현하기

void dfs(int x){
    visited[x] = true;
    cout << x << " ";
    for(int i = 0; i < arr[x].size(); i++){
        int n = arr[x][i];
        if(!visited[n]){
            dfs(n);
        }
    }
}

void bfs(int y){
    visited[y] = true;
    q.push(y);
    while(!q.empty()){
        int y = q.front();
        q.pop();
        cout << y << " ";
        for(int i = 0; i < arr[y].size(); i++){
            int n = arr[y][i];
            if(!visited[n]){
                visited[n] = true;
                q.push(n);
            }
        }
    }
}

int main(){
    int N, M, V; //정점의 개수, 간선의 개수, 팀색을 시작할 정점의 번호
    cin >> N >> M >> V;
    for(int i = 0; i < M; i++){
        int ver1, ver2;
        cin >> ver1 >> ver2;
        arr[ver1].push_back(ver2);
        arr[ver2].push_back(ver1);
    }
    for(int i = 0; i < N; i++){
        sort(arr[i].begin(), arr[i].end());
    }
    
    dfs(V);

    cout <<'\n';
    
    for (int i = 1; i <= N; i++) {
        visited[i] = 0;
    }
    bfs(1);
}