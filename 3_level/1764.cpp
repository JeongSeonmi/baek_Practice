/* 듣보잡 */
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
    int N, M;  //못들은, 못본
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
        if(Dic[word] > 1){    //듣보잡이면 NM에 저장
            NM.push_back(word);    //word자리가 아니라 값을 맨 뒤에 저장
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