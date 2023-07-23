/* °ýÈ£ÀÇ °ª */
// 23.07.23
// https://www.acmicpc.net/problem/2504
 
#include<iostream>
#include<stack>
using namespace std;
stack<char> s;

int main(){
    string str;
    int tmp = 1;
    int result = 0;
    cin >> str;

    for(int i = 0; i < str.size(); i++){
        if(str[i] == '(' || str[i] == '['){
            s.push(str[i]);
            if(str[i] == '(')
                tmp *= 2;
            if(str[i] == '[')
                tmp *= 3;
        }
        else if(str[i] == ')'){
            if(s.empty() || s.top() != '(') {
                result = 0;
                break;
            }
            if(str[i-1] == '(') {
                result += tmp;
            }
            s.pop();
            tmp /= 2;
        }
        else if(str[i] == ']'){
            if(s.empty() || s.top() !='['){
                result = 0;
                break;
            }
            if(str[i-1] =='['){
                result += tmp;
            }
            s.pop();
            tmp /= 3;
        }
    }
    if(s.empty()){
        cout << result << '\n'; 
    }
    else cout << "0\n";
    
    return 0;
}