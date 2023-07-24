/* Á¦·Î */
// 23.07.24
// https://www.acmicpc.net/problem/10773

#include<iostream>
#include<stack>
using namespace std;
stack<int> st;

int main(){
    int K, result = 0;
    cin >> K;
    for(int i = 0; i < K; i++){
        int num;
        cin >> num;
        if(num == 0) st.pop();
        else st.push(num);
    }
    
    while(!st.empty()){
        result += st.top();
        st.pop();
    } 
    cout << result << endl;
}