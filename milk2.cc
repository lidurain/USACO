/*
ID: rainywa1
PROG: milk2
LANG: C++11
*/

#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

bool merge(int &coming_start, int &coming_end, int store_start, int store_end) {
  if (coming_start > store_end || store_start > coming_end)
    return false;
  coming_start = min(coming_start, store_start);
  coming_end = max(coming_end, store_end);
  return true;
}

int main() {
  std::vector<int> start;
  std::vector<int> end;

  ifstream fin("milk2.in");
  ofstream fout("milk2.out");
  int times;
  fin >> times;

  for (int time = 0; time < times; ++time) {
    int beginning, ending;
    fin >> beginning >> ending;
    bool m = false;
    int i;
    for (i = 0; i < start.size(); ++i) {
      m = merge(beginning, ending, start[i], end[i]);
      if (m) {
        start.erase(start.begin() + i);
        end.erase(end.begin() + i);
        --i;
      }
      if (!m && start[i] > ending) {
        start.insert(start.begin()+i, beginning);
        end.insert(end.begin()+i, ending);
        break;
      }
    }
    if (start.size() == i) {
      start.push_back(beginning);
      end.push_back(ending);
    }
  }

  int milking = 0, idle = 0;
  for (int i = 0; i < start.size(); ++i) {
    int interval = end[i] - start[i];
    milking = max(interval, milking);
    if (i < start.size() - 1) {
      idle = max(idle, start[i+1] - end[i]);
    }
  }
  fout << milking << " " << idle << endl;
  return 0;
}
