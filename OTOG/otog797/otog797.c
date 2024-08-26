#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char s[1005];
char tmp[3];
int ans[1005];

int stoi(char *t, int size)
{
    int res = 0;
    int pow = 1;

    for (int i = 1; i < size; i++)
        pow *= 10;

    for (int i = 0; i < size; i++)
    {
        res += (t[i] - '0') * pow;
        pow /= 10;
    }

    return res;
}

int main()
{
    scanf("%s", s);

    int i = 0, j = 0;
    int ss = 0;
    int aa;
    while (s[i] != '\0')
    {
        if (s[i] == ',')
        {
            aa = stoi(tmp, ss);
            ss = 0;

            printf("%c", aa);
            i++;
            continue;
        }

        tmp[ss++] = s[i];
        i++;
    }

    if (ss != 0)
    {
        aa = stoi(tmp, ss);
        printf("%c", aa);
    }

    return 0;
}