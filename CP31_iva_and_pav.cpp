// #include <bits/stdc++.h>
// using namespace std;

// #define ll long long
// #define nl "\n"
// #define all(x) (x).begin(), (x).end()
// #define inp(i, a, n)                   \
//     for (int(i) = 0; (i) < (n); (i)++) \
//         cin >> (a[(i)]);

// void solveTest()
// {
//     int n;
//     cin >> n;
//     vector<ll> a(n, -1);
//     inp(i, a, n);
//     int q;
//     cin >> q;
//     while (q--)
//     {
//         int l, k;
//         cin >> l >> k;
//         l-=1;
//         int r = -1;
//         if (a[l] >= k)
//         {
//             r = l;
//             ll ans = a[l];
//             for (int i = l + 1; i < n; i++)
//             {
//                 ans &= a[i];
//                 if (ans >= k)
//                 {
//                     r = i;
//                 }
//             }
//         }
//         if(r==-1) cout<<"-1 "<<nl;
//         else cout<<r+1<<" ";
//     }
//     cout << nl;
//     return;
// }
// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);
//     int tt;
//     cin >> tt;
//     while (tt--)
//         solveTest();
//     return 0;
// }

/*
PREFIX SUMS for bits ->new concept :)
binary search
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
 
const int N =200003;
const int bits=30;
int pref[N][bits];
int a[N];
void Buildprefix(int n){ //Builds the prefix sums for each bit
    for(int i=0; i< n; i++){
        for(int j=0; j<30; j++){
            if(a[i]&(1<<j)){
                pref[i+1][j]=pref[i][j]+1;
            }
            else{
                pref[i+1][j]=pref[i][j];
            }
        }
    }
}
void solve(){
    int n;
    cin >> n;
    for(int i=0; i< n; i++){
        cin >> a[i];
    }
    Buildprefix(n);
    int q;
    cin >> q;
    while(q--){
        int l, k;
        cin >> l >> k;
        if(a[l-1]<k){
            cout << -1 << '\n';
            continue;
        }
        int lo=l;
        int hi=n;
        int ans=l;
        while(lo<=hi){
            int s=(lo+hi)/2;
            int num=0;
            for(int j=0; j< bits; j++){
                if(pref[s][j]-pref[l-1][j]==s-l+1){
                    num+=(1<<j);
                }
            }
            if(num>=k){
                lo=s+1;
                ans=max(ans, s);
            }
            else hi=s-1;
        }
        cout << ans << '\n';
    }
}
 
int main(){
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
}