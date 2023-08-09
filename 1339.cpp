/* 단어수학 */
// 23.08.09
// https://www.acmicpc.net/problem/1339

#include<iostream>
#include<algorithm>
using namespace std;
int str[26];

int compare(int x, int y){
    return x > y;
}

//어느 순간에 어느 알파벳이 제일 큰 수가 되야 하는지 -> 자릿수가 큰 숫자 순서대로 숫자 넣기

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

    sort(str, str + 26, compare);    //내림차순

    int sum = 0;
    for(int i = 0; i < 10; i++){
        sum += str[i] * (9 - i);
    }
    cout << sum << endl;
    return 0;
}