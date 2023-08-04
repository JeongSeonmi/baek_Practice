/* 부분 수열의 합 */
// 23.08.03
// https://www.acmicpc.net/problem/1182

#include<iostream>
using namespace std;
int arr[21], cnt = 0;
int N, S;

void search(int index, int sum){
    if(index == N){
        return;
    }
    if(sum + arr[index] == S){
        cnt++;
    }
    search(index + 1, sum);
    search(index + 1, sum + arr[index]);
}

int main(){
    cin >> N >> S;
    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }

    search(0, 0);

    cout << cnt;
}