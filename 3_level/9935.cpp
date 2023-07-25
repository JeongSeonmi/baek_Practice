/* ���ڿ� ���� */
// 23.07.25 �ٸ� ������� �ٽ� Ǯ� ��
// https://www.acmicpc.net/problem/9935

#include<iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    cout.tie(NULL);
    
    string str;     //���� ��ü�� ����
    string bomb;    //���� �ܾ ����
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