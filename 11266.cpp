/* 단절점 */
// 23.07.14
// https://www.acmicpc.net/problem/11266

#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
#define MAX 10001
using namespace std;
vector<int> arr[MAX];
stack<int> stac;
int visited[MAX] = {0, };
int V, E; //정점과 간선의 수
int num = 0;

void DFS(int x){
    visited[x] = num++;
    int res = visited[x];
    for(int i = 0; i < arr[x].size(); i++){
        int next = arr[x][i];
        if(!visited[next]){
            res = min(visited[x], visited[next]);
            continue;
        }
        if()
        
    }
}

int main(){
    cin >> V >> E;
    for(int i = 1; i <= E; i++){
        int verA, verB;
        cin >> verA >> verB;
        arr[verA].push_back(verB);
        arr[verB].push_back(verA);
    }

    for (int i = 1; i <= V; i++){
		if (!visited[i])
			DFS(i);
    }

}