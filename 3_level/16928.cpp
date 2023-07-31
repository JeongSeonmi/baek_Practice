/* ��� ��ٸ� ���� */
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
        int cur = q.front().first;  //���� ��ġ
        int cnt = q.front().second; //Ƚ��
        q.pop();
        if(cur == 100) {    // 100�� �������� �� Ƚ�� ����ϰ� ��
            cout << cnt << '\n';
            return;
        }
        for(int i = 1; i <= 6; i++){
            int next = cur + i; //�ֻ��� �̵�
            if(next > 100 || visit[next]){
                continue;
            }
            if(!gameMap[next].empty()){ //��ٸ��� ���� ���� ���
                next = gameMap[next][0];    //�̵��ؾ��� ĭ���� ������Ʈ
            }
            q.push({next, cnt + 1});    //Ƚ�� �߰�, ť�� 0111112222�̷������� ����ǥ�� 
            visit[next] = true;
        }
    }
}

int main(){
    int N, M;   // ��ٸ� ��, ���� ��(1 <= N,M <= 15)
    cin >> N >> M;

    for(int i = 0; i < N + M; i++){ // ��ٸ� ���� �Է�(��ٸ��� �ö�)
        int start, end;
        cin >> start >> end;
        gameMap[start].push_back(end);
    }
    
    BFS();

    return 0;
}