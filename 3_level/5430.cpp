/* AC */
// 23.07.26
// https://www.acmicpc.net/problem/5430

#include<iostream>
#include<string>
#include<deque>
using namespace std;
string option;
string arr;
string temp = "";    
deque<int> result;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T, n;  // 테스트 케이스 횟수 T, 배열에 들어있는 수의 개수 n
    cin >> T;
    for(int i = 0; i < T; i++){
        cin >> option >> n >> arr;
        
        for(int j = 0; j < arr.size(); j++){
            if(arr[j] == '['){
                continue;
            }
            if( '0' <= arr[j] && arr[j] <= '9'){
                temp += arr[j];     //두~세자리 숫자인지도 구분해야하므로 한자리씩 입력받고
            }
            if(arr[j] == ']' || arr[j] == ','){
                if(!temp.empty()){  //입력 : 1 R 0 []일 경우 처리
                    result.push_back(stoi(temp));   //숫자를 구분할 수 있는 문자가 있으면 result에 저장
                    temp = "";  //숫자를 다시 받아와야하므로 초기화
                }
            }
        }

        int reverseTime = 1;    //뒤집기 여부 기록
        bool er = false;    //에러 여부 기록
        for(int i = 0; i < option.size(); i++){
            if(option[i] == 'R'){
                reverseTime *= -1;
            }                                           
            else if(option[i] == 'D'){
                if(!result.empty()){
                    if(reverseTime == -1){    //뒤집기를 홀수 번 했을 때(뒤집어짐)
                        result.pop_back();
                    }
                    else{   //뒤집기를 짝수 번 했을 때(그대로)
                        result.pop_front();
                    }
                }
                else{
                    er = true;
                    cout << "error\n";
                    break;
                }
            }

        }
    
        /* 출력 */
        if(!er){    //에러인 경우, error 문자만 띄우고 끝내도록
            cout << '[';
            if(reverseTime == 1){
                while(!result.empty()){
                    cout << result.front();
                    result.pop_front();
                    if(!result.empty()){
                        cout << ",";
                    }
                }
            }
            else{
                while(!result.empty()){
                    cout << result.back();
                    result.pop_back();
                    if(!result.empty()){
                        cout << ",";
                    }
                }
            }
            cout << ']' << endl;
        }
    }

    return 0;
}