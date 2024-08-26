#include <stdio.h>
#include <string.h>

int n, s;
int arr[1005];
char vis[1005];

int main()
{
    scanf("%d%d", &n, &s);

    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int cnt = 0, tmp;

    do
    {
        vis[s] = 1;
        cnt++;

        s = arr[s];
        if (s == 0)
            break;
    } while (vis[s] != 1);

    printf("%d", cnt);
}