#observe constraints carefully to boil the problem down into an easier version

def solve():
    n, m = map(int, input().split())
    x = input()
    s = input()
    for i in range(6): # so we use observation of the constraints to make this constant time
        if s in x: # quadratic (n*m)
            print(i)
            return
        x += x
    print(-1)


for _ in range(int(input())):
    solve()

# CPP CODE -----------

#     #include <iostream>
# #include <string>
# using namespace std;

# void solve() {
#     int n, m;
#     cin >> n >> m;
#     string x, s;
#     cin >> x >> s;
    
#     for (int i = 0; i < 6; ++i) {
#         if (x.find(s) != string::npos) {
#             cout << i << endl;
#             return;
#         }
#         x += x;
#     }
#     cout << -1 << endl;
# }

# int main() {
#     int t;
#     cin >> t;
#     while (t--) {
#         solve();
#     }
#     return 0;
# }
