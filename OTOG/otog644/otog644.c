#include <stdio.h>
#include <string.h>

char dna[1000000][32];

void mSort(int l, int r)
{
    if (l >= r)
        return;

    int mid = l + (r - l) / 2;
    mSort(l, mid);
    mSort(mid + 1, r);

    int n1 = mid - l + 1;
    int n2 = r - mid;

    char temp1[n1][32], temp2[n2][32];

    for (int i = 0; i < n1; i++)
    {
        strcpy(temp1[i], dna[l + i]);
    }

    for (int j = 0; j < n2; j++)
    {
        strcpy(temp2[j], dna[mid + 1 + j]);
    }

    int i, j, k;
    i = 0;
    j = 0;
    k = l;

    while (i < n1 && j < n2)
    {
        if ((strcmp(temp1[i], temp2[j]) < 0) || (strcmp(temp1[i], temp2[j]) == 0))
        {
            strcpy(dna[k++], temp1[i++]);
        }
        else
        {
            strcpy(dna[k++], temp2[j++]);
        }
    }

    while (i < n1)
    {
        strcpy(dna[k++], temp1[i++]);
    }

    while (j < n2)
    {
        strcpy(dna[k++], temp2[j++]);
    }
}

int bs(char *x, int l, int r)
{
    if (l > r)
        return -1;

    int mid = l + (r - l) / 2;

    if (strcmp(x, dna[mid]) == 0)
    {
        return 1;
    }
    else if (strcmp(x, dna[mid]) > 0)
    {
        return bs(x, mid + 1, r);
    }
    else if (strcmp(x, dna[mid]) < 0)
    {
        return bs(x, l, mid - 1);
    }

    return -1;
}

int main()
{
    int n, q, len;

    scanf("%d %d %d", &n, &q, &len);

    for (int i = 0; i < n; i++)
    {
        scanf("%s", &dna[i]);

        for (int j = 0; j < len; j++)
        {
            switch (dna[i][j])
            {
            case 'A':
                dna[i][j] = 'T';
                break;
            case 'T':
                dna[i][j] = 'A';
                break;
            case 'C':
                dna[i][j] = 'G';
                break;
            case 'G':
                dna[i][j] = 'C';
                break;
            }
        }
    }

    // mSort
    mSort(0, n - 1);

    /*
    for (int i = 0; i < n; i++)
    {
        printf("%s ", dna[i]);
    }
    */

    for (int i = 0; i < q; i++)
    {
        char temp[32];

        scanf("%s", &temp);

        if (bs(temp, 0, n - 1) == 1)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }

    return 0;
}

/*
3 2 8
ACTCCGAT
ATCGACTC
CCGGCCGA
TGAGGCTA
AAAAAAAA
*/