/* 패션왕 신해빈 */
// 23.08.02
// https://www.acmicpc.net/problem/9375

#include<iostream>
#include<map>
using namespace std;

int main(){
    int n;  //testcase num
    cin >> n;

    while(n--){
        int num;
        cin >> num;

        map<string, int> clothes;   //의상 종류, 의상 수
        for(int i = 0; i < num; i++){
            string name, tags;
            cin >> name >> tags;

            clothes[tags]++;
        }

        int result = 1;
        for(auto iter = clothes.begin(); iter != clothes.end(); iter++){  //map clothes를 전체 순회 
            result *= (iter->second + 1);   //map에 저장된 의상수 + 1 해서 곱하기
        }
        cout << result - 1 << "\n"; //다 안입는 경우도 있으므로 -1
        
    }
    return 0;
}