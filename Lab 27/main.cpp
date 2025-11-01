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
    string name, species, phrase;
    int friendship;
     
                     
    do {
        cout << "\n--- Villager Friendship Menu ---\n";
        cout << "1. Add New Villager\n";
        cout << "2. Delete Villager\n";
        cout << "3. Modify Friendship Level\n";
        cout << "4. Search for Villagers\n";
        cout << "5. Display All Villagers\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                cout << "\nEnter villager's name: ";
                cin >> name;
                if (villagers.find(name) != villagers.end()) {
                    cout << "Villager already exist!\n";
                break;
            }
                cout << "Enter species: ";
                cin >> species;
                cout << "Enter catchphrase: ";
                cin.ignore();
                getline(cin, phrase);
                cout << "Enter friendship level (1-10): ";
                cin >> friendship;

                villagers[name] = make_tuple(friendship, species, phrase);
        cout << name << " added successfully!\n";
        break;
    }
            case 2: {
                cout << "\nEnter villager name to delete: ";
                cin >> name;
                if (villagers.erase(name))
                    cout << name << " deleted successfully!\n";
                else
                    cout << "Villager not found.\n";
                break;
            }
                
            case 3: {
               cout << "\nEnter villager name: ";
               cin >> name;
               auto it = villagers.find(name);
               if (it != villagers.end()) {
               cout << "Current friendship level: " << get<0>(it->second) << endl;
               cout << "Enter new friendship level (1–10): ";
              cin >> friendship;
               get<0>(it->second) = friendship;
               cout << "Friendship updated for " << name << "!\n";
                 } else {
                   cout << "Villager not found.\n";
                }
             break;
             }

            case 4: {
                cout << "\nEnter villager name: ";
                cin >> name;
                auto it = villagers.find(name);
                if (it != villagers.end()) {
                cout << "\n" << name << " -> Friendship: " << get<0>(it->second)
                << ", Species: " << get<1>(it->second)
                << ", Catchphrase: " << get<2>(it->second) << endl;
           } else {
           cout << "Villager not found.\n";
           }
           break;
         }

            case 5: {
                cout << "\n--- Current Villagers ---\n";
                for (auto &v : villagers)
                    cout << v.first << " -> Friendship: " << get<0>(v.second)
                         << ", Species: " << get<1>(v.second)
                         << ", Catchphrase: " << get<2>(v.second) << endl;
                cout << "--------------------------\n";
                break;
            }

            case 6:
                cout << "\nExiting program... Goodbye!\n";
                break;

            default:
                cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 5);

    return 0;
}
