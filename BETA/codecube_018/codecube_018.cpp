#include <bits/stdc++.h>
using namespace std;

int num[1000002];

int main()
{
    cin.tie(NULL)->sync_with_stdio(false);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> num[i];
    }

    cout << *max_element(num, num + n) << "\n";
    cout << *min_element(num, num + n);

    return 0;
}