/* 프린트 큐 */
// 23.08.11
// https://www.acmicpc.net/problem/1966

#include<iostream>
#include<queue>
using namespace std;

int main(){
    int T;
    cin >> T;
    while(T--){
        int N, M;
        cin >> N >> M;
        
        priority_queue<int>pq;
        queue<pair<int, int>>q;
        for(int i = 0; i < N; i++){
            int num;
            cin >> num;
            q.push({i, num});
            pq.push(num);
        }

        int cnt = 0;
        while(!q.empty()){
            int rank = q.front().first;
            int value = q.front().second;
            q.pop();
            if(pq.top() == value){
                pq.pop();
                cnt++;
                if(M == rank){
                    cout << cnt << "\n";
                    break;
                }
            }
            else{
                q.push({rank, value});
            }
        }

    }
}