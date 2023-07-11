/* 바이러스 */
// https://www.acmicpc.net/problem/2606

#include <iostream>
#include<vector>
#include<queue>
using namespace std;
vector <int> arr[1001];
queue <int> q;
int visited[1001] = {0, };
 int com, num, count = 0 ;

void bfs(int x){
    visited[x] = 1;
    q.push(x);
    while(!q.empty()){
        x = q.front();
        q.pop();
        for(int i = 0; i < arr[x].size(); i++){
            int n = arr[x][i];
            if(!visited[n]){
                visited[n] = 1;
                q.push(n);
                count++;
            }
        }
    }
}

int main(){

    cin >> com;
    cin >> num;
    for(int i = 1; i <= num; i++){
        int ver1, ver2;
        cin >> ver1 >> ver2;
        arr[ver1].push_back(ver2);
        arr[ver2].push_back(ver1);
    }

    bfs(1);

    cout << count << endl;
}

// 어려웠던 부분 : 1 또는 (1, 1)에서 시작하는 문제 유형 