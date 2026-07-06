#include <iostream>
#include <string>

using namespace std;

bool check_identifier(string input) {
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
    return is_Valid;
}

void check(string input)
{
    string keyarr[] = {"cout", "cin", "endl", "void"};
    string opparr[] = {"=", "+", "-", "*","<<"};
    string puncharr[] = {";", ":", "{", "}"};

    int punchSize = 4 ;
    int keySize = 4 ;
    int oppSize = 5;
    
    int start = 0;
    

    for (int last=0;last <= input.length(); last++)
    {
        if (last == input.length() || input[last] == ' '){
            string tokn = input.substr(start, last - start);
            bool found = false;
                for (int i= 0; i < keySize; i++){
                    if (tokn == keyarr[i]){
                        cout << tokn <<"--->"<< " keyword"<<endl;
                        found = true;
                  }
             }
                for (int i= 0; i < oppSize && !found; i++){
                    if (tokn == opparr[i]){
                        cout << tokn <<"--->" << "operator"<<endl;
                        found = true;
                 }
          }


                for (int i = 0; i < punchSize && !found; i++){
                    if (tokn == puncharr[i]){
                    cout << tokn <<"--->"<< "punctuation"<<endl;
                    found = true;
                    }
            }
                if (!found){
                if (check_identifier(tokn)){
                        cout << tokn <<"--->"<< " identifier"<<endl;}
                else{
                        cout << tokn <<"--->" << "constant"<<endl;}
            }
            

            start = last + 1;
        }
    }

}

int main() {

string input = "cout << 60 + sum << \"Hello\" << endl ;";

check(input);



    return 0;
}