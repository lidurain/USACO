/*
ID: rainywa1
PROG: milk
LANG: C++11
*/

#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  ifstream fin("milk.in");
  ofstream fout("milk.out");
  int total;
  fin >> total;
  int numFarms;
  fin >> numFarms;
  // Read the price and unit.
  std::vector<std::pair<int, int>> farms;
  for (int i = 0; i < numFarms; ++i) {
    int price, unit;
    fin >> price >> unit;
    farms.push_back(std::make_pair(price, unit));
  }

  std::sort(farms.begin(), farms.end());

  int currentUnits = 0;
  int money = 0;
  for (int i  = 0; i < numFarms; ++i) {
    int getUnits = farms[i].second;
    if (currentUnits + getUnits > total) {
      getUnits=total - currentUnits;
    }
    money += farms[i].first * getUnits;
    currentUnits += getUnits;
    if (currentUnits + getUnits == total) {
      break;
    }
  }
  fout << money << endl;
  return 0;
}
