// Finding Common Passwords - Andrés Mejía
//
// Fast solution using suffix arrays. This one should pass.
#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <sstream>
#include <fstream>
#include <cassert>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <bitset>
#include <string>
#include <cstdio>
#include <vector>
#include <array>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <map>
#include <set>
using namespace std;

#define D(x) cerr << #x " is " << (x) << endl

vector<int> sort_cyclic_shifts(const vector<int>& s, int alphabetSize) {
  int n = s.size();
  vector<int> p(n), c(n), cnt(max(alphabetSize, n), 0);
  for (int i = 0; i < n; i++)
      cnt[s[i]]++;
  for (int i = 1; i < alphabetSize; i++)
      cnt[i] += cnt[i-1];
  for (int i = 0; i < n; i++)
      p[--cnt[s[i]]] = i;
  c[p[0]] = 0;
  int classes = 1;
  for (int i = 1; i < n; i++) {
      if (s[p[i]] != s[p[i-1]])
          classes++;
      c[p[i]] = classes - 1;
  }
  vector<int> pn(n), cn(n);
  for (int h = 0; (1 << h) < n; ++h) {
      for (int i = 0; i < n; i++) {
          pn[i] = p[i] - (1 << h);
          if (pn[i] < 0)
              pn[i] += n;
      }
      fill(cnt.begin(), cnt.begin() + classes, 0);
      for (int i = 0; i < n; i++)
          cnt[c[pn[i]]]++;
      for (int i = 1; i < classes; i++)
          cnt[i] += cnt[i-1];
      for (int i = n-1; i >= 0; i--)
          p[--cnt[c[pn[i]]]] = pn[i];
      cn[p[0]] = 0;
      classes = 1;
      for (int i = 1; i < n; i++) {
          pair<int, int> cur = {c[p[i]], c[(p[i] + (1 << h)) % n]};
          pair<int, int> prev = {c[p[i-1]], c[(p[i-1] + (1 << h)) % n]};
          if (cur != prev)
              ++classes;
          cn[p[i]] = classes - 1;
      }
      c.swap(cn);
  }
  return p;
}

vector<int> suffix_array_construction(vector<int> s, int alphabetSize) {
  s.push_back(0);
  vector<int> sorted_shifts = sort_cyclic_shifts(s, alphabetSize);
  sorted_shifts.erase(sorted_shifts.begin());
  return sorted_shifts;
}

vector<int> lcp_construction(const vector<int>& s, vector<int> const& p) {
  int n = s.size();
  vector<int> rank(n, 0);
  for (int i = 0; i < n; i++)
      rank[p[i]] = i;

  int k = 0;
  vector<int> lcp(n-1, 0);
  for (int i = 0; i < n; i++) {
      if (rank[i] == n - 1) {
          k = 0;
          continue;
      }
      int j = p[rank[i] + 1];
      while (i + k < n && j + k < n && s[i+k] == s[j+k])
          k++;
      lcp[rank[i]] = k;
      if (k)
          k--;
  }
  return lcp;
}

int works(const vector<int> &sa, const vector<int> &lcp, const vector<int>  &color, int K, int L) {
  for (int l = 0; l < sa.size(); ) {
    if (lcp[l] < L) {
      l++;
      continue;
    }

    int r = l;
    set<int> seenColors;
    while (r < sa.size() && lcp[r] >= L) {
      seenColors.insert(color[sa[r]]);
      r++;
    }
    assert(r < sa.size());
    seenColors.insert(color[sa[r]]);

    if (seenColors.size() >= K) {
      return sa[l];
    }

    l = r;
  }
  return -1;
}

void binarySearch(int N, const vector<int>& longString, const vector<int>& sa, const vector<int>& lcp, const vector<int>& color, int K) {
  int low = 0, high = sa.size();
  while (low < high) {
    int mid = (low + high + 1) / 2;
    int got = works(sa, lcp, color, K, mid);
    if (got == -1) {
      high = mid - 1;
    } else {
      low = mid;
    }
  }
  assert(low == high);
  if (low == 0) {
    cout << "*" << endl;
    return;
  }
  int i = works(sa, lcp, color, K, low);
  for (int at = i; at < i + low; at++) {
    assert(at < longString.size());
    assert(N + 1 <= longString[at] and longString[at] <= N + 1 + 26);
    cout << char('a' + longString[at] - N - 1);
  }
  cout << endl;
}

// Find longest substring that appears in at least K of the strings. In case of
// ties, find lexicographically smallest.
void solve(int N, int K) {
  vector<string> s(N);

  int totalLength = 0;
  for (int i = 0; i < N; ++i) {
    cin >> s[i];
    totalLength += s[i].size();
  }

  vector<int> longString, color;
  longString.reserve(totalLength + N);
  color.reserve(totalLength + N);
  for (int i = 0; i < N; ++i) {
    for (char c : s[i]) {
      longString.push_back(c - 'a' + N + 1);
      color.push_back(i + 1);
    }
    longString.push_back(i + 1); // $_i
    color.push_back(i + 1);
  }
  assert(longString.size() == totalLength + N);
  assert(color.size() == totalLength + N);

  vector<int> sa = suffix_array_construction(longString, N + 1 + 26);
  assert(sa.size() == totalLength + N);
  vector<int> lcp = lcp_construction(longString, sa);
  assert(lcp.size() == totalLength + N - 1);
  lcp.push_back(-1);

  if (K == 1) {
    // Special case. Find the longest string. In case of ties, pick the lexicographically smallest.
    vector<int> reverse_sa(sa.size());
    for (int i = 0; i < sa.size(); ++i) {
      reverse_sa[sa[i]] = i;
    }
    int bestString = 0;
    int bestSum = 0;
    for (int i = 0, sum = 0; i < s.size(); ++i) {
      int thisLength = s[i].size();
      if (thisLength > s[bestString].size() || thisLength == s[bestString].size() && reverse_sa[sum] < reverse_sa[bestSum]) {
        bestString = i;
        bestSum = sum;
      }
      sum += thisLength + 1;
    }
    cout << s[bestString] << endl;
    return;
  }

  // K >= 2.
  binarySearch(N, longString, sa, lcp, color, K);
}

int main() {
  int N, K;
  while (cin >> N >> K) {
    if (N == 0 and K == 0) break;
    assert(1 <= N and N <= 100000);
    assert(1 <= K and K <= N);
    solve(N, K);
  }
}
