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

    int T, n;  // �׽�Ʈ ���̽� Ƚ�� T, �迭�� ����ִ� ���� ���� n
    cin >> T;
    for(int i = 0; i < T; i++){
        cin >> option >> n >> arr;
        
        for(int j = 0; j < arr.size(); j++){
            if(arr[j] == '['){
                continue;
            }
            if( '0' <= arr[j] && arr[j] <= '9'){
                temp += arr[j];     //��~���ڸ� ���������� �����ؾ��ϹǷ� ���ڸ��� �Է¹ް�
            }
            if(arr[j] == ']' || arr[j] == ','){
                if(!temp.empty()){  //�Է� : 1 R 0 []�� ��� ó��
                    result.push_back(stoi(temp));   //���ڸ� ������ �� �ִ� ���ڰ� ������ result�� ����
                    temp = "";  //���ڸ� �ٽ� �޾ƿ;��ϹǷ� �ʱ�ȭ
                }
            }
        }

        int reverseTime = 1;    //������ ���� ���
        bool er = false;    //���� ���� ���
        for(int i = 0; i < option.size(); i++){
            if(option[i] == 'R'){
                reverseTime *= -1;
            }                                           
            else if(option[i] == 'D'){
                if(!result.empty()){
                    if(reverseTime == -1){    //�����⸦ Ȧ�� �� ���� ��(��������)
                        result.pop_back();
                    }
                    else{   //�����⸦ ¦�� �� ���� ��(�״��)
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
    
        /* ��� */
        if(!er){    //������ ���, error ���ڸ� ���� ��������
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