#include <iostream>
#include <string>

using namespace std;

// encryption func
string encrypt(string plainText, int shift) {
    string cipherText = "";

    for (char& ch : plainText) {
        if (isalpha(ch)) {
            char base = isupper(ch) ? 'A' : 'a';
            ch = (ch - base + shift) % 26 + base;
        }
        cipherText += ch;
    }

    return cipherText;
}

// decryption func
string decrypt(string cipherText, int shift) {
    return encrypt(cipherText, 26 - shift); // decryption is same as encryption with opposite shift
}

int main() {
    char choice;

    do {
        string input;
        int shift;

        cout << "Do you want to encrypt (e), decrypt (d), or quit (q)? ";
        cin >> choice;

        cin.ignore(); 

        if (choice == 'q' || choice == 'Q') {
            cout << "Program terminated." << endl;
            break; 
        }

        if (choice == 'e' || choice == 'E' || choice == 'd' || choice == 'D') {
            cout << "Enter text: ";
            getline(cin, input);

            cout << "Enter the shift value: ";
            cin >> shift;

            if (choice == 'e' || choice == 'E') {
                
                string encryptedText = encrypt(input, shift);
                cout << "Encrypted Text: " << encryptedText << endl;
            } else {
                
                string decryptedText = decrypt(input, shift);
                cout << "Decrypted Text: " << decryptedText << endl;
            }
        } else {
            cout << "Invalid choice. Please enter 'e' for encryption, 'd' for decryption, or 'q' to quit." << endl;
        }

    } while (true);

    return 0;
}
