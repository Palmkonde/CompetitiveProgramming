#include <bits/stdc++.h>
using namespace std;

int n;
int main()
{
    scanf("%d", &n);

    int row = ((n - 3) * 2) + 5;
    int col = ((n * 4) - 1) + 3;
    int r = 2;

    for (int i = 1; i <= row; i++)
    {
        if (i == 1)
        {
            int tmp = n;
            for (int k = 1; k <= 4; k++)
            {

                if (k == 4)
                    tmp--;

                for (int j = 1; j <= tmp; j++)
                {
                    printf("#");
                }
                printf(" ");
            }
        }

        else if (i != ceil(row / 2.0) and i < ceil(row / 2.0))
        {
            for (int j = 1; j <= 4; j++)
            {
                for (int k = 1; k <= n; k++)
                {
                    if (j == 1)
                    {
                        if (k == 1)
                            printf("#");

                        else
                            printf(" ");
                    }

                    else
                    {
                        if (k == 1 or k == n)
                            printf("#");

                        else
                            printf(" ");
                    }
                }
                printf(" ");
            }
        }

        else if (i == ceil(row / 2.0))
        {
            for (int j = 1; j <= 4; j++)
            {
                for (int k = 1; k <= n; k++)
                {
                    if (j == 1 or j == 3)
                    {
                        printf("#");
                    }

                    else
                    {
                        if (k == 1 or k == n)
                            printf("#");

                        else
                            printf(" ");
                    }
                }
                printf(" ");
            }
        }

        else if (i != row and i > ceil(row / 2.0))
        {
            for (int j = 1; j <= 4; j++)
            {
                for (int k = 1; k <= n; k++)
                {
                    if (j == 1)
                    {
                        if (k == 1)
                            printf("#");
                        else
                            printf(" ");
                    }
                    else if (j == 3)
                    {
                        if (k == r or k == 1)
                            printf("#");
                        else
                            printf(" ");
                    }
                    else if (j == 2 or j == 4)
                    {
                        if (k == 1 or k == n)
                            printf("#");
                        else
                            printf(" ");
                    }
                }
                printf(" ");
            }
            r++;
        }

        else if (i == row)
        {
            int tmp = n;
            for (int j = 1; j <= 4; j++)
            {
                if (j == 4)
                    tmp--;

                for (int k = 1; k <= tmp; k++)
                {
                    if (j == 1)
                    {
                        if (k == 1)
                            printf("#");
                        else
                            printf(" ");
                    }

                    if (j == 2)
                    {
                        printf("#");
                    }
                    else if (j == 3)
                    {
                        if (k == 1 or k == r)
                        {
                            printf("#");
                        }
                        else
                            printf(" ");
                    }

                    else if (j == 4)
                    {
                        printf("#");
                    }
                }
                printf(" ");
            }
        }

        printf("\n");
    }

    return 0;
}
