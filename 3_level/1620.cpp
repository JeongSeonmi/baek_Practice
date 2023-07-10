#include<iostream>
#include<map>
#include<string>
using namespace std;
string arr[100001];
map <string, int> poke; //Ű�� ����, ���� ����

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, M; //���ϸ� ����, ������ ����
    cin >> N >> M;

    /*���ϸ� �̸� ���� �κ�*/
    for(int i = 0; i < N; i++){
        cin >> arr[i+1];
        poke.insert(make_pair(arr[i+1], i+1));
    }

    /*���ϸ� ã�� �κ�*/
    for(int i = 0; i < M; i++){
        string find;
        cin >> find;
        if(isdigit(find[0]) != 0){
            cout << arr[stoi(find)] << "\n";
        }
        else{
            cout << poke[find] << "\n"; //���ڿ��� �Էµ��� ���.
        }
    }
    return 0;
}
