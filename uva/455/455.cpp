//
//  455.cpp
//  Problems
//
//  Created by NicolasCardozo on 5/04/22.
//  Copyright © 2022 NicolasCardozo. All rights reserved.
//

/*
Problem link
Type: string process, kmp, adhoc
Algorithm:

- For each prefix of the input of length i:
  + Use KMP or naive string matching to find all occurrences.
  + Check if the occurrences are periodic.

- In this problem I use KMP for string matching.
- The function kmpProcess() build the "reset table" b for string "s".
- The function kmpSearch() find all occurrences of "pattern" in input string "s".
- The solve() function generates all prefix of length "i" from 1 to n.
  Run kmpSearch() on each prefix and check if it is a period of input string.
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

const int maxn = 100;

string s;
int b[maxn];
int res[maxn];

void kmpProcess(string s, int b[]) {
 int i = 0, j = -1;
 b[0] = j;
 int m = s.length();
 while (i < m) {
  while (j >= 0 && s[i] != s[j]) j = b[j];
  i++; j++;
  b[i] = j;
 }
}

void kmpSearch(string s, string pattern, int b[], int res[], int& cnt) {
 int i = 0, j = 0;
 cnt = 0;
 int n = s.length();
 int m = pattern.length();

 while (i < n) {
  while (j >= 0 && s[i] != pattern[j]) j = b[j];
  i++; j++;
  if (j == m) {
   res[cnt++] = i - j;
   j = b[j];
  }
 }
}

int solve() {
 string p;
 int n = s.length();
 int cnt;

 for (int i = 0; i < n; i++) {
  p = p + s[i];
  kmpProcess(p,b);
  kmpSearch(s, p, b, res, cnt);

  int k = 0;
  for (int j = 0; j < cnt; j++) {
   if (k != res[j]) break;
   k += p.length();
  }

  if (k == n) {
   return p.length();
  }
 }

 return 0;
}

int main() {
 int nTest;
 cin >> nTest;
 getline(cin, s);
 getline(cin, s);

 for (int i = 0; i < nTest; i++) {
  if (i > 0) cout << endl;
  getline(cin, s);
  cout << solve() << endl;
  getline(cin, s);
 }
 return 0;

}
