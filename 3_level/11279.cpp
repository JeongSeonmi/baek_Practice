/* �ִ� �� */
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

    int N;  //������ ����
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
//������ : ť���� ���� ������ ��� ������������ �����ؼ� ������ ���ΰ�.