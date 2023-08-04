// IOIOI
// 23.08.02
// https://www.acmicpc.net/problem/5525

#include<iostream>
using namespace std;

int main(){
    int N, M;
    cin >> N >> M;

    string num;
    cin >> num;

    int result = 0;
    for(int i = 0; i < M; i++){
        int cnt = 0;
        if(num[i] == 'O') continue;
        else{   //I일때 옆에 있는 문자 확인
            while(num[i + 1] == 'O' && num[i + 2] == 'I'){
                cnt++;
                i += 2;
                if(cnt == N){  
                    result++;
                    cnt--;
                }
            }
        }
    }

    cout << result;
    return 0;
}