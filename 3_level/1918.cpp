/* 후위 표기식 */
// 23.07.23
// https://www.acmicpc.net/problem/1918

#include<iostream>
#include<stack>
using namespace std;
stack<char> s;   //연산자 저장

int main(){
    string str;
    string result = "";    

    cin >> str;

    for(int i = 0; i < str.size(); i++){   
        if(str[i] >= 'A' && str[i] <= 'Z'){     //피연산자라면 result에 더해서 저장
            result += str[i];
        }
        else if(str[i] == '('){      
            s.push(str[i]);     //스택에 '('저장
        }
        else if(str[i] == ')'){      
            while(!s.empty() && s.top() != '(')   
            {
                result += s.top();     //스택의 연산자 값 저장
                s.pop();
            }
            s.pop(); // '(' 제거
        }
        else if(str[i] == '*' || str[i] == '/' ){  
            while(!s.empty() && (s.top() == '*' || s.top() == '/')){
                result += s.top();
                s.pop();
            }
            s.push(str[i]); //현재 연산자 저장
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
        result += s.top(); // 스택에 남아있는 모든 연산자를 result에 추가
        s.pop();
    }
    
    cout << result <<'\n'; 
}