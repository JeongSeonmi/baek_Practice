/* 소수 구하기 */
// 23.08.11
// https://www.acmicpc.net/problem/1929

#include<iostream>
using namespace std;
bool prime[1000001];

int main(){
    int N, M;
    cin >> N >> M;
    for(int i = N; i <= M; i++){
        prime[i] = true;
    }

    for(int i = N; i <= M; i++){
        if(i < 2){
            prime[i] = false;
            continue;
        }
        for(int j = 2; j * j <= i; j++){
            if(i % j == 0){
                prime[i] = false;
            }
        }

        if(prime[i]){
            printf("%d\n", i);
        }
    }
    return 0;
}