#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
const int M = 200005;

int n, m;
int parent[N], h[N];
stack<int> st, ans;
pair<int, int> edge[M];

int root(int x)
{
    if (parent[x] == -1)
    {
        return x;
    }
    else
        return parent[x] = root(parent[x]);
}

int main()
{
    scanf("%d%d", &n, &m);

    memset(parent, -1, sizeof(parent));
    fill(h + 1, h + n + 1, 1);

    int a, b;
    int cnt = n;
    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d", &a, &b);
        edge[i] = {a, b};
    }

    for (int i = 1; i <= m; i++)
    {
        scanf("%d", &a);
        st.push(a);
    }

    while (not st.empty())
    {
        a = edge[st.top()].first;
        b = edge[st.top()].second;
        st.pop();

        int pa = root(a);
        int pb = root(b);

        ans.push(cnt);
        if (pa != pb)
        {
            if (h[pa] < h[pb])
                swap(pa, pb);

            parent[pb] = pa;
            h[pa] += h[pb];
            cnt--;
        }
    }

    while (not ans.empty())
    {
        printf("%d\n", ans.top());
        ans.pop();
    }

    return 0;
}

/*
4 6
1 2
1 3
1 4
2 3
2 4
3 4
6
5
4
3
2
1
*/