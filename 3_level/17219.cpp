/* 비밀번호 찾기 */
// 23.07.29
// https://www.acmicpc.net/problem/17219

#include<iostream>
#include<map>
using namespace std;
map<string, string> site_pw;

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    int N, M;    //사이트 주소의 수, 비밀번호를 찾으려는 사이트 주소의 수
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        string site, pw;
        cin >> site >> pw;
        site_pw.insert({site, pw});
    }

    for(int i = 0; i < M; i++){
        string search;
        cin >> search;  
        cout << site_pw[search] << "\n";
    }
    
    return 0;
}