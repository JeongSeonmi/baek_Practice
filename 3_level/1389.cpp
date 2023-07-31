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
            int next = arr[cur][i]; //현재 정점과 연결된 정점을 다음으로 설정
            if(kevin[next] == 0){   //만약 거리를 구한 적(저장한 적)이 없으면
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
        cin >> me >> fri;   //정점과 연결된 다른 정점
        arr[me].push_back(fri);
        arr[fri].push_back(me);
    }

    int minKevin = 50000;
    int answer = 0;

    for(int i = 1; i <= N; i++){
        for (int j = 1; j <= N; j++){
            kevin[j] = 0;   //거리를 저장할 배열 초기화
        }
        BFS(i); // 정점 순서대로 탐색하면서 거리를 구함 
        
        int sum = 0;    
        for(int j = 1; j <= N; j++){
            sum += kevin[j];    //해당하는 정점의 거리의 총합
        }

        if(sum < minKevin){ //총합들을 비교하며 작은 총합이 있으면 해당 정점을 출력
            minKevin = sum; 
            answer = i;
        }
    }

    cout << answer << endl;

    return 0;
}
