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
  // The number of empty stalls between occupied stalls.
  std::vector<int> empty_stalls;

  int last_stall_num = 0;
  for (int i = 0; i < num_cows; ++i) {
    int stall_num;
    fin >> stall_num;
    occupied_stalls.push_back(stall_num);
    if (i == 0) {
      last_stall_num = stall_num;
    } else {
      if (stall_num - last_stall_num > 1) {
        empty_stalls.push_back(stall_num - last_stall_num - 1);
      }
      last_stall_num = stall_num;
    }
  }

  int length = occupied_stalls[num_cows - 1] - occupied_stalls[0] + 1;
  std::sort(empty_stalls.begin(), empty_stalls.end(), std::greater<int>());
  int empty_size = empty_stalls.size();
  int i = 0;
  while (num_boards > 1 && i < empty_size) {
    length -= empty_stalls[i];
    ++i;
    num_boards--;
  }

  fout << length << endl;

  return 0;
}


