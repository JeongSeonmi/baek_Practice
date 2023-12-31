/* 1, 2, 3 더하기 */
// dp 사용 기초
// https://www.acmicpc.net/problem/9095

#include<iostream>
#include<vector>
using namespace std;
int dp[11];
int main(){
    int T, n;
    cin >> T;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;

    for(int i = 4; i < 12; i++){
        dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
    }
    for (int i = 0; i < T; i++)
    {
        cin >> n;
        cout << dp[n] << '\n';
    }

}