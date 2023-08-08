/* ÆÓ¸°µå·Ò¼ö */
// 23.08.08
// https://www.acmicpc.net/problem/1259

#include<iostream>
#include<algorithm>
using namespace std;

int main(){
        string num;
        while(num != "0"){
            cin >> num;
            string palin = num;
            if(palin == "0"){
                break;
            }

            int flag = 0;
            int size = palin.size();
            for(int i = 0; i < size / 2; i++){
                if(palin[i] != palin[size - 1 - i]){
                    flag = 1;
                }
            }
            if(!flag){
                cout << "yes\n";
            }
            else{
                cout << "no\n";
            }
        }
    return 0;
}