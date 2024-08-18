#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <utility>
#include <iterator>
#include <cmath>
#include <limits>
// #include <bits/stdc++.h>
using namespace std;

/*
signed main(){
		char a[200];int b;
		char tmp;
		tmp=getchar();
		while(tmp!='.') write(tmp),tmp=getchar();
		if(1){
			char a = getchar();
			char b = getchar();
			char c = getchar();
			if(a=='0'&&b=='0'&&c=='0') return 0;
			write('.');
			if(c!='0') write(a),write(b),write(c);
			else if(b!='0') write(a),write(b);
			else write(a);
			
		}
		return 0;
	}

the above solution makes use of the fact that there are only 3 decimal places, so we dont need a while loop for that part.
*/

int main()
{
    string x;
    cin >> x;
    int n = x.length();
    int i = n - 1;
    string ans = "";
    while (i >= 0 && x[i] == '0')
    {
        // cout << "not appending" << endl;
        i--;
        if (x[i] == '.')
        {
            i--;
            break;
        }
    }
    while (i >= 0)
    {
        // cout << "appending" << endl;
        // cout << x[i] << endl;
        ans += x[i];
        // cout << ans << endl;
        i--;
    }
    if (i <= 0 && ans == "")
        cout << "0" << endl;
    else
    {
        // cout << "reversing" << endl;
        reverse(ans.begin(), ans.end());
        cout << ans << endl;
    }
    return 0;
}