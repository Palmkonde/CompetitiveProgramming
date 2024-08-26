#include <bits/stdc++.h>
using namespace std;

int n;
priority_queue<int> pq;

int main()
{
    scanf("%d", &n);
    while (n--)
    {
        char c;
        int q;

        scanf(" %c", &c);
        if (c == 'Q')
        {
            if (pq.empty())
            {
                printf("-1\n");
            }
            else
            {
                int t = pq.top();
                pq.pop();

                printf("%d\n", t);
            }
        }

        else if (c == 'P')
        {
            scanf("%d", &q);
            pq.push(q);
        }
    }

    return 0;
}

/*
7
P 11516
P 25485
Q
Q
P 2634
Q
Q
*/