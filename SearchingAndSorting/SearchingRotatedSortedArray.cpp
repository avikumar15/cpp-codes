#include <iostream>

using namespace std;

#include<bits/stdc++.h>

void solve() {
  int n;
  cin >> n;
  int temp;
  vector < int > vec;

  for (int i = 0; i < n; i++) {
    cin >> temp;
    vec.push_back(temp);
  }

  int k;
  cin >> k;

  int l = 0;
  int h = n - 1;
  int m = l + (h - l) / 2;
  int ans = 0;

  while (h > l) {
    m = l + (h - l) / 2;

    if (vec[l] > vec[l + 1]) {
      ans = l;
      break;
    }
    if (vec[h - 1] > vec[h]) {
      ans = h - 1;
      break;
    }
    if (vec[m] > vec[m + 1]) {
      ans = m;
      break;
    } else if (vec[m] > vec[l]) {
      l = m + 1;
    } else {
      h = m - 1;
    }

  }

  for (int i = l - 2; i <= l + 2; i++) {
    if (i < 0 || i >= n)
      continue;
    if (vec[i] > vec[(i + 1) % n]) {
      ans = i;
      break;
    }
  }
  
  int final = -1;
  l = 0;
  h = ans;

  while (h > l) {
    m = l + (h - l) / 2;
    if (vec[m] == k) {
      final = m;
      break;
    } else if (vec[m] < k) {
      l = m + 1;
    } else {
      h = m - 1;
    }
  }

  if (vec[l] == k) {
    final = l;
  }
  

  if (final == -1) {
    l = ans + 1;
    h = n - 1;

    while (h > l) {
      m = l + (h - l) / 2;
      if (vec[m] == k) {
        final = m;
        break;
      } else if (vec[m] < k) {
        l = m + 1;
      } else {
        h = m - 1;
      }
    }
    
    if (vec[l] == k) {
      final = l;
    }

  }

  cout << final << endl;

}
int main() {
  int t;
  cin >> t;

  while (t--) {
    solve();
  }
  return 0;
}
