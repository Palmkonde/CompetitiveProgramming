#include <stdio.h>
#include <string.h>

char buff[1005];
char https[] = {'h', 't', 't', 'p', 's'};

int main()
{
    int first = 1;
    while (scanf("%s", buff) != EOF)
    {
        int fg = 0;
        if (strlen(buff) >= 5)
        {
            char tmp[10];
            for (int i = 0; i < 5; i++)
            {
                tmp[i] = buff[i];
            }
            tmp[5] = '\0';

            if (strcmp(tmp, https) == 0)
            {
                fg = 1;
            }
        }

        if (fg)
            (first) ? printf("%s", buff) : printf("\n%s", buff);
        else
            printf("%s", buff);

        first = 0;
    }
    return 0;
}