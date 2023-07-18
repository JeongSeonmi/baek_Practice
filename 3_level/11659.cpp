/* ���� �� ���ϱ� 4 */
// 23.07.18
// https://www.acmicpc.net/problem/11659

#include<iostream>
using namespace std;
int num[100001];

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    cout.tie(NULL);

    int N, M;   //���� ����, ���� ���ؾ��ϴ� Ƚ��
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