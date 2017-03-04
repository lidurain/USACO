/*
ID: rainywa1
PROG: beads
LANG: C++11
*/

#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void process(vector<int> beads, std::vector<std::vector<std::vector<int>>> &next_color) {
  // Left is 0, right is 1; red is 0; blue is 1
  // Count from left to right
  next_color[0][0][0] = beads[0] == 0 ? 0 : -1;
  next_color[0][1][0] = beads[0] == 1 ? 0 : -1;
  for (int i = 1; i < beads.size(); ++i) {
    for (int c = 0; c < 2; ++c) {
      // next_color[i][c][0];
      next_color[i][c][0] = (beads[i] == c ? i : next_color[i-1][c][0]);
    }
  }
  // Count from right to left
  int len = beads.size();
  next_color[len-1][0][1] = beads[len-1] == 0 ? len - 1 : len;
  next_color[len-1][1][1] = beads[len-1] == 1 ? len - 1 : len;
  for (int i = len - 2; i >= 0; --i) {
    for (int c = 0; c < 2; ++c) {
      next_color[i][c][1] = beads[i] == c ? i : next_color[i+1][c][1];
    }
  }
}

int main() {
  ifstream fin("beads.in");
  ofstream fout("beads.out");
  int len;
  fin >> len;

  vector<int> beads;
  // red = 0, blue = 1, white = 2;
  for (int i = 0; i < len; ++i) {
    char c;
    fin >> c;
    switch (c) {
      case 'r':
        beads.push_back(0);
        break;
      case 'b':
        beads.push_back(1);
        break;
      case 'w':
        beads.push_back(2);
        break;
      default:
        break;
    }
  }

  int result;
  std::copy(beads.begin(), beads.end(), std::back_inserter(beads));
  
  vector<vector<vector<int>>> next_color(beads.size(), vector<vector<int>>(2, vector<int>(2)));
  process(beads, next_color);

  for (int i = 0; i < beads.size() - 1; ++i) {
    // break point is between i and i + 1
    int collect = 0;
    int left_pos = (beads[i] == 2 ? min(next_color[i][0][0], next_color[i][1][0]) : next_color[i][1 - beads[i]][0]);
    // right
    int right_pos = (beads[i+1] == 2 ? max(next_color[i+1][0][1], next_color[i+1][1][1]) : next_color[i+1][1 - beads[i+1]][1]);
    collect = min(len, right_pos - (i+1) + i - left_pos);
    result = max(result, collect);
  }
  fout << result << endl;
  return 0;
}
