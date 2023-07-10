#include<iostream>
using namespace std;

void dfs(int arr[][50], int a, int b, int w, int h) {
    if (a < 0 || b < 0 || a >= w || b >= h || arr[a][b] != 1)
        return;
        
    arr[a][b] = 0;

    // �����¿�� ������ ���ߵ鿡 ���� ��������� Ž��
    dfs(arr, a - 1, b, w, h); // ��
    dfs(arr, a + 1, b, w, h); // ��
    dfs(arr, a, b - 1, w, h); // ��
    dfs(arr, a, b + 1, w, h); // ��
}

int main(){
    int num, w, h, n;  //�׽�Ʈ ���̽�, ����, ����, ���� ����
    cin >> num;
    int arr[50][50] = {0};
    for(int k = 0; k < num; k++){
        cin >> w >> h >> n;

        int x, y, cnt = 0; //���� ��ǥ, �ֹ��� ����
        for(int i = 0; i < n; i++){
            cin >> x >> y;
            arr[x][y] = 1;
        }

        //���߹� Ž��
        for(int i = 0; i < w; i++){
            for(int j = 0; j < h; j++){
                if(arr[i][j] == 1){
                    dfs(arr, i, j, w, h);
                    cnt++;
                }
            }
        }
        
        cout << cnt << "\n";
    }
    return 0;
}