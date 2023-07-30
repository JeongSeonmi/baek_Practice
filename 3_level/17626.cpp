/* Four Squares */
// 23.07.30
// https://www.acmicpc.net/problem/17626

#include<iostream>
#include<algorithm>
using namespace std;
int dp[50001];

int main(){
    int n;  //ÀÚ¿¬¼ö n
    cin >> n;

    dp[0] = 0;
    for(int i = 1; i <= n; i++){
        dp[i] = dp[i - 1] + 1;
        for(int j = 2; j*j <= i; j++){
            dp[i] = min(dp[i], dp[i - j*j] + 1);
        }
    }
    cout << dp[n];
    return 0;
}