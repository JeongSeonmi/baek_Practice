/* 2xn Ÿ�ϸ� */
// 23.07.24
// https://www.acmicpc.net/problem/11726

#include<iostream>
using namespace std;
int N;  //Ÿ���� ����ũ��
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