/* 잃어버린 괄호 */
// 23.07.22
// https://www.acmicpc.net/problem/1541

#include<iostream>
using namespace std;

int main(){
    string num = "";
    bool check = false;     //+ 일 때
    int result = 0;
    string str;
    cin >> str;

    for(int i = 0; i <= str.size(); i++){   //문자끝을 살피기 위해 <=
        if(str[i] == '-' || str[i] == '+' || i == str.size()){
            if(check){
                result -= stoi(num);
                num = "";   //이미 값을 넣어줬으므로 초기화
            }
            else{
                result += stoi(num);
                num = "";
            }
        }
        else{
            num += str[i];
        }

        if (str[i] == '-')
        {
            check = true;
        }
    }
    cout << result;
}