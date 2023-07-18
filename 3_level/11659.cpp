/* 구간 합 구하기 4 */
// 23.07.18
// https://www.acmicpc.net/problem/11659

#include<iostream>
using namespace std;
int num[100001];

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    cout.tie(NULL);

    int N, M;   //수의 개수, 합을 구해야하는 횟수
    cin >> N >> M;

    for(int i = 1; i <= N; i++){
        cin >> num[i];
        num[i] += num[i-1];
    }

    int Rbegin, Rend; 
    for(int i = 0; i < M; i++){
        cin >> Rbegin >> Rend;
        cout << num[Rend] - num[Rbegin - 1] << "\n";
    }
    return 0;
}