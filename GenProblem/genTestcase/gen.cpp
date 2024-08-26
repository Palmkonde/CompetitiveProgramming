#include<bits/stdc++.h>
#include "D:\CodingProject\Cpp_C\Problem\GenProblem\testlib.h"
using namespace std;
using ll = long long;

const int N = 10000;
const int Q = 100;
const ll MAX_A_I = 1e12;
// 2 <= K <= N;

int main(int argc, char* argv[])
{
    registerGen(argc,argv,1);
    
    // for(int i=1;i<=3;i++) //Brute force N <= 1000, Q = 1, MAX_A_I = 100
    // {
    //     string path = "D:\\CodingProject\\Cpp_C\\Problem\\GenProblem\\inandsol\\" + to_string(i) + ".in";
    //     freopen(path.c_str(),"w",stdout);
        
    //     int n = rnd.next(1,1000);
    //     int q = 1; //rnd.next(1,Q);

    //     cout << n << " " << q << "\n";

    //     for(int j=0;j<n;j++) //generate array
    //     {
    //         cout << rnd.next(1,100) << " ";
    //     }

    //     cout << "\n";
    //     cout << rnd.next(1,n);

    //     fclose(stdout);
    // }

    for(int i=4;i<=4;i++) //K = 1 or K = N, N, Q, MAX_A_I
    {
        string path = "D:\\CodingProject\\Cpp_C\\Problem\\GenProblem\\inandsol\\" + to_string(i) + ".in";
        freopen(path.c_str(),"w",stdout);
        
        int n = rnd.next(1,N);
        int q = rnd.next(1,Q);

        cout << n << " " << q << "\n";

        for(int j=0;j<n;j++) //generate array
        {
            ll tmp = rnd.next(LLONG_MAX)%MAX_A_I;
            cout << (tmp == 0 ? 1 : tmp) << " ";
        }
        
        vector<int> k{1,n};
        cout << "\n";
        for(int j=0;j<q;j++)
        {
            cout << rnd.any(k) << "\n";
        }

        fclose(stdout);
    }

    for(int i=5;i<=6;i++) //same A_I, N, Q, MAX_A_I
    {
        string path = "D:\\CodingProject\\Cpp_C\\Problem\\GenProblem\\inandsol\\" + to_string(i) + ".in";
        freopen(path.c_str(),"w",stdout);
        
        int n = rnd.next(1,N);
        int q = rnd.next(1,Q);

        cout << n << " " << q << "\n";

        ll tmp = rnd.next(LLONG_MAX)%MAX_A_I;
        tmp = (tmp == 0 ? 1 : tmp);

        for(int j=0;j<n;j++) //generate array
        {
            cout << tmp << " ";
        }
        
        cout << "\n";
        for(int j=0;j<q;j++)
        {
            cout << rnd.next(1,n) << "\n";
        }

        fclose(stdout);
    }

     for(int i=7;i<=10;i++) //no other condition
    {
        string path = "D:\\CodingProject\\Cpp_C\\Problem\\GenProblem\\inandsol\\" + to_string(i) + ".in";
        freopen(path.c_str(),"w",stdout);
        
        int n = rnd.next(5000,N);
        int q = rnd.next(50,Q);

        cout << n << " " << q << "\n";

        for(int j=0;j<n;j++) //generate array
        {
            ll tmp = rnd.next(LLONG_MAX)%MAX_A_I;
            tmp = (tmp == 0 ? 1 : tmp);
            cout << tmp << " ";
        }
        
        cout << "\n";
        for(int j=0;j<q;j++)
        {
            cout << rnd.next(1,n) << "\n";
        }

        fclose(stdout);
    }

    return 0;
}