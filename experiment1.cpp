#include <iostream>

using namespace std;

void checkCons(string input) {
    bool is_numaric = true;
    
    for (int i = 0; i < input.length(); i++) {
        char ch = input[i];
        if (ch < 48 || ch > 57) {
            is_numaric = false;
        }
    }

    if (is_numaric == true) {
        cout << "numeric const" << endl;
    } else {
        cout << "not numeric const" << endl;
    }
}


void checkops(string input) {
    int x = 1;

    for (int i = 0; i < input.length(); i++) {
        char ch = input[i];
        if (ch == 43 || ch == 45 || ch == 42 || ch == 47 || ch == 37 || ch == 61) {
            cout << "operator" << x << ":  " << ch << endl;
            x = x + 1;
        }
    }
}

void cmmtlinefind(string input) {
    int a = input.length();
    
    bool is_singleLine = false;
    bool is_multi = false;
    bool invalidcommt = false;

    for (int i = 0; i < a - 1; i++) {
        
        
        if (input[i] == 47 && input[i + 1] == 47) {
            is_singleLine = true;
            break; 
        }
        
        
        if (input[i] == 47 && input[i + 1] == 42) {
            bool foundlast = false;
            
            
            for (int j = i + 2; j < a - 1; j++) {
                if (input[j] == 42 && input[j + 1] == 47) {
                    foundlast = true;
                    break;
                }
            }
            
            if (foundlast == true) {
                is_multi = true;
            } else {
                invalidcommt = true;
            }
            break; 
        }
    }

    if (is_singleLine == true) {
        cout << "single line comment" << endl;
    } 
    else if (is_multi == true) {
        cout << "multiple line comment" << endl;
    } 
    else if (invalidcommt == true) {
        cout << "Not a valid comment" << endl;
    } 
    else {
        cout << "Not a comment" << endl;
    }
}

void check_identifier(string input) {
    bool is_Valid = true;
    char C = input[0];

    if ((C >= 65 && C <= 90) || (C >= 97 && C <= 122) || C == 95) {
        for (int i = 1; i < input.length(); i++) {
            char ch = input[i];
            if ((ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <= 57) || ch == 95) {
            
            } else {
                is_Valid = false; 
            }
        }
    } else {
        is_Valid = false; 
    }

    if (is_Valid == true) {
        cout << "Valid identifier" << endl;
    } else {
        cout << "Not an identifier" << endl;
    }
}

int main() {
    string input;
    
    getline(cin, input); 
    
    cout << endl;
    checkCons(input);
    cout << endl;
    checkops(input);
    cout << endl;
    cmmtlinefind(input);
    check_identifier(input);
    return 0;
}