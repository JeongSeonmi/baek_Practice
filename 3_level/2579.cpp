/* 계단 오르기 */
// 23.07.14
// https://www.acmicpc.net/problem/2579

#include<iostream>
#include<algorithm>
#define MAX 10001
using namespace std;
int stair[MAX];
int DP[MAX];

int main(){
    int num;
    cin >> num;
    for(int i = 1; i <= num; i++){
        cin >> stair[i];
    }

    DP[1] = stair[1];
    DP[2] = stair[1] + stair[2];
    DP[3] = max(stair[1], stair[2]) + stair[3];
    
    for(int i = 4; i <= num; i++){
        DP[i] = max(DP[i-3] + stair[i-1], DP[i-2]) + stair[i];
    }
    cout << DP[num] << endl;
    return 0;
}
