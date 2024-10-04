#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class UnionFind {
private:
    vector<int> parents;
    vector<vector<int>> member;

public:
    UnionFind(int n) {
        parents.resize(n, -1);
        member.resize(n);
        // Initialize each connected component with one vertex
        for (int i = 0; i < n; i++) {
            member[i].push_back(i);
        }
    }

    int find(int x) {
        if (parents[x] < 0) {
            return x;
        } else {
            return parents[x] = find(parents[x]); // Path compression
        }
    }

    void merge(int x, int y) {
        x = find(x);
        y = find(y);

        if (x == y) {
            return;
        }

        // Union by size, ensuring the larger root becomes the parent
        if (parents[x] > parents[y]) {
            swap(x, y);
        }

        parents[x] += parents[y];
        parents[y] = x;

        // Merge the information of children y into that of parent x
        member[x].insert(member[x].end(), member[y].begin(), member[y].end());
        sort(member[x].rbegin(), member[x].rend()); // Sort in descending order
        if (member[x].size() > 10) {
            member[x].resize(10); // Keep only the 10 largest vertices
        }
    }

    int getKthLargest(int v, int k) {
        v = find(v);
        if (member[v].size() < k) {
            return -1;
        } else {
            return member[v][k - 1];
        }
    }
};

int main() {
    int N, Q;
    cin >> N >> Q;
    UnionFind uf(N + 1);

    for (int i = 0; i < Q; i++) {
        int type;
        cin >> type;
        if (type == 1) {
            int u, v;
            cin >> u >> v;
            uf.merge(u, v);
        } else if (type == 2) {
            int v, k;
            cin >> v >> k;
            cout << uf.getKthLargest(v, k) << endl;
        }
    }

    return 0;
}
