/*
ID: rainywa1
PROG: beads
LANG: C++11
*/

#include <fstream>
#include <string>
#include <iostream>
#include <deque>

using namespace std;

char merge(char c1, char c2) {
  if (c1 == 'w')
    return c2;
  if (c2 == 'w')
    return c1;
  if (c1 == c2)
    return c1;
  return '0';
}

int main() {
  ifstream fin("beads.in");
  ofstream fout("beads.out");
  int len;
  fin >> len;
  string beads_str;
  fin >> beads_str;

  std::deque<char> beads(beads_str.begin(), beads_str.end());

  int result = 0;
  for (int i = 0; i < len; ++i) {
    beads.push_back(beads[0]);
    beads.pop_front();
    // count back from i and forwad from i + 1
    char back = beads[0];
    char forward = beads[len - 1];
    int collect = 2;
    int j;
    for (j = 1; j < len -1 ; ++j) {
      back = merge(back, beads[j]);
      if (back == '0')
        break;
      ++collect;
    }
    for (int k = len-2; k >= j; --k) {
      forward = merge(forward, beads[k]);
      if (forward == '0')
        break;
      ++collect;
    }
    result = collect > result ? collect : result;
    if (result == len) {
      break;
    }
  }
  fout << result << endl;
  return 0;
}
