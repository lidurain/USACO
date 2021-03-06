/*
ID: rainywa1
PROG: barn1
LANG: C++11
*/

#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  ifstream fin("barn1.in");
  ofstream fout("barn1.out");

  int num_boards, num_stalls, num_cows;
  fin >> num_boards >> num_stalls >> num_cows;
  std::vector<int> occupied_stalls;
  for (int i = 0; i < num_cows; ++i) {
    int stall_num;
    fin >> stall_num;
    occupied_stalls.push_back(stall_num);
  }
  std::sort(occupied_stalls.begin(), occupied_stalls.end());

  // The number of empty stalls between occupied stalls.
  std::vector<int> empty_stalls;
  for (int i = 1; i < num_cows; ++i) {
    int empty_stall = occupied_stalls[i] - occupied_stalls[i - 1];
    if (empty_stall > 1) {
      empty_stalls.push_back(empty_stall - 1);
    }
  }

  int length = occupied_stalls[num_cows - 1] - occupied_stalls[0] + 1;
  std::sort(empty_stalls.begin(), empty_stalls.end(), std::greater<int>());
  int boards_required = 1;
  for (int empty_stall : empty_stalls) {
    if (boards_required >= num_boards)
      break;
    ++boards_required;
    length -= empty_stall;
  }
  fout << length << endl;

  return 0;
}
