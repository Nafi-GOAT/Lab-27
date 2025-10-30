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

    villagers["Audie"] = make_tuple(7, "Wolf", "Foxtrot!");
    villagers["Raymond"] = make_tuple(10, "Cat", "Nice fit!");
    villagers.insert({"Marshal", make_tuple(9, "Squirrel", "Sulky...")});
    
    cout << "Villagers and their details:\n";
    for (auto &pair : villagers) {
        cout << pair.first << " ["
             << get<0>(pair.second) << ", "
             << get<1>(pair.second) << ", "
             << get<2>(pair.second) << "]\n";
    }

  
    return 0;
}
