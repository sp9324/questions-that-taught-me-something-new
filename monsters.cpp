#include <bits/stdc++.h>
 
using namespace std;

/*
using iota and stable sort
iota: This creates an index vector ord such that ord[0] = 0, ord[1] = 1, ..., ord[n-1] = n-1.
stable sort: The lambda function [&](int i, int j) { return a[i] > a[j]; } compares the values at indices i and j 
in a and sorts ord in descending order based on a[i] > a[j].
After sorting, ord contains the indices of elements in a arranged so that the elements in a appear in descending order.
*/

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto &x : a) {
      cin >> x;
      x %= k;
      if (!x) x = k;
    }
    vector<int> ord(n);
    iota(ord.begin(), ord.end(), 0);
    stable_sort(ord.begin(), ord.end(), [&](int i, int j) {
      return a[i] > a[j];
    });
    for (auto &x : ord) cout << x + 1 << ' ';
    cout << endl;
  }
}