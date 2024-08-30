#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <utility>
#include <iterator>
#include <cmath>
#include <limits>
#include <numeric>
#include <map>
#include <climits>
// #include <bits/stdc++.h>
using namespace std;

/*
glad to get this accepted!!
int main()
{
    optimize();
    int t;
    cin>>t;
    while(t--)
    {
        string s,t,ans="";
        cin>>s>>t;
        int a[30],i;
        memset(a,0,sizeof(a));
        for(i=0;i<t.size();i++)
        {
            int x = t[i]-'A';
            a[x]++;
        }

        for(i=s.size()-1;i>=0;i--)
        {
            int x = s[i]-'A';
            if(a[x])
            {
                ans+= s[i];
                a[x]--;
            }
        }
        reverse(ans.begin(),ans.end());
        if(ans==t) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}

the above is aa simpler version of the code (just build the string)
*/

#define ll long long

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s, t;
        cin >> s >> t;
        int n = s.length();
        int m = t.length();

        map<char, int> cnt;
        for (int i = 0; i < m; i++)
        {
            cnt[t[i]]++;
        }

        map<char, vector<int>> mp;
        for (int i = n - 1; i >= 0; i--)
        {
            if (mp[s[i]].size() < cnt[s[i]])
            {
                mp[s[i]].push_back(i);
            }
        }

        bool ok = true;
        if (mp.find(t[0]) != mp.end())
        {
            int curr = mp[t[0]].back();
            mp[t[0]].pop_back();
            int next = -1;
            for (int j = 1; j < m; j++)
            {
                if (mp[t[j]].size() > 0)
                    next = mp[t[j]].back();
                mp[t[j]].pop_back();
                if (next <= curr)
                {
                    ok = false;
                    break;
                }
                curr = next;
            }
        }
        else
            ok = false;
        if (!ok)
            cout << "no" << endl;
        else
            cout << "yes" << endl;
    }
    return 0;
}