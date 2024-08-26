#include <stdio.h>
#include <stdlib.h>

#define N 10005
#define M 5005
#define MIN -1e9
#define max(x, y) ((x > y) ? x : y)

int n, m, k, x, y, r;
int areaX[M], areaY[M];

int main()
{
    scanf("%d%d%d", &n, &m, &k);

    for (int i = 0; i < k; i++)
    {
        scanf("%d%d%d", &x, &y, &r);
        areaX[(x - r < 0) ? 0 : (x - r)] += 1;
        areaX[(x + r + 1 >= n) ? n - 1 : (x + r + 1)] -= 1;
        areaY[(y - r < 0) ? 0 : (y - r)] += 1;
        areaY[(y + r + 1 >= m) ? m - 1 : (y + r + 1)] -= 1;
    }

    int mx = MIN;
    int temp = 0;
    for (int i = 0; i < n; i++)
    {
        temp += areaX[i];
        mx = max(mx, temp);
    }

    temp = 0;
    for (int i = 0; i < m; i++)
    {
        temp += areaY[i];
        mx = max(mx, temp);
    }

    printf("%d", mx);

    return 0;
}