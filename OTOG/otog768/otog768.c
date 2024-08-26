#include <stdio.h>
#define ll long long

ll n;

int main()
{
    scanf("%lld", &n);

    if (n <= 1)
    {
        printf("No");
        return 0;
    }

    for (size_t i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            printf("No");
            return 0;
        }
    }

    printf("Yes");
    return 0;
}
