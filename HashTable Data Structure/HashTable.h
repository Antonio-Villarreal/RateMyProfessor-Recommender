#include<list>
#include<functional>

class HashTable {
private:
    list<Professor> *table;
    const double load_factor = 0.5;
    int tableSize;

    unsigned int Hash(const string& key, int &ts) {
        hash<string> h;
        unsigned int f = h(key) % ts;
        return f;
    } // Hash Func

public:

    HashTable(int ts) {
        tableSize = ts;
        table = new list<Professor>[tableSize];
    } // Default Constructor

    double getCount(string &uni) {
        int count = 0;
        for (auto i : table[Hash(uni, tableSize)]) count++;
        return count;
    } // Get a count of how many profs are in a university.

    void Copy(list<Professor> *l) {
        auto ts = tableSize * 2;
        for (int i = 0; i < tableSize; i++) {
            for (const auto& j : l[i]) {
                table[Hash(j.uni, ts)].push_back(j);
            }
        }
    } // Copies a temporary list pointer of profs to be used for resize.

    void insertElement(string &uni, Professor &prof) {
        table[Hash(uni, tableSize)].push_back(prof);
        // Resizable: array connected to an index cannot be bigger than the entire list, so double the size and reassign
        if (getCount(uni) / tableSize > load_factor) {
            auto ts = tableSize * 2;
            auto *temp = new list<Professor>[tableSize];

            temp->assign(table->begin(), table->end());
            table = new list<Professor>[ts];

            Copy(temp);

            tableSize = ts;
        }
    } // Insert Data in the Hash Table.

    void printAll(string &uni, int input){
        cout << "University: " << uni << endl;
        cout << endl;
        for (const auto& i : table[Hash(uni, tableSize)]) {
            if (i.uni == uni) {
                if (input == 5)
                    cout << i.fullname << endl;
                if (input == 11)
                    cout << i.dept << endl;
            }
        }
    } // Prints out all the information of a Prof.

    void printProfUni(string &uni, string &name) {
        for (const auto& i : table[Hash(uni, tableSize)]) {
            if (i.uni == uni && i.fullname == name)
                cout << i.fullname << " - " << i.profID << endl;
        }
    } // Finds Profs ID.

    void printUniID(string &uni) {
        if (uni == table[Hash(uni, tableSize)].front().uni)
            cout << uni << " - " << table[Hash(uni, tableSize)].front().uniID << endl;
        else {
            for (const auto &i : table[Hash(uni, tableSize)]) {
                if (i.uni == uni)
                    cout << " - " << i.uniID << endl;
                break;
            }
        }
    } // Finds Unis ID.

    void printSpecMenu(int menu, string &name) {
        for (int i = 0; i < tableSize; i++) {
            for (const auto& j : table[i]) {
                if (menu == 1 && name == j.firstname) {
                    cout << "Name: " << j.fullname << endl;
                    cout << "ID: " << j.profID << endl;
                    cout << "Verbal Rating: " << j.verbalRating << endl;
                    cout << "Number of Ratings: " << j.numRatings << endl;
                    cout << "Numerical Rating: " << j.overallRating << endl;
                    cout << "Department: " << j.dept << endl;
                    cout << "University: " << j.uni << endl;
                    cout << "University ID: " <<j.uniID << endl;
                    cout << endl;
                }
                if (menu == 2 && name == j.lastname) {
                    cout << "Name: " << j.fullname << endl;
                    cout << "ID: " << j.profID << endl;
                    cout << "Verbal Rating: " << j.verbalRating << endl;
                    cout << "Number of Ratings: " << j.numRatings << endl;
                    cout << "Numerical Rating: " << j.overallRating << endl;
                    cout << "Department: " << j.dept << endl;
                    cout << "University: " << j.uni << endl;
                    cout << "University ID: " <<j.uniID << endl;
                    cout << endl;
                }
                if (menu == 3 && name == j.fullname) {
                    cout << "Name: " << j.fullname << endl;
                    cout << "ID: " << j.profID << endl;
                    cout << "Verbal Rating: " << j.verbalRating << endl;
                    cout << "Number of Ratings: " << j.numRatings << endl;
                    cout << "Numerical Rating: " << j.overallRating << endl;
                    cout << "Department: " << j.dept << endl;
                    cout << "University: " << j.uni << endl;
                    cout << "University ID: " <<j.uniID << endl;
                    cout << endl;
                }
                if (menu == 4 && stoi(name) == j.profID) {
                    cout << "Name: " << j.fullname << endl;
                    cout << "ID: " << j.profID << endl;
                    cout << "Verbal Rating: " << j.verbalRating << endl;
                    cout << "Number of Ratings: " << j.numRatings << endl;
                    cout << "Numerical Rating: " << j.overallRating << endl;
                    cout << "Department: " << j.dept << endl;
                    cout << "University: " << j.uni << endl;
                    cout << "University ID: " <<j.uniID << endl;
                    cout << endl;
                }
                if (menu == 6) {
                    if (j.uniID == stoi(name))
                        cout << j.fullname << endl;
                }
            }
        }
    } // Prints out for a specific Prof.

    void tester() {
        for(int i = 0; i < tableSize; i++){
            cout << "Index " << i << ": ";
            for(const auto& j : table[i])
                cout << j.fullname << " -> " << endl;
        }
    } // Temporary Testing Function
};


