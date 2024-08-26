#include <stdio.h>
#include <stdlib.h>

int n, m;

void recur(int x, int y)
{
    if (y > m)
        return;

    printf("%d x %d = %d\n", x, y, x * y);
    recur(x, y + 1);
}

int main()
{
    scanf("%d%d", &n, &m);

    recur(n, 1);
    return 0;
}