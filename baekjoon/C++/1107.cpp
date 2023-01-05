#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;

vector<bool> mal(10);

bool check(int now) { //���峭 Ű�� �ִ��� Ȯ���ϱ�

    string s = to_string(now);
    for (int i = 0; i < s.length(); i++) {
        if (mal[s[i] - 48]) {//0�� �ƽ�Ű �ڵ�� 48
            return false;
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, c;
    cin >> n >> c;
    int tmp;
    for (int i = 0; i < c; i++) {
        cin >> tmp;
        mal[tmp] = true;
    }
    string st = to_string(n);
    int minimum = abs(n - 100); //�������� 100�̴ѱ� 100���� +- ���ִ� ��� 
    for (int i = 0; i <= 1000000; i++) {
        if (check(i)) {//����ȳ� Ű�� ���� ��
            int tmp = abs(n - i) + to_string(i).length();
            minimum = min(minimum, tmp);
        }
    }
    cout << minimum << endl;


    return 0;
}