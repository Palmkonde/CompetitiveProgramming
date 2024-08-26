#include <bits/stdc++.h>
using namespace std;

int n;
int num[500005];
vector<int> odd, idx;
int main()
{
    cin.tie(NULL)->sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> num[i];

        if (num[i] % 2 == 0)
        {
            idx.push_back(i);
            odd.push_back(num[i]);
        }
    }

    sort(odd.begin(), odd.end());

    int k = 0;
    int m = 0;
    for (int i = 0; i < n; i++)
    {
        if (i)
            cout << " ";
        if (idx[m] == i)
        {
            cout << odd[k++];
            m++;
        }

        else
        {
            cout << num[i];
        }
    }

    return 0;
}

/*
6
9 8 7 6 2 3

 */