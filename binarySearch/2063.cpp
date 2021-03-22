#include <bits/stdc++.h>
using namespace std;
int main()
{ 
  int n; 
  int a[100001]; 
  cin >> n; 
  for (int i = 1; i <= n; ++i) 
    cin >> a[i]; 
  int q, m; 
  cin >> q; 
  for (int i = 1; i <= q; ++i) 
 { 
    cin >> m; 
    if (*lower_bound(a + 1, a + 1 + n, m) == m) 
      cout << "Yes\n"; 
    else 
      cout << "No\n"; 
 } 
  return 0; 
}