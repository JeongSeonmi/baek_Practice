/* 소수 찾기 */
// 23.08.12
// https://www.acmicpc.net/problem/1978

#include<iostream>
using namespace std;

int main(){
    int N;
    cin >> N;

    int cnt = 0, result = 0;
    for(int i = 0; i < N; i++){
        int M;
        cin >> M;
        for(int j = 1; j <= M; j++){
            if(M % j == 0){
                cnt++;
            }
        }
        if(cnt == 2){
            result++;
        }
        cnt = 0; 
    }
    cout << result;
}