/* ¿µÈ­°¨µ¶ ¼ò */
// 23.08.08
// https://www.acmicpc.net/problem/1436

#include<iostream>
using namespace std;

int main(){
    int N; 
    cin >> N ;
    
    int cnt = 0;
    int num = 665;
    while(cnt != N){
        num++;
        int temp = num;
        while(temp >= 666){
            if(temp % 1000 == 666){
                cnt++;
                break;
            }
            else {
                temp /= 10;
            }
        }      
    }
    cout << num << "\n";
    return 0;
}