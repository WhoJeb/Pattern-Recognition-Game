// General
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

// Sleep Debug
#include <unistd.h>

// Utils
#include "../include/utils.hpp"

// ------ Main Code ------ //

using namespace std;
using namespace utils;

const int GENSIZE = 1;
const int ROOTSIZE = 4;
const int TRICKSIZE = 3;

const string indexer[] = { 
  "F", 
  "G",
  "H",
};

const unordered_map<string, string> System {
  {"F", "|"},
  {"G", "{"},
  {"GG", "}"},
  {"H", ":"},
};

void convert(vector<string>& v, string& s) {
  for (int i = 0; i <= s.size(); i++) {
    // Ugly and slow but was the best way I could think of without a complete redesign of code to make a switch statement work
    if (s.find("F") != string::npos) {
      s.erase(i, 1);
      v.push_back(System.at("F"));
    }
  }
  for (int i = 0; i <= s.size(); i++) {
    if (s.find("GG") != string::npos) {
      s.erase(i, 1);
      v.push_back(System.at("GG"));
    }
  }
  for (int i = 0; i <= s.size(); i++) {
    if (s.find("G") != string::npos) {
      s.erase(i, 1);
      v.push_back(System.at("G"));
    }
  }
  for (int i = 0; i <= s.size(); i++) {
    if (s.find("H") != string::npos) {
      s.erase(i, 1);
      v.push_back(System.at("H"));
    }
  }
}

int main(int argc, char *argv[]) {

  while (1) {
    srand(time(0)); // seed every loop run to make sure the same rand val can't be generated
    
    vector<string> s;
    string multi_s;
    string tricks;
    string root;

    // System Generation
    int genSize = rng(GENSIZE);
    int rootSize = rng(ROOTSIZE) - 1;

    // Gen root
    for (int i = 0; i <= rootSize; i++) {
      multi_s += indexer[rng(System.size())];
    }

    // Gen tricks
    for (int i = 0; i <= rng(TRICKSIZE); i++) {
      tricks += indexer[rng(System.size())];
    }

    root = multi_s;

    convert(s, multi_s);

    string buf1 = readVec(s);

    multi_s.erase(0, multi_s.size());
    multi_s = buf1;

    // Gen Stem
    for (int i = 0; i <= GENSIZE; i++) {
      multi_s += multi_s;
    }

    vector<string> tricks_vec;
    convert(tricks_vec, tricks);
    string buf2 = readVec(tricks_vec);
    multi_s.insert(rng(multi_s.size()), buf2);

    if (root == "") {
      continue;
    }

    clr();
    println("");
    println("Pattern Recognition Game");
    println("");
    println("");
    println("");

    vector<string> v;
    convert(v, root);
    string v_string = readVec(v);

    // Debug
    println("Pattern:");
    println(multi_s);
    cout << "Hint (Pattern Length): " << v_string.size() << endl;

    println("");
    string user_input;
    cout << "What is the pattern? ";
    cin >> user_input;
    

    if (user_input == v_string) {
      println("Well Done!");
    } else {
      cout << "The pattern was actually: " << v_string << endl;
    }
    sleep(1);
  }

  return 0;
}

