/* ���� ǥ��� */
// 23.07.23
// https://www.acmicpc.net/problem/1918

#include<iostream>
#include<stack>
using namespace std;
stack<char> s;   //������ ����

int main(){
    string str;
    string result = "";    

    cin >> str;

    for(int i = 0; i < str.size(); i++){   
        if(str[i] >= 'A' && str[i] <= 'Z'){     //�ǿ����ڶ�� result�� ���ؼ� ����
            result += str[i];
        }
        else if(str[i] == '('){      
            s.push(str[i]);     //���ÿ� '('����
        }
        else if(str[i] == ')'){      
            while(!s.empty() && s.top() != '(')   
            {
                result += s.top();     //������ ������ �� ����
                s.pop();
            }
            s.pop(); // '(' ����
        }
        else if(str[i] == '*' || str[i] == '/' ){  
            while(!s.empty() && (s.top() == '*' || s.top() == '/')){
                result += s.top();
                s.pop();
            }
            s.push(str[i]); //���� ������ ����
        }
        else if(str[i] == '+' || str[i] == '-'){ 
            while(!s.empty() && s.top() != '('){
                result += s.top();
                s.pop();
            }
            s.push(str[i]);
        }
    }

    while(!s.empty()){
        result += s.top(); // ���ÿ� �����ִ� ��� �����ڸ� result�� �߰�
        s.pop();
    }
    
    cout << result <<'\n'; 
}