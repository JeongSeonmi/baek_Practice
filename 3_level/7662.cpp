/* ���� �켱���� ť */
// 23.08.07
// https://www.acmicpc.net/problem/7662

#include<iostream>
#include<set>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    cout.tie(NULL);

    int T, k;   //�׽�Ʈ Ƚ��, ������ ����
    cin >> T;
    while(T--){
        cin >> k;
        multiset<int> q; // �߿� : multiset �������� ����
        while(k--){
            char oper;
            int num;
            cin >> oper >> num;
            if(oper == 'I'){
                q.insert(num);
            }
            if(oper == 'D'){
                if(q.empty()){
                    continue;
                }
                if(num == 1){ //�ִ밪
                    auto iter = q.end(); //�� �� ���� +1 ����
                    iter--; 
                    q.erase(iter);
                }
                if(num == -1){
                    q.erase(q.begin()); // �ּҰ� ����
                }
            }
        }
        if(q.empty()){
        cout << "EMPTY" << '\n';
        }
        else{   
            auto iter = q.end();    //������ ���� ����
            iter--;
            cout << *iter << " " << *q.begin() << '\n';
        }
    }
    
    return 0;
}
