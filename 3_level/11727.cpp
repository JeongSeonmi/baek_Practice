/* 2��n Ÿ�ϸ� 2 */
// 23.07.17
// https://www.acmicpc.net/problem/11727

#include<iostream>
using namespace std;
int N;  //Ÿ���� ����ũ��
int dp[1001];

int main(){
    cin >> N;
    dp[1] = 1;
    dp[2] = 3;
    for(int i = 3; i <= N; i++){
        dp[i] = (dp[i-1] + 2 * dp[i-2]) % 10007;
    }

    cout << dp[N] << endl;
    return 0;
}