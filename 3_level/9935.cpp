/* 문자열 폭발 */
// 23.07.25 다른 방법으로 다시 풀어볼 것
// https://www.acmicpc.net/problem/9935

#include<iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    cout.tie(NULL);
    
    string str;     //문장 전체를 저장
    string bomb;    //폭단 단어를 저장
    cin >> str;
    cin >> bomb;
    
    string temp;
    for(int i = 0; i < str.size(); i++){
        temp.push_back(str[i]);
        if(temp.back() == bomb.back()){
            if(temp.size() >= bomb.size()){
                if(temp.substr(temp.size() - bomb.size(), bomb.size()) == bomb){
                    temp.erase(temp.size() - bomb.size(), bomb.size());
                }
            }
        }
    }



    if(temp.size() <= 0){
        cout << "FRULA" << endl;
    }
    else{
        cout << temp << endl;
    }

    return 0;
}