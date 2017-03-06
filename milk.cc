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
  // Read the prices from each farm, and sort.
  vector<int> prices;
  vector<int> units;
  for (int i = 0; i < numFarms; ++i) {
    int price, unit;
    fin >> price >> unit;
    // find the correct position;
    int j;
    for (j = 0; j < i; ++j) {
      if (prices[j] > price) {
        break;
      }
    }
    auto it_prices = prices.begin();
    auto it_units = units.begin();
    prices.insert(it_prices + j, price);
    units.insert(it_units + j, unit);
  }

  int currentUnits = 0;
  int money = 0;
  for (int i  = 0; i < numFarms; ++i) {
    int getUnits = units[i];
    if (currentUnits + units[i] > total) {
      getUnits=total - currentUnits;
    }
    money += prices[i] * getUnits;
    currentUnits += getUnits;
    if (currentUnits + getUnits == total) {
      break;
    }
  }
  fout << money << endl;
  return 0;
}
