#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

int n;
int arr[N];

int main()
{
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int cnt = n;

    while (cnt)
    {
        for (int i = 0; i < n; i++)
        {
            
        }

        printf("%d ", g);
        for (int i = 0; i < n; i++)
        {
            arr[i] /= g;

            if (arr[i] == 1)
                n--;
        }
    }

    return 0;
}