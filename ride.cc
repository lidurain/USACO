/*
ID: rainywa1
PROG: ride
LANG: C++11
*/

#include <fstream>
#include <string>

using namespace std;

int main() {
  ifstream fin("ride.in");
  string comet, group;
  int modComet, modGroup;
  fin >> comet >> group;

  int i = 0, product = 1;
  for (; i < comet.length(); ++i) {
    product *= (comet[i] - 'A' + 1);
  }
  modComet = product % 47;
  product = 1;
  for (i = 0; i < group.length(); ++i) {
    product *= (group[i] - 'A' + 1);
  }
  modGroup = product % 47;

  string out = modComet == modGroup ? "GO" : "STAY";
  ofstream fout("ride.out");
  fout << out << endl;
  return 0;
}


