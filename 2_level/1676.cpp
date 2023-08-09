/* 팩토리얼 0의 개수 */
// 23.08.09
// https://www.acmicpc.net/problem/1676

#include<iostream>
using namespace std;

int main(){
    int num;
    cin >> num;
    
    int cnt = 0;
    for(int i = 5; i <= num; i *= 5){
        cnt += (num / i);
    }
    cout << cnt << endl;
    return 0;
}