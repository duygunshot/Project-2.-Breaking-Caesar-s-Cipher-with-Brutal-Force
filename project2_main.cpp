#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
using namespace std;

string decrypt(string code_to_decrypt, int letter){
    string decrypted_text = "";
    char character;
    int index=0;
    while(index<code_to_decrypt.length()){
        character = code_to_decrypt[index];
        if (character <= 90  && character >= 65){
            character -= letter;
            if (character < 65){
                character += 26;
            }
            decrypted_text += character;
        }
        else if (character <= 122  && character >= 97){
            character -= letter;
            if (character < 97){
                character += 26; 
            }
            decrypted_text += character;
        }
        else {
            decrypted_text += character;
        }
        index++;
    }
    return decrypted_text;
}

int main(){
    string fileName = "code.txt";
    ifstream input(fileName.c_str());
    ofstream output("output.txt");

    string code_to_decrypt;
    getline(input, code_to_decrypt);

    int letter=1;
    while(letter<=26){     
        output << "Shift value: " << letter<<endl;
        output << "The decrypted text:" <<endl<<decrypt(code_to_decrypt, letter) << endl<<endl;
        letter++;
    }
    cout << "Done. For output, open the file named output.txt";

    return 0;
}

