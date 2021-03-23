#include <iostream>
#include <string>

using namespace std;

class Bank {
    int code;
    string name, address;

    public:
    Bank() {
        code = 1234;
        name = "HDFC";
        address = "Bank address";
    }
}