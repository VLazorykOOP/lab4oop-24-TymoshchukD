#include <iostream>
#include <string>
using namespace std;

class EmailNameMap {
private:
    struct Entry {
        string email;
        string fullName;
    };

    Entry* data;
    int size;
    int capacity;
    int codeError;

public:
    EmailNameMap(int cap = 10) {
        capacity = cap;
        size = 0;
        codeError = 0;
        data = new Entry[capacity];
    }

    ~EmailNameMap() {
        delete[] data;
    }

    int getCodeError() const {
        return codeError;
    }

    void add(const string& email, const string& fullName) {
        if (size < capacity) {
            data[size].email = email;
            data[size].fullName = fullName;
            size++;
            codeError = 0;
        }
        else {
            codeError = 1; // No space
        }
    }

    // operator[] to get full name by email
    string operator[](const string& email) {
        for (int i = 0; i < size; i++) {
            if (data[i].email == email) {
                codeError = 0;
                return data[i].fullName;
            }
        }
        codeError = 2; // Not found
        return "";
    }

    // alternative access using ()
    string operator()(const string& email) {
        return (*this)[email];
    }

    // output operator
    friend ostream& operator<<(ostream& out, const EmailNameMap& map) {
        for (int i = 0; i < map.size; i++) {
            out << map.data[i].email << " : " << map.data[i].fullName << endl;
        }
        return out;
    }

    // input operator to add entry
    friend istream& operator>>(istream& in, EmailNameMap& map) {
        string email, fullName;
        cout << "Enter email: ";
        in >> email;
        cout << "Enter full name: ";
        in.ignore(); // clear newline
        getline(in, fullName);
        map.add(email, fullName);
        return in;
    }
};
int main() {
    EmailNameMap book;
    book.add("ivanov@example.com", "Ivanov Ivan Ivanovich");
    book.add("dtymoshchuk@gmail.com", "Dmytro Dmytrovich");

    std::cout << book;

    std::cout << "By email: " << book["dtymoshchuk@gmail.com"] << std::endl;
    std::cout << "By operator(): " << book("dtymoshchuk@gmail.com") << std::endl;

    std::cout << "Non-existent email: " << book["unknown@email.com"] << std::endl;
    std::cout << "CodeError: " << book.getCodeError() << std::endl;

    return 0;
}

