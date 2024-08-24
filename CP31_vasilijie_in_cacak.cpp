#include <iostream>
using namespace std;

#define ll long long

/*
WHAT I LEARNT:
cp is different from dsa in the sense that you would observe patterns. this question could be done using 
dp, but the numbers given are in sequence. so, a more straightforward algo is used. moreover, to optimize, we can use 
the direct formula for sum instead of looping over the elements. ->make sure to optimize in problem Cs.
*/

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n, k, x;
        cin >> n >> k >> x;
        
        // Calculate the minimum sum of the first k natural numbers
        ll mn = k * (k + 1) / 2;
        
        // Calculate the maximum sum of the last k natural numbers from n
        ll mx = k * (2 * n - k + 1) / 2;

        if (x >= mn && x <= mx)
            cout << "yes" << endl;
        else
            cout << "no" << endl;
    }
    return 0;
}