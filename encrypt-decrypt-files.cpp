#include <iostream>
#include <fstream>
using namespace std;

class encdec {
    int key;
    string inputFileName;
    string outputFileName;
    char c;

public:
    void encrypt();
    void decrypt();
    void getInputOutputFiles();
};

void encdec::getInputOutputFiles() {
    cout << "Enter input file name: ";
    cin >> inputFileName;
    cout << "Enter output file name: ";
    cin >> outputFileName;
}

void encdec::encrypt() {
    getInputOutputFiles();

    cout << "Enter key: ";
    cin >> key;

    fstream fin, fout;
    fin.open(inputFileName, fstream::in);
    fout.open(outputFileName, fstream::out);

    while (fin >> noskipws >> c) {
        int temp = (c + key);
        fout << (char)temp;
    }

    fin.close();
    fout.close();

    cout << "Encryption completed. Result saved in " << outputFileName << endl;
}

void encdec::decrypt() {
    getInputOutputFiles();

    cout << "Enter key: ";
    cin >> key;

    fstream fin, fout;
    fin.open(inputFileName, fstream::in);
    fout.open(outputFileName, fstream::out);

    while (fin >> noskipws >> c) {
        int temp = (c - key);
        fout << (char)temp;
    }

    fin.close();
    fout.close();

    cout << "Decryption completed. Result saved in " << outputFileName << endl;
}

int main() {
    encdec enc;
    char choice;

    cout << "Enter Your Choice:\n";
    cout << "1. Encrypt\n";
    cout << "2. Decrypt\n";
    cin >> choice;

    switch (choice) {
        case '1':
            enc.encrypt();
            break;

        case '2':
            enc.decrypt();
            break;

        default:
            cout << "Invalid choice. Exiting.\n";
            break;
    }

    return 0;
}
