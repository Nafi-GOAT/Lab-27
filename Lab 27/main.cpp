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
    {"Audie", make_tuple(7, "Wolf", "Foxtrot!")},
    {"Raymond", make_tuple(10, "Cat", "Nice fit!")},
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
        if (choice == 1 || choice == 2 || choice == 3) {
            cout << "Enter villager name: ";
            cin >> name;
        }
        switch (choice) {
                   case 1:
                       if (villagers.find(name) != villagers.end()) {
                           get<0>(villagers[name])++;
                           cout << "Friendship increased for " << name << "!\n";
                       } else {
                           cout << "Villager not found.\n";
                       }
                       break;
                
            case 2:
                if (villagers.find(name) != villagers.end()) {
                    get<0>(villagers[name])--;
                    cout << "Friendship decreased for " << name << "!\n";
                } else {
                    cout << "Villager not found.\n";
                }
                break;
                
            case 3:
                if (villagers.find(name) != villagers.end()) {
                    cout << name << " -> Friendship: " << get<0>(villagers[name])
                         << ", Species: " << get<1>(villagers[name])
                         << ", Catchphrase: " << get<2>(villagers[name]) << endl;
                } else {
                    cout << "Villager not found.\n";
                }
                break;

            case 4:
                cout << "\nAll villagers:\n";
                for (auto &v : villagers)
                    cout << v.first << " -> Friendship: " << get<0>(v.second)
                         << ", Species: " << get<1>(v.second)
                         << ", Catchphrase: " << get<2>(v.second) << endl;
                break;

            case 5:
                cout << "Exiting program...\n";
                break;

            default:
                cout << "Invalid choice. Try again.\n";
        }
    }
  
    return 0;
}
