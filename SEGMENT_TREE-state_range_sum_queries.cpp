#include <iostream>
using namespace std;

const int MAXN = 200005;
long long a[MAXN], seg[4 * MAXN];

// Build the segment tree for range sum
void build(int ind, int low, int high)
{
    if (low == high)
    {
        seg[ind] = a[low];
        return;
    }
    int mid = (low + high) / 2;
    build(2 * ind + 1, low, mid);
    build(2 * ind + 2, mid + 1, high);
    seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2]; // Sum of left and right children
}

// Query the segment tree for range sum
long long query(int ind, int low, int high, int l, int r)
{
    // If the current range [low, high] is completely within the query range [l, r]
    if (l <= low && high <= r)
    {
        return seg[ind];
    }
    // If the current range [low, high] is completely outside the query range [l, r]
    if (high < l || low > r)
    {
        return 0;
    }
    // Partial overlap case
    int mid = (low + high) / 2;
    return query(2 * ind + 1, low, mid, l, r) + query(2 * ind + 2, mid + 1, high, l, r);
}

int main()
{
    int n, q;
    cin >> n >> q;

    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }

    // Build the segment tree
    build(0, 0, n - 1);

    // Process each query
    while (q--)
    {
        int a, b;
        cin >> a >> b;
        // Convert to 0-based index for internal processing
        cout << query(0, 0, n - 1, a - 1, b - 1) << endl;
    }

    return 0;
}
