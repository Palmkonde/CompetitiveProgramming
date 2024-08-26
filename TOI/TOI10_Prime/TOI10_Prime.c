#include <stdio.h>
#define N 10000000

unsigned char fg[N + 5];
int ans[N + 5];

int main()
{

    int n;
    scanf("%d", &n);

    int idx = 1;
    for (int i = 2; i < N; i++)
    {
        if (fg[i])
            continue;

        ans[idx++] = i;
        for (int j = 2 * i; j < N; j += i)
        {
            fg[j] = 1;
        }
    }

    printf("%d", ans[n]);

    return 0;
}