/*
ID: rainywa1
PROG: gift1
LANG: C++11
*/

#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <iostream>

using namespace std;

int main() {
  ifstream fin("gift1.in");
  ofstream fout("gift1.out");

  std::map<std::string, int> index;
  std::vector<std::string> names;
  std::vector<int> money;
  std::vector<int> initmoney;

  int number;
  fin >> number;
  for (int i = 0; i < number; ++i) {
    string name;
    fin >> name;
    index[name] = i;
    names.push_back(name);
  }
  money.resize(number);
  initmoney.resize(number);
  for (int i = 0; i < number; ++i) {
    string owner;
    fin >> owner;
    int init, num_receiver;
    fin >> init >> num_receiver;
    initmoney[index[owner]] = init;
    int each = num_receiver == 0 ? 0 : init/num_receiver;
    money[index[owner]] += init - each * num_receiver;
    for (int j = 0; j < num_receiver; ++j) {
      string receiver;
      fin >> receiver;
      money[index[receiver]] += each;
    }
  }
  for (int i = 0; i < number; ++i) {
    fout << names[i] << " " << money[i] - initmoney[i] << endl;
  }
  return 0;
}
