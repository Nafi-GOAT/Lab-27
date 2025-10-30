//
//  main.cpp
//  Lab 27
//
//  Created by Nafi on 10/29/25.
//
#include <iostream>
#include <map>
#include <tuple>
using namespace std;

int main() {
    // declarations
    map<string, tuple<int, string, string>> villagers = {
    {"Audie", make_tuple(7, "Wolf", "Foxtrot!")};
    {"Raymond", make_tuple(10, "Cat", "Nice fit!")};
    {"Marshal", make_tuple(9, "Squirrel", "Sulky...")}
    };
                     
    int choice;
    string name;
     
                     
    do {
        cout << "\n--- Villager Friendship Menu ---\n";
        cout << "1. Increase Friendship\n";
        cout << "2. Decrease Friendship\n";
        cout << "3. Search for Villager\n";
        cout << "4. Display All Villagers\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
    
    cout << "Villagers and their details:\n";
    for (auto &pair : villagers) {
        cout << pair.first << " ["
             << get<0>(pair.second) << ", "
             << get<1>(pair.second) << ", "
             << get<2>(pair.second) << "]\n";
    }

  
    return 0;
}
