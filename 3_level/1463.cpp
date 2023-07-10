#include<iostream>
#include<algorithm>
using namespace std;
int dp[1000000];

int main(){
    int num;
    dp[1] = 0;
    cin >> num;
    for(int i = 2; i <= num; i++){
        dp[i] = dp[i-1] + 1; //1�� ���� ���
        if(i % 2 == 0)
            dp[i] = min(dp[i], dp[i/2] + 1);   //2�� ������ ���
        if(i % 3 == 0)
            dp[i] = min(dp[i], dp[i/3] + 1);  //3���� ������ ��� 
    }
    cout << dp[num];
    return 0;
}
