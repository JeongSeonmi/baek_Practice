// 파도반 수열
// 23.07.17
// https://www.acmicpc.net/problem/9461

#include<iostream>
using namespace std;
long long int dp[101];  //범위 초과로  long long을 붙힘
int main(){
    int T, N;
    cin >> T;
    for(int i = 0; i < T; i++){
        cin >> N;
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 1;
        dp[3] = 2;
        dp[4] = 2;
        for(int j = 5; j < 100; j++){ //100까지 미리 만들면 O(N)만큼의 시간이 걸림
            dp[j] = dp[j-1] + dp[j-5];
        }
        cout << dp[N-1] << endl;
    }
    return 0;
}