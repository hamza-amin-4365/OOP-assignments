#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Person {
    string first_name;
    string last_name;
    char gender;
    string address;
    string phone_number;
    string dob;
    int month_no;
    string status;
};

vector<Person> users;

void add_user() {
    Person new_user;
    cout << "Enter first name: ";
    cin >> new_user.first_name;
    cout << "Enter last name: ";
    cin >> new_user.last_name;
    cout << "Enter gender (M/F): ";
    cin >> new_user.gender;
    cin.ignore();  // Add this line to clear the newline character in buffer
    cout << "Enter address: ";
    getline(cin, new_user.address);  // Changed from cin to getline to properly read the address
    cout << "Enter phone number: ";
    cin >> new_user.phone_number;
    cout << "Enter date of birth (YYYY-MM-DD): ";
    cin >> new_user.dob;
    cout << "Enter the status of the user (Family/ Friend/ Business Partner): ";
    cin >> new_user.status;
    cout << "Enter the month number of your birth: ";
    cin >> new_user.month_no;
    users.push_back(new_user);
    cout << "User added successfully!\n";
};

void remove_user() {
    int index;
    cout << "Enter the index of the user to delete: ";
    cin >> index;
    if (index >= 0 && index < users.size()) {
        users.erase(users.begin() + index);
        cout << "User deleted successfully!\n";
    } else {
        cout << "Invalid index!\n";
    }
};

void display_users() {
    cout << "Users:\n";
    for (int i = 0; i < users.size(); i++) {
        cout << "Index: " << i << endl;
        cout << "Name: " << users[i].first_name << " " << users[i].last_name << endl;
        cout << "Gender: " << users[i].gender << endl;
        cout << "Address: " << users[i].address << endl;
        cout << "Phone number: " << users[i].phone_number << endl;
        cout << "DOB: " << users[i].dob << endl;
        cout << "Status: " << users[i].status << endl;
        cout << "Month of birth: " << users[i].month_no << endl;
        cout << endl;
    }
}

void searchByLastName(vector<Person> &people) {
    string lastName;
    cout << "Enter the last name: ";
    cin >> lastName;
    for (auto &person : people) {
        if (person.last_name == lastName) {
            cout << person.first_name << " " << person.last_name << " | "
                 << person.dob
                 << " | " << person.status << " | "
                 << person.gender << endl;
            cout << person.phone_number << endl;
        }
    }
}

void searchByMonth(vector<Person> &people) {
    int month;
    cout << "Enter the month (1-12): ";
    cin >> month;
    for (auto &person : people) {
        if (person.month_no == month) {
            cout << person.first_name << " " << person.last_name << endl;
        }
    }
}

void searchByStatus(vector<Person> &people) {
    string status;
    cout << "Enter the status: ";
    cin >> status;
    for (auto &person : people) {
        if (person.status == status) {
            cout << person.first_name << " " << person.last_name << endl;
        }
    }
}

void searchByLastNameRange(vector<Person> &people) {
    string lastName1, lastName2;
    cout << "Enter the first last name: ";
    cin >> lastName1;
    cout << "Enter the second last name: ";
    cin >> lastName2;
    bool print = false;
    for (auto &person : people) {
        if (person.last_name == lastName1) {
            print = true;
        }
        if (print) {
            cout << person.first_name << " " << person.last_name << " | "
                 << person.dob << " " << person.status << " | "
                 << person.gender << endl;
        }
        if (person.last_name == lastName2) {
            break;
        }
    }
}

void searchByGender(vector<Person> &people) {
    char gender;
    cout << "Enter the gender (M/F): ";
    cin >> gender;
    for (auto &person : people) {
        if (person.gender == gender) {
            cout << person.first_name << " " << person.last_name << " | "
                 << person.dob << " | " << person.status << endl;
        }
    }
}

int get_menu_choice()
{
    int choice;
    cout << "Address Book Menu:\n";
    cout << "1. Add user\n";
    cout << "2. Remove user\n";
    cout << "3. Display all users\n";
    cout << "4. Quit\n";
    cout << "Enter your choice: ";
    cin >> choice;
    return choice;
}

void Admin() {
    int choice = 0;
    while (choice != 4) {
        choice = get_menu_choice();
        switch (choice) {
            case 1:
                add_user();
                break;
            case 2:
                remove_user();
                break;
            case 3:
                display_users();
                break;
            case 4:
                cout << "Return to main menu!\n";
                break;
            default:
                cout << "Invalid choice!\n";
                break;
        }
    }
}

void User() {
    int choice = 0;
    while (choice != 6) {
        cout << "1. Search and display Person by last name" << endl;
        cout << "2. Names of people born in the given month" << endl;
        cout << "3. Names of people having the same status" << endl;
        cout << "4. Print all the people between two last names" << endl;
        cout << "5. Print details of people with the same gender" << endl;
        cout << "6. Return" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                searchByLastName(users);
                break;
            case 2:
                searchByMonth(users);
                break;
            case 3:
                searchByStatus(users);
                break;
            case 4:
                searchByLastNameRange(users);
                break;
            case 5:
                searchByGender(users);
                break;
            case 6:
                cout << "Return to main menu!\n";
                break;
            default:
                cout << "Invalid choice!\n";
                break;
        }
    }
}

int main() {
    system("CLS");
    int choice;
    do {
        cout << "Address book" << endl;
        cout << "1. Admin" << endl;
        cout << "2. User" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                Admin();
                break;
            case 2:
                User();
                break;
            case 3:
                cout << "Goodbye!\n";
                break;
            default:
                cout << "Invalid choice!\n";
                break;
        }
    } while (choice != 3);
    return 0;
}
