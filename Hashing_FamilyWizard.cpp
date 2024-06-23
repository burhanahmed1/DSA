///FamilyManagementSystem for upto 20 families each of upto 5 members
#include<iostream>
using namespace std;
class FamilyManagementSystem;
struct Family {
    string fname;
    string members[5];
    bool occupied;
    Family() {
        occupied = false;
    }
};

class FamilyManagementSystem {
private:
    Family families[20];
    int hashFunction(string key) {
        int hash = 0;
        for (char c : key) {
            hash = (hash * 31 + c) % 20;
        }
        return hash;
    }
    int quadraticProbing(int hash, int i) {
        return (hash + i * i) % 20;
    }

public:
    void addFamily(string familyName) {
        int index = hashFunction(familyName);
        int i = 0;
        while (i < 20) {
            int newIndex = quadraticProbing(index, i);
            if (!families[newIndex].occupied) {
                families[newIndex].fname = familyName;
                families[newIndex].occupied = true;
                break;
            }
            i++;
        }
    }

    Family* findFamily(string familyName) {
        int index = hashFunction(familyName);
        int i = 0;
        while (i < 20) {
            int newIndex = quadraticProbing(index, i);
            if (families[newIndex].occupied && families[newIndex].fname == familyName) {
                return &families[newIndex];
            }
            i++;
        }
        return nullptr;
    }

    void removeFamily(string familyName) {
        Family* family = findFamily(familyName);
        if (family) {
            family->occupied = false;
        }
    }

    string addMember(string familyName, string memberName) {
        Family* family = findFamily(familyName);
        if (family) {
            for (int i = 0; i < 5; ++i) {
                if (family->members[i].empty()) {
                    family->members[i] = memberName;
                    return memberName + " added to " + familyName + ".";
                }
            }
            return "Family is already full.";
        }
        else {
            return "Family not found.";
        }
    }

    string removeMember(string familyName, string memberName) {
        Family* family = findFamily(familyName);
        if (family) {
            for (int i = 0; i < 5; ++i) {
                if (family->members[i] == memberName) {
                    family->members[i] = "";
                    return memberName + " removed from " + familyName + ".";
                }
            }
            return memberName + " is not a member of " + familyName + ".";
        }
        else {
            return "Family not found.";
        }
    }
};
int main() {
    FamilyManagementSystem System;

    // Adding families
    System.addFamily("Potter");
    System.addFamily("Granger");
    System.addFamily("Weasley");

    // Adding members to families
    System.addMember("Potter", "Harry");
    System.addMember("Potter", "James");
    System.addMember("Granger", "Hermione");
    System.addMember("Weasley", "Ron");
    System.addMember("Weasley", "Ginny");

    // Finding and displaying family information
    Family* potterFamily = System.findFamily("Potter");
    if (potterFamily) {
        cout << "Potter family members:" << endl;
        for (int i = 0; i < 5; ++i) {
            if (!potterFamily->members[i].empty()) {
                cout << potterFamily->members[i] << endl;
            }
        }
    }
    else {
        cout << "Potter family not found." << endl;
    }
    // Removing a family
    System.removeFamily("Granger");

    // Removing a member from a family
    cout << System.removeMember("Weasley", "Ron") << endl;

    system("pause>nul");
    return 0;
}
