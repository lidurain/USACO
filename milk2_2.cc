/*
ID: rainywa1
PROG: milk2
LANG: C++11
*/

#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  // 0 is coming, 1 is going;
  std::vector<std::pair<int, int>> time_points;

  ifstream fin("milk2.in");
  ofstream fout("milk2.out");
  int times;
  fin >> times;

  for (int time = 0; time < times; ++time) {
    int beginning, ending;
    fin >> beginning >> ending;
    time_points.push_back(std::make_pair(beginning, 0));
    time_points.push_back(std::make_pair(ending, 1));
  }
  std::sort(time_points.begin(), time_points.end());

  int count = 0, milking = 0, idle = 0;
  int start_point = time_points[0].first, end_point = 0;
  for (int i = 0; i < time_points.size(); ++i) {
    if (time_points[i].second == 0) {
      ++count;
    } else {
      --count;
    }
    if (count == 0) {
      end_point = time_points[i].first;
      milking = max(milking, end_point - start_point);
      if (i < time_points.size() - 1) {
        idle = max(idle, time_points[i+1].first - end_point);
        start_point = time_points[i+1].first;
      }
    }
  }
  fout << milking << " " << idle << endl;
  return 0;
}
