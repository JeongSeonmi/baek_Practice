#include<iostream>
#include<map>
#include<string>
using namespace std;
string arr[100001];
map <string, int> poke; //키는 영어, 값은 정수

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, M; //포켓몬 개수, 문제의 개수
    cin >> N >> M;

    /*포켓몬 이름 저장 부분*/
    for(int i = 0; i < N; i++){
        cin >> arr[i+1];
        poke.insert(make_pair(arr[i+1], i+1));
    }

    /*포켓몬 찾는 부분*/
    for(int i = 0; i < M; i++){
        string find;
        cin >> find;
        if(isdigit(find[0]) != 0){
            cout << arr[stoi(find)] << "\n";
        }
        else{
            cout << poke[find] << "\n"; //문자열이 입력됐을 경우.
        }
    }
    return 0;
}
