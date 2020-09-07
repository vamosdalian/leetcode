#include "include.h"

using namespace std;

#define N 100005

struct Node
{
    string str;
    int num;   
}a[N];

int cmp1(Node A, Node B){
    if(A.num == B.num){
        return strcmp(A.str.c_str(), B.str.c_str()) < 0;
    }
    return A.num > B.num;
}

int cmp2(Node A, Node B){
    if(A.num == B.num){
        return strcmp(A.str.c_str(), B.str.c_str()) < 0;
    }
    return A.num < B.num;
}

unordered_map<string, int> M;
string s[N];
unordered_map<string, int> vis;

int main(int argc, char const *argv[])
{
    int n, k;
    M.clear();
    vis.clear();
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
        M[s[i]]++;
    }
    int len = 0;
    for (int i = 0; i < n; i++)
    {
        if(vis[s[i]] == 0){
            vis[s[i]] = 1;
            a[len].str = s[i];
            a[len++].num = M[s[i]];
        }
    }
    sort(a, a+len,cmp1);
    for (int i = 0; i < k; i++)
    {
        cout << a[i].str << " " << a[i].num << endl;
    }
    sort(a, a+len,cmp2);
    for (int i = 0; i < k; i++)
    {
        cout << a[i].str << " " << a[i].num << endl;
    }
    
    return 0;
}
