/* �Ҿ���� ��ȣ */
// 23.07.22
// https://www.acmicpc.net/problem/1541

#include<iostream>
using namespace std;

int main(){
    string num = "";
    bool check = false;     //+ �� ��
    int result = 0;
    string str;
    cin >> str;

    for(int i = 0; i <= str.size(); i++){   //���ڳ��� ���Ǳ� ���� <=
        if(str[i] == '-' || str[i] == '+' || i == str.size()){
            if(check){
                result -= stoi(num);
                num = "";   //�̹� ���� �־������Ƿ� �ʱ�ȭ
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