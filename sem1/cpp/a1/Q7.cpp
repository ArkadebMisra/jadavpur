#include <iostream>
#include <cstring>

class String {
private:
    char *str;

public:
    
    String(const char *s = "") {
        str = new char[strlen(s) + 1];
        strcpy(str, s);
    }

    void display() {
        std::cout << "String: " << str << std::endl;
    }

    void join(const String &s1, const String &s2) {
        
        str = new char[strlen(s1.str) + strlen(s2.str) + 1];
        strcpy(str, s1.str);
        strcat(str, s2.str);
    }
};

int main() {
    
    String s1("Hello");
    String s2(" World");
    String s3("");
    
    s1.display();
    s2.display();

    s3.join(s1, s2);
    s3.display();

    return 0;
}
