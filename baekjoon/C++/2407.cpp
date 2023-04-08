#include <iostream>
#include <string>
#include <algorithm> // reverse �Լ�

using namespace std;

int n, m;
string factorial[101][101];

string bigNumAdd(string n1, string n2)
{
    int sum = 0;
    string result;

    // 1�� �ڸ����� ���ϱ�
    while (!n1.empty() || !n2.empty() || sum)
    {
        if (!n1.empty())
        {
            sum += n1.back() - '0';
            n1.pop_back();
        }
        if (!n2.empty())
        {
            sum += n2.back() - '0';
            n2.pop_back();
        }
        result.push_back((sum % 10) + '0');
        sum /= 10;
    }

    // 1�� �ڸ����� push �����Ƿ� �������ش�.
    reverse(result.begin(), result.end());
    return result;
}

string combination(int n, int r)
{
    if (n == r || r == 0)
        return "1";
    string& result = factorial[n][r]; // ������ ����

    // �̹� ��������� �ٷ� return, memoization ���
    if (result != "")
        return result;

    // �Ľ�Į�ﰢ�� ���� �̿�
    result = bigNumAdd(combination(n - 1, r - 1), combination(n - 1, r));
    return result;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    cout << combination(n, m);

    return 0;
}