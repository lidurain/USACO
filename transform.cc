/*
ID: rainywa1
PROG: transform
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

vector<std::string> nochange(const vector<std::string> org) {
  return org;
}

vector<std::string> rotate90(const vector<std::string> org) {
  int size = org.size();
  vector<std::string> newSquare(size);
  for (int i = 0; i < size; ++i) {
    string line;
    for (int j = 0; j < size; ++j) {
      line += org[size-1-j][i];
    }
    newSquare[i] = line;
  }
  return newSquare;
}

vector<std::string> rotate180(const vector<std::string> org) {
  return rotate90(rotate90(org));
}

vector<std::string> rotate270(const vector<std::string> org) {
  return rotate180(rotate90(org));
}

vector<std::string> reflection(const vector<std::string> org) {
  int size = org.size();
  vector<std::string> newSquare(size);
  for (int i = 0; i < size; ++i) {
    string line = org[i];
    for (int j = 0; j < size/2; ++j) {
      char tmp = line[j];
      line[j] = line[size-1-j];
      line[size-1-j] = tmp;
    }
    newSquare[i] = line;
  }
  return newSquare;
}

vector<std::string> reflection90(const vector<std::string> org) {
  return rotate90(reflection(org));
}

vector<std::string> reflection180(const vector<std::string> org) {
  return rotate180(reflection(org));
}

vector<std::string> reflection270(const vector<std::string> org) {
  return rotate270(reflection(org));
}

int main() {
  ifstream fin("transform.in");
  ofstream fout("transform.out");

  int lines;
  fin >> lines;
  std::vector<std::string> square(lines);
  for (int i = 0; i < lines; ++i) {
    fin >> square[i];
  }
  std::vector<std::string> after(lines);
  for (int i = 0; i < lines; ++i) {
    fin >> after[i];
  }

  if (rotate90(square) == after) {
    fout << "1";
  } else if (rotate180(square) == after) {
    fout << "2";
  } else if (rotate270(square) == after) {
    fout << "3";
  } else if (reflection(square) == after) {
    fout << "4";
  } else if (reflection90(square) == after) {
    fout << "5";
  } else if (reflection180(square) == after) {
    fout << "5";
  } else if (reflection270(square) == after) {
    fout << "5";
  } else if (nochange(square) == after) {
    fout << "6";
  } else {
    fout << "7";
  }
  fout << endl;
  return 0;
}
