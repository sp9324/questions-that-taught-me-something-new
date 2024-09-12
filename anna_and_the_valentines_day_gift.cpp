#include <bits/stdc++.h>

#define all(arr) arr.begin(), arr.end()

/*
WHAT I LEARNT:
simulation does not only mean brute force. this solution does not involve any trick; it just uses a basic observation and 
cleverly implements it using storing of values in arrays.
the key observations to be made were:
1. number of digits matter ONLY (the parameter was 10^m, not anythin else^m->this was a hint)
->how zeroes are to be preserved and removed optimally was the only tough point in this question.
*/

using namespace std;

const int MAXN = 200200;

int n, m;
string arr[MAXN];
// len stores length of each number in array. zrr stores number of trailing zeroes in each number in the array.
// (and arr is an array of strings for convenience)
int len[MAXN], zrr[MAXN];

void build()
{
    memset(zrr, 0, sizeof(*zrr) * n);
    for (int i = 0; i < n; ++i)
    {
        len[i] = arr[i].size();
        // this uses a reverse iterator. it runs until the end (or until 1st non zero digit is encountered).
        for (auto it = arr[i].rbegin(); it != arr[i].rend() && *it == '0'; ++it)
        {
            ++zrr[i];
        }
    }
}

string solve()
{
    int ans = 0;
    /*this first initialises ans (which is the variable which we will compare with 10^m in
    the end to the total number of non zero digits. anna can definitely not remove these digits.)
    */
    for (int i = 0; i < n; ++i)
    {
        ans += len[i] - zrr[i];
    }
    // sort the array with number of zeroes in reverse order. we ge max number of zeroes first.
    sort(zrr, zrr + n);
    reverse(zrr, zrr + n);
    for (int i = 0; i < n; ++i)
    {
        /*every odd i is sasha's turn. he will preserve the zeroes at his turn.*/
        if (i & 1)
            ans += zrr[i];
    }
    return (ans - 1 >= m ? "Sasha" : "Anna");
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        build();
        cout << solve() << '\n';
    }
}