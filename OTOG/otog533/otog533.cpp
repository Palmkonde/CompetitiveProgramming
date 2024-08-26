#include <bits/stdc++.h>
#include "binary_search.h"
using namespace std;

int main()
{
    int64_t l = 0;
    int64_t r = get_n();
    int64_t mid;
    bool less = false;

    for (int i = 0; i < 50; i++)
    {
        mid = l + (r - l) / 2;

        if (i == 48 and is_equal(mid) != true)
        {
            if (is_less(mid))
            {
                less = true;
            }

            break;
        }

        if (is_equal(mid))
        {
            answer(mid);
            return 0;
        }

        else if (is_less(mid))
        {
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }

    while (!is_equal(mid))
    {
        if (less)
        {
            mid++;
        }
        else
        {
            mid--;
        }
    }

    answer(mid);
    return 0;
}