/* ���� �ڸ��� */
// 23.08.09
// https://www.acmicpc.net/problem/1654

#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
ll num[10000];

int main(){
    int K, N;   //������ �ִ� ������ ����, �ʿ��� ������ ����
    cin >> K >> N;
    for(int i = 0; i < K; i++){
        cin >> num[i];
    }

    sort(num, num + K);

    ll result = 1;
    ll low = 1;
    ll high = num[K - 1];
    while(low <= high){
        ll sum = 0;
        ll mid = (low + high) / 2;
        for(int i = 0; i < K; i++){
                sum += num[i] / mid;
        }
        if(sum >= N){
            if(result < mid){
                result = mid;
            }
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    cout << result << endl;
    return 0;

}