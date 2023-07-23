/* 스택 수열 */
// 23.07.23
// https://www.acmicpc.net/problem/1874

#include<iostream>
#include<stack>
using namespace std;
stack<int> s;

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int N, cnt = 1;
    string result;
    cin >> N;

    for(int i = 0; i < N; i++){
        int num;
        cin >> num;
        while(cnt <= num){
            s.push(cnt);
            ++cnt;
            result += '+';
        }
        if(s.top() == num){
            s.pop();
            result += '-';
        }
        else{  
            cout << "NO";
            return 0;
        }
    }

    for(int i = 0; i < result.size(); i++){
        cout << result[i] << "\n";
    }
    return 0;
}