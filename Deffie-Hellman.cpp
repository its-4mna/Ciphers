#include <iostream>
#include <fstream>
#include <string>
using namespace std;
//Manual modulus
int modNoPercent(int a, int b) {
    while (a >= b) a -= b;
    while (a < 0) a += b;
    return a;
}
// Manual modular exponentiation without %
int modExp(int base, int exp, int mod) {
    int result = 1;
    for (int i = 0; i < exp; i++) {
        result *= base;
        while (result >= mod) result -= mod;
    }
    return result;
}
int main() {
    int p, g;
    cout << "Enter a prime number (p): ";
    cin >> p;
    cout << "Enter a generator (g): ";
    cin >> g;
    //private keys
    int a, b;
    cout << "Enter private key for User A: ";
    cin >> a;
    cout << "Enter private key for User B: ";
    cin >> b;
    //public keys
    int A = modExp(g, a, p);
    int B = modExp(g, b, p);
    //shared secrets
    int sharedSecretA = modExp(B, a, p);
    int sharedSecretB = modExp(A, b, p);
    cout << "\nPublic key A: " << A;
    cout << "\nPublic key B: " << B;
    cout << "\nShared Secret (A): " << sharedSecretA;
    cout << "\nShared Secret (B): " << sharedSecretB << "\n";
    // Write to file
    ofstream output("diffie_hellman.txt");
    output << "Prime p: " << p << "\n";
    output << "Generator g: " << g << "\n";
    output << "Private keys: a=" << a << ", b=" << b << "\n";
    output << "Public keys: A=" << A << ", B=" << B << "\n";
    output << "Shared Secret (A): " << sharedSecretA << "\n";
    output << "Shared Secret (B): " << sharedSecretB << "\n";
    output.close();
    // Read back from file
    ifstream input("diffie_hellman.txt");
    string line;
    cout << "\n--- File Content ---\n";
    while (getline(input, line)) {
        cout << line << endl;
    }
    input.close();
    return 0;
}
