/* Z */
// 23.07.20
// https://www.acmicpc.net/problem/1074

#include<iostream>
using namespace std;
int N, r, c, count = 0; //�簢�� ũ��, ��, ��

void Z(int y, int x, int size){
    if(y == r && x == c){    //��ǥ ��ǥ�� ������ ��� ����Ƚ�� ���
        cout << count << endl;
        return;
    }

    if(r < y + size && c < x + size && r >= y && c >= x){   //��ġ���� �簢���� 4����ؼ� �̵�
        Z(y, x, size / 2);  //�� 1 ��и� 
        Z(y, x + size / 2, size / 2);   //�� 2 ��и�
        Z(y + size / 2, x, size / 2);   //�� 3 ��и�
        Z(y + size / 2, x + size / 2, size / 2);    //�� 4 ��и�
    }   //��и��� ������� �̵��ϴ� ���� : Z������� �̵��ϱ� ���� �� 1 2 3 4 ��и� ������ �̵��Ѵ�.
    count += size * size;   //�簢�� ������ ������ �簢�� ũ�⸸ŭ Ƚ�� ����
}

int main(){
    cin >> N >> r >> c;
    Z(0, 0, (1 << N));  //(0, 0)���� �����ؼ� �簢�� Z������� �̵�
    return 0;
}
