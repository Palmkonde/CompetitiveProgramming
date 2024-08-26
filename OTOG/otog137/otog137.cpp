#include<bits/stdc++.h>
using namespace std;

const int N = 102;

int n;
vector<string> w;
string code;

int main()
{
    cin.tie(NULL)->sync_with_stdio(false);

    cin >> n;
    for(int i=0;i<n;i++)
    {
        string temp;
        cin >> temp;
        w.push_back(temp);
    }

    sort(w.begin(),w.end(),[](const string a,const string b){
        return a.length() > b.length();
    });
    
    cin >> code;
    
    for(int i=0;i<code.length();i++)
    {
    
    }

    return 0;
}

/*
แนวคิด

A
AB
BA
BBC
CA

ABABACABAABCB


ตัวที่เป็นไปได้ ดูที่ 1
A
AB

ตัวที่เป็นไปได้ ดูที่ 2 (B)
A + เอามาใส่ใหม่ได้ (ใส่อะไรดี) (BA)ใส่ได้
AB ยังอยู่ระหว่างพิจารณา ข้ามไป

ตัวที่ 3 (A) check ว่าใส่คำใหม่ได้มั้ย
A + BA ใส่ไม่ได้
AB + ใส่คำใหม่ได้(เพราะเพิ่งจบจากคำที่แล้ว) ใส่(AB) หรือ 
AB + A

ตัวที่ 4 (B)
A + BA + คำใหม่
AB + AB ใส่ไม่ได้
AB + A + BA

ซ้ำไปรื่อยๆ

sol พี่ต่อ
bool N
ติ๊กถูกตรงคำที่สามารถเพิ่มคำได้ แล้วก็วนไปเรื่อยๆ
*/