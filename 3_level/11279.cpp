/* 최대 힙 */
// 23.07.28
// https://www.acmicpc.net/problem/11279

#include<iostream>
#include<queue>
using namespace std;
priority_queue<int, vector<int>, less<int>> temp;

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    cout.tie(NULL);

    int N;  //연산의 개수
    cin >> N;
    while(N--){
        int num;
        cin >> num;
       if(num == 0){
            if(!temp.empty()){
                cout << temp.top() << "\n";
                temp.pop();
            }
            else{
                cout << "0" << "\n";
            }
        }
        else{
            temp.push(num);
        }
    } 
    return 0;
}
//문제점 : 큐에서 받은 값들을 어떻게 내림차순으로 정렬해서 저장할 것인가.