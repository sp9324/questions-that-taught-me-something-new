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
glad to have got the solution exactly right during the contest!
getting to the root of the problem wa key. the sum shd be xc*k and yc*k-> figure out the easiest way to get this
*/

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int x, y, k;
        cin >> x >> y >> k;
        if (k % 2 == 0)
        {
            int j = 1;
            for (int i = 0; i < k; i++)
            {
                if (i % 2 == 0)
                    cout << x - j << " " << y + j << endl;
                else
                    cout << x + j << " " << y - j << endl;
                if (i % 2 != 0)
                    j++;
            }
        }
        else
        {
            int j = 1;
            for (int i = 0; i < k - 1; i++)
            {
                if (i % 2 == 0)
                    cout << x - j << " " << y + j << endl;
                else
                    cout << x + j << " " << y - j << endl;
                if (i % 2 != 0)
                    j++;
            }
            cout << x << " " << y << endl;
            // cout << endl;
        }
    }
    return 0;
}

/*
the below code only changes x coord and keeps y same. it is more concise.
ans: (𝑥𝑐−1,𝑦𝑐),(𝑥𝑐+1,𝑦𝑐),(𝑥𝑐−2,𝑦𝑐),(𝑥𝑐+2,𝑦𝑐),...,(𝑥𝑐−⌊𝑘2⌋,𝑦𝑐),(𝑥𝑐+⌊𝑘2⌋,𝑦𝑐)
*/

// #include <iostream>
// using namespace std;

// int main() {
// 	int t; cin >> t;
// 	while(t--){
// 		int x, y, k; cin >> x >> y >> k;
// 		for(int i = 0; i < k - k % 2; i++){
// 			cout << x - (i & 1 ? 1 : -1) * (i / 2 + 1) << " " << y << "\n";
// 		} 
// 		if(k & 1){
// 			cout << x << " " << y << "\n";
// 		}
// 	}
// }