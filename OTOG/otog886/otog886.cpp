#include <bits/stdc++.h>
using namespace std;

multiset<int> st;

bool usePakpim(int x)
{
    bool fg = false;
    if (st.find(x) != st.end())
    {
        fg = true;
    }

    st.insert(x);
    return fg;
}

int usePeteza()
{
    int mx = INT_MAX;

    if (st.empty())
        return mx;
    else
    {
        mx = *st.rbegin();
        st.erase(st.find(mx));
    }
    return mx;
}

int useBlackslex()
{
    int mn = INT_MIN;
    if (st.empty())
        return mn;

    else
    {
        mn = *st.begin();
        st.erase(st.begin());
    }
    return mn;
}