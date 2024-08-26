#include<bits/stdc++.h>
using namespace std;

struct Vertex {
    int left, right;
    int sum = 0;
    Vertex *left_child = nullptr, *right_child = nullptr;

    Vertex(int lb, int rb) {
        left = lb;
        right = rb;
    }

    void extend() {
        if (!left_child && left + 1 <= right) {
            int mid = left + (right-left)/2;
            left_child = new Vertex(left, mid);
            right_child = new Vertex(mid+1, right);
        }
    }

    void add(int k, int x, char cmd) {
        extend();
        //cout << left << " " << right << "\n";
        if (left_child) {
            if (k <= left_child->right)
                left_child->add(k, x,cmd);
            else
                right_child->add(k, x,cmd);
        }
        
        
        if(left == right)
        {
            if(cmd == 'G') sum += x;
            else if(cmd == 'S') sum = x;
        }
        if(left_child and right_child) sum = left_child->sum + right_child->sum;

        //cout << sum << "\n";
    }

    int get_sum(int lq, int rq) {
        if (lq <= left && right <= rq)
            return sum;
        if (max(left, lq) > min(right, rq))
            return 0;
        extend();
        return left_child->get_sum(lq, rq) + right_child->get_sum(lq, rq);
    }
};

char cmd;
int l,r;
vector<tuple<char,int,int>> s;

int main()
{
    int mn = INT_MAX, mx = INT_MIN;
    while(cin >> cmd >> l >> r)
    {
        mn = min(mn,l);
        mx = max(mx,r);
        s.push_back({cmd,l,r});
    }

    Vertex Tree(mn,mx);

    for(int i=0;i<s.size();i++)
    {
        tie(cmd,l,r) = s[i];
        if(cmd == 'S') Tree.add(l,r,cmd);
        if(cmd == 'G') Tree.add(l,r,cmd);
        if(cmd == 'Q') cout << Tree.get_sum(l,r) << "\n";
    }

    return 0;
}