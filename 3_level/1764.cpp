/* �躸�� */
// 23.07.18
// https://www.acmicpc.net/problem/1764

#include<iostream>
#include<algorithm>
#include<map>
#include<vector>
using namespace std;
map <string, int> Dic;
vector <string> NM;

int main(){
    int N, M;  //������, ����
    cin >> N >> M;
    for(int i = 0; i < N + M; i++){
        string word;
        cin >> word;
        Dic[word]++;
        if(Dic[word] > 1){
            NM.push_back(word);
        }
    }

    /*
    for(int i = 0; i < N; i++){
        cin >> word;
        Dic[word]++;
    }

    for(int i = 0; i < M; i++){
        cin >> word;
        Dic[word]++;
        if(Dic[word] > 1){    //�躸���̸� NM�� ����
            NM.push_back(word);    //word�ڸ��� �ƴ϶� ���� �� �ڿ� ����
        }
    }
    */

    sort(NM.begin(), NM.end());
    cout << NM.size() << endl;
    for(int i = 0; i < NM.size(); i++){
        cout << NM[i] << endl;
    }
    return 0;
}