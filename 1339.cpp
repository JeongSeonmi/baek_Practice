/* �ܾ���� */
// 23.08.09
// https://www.acmicpc.net/problem/1339

#include<iostream>
#include<algorithm>
using namespace std;
int str[26];

int compare(int x, int y){
    return x > y;
}

//��� ������ ��� ���ĺ��� ���� ū ���� �Ǿ� �ϴ��� -> �ڸ����� ū ���� ������� ���� �ֱ�

int main(){
    int N;
    cin >> N;
    for(int i = 0; i < N; i++){
        string s;
        cin >> s;

        int c = 1;
        for(int j = s.size() - 1; j >= 0; j--){
            str[s[j] - 65] += c;
            c *= 10;
        }
    }

    sort(str, str + 26, compare);    //��������

    int sum = 0;
    for(int i = 0; i < 10; i++){
        sum += str[i] * (9 - i);
    }
    cout << sum << endl;
    return 0;
}