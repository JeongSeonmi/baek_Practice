/* 케빈 베이컨의 6단계 법칙 */
// 23.07.31
// https://www.acmicpc.net/problem/1389

#include <iostream>
#include <vector>
#include <queue>
#define MAX 101
using namespace std;

vector<int> arr[MAX];
int kevin[MAX];

void BFS(int start){
    queue<int> q;
    kevin[start] = 0;
    q.push(start);

    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(int i = 0; i < arr[cur].size(); i++){ 
            int next = arr[cur][i];
            if(kevin[next] == 0){
                kevin[next] = kevin[cur] + 1;
                q.push(next);
            }
        }
    }
}

int main(){
    int N, M;
    cin >> N >> M;

    for (int i = 0; i < M; i++){
        int me, fri;
        cin >> me >> fri;
        arr[me].push_back(fri);
        arr[fri].push_back(me);
    }

    int minKevin = 50000;
    int answer = 0;

    for(int i = 1; i <= N; i++){
        for (int j = 1; j <= N; j++){
            kevin[j] = 0;
        }
        BFS(i);
        
        int sum = 0;
        for(int j = 1; j <= N; j++){
            sum += kevin[j];
        }

        if(sum < minKevin){
            minKevin = sum;
            answer = i;
        }
    }

    cout << answer << endl;

    return 0;
}
