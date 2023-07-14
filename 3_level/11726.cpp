/* 2xn 타일링 */
// 23.07.24
// https://www.acmicpc.net/problem/11726

#include<iostream>
using namespace std;
int N;  //타일의 가로크기
int dp[1001];

int main(){
    cin >> N;
    dp[1] = 1;
    dp[2] = 2;
    for(int i = 3; i <= N; i++){
        dp[i] = (dp[i-1] + dp [i-2]) % 10007;
    }

    cout << dp[N] << endl;
    return 0;
}