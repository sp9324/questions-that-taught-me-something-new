#include <cassert>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

/*
WHAT I LEARNT:
The lower_bound() method in C++ is used to return an iterator pointing to the first element in the range [first, last) which has a value not less than val.
begin points to first element of set. !=end checks if that element is present in the set or not.
Why not upper_bound?
upper_bound would return an iterator that strictly points to the element greater than the target value R or C. In the "down" and "right" cases, we need the element that is equal to 
or greater than the current value, so upper_bound would skip over the element we're interested in.
In the "up" and "left" cases, upper_bound would still skip over the element we're currently pointing to, while we want to check the one just before the target.
*/

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  int H, W, Q;
  cin >> H >> W >> Q;

  vector<set<int>> g1(H), g2(W);
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      g1[i].insert(j);
      g2[j].insert(i);
    }
  }

  auto erase = [&](int i, int j) { g1[i].erase(j), g2[j].erase(i); };

  while (Q--) {
    int R, C;
    cin >> R >> C;
    --R, --C; // to convert to 0 based

    if (g1[R].count(C)) {
      erase(R, C);
      continue;
    }

    // up
    {
      auto it = g2[C].lower_bound(R);
      if (it != begin(g2[C])) erase(*prev(it), C);
    }
    // down
    {
      auto it = g2[C].lower_bound(R);
      if (it != end(g2[C])) erase(*it, C);
    }
    // left
    {
      auto it = g1[R].lower_bound(C);
      if (it != begin(g1[R])) erase(R, *prev(it));
    }
    // right
    {
      auto it = g1[R].lower_bound(C);
      if (it != end(g1[R])) erase(R, *it);
    }
  }

  int ans = 0;
  for (int i = 0; i < H; i++) ans += g1[i].size();
  cout << ans << "\n";
}
