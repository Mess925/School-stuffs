#include <iostream>
#include <cstring>

class MyString {
private:
    char* str;

public:
    MyString(const char* s = "") {
        str = new char[strlen(s) + 1];
        strcpy(str, s);
    }

    // Copy constructor
    MyString(const MyString& other) {
        str = new char[strlen(other.str) + 1];
        strcpy(str, other.str);
    }

    // Copy assignment operator
    MyString& operator=(const MyString& other) {
        if (this != &other) { // protect against self-assignment
            delete[] str;
            str = new char[strlen(other.str) + 1];
            strcpy(str, other.str);
        }
        return *this;
    }

    void print() const {
        std::cout << str << std::endl;
    }

    ~MyString() {
        delete[] str;
    }
};

int main() {
    MyString a("Hello");
    MyString b("World");

    b = a;  // calls the copy assignment operator

    a.print(); // Hello
    b.print(); // Hello

    return 0;
}
