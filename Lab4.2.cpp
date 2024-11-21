#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;


class Association {
private:
    unordered_map<string, string> data; 
    int CodeError;  

public:
    
    Association() : CodeError(0) {}

    
    string& operator[](const string& key) {
        if (data.find(key) == data.end()) {
            CodeError = 1; 
            cout << "Error: Entity not found!" << endl;
        }
        return data[key];
    }

    
    string operator()(const string& key) {
        if (data.find(key) == data.end()) {
            CodeError = 1;  
            cout << "Error: Entity not found!" << endl;
            return "";
        }
        return data[key];
    }

    
    void addEntity(const string& email, const string& phone) {
        data[email] = phone;
        CodeError = 0;  
    }

    
    friend istream& operator>>(istream& in, Association& assoc) {
        string email, phone;
        cout << "Enter email: ";
        in >> email;
        cout << "Enter phone number: ";
        in >> phone;
        assoc.addEntity(email, phone);
        return in;
    }

    
    friend ostream& operator<<(ostream& out, const Association& assoc) {
        for (const auto& pair : assoc.data) {
            out << "Email: " << pair.first << ", Phone: " << pair.second << endl;
        }
        return out;
    }

    
    int getError() const {
        return CodeError;
    }

    
    string searchByEmail(const string& email) {
        if (data.find(email) != data.end()) {
            return data[email];
        } else {
            return "";
        }
    }
};

int main() {
    Association assoc;
    
    assoc.addEntity("roma.hudz@gmail.com", "+123456789");
    assoc.addEntity("shaha_kusik@gmail.com", "+987654321");

    
    cout << "Association List: " << endl;
    cout << assoc;

    int n;
    cout << "Enter the number of emails and phone numbers to add: ";
    cin >> n;

    
    for (int i = 0; i < n; i++) {
        cout << "Enter details for entity " << i + 1 << ":\n";
        cin >> assoc;
    }

    cout << "\nYour Association List:\n";
    cout << assoc;

    int choice;
    do {
        cout << "\nMenu:\n";
        cout << "1. Search by email\n";
        cout << "2. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            string email;
            cout << "Enter email to search: ";
            cin >> email;

            string phone = assoc.searchByEmail(email);
            if (phone.empty()) {
                cout << "Email not found!" << endl;
            } else {
                cout << "Phone number: " << phone << endl;
            }
        }
    } while (choice != 2);

    return 0;
}
