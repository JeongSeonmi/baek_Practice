/* DSLR */
// 23.08.10
// https://www.acmicpc.net/problem/9019

#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
bool visited[10000];
int start, final;

void bfs(){
    queue<pair<int, string>> q;
    q.push({start, ""});
    visited[start] = true;

    while(!q.empty()){
        int curNum = q.front().first;
        string curSt = q.front().second;
        q.pop();

        if (curNum == final)
        {
            cout << curSt << '\n';
            return;
        }

        int D, S, L, R;
        D = curNum * 2 % 10000;
        if(!visited[D])
        {
            visited[D] = true;
            q.push({D, curSt + "D"});
        }

        S = (curNum - 1 < 0) ? 9999 : curNum - 1;
        if(!visited[S]){
            visited[S] = true;
            q.push({S, curSt + "S"});
        }

        L = (curNum % 1000) * 10 + (curNum / 1000); //맨 앞자리를 없애서 *10 해준 다음, 원래 앞자리를 맨 뒤에 더해줌
        if(!visited[L]){
            visited[L] = true;
            q.push({L, curSt + "L"});
        }

        R = curNum / 10 + (curNum % 10) * 1000; //끝자리를 없앤 후 원래 끝자리 수를 맨 앞자리에 더해줌
        if(!visited[R]){
            visited[R] = true;
            q.push({R, curSt + "R"});
        }

    }
}

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin >> N;

    for(int i = 0; i < N; i++){
        cin >> start >> final;
        memset(visited, false, sizeof(visited));
        bfs();
    }
    return 0;
}