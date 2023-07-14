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
    
}

//계단은 한 번에 한 계단씩 또는 두 계단씩 오를 수 있다. 즉, 한 계단을 밟으면서 이어서 다음 계단이나, 다음 다음 계단으로 오를 수 있다.
//연속된 세 개의 계단을 모두 밟아서는 안 된다. 단, 시작점은 계단에 포함되지 않는다.
//마지막 도착 계단은 반드시 밟아야 한다.