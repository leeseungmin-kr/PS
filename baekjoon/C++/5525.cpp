#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    string s;
    cin >> s;

    int ans = 0;
    for (int i = 0; i < m; i++)
    {
        int k = 0; // k�� IOI�� ����. IOI�� 1 , IOIOI�� 2
        // O�� ������ pass
        if (s[i] == 'O')
            continue;
        // s[i] == 'I'�� ��
        else
        {
            while (s[i + 1] == 'O' && s[i + 2] == 'I')
            {
                k++;
                if (k == n)
                {
                    k--; // �ߺ� ī��Ʈ�� ���� ���� -1 ���ش�.
                    ans++;
                }
                i += 2; // O�� �ǳ� �ڴ�.
            }
            k = 0;
        }
    }
    cout << ans;

    return 0;
}