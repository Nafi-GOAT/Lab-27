//
//  main.cpp
//  Lab 27
//
//  Created by Nafi on 10/29/25.
//
#include <iostream>
#include <map>
#include <vector>
#include <tuple>
using namespace std;

int main() {
    // declarations
    map<string, tuple<int, string, string>> villagers;

    // insert elements into the map
    villagers["Audie"] = make_tuple(7, "Orange", "Yellow", "Red");
    villagers["Raymond"] = {"Black", "Gray", "White"};
    villagers.insert({"Marshal", {"Blue", "White", "Black"}});

  
    return 0;
}
