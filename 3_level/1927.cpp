/* �ּ� �� */ 
// 23.07.21 C���� �ٽ� ¥����
// https://www.acmicpc.net/problem/1927

#include<iostream>
#include<queue>
using namespace std;
int N; //������ ����
priority_queue<int, vector<int>, greater<int>>q;

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
    cin >> N;
    for(int i = 0; i < N; i++){
        int num;
        cin >> num;
        if(num == 0){
            if(q.empty()){
                cout << "0" << "\n";
            }
            else{
                cout << q.top() << "\n";
                q.pop();
            }
        }
        else{
            q.push(num);
        }
    }    
    return 0;
}