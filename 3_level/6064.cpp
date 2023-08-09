/* ī�� �޷� */
// 23.08.06
// https://www.acmicpc.net/problem/6064

#include<iostream>
using namespace std;

int gcd(int a, int b){ // �ִ� �����
    if(a % b == 0)
        return b;
    return gcd(b, a % b);
}

int lcm(int a, int b){  // �ּ� �����
    return a * b / gcd(a, b);
}

int main(){
    int T;
    cin >> T;

    int M, N, x, y;
    for(int i = 0; i < T; i++){
        cin >> M >> N >> x >> y;

        if(x > y){
            cout << "-1" << endl;
            continue;
        }

        int end = lcm(M, N);    //x, y�� ���ÿ� ������ ���� �Ǵ� ��� -> �ּҰ����

        int cnt = 0;
        for(int i = x; i <= end; i = i + M){
            if(i % N == y){
                cnt = i;
                break;
            }
            else if(i % N == 0){
                if(N == y){
                    cnt = i;
                    break;
                }
            }
        }
    }
    return 0;
}