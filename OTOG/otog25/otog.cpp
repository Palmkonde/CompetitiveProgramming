#include <bits/stdc++.h>
using namespace std;

int n;
string a;

string muti(string num1, string num2)
{
    int len1 = num1.size();
    int len2 = num2.size();

    if (len1 == 0 or len2 == 0)
        return "0";

    vector<int> temp(len1 + len2, 0);
    int idx1 = 0;
    int idx2 = 0;

    for (int i = len1 - 1; i >= 0; i--)
    {
        int carry = 0;
        int n1 = num1[i] - '0';

        idx2 = 0;

        for (int j = len2 - 1; j >= 0; j--)
        {
            int n2 = num2[j] - '0';

            int sum = n1 * n2 + temp[idx1 + idx2] + carry;

            carry = sum / 10;
            temp[idx1 + idx2] = sum % 10;

            idx2++;
        }

        if (carry > 0)
        {
            temp[idx1 + idx2] += carry;
        }

        idx1++;
    }

    int i = temp.size() - 1;
    while (i >= 0 and temp[i] == 0)
        i--;

    if (i == -1)
        return "0";

    string s = "";

    while (i >= 0)
        s += to_string(temp[i--]);

    return s;
}

string dive(string num1, int num2)
{
    string ans;

    int idx = 0;
    int temp = num1[idx] - '0';

    while (temp < num2)
    {
        temp = temp * 10 + (num1[++idx] - '0');
    }

    while (num1.size() > idx)
    {
        ans += (temp / num2) + '0';

        temp = (temp % num2) * 10 + num1[++idx] - '0';
    }

    if (ans.size() == 0)
        return "0";

    return ans;
}

int mod(string num1, int a)
{
    int res = 0;

    for (int i = 0; i < num1.length(); i++)
    {
        res = (res * 10 + (int)num1[i] - '0') % a;
    }

    return res;
}

int main()
{
    cin.tie(NULL)->sync_with_stdio(false);
    cin >> n;

    a = "1";
    cout << a << " ";

    for (int64_t i = 1; i <= n; i++)
    {
        int temp = n - i + 1;
        string now = dive(muti(a, to_string(temp)), i);

        cout << mod(now, 55555) << " ";
        a = now;
    }

    return 0;
}

/*
#include <bits/stdc++.h>
using namespace std;

int64_t n, a;
const int MOD = 55555;

int main()
{
    cin >> n;

    a = 1;
    cout << a << " ";

    for (int64_t i = 1; i <= n; i++)
    {
        int64_t now = ((a * (n - i + 1)) / i) % MOD;
        cout << now << " ";
        a = now;
    }

    return 0;
}
*/