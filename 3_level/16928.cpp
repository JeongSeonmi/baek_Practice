/* 뱀과 사다리 게임 */
// 23.07.31
// https://www.acmicpc.net/problem/16928

#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
vector<int> gameMap[101];
bool visit[101] = {0, };


void BFS(){
    queue<pair<int, int>> q;
    q.push({1, 0});
    int cnt = 0;
    visit[1] = true;
    while(!q.empty()){
        int cur = q.front().first;  //현재 위치
        int cnt = q.front().second; //횟수
        q.pop();
        if(cur == 100) {    // 100에 도착했을 때 횟수 출력하고 끝
            cout << cnt << '\n';
            return;
        }
        for(int i = 1; i <= 6; i++){
            int next = cur + i; //주사위 이동
            if(next > 100 || visit[next]){
                continue;
            }
            if(!gameMap[next].empty()){ //사다리나 뱀이 있을 경우
                next = gameMap[next][0];    //이동해야할 칸으로 업데이트
            }
            q.push({next, cnt + 1});    //횟수 추가, 큐에 0111112222이런식으로 숫자표시 
            visit[next] = true;
        }
    }
}

int main(){
    int N, M;   // 사다리 수, 뱀의 수(1 <= N,M <= 15)
    cin >> N >> M;

    for(int i = 0; i < N + M; i++){ // 사다리 정보 입력(사다리는 올라감)
        int start, end;
        cin >> start >> end;
        gameMap[start].push_back(end);
    }
    
    BFS();

    return 0;
}