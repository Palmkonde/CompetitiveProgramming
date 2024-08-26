#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using pii = pair<ll, ll>;

const int N = 3035;
ll h[N];
int n;

int main()
{
    while (scanf("%d", &n))
    {
        if (n == 0)
            break;

        for (int i = 0; i < n; i++)
        {
            scanf("%d", &h[i]);
        }

        vector<ll> pr(n, -1), hr(n, 0);
        stack<pii> st;

        st.push({-1, -1});

        for (int i = 0; i < n; i++)
        {
            if (st.top().first != -1 and st.top().first < h[i])
            {
                pr[i] = st.top().second;
                st.push({h[i], i});
            }

            else
            {
                while (h[i] <= st.top().first and st.top().first != -1)
                {
                    st.pop();
                }

                pr[i] = st.top().second;
                st.push({h[i], i});
            }
        }

        st.pop();
        st.push({-1, n});

        for (int i = n - 1; i >= 0; --i)
        {
            if (st.top().first != -1 and st.top().first < h[i])
            {
                hr[i] = st.top().second;
                st.push({h[i], i});
            }

            else
            {
                while (h[i] <= st.top().first and st.top().first != -1)
                {
                    st.pop();
                }

                hr[i] = st.top().second;
                st.push({h[i], i});
            }
        }

        ll mx = -1;
        for (int i = 0; i < n; i++)
        {
            if (mx < (hr[i] - pr[i] - 1) * h[i])
            {
                mx = (hr[i] - pr[i] - 1) * h[i];
            }
        }

        printf("%lld\n", mx);
    }
    return 0;
}

/*
7
2 1 4 5 1 3 3
0
*/