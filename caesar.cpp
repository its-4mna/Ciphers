#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
using namespace std;
//Manual modulus
int modNoPercent(int a, int b) {
    while (a >= b) a -= b;
    while (a < 0) a += b;
    return a;
}
//Encryption
string caesarEncrypt(const string &text, int key) {
    string result;
    for (char c : text) {
        if (isalpha(c)) {
            char base;
            if (isupper(c)) {
                base = 'A';
            } else {
                base = 'a';
            }
            int shifted = modNoPercent((c - base + key), 26);
            result += char(base + shifted);
        } else {
            result += c;
        }
    }
    return result;
}
//Decryption
string caesarDecrypt(const string &text, int key) {
    return caesarEncrypt(text, -key);
}
int main() {
    clock_t start = clock(); // Start time
    cout << "1) encryption\n";
    cout << "2) decryption\n";
    cout << "input: ";
    int choice;
    cin >> choice;
    cin.ignore();
    string text;
    cout << "Enter text: ";
    getline(cin, text);
    int key;
    cout << "Enter key: ";
    cin >> key;
    // Normalize key without %
    key = modNoPercent(key, 26);
    if (key == 0) key = 1;
    string result;
    if (choice == 1) {
        result = caesarEncrypt(text, key);
        cout << "Encrypted text: " << result << "\n";
    } else if (choice == 2) {
        result = caesarDecrypt(text, key);
        cout << "Decrypted text: " << result << "\n";
    } else {
        cout << "Invalid choice!\n";
        return 0;
    }
    cout << "-----------------------------\n";
    // File handling: write result
    ofstream outFile("ceasercipher.txt");
    outFile << "Operation: " << (choice == 1 ? "Encryption" : "Decryption") << "\n";
    outFile << "Original Text: " << text << "\n";
    outFile << "Key: " << key << "\n";
    outFile << "Result: " << result << "\n";
    outFile.close();
    // Read back and display
    ifstream inFile("ceasercipher.txt");
    string line;
    cout << "\n--- File Content ---\n";
    while (getline(inFile, line)) {
        cout << line << endl;
    }
    return 0;
}


