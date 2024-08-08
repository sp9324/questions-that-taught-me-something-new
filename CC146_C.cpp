/*
SECOND METHOD:
soet the array, the ans is checkpow(idx+1) => this comes from observing the pattern.. can be
extended to more thatn 16 easily
coplexities of both are similar, but the actual one is simpler to implement and can be extended to more than 16 also
*/
ll checkpow(ll n)
{
    if (n == 16)
        return 4;
    if (n >= 8)
        return 3;
    if (n >= 4)
        return 2;
    if (n >= 2)
        return 1;
    return 0;
}

void solve()
{
    ll arr[16];
    inputArr(16, arr);

    ll brr[16] = {0};
    for (ll i = 0; i < 16; i++)
        brr[i] = arr[i];

    sort(brr, brr + 16);

    map<ll, ll> hm;
    for (ll i = 0; i < 16; i++)
        hm[brr[i]] = i + 1;

    for (ll i = 0; i < 16; i++)
    {
        cout << checkpow(hm[arr[i]]) << " ";
    }
    cout << nl;
}

int main()
{
    file();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}

/*
-----------MY CODE------------
*/

// #include <bits/stdc++.h>
// using namespace std;

// int main() {
// 	// your code goes here
//     int t;
//     cin>>t;
//     while(t--) {
//         vector<int>nums(16, -1);
//         for(int i=0; i<16; i++) {
//             int ele;
//             cin>>ele;
//             nums[i]=ele;
//         }
//         unordered_map<int, int>mp;
//         vector<int>temp=nums;
//         sort(temp.begin(), temp.end());
//         mp[temp[0]]=0;
//         for(int i=1; i<=2; i++) {
//             mp[temp[i]]=1;
//         }
//         for(int i=3; i<=6; i++) {
//             mp[temp[i]]=2;
//         }
//         for(int i=7; i<=14; i++) {
//             mp[temp[i]]=3;
//         }
//         mp[temp[15]]=4;

//         for(int i=0; i<16; i++) {
//             nums[i]=mp[nums[i]];
//             cout<<nums[i]<<" ";
//         }
//         cout<<endl;
//     }
// }
