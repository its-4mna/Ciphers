#include <iostream>
#include <fstream>
#include <ctime>

int modulusFinder(int, int);
int modExp(int, int, int);
int prime();

using namespace std;

int main() 
{
    srand(time(0));

    cout << "=== XOR CIPHER ===";
    char PlainText[100];
    cout << "\nEnter PlainText: ";
    cin.getline(PlainText, 100);

    int msglen = 0;
    while(PlainText[msglen] != '\0')
    {
        msglen++;
    }

    int p = prime();

    //Common Primitive Root
    int g;
    cout << "Enter a generator (g): ";
    cin >> g;

    //private keys
    int a = 1 + modulusFinder(rand(), p-2);
    int b = 1 + modulusFinder(rand(), p-2);

    cout << "Private key for user A: " << a;
    cout << "\nPrivate key for user B: " << b;

    //public keys
    int A = modExp(g, a, p);
    int B = modExp(g, b, p);

    cout << "\nPublic key A: " << A;
    cout << "\nPublic key B: " << B;

    //shared secrets
    int sharedSecretA = modExp(B, a, p);
    int sharedSecretB = modExp(A, b, p);
    
    cout << "\nShared Secret (A): " << sharedSecretA;
    cout << "\nShared Secret (B): " << sharedSecretB << "\n";

    //xor encryption:
    int xorKey = modulusFinder(sharedSecretA, 256);
    cout << "\nXOR Key: " << xorKey << endl;

    char encrypted[100];
    for(int i=0; i<msglen; i++)
    {
        encrypted[i] = PlainText[i] ^ xorKey;
    }
    encrypted[msglen] = '\0';

    ofstream enc("EncryptedText.txt");
    if(enc.is_open())
    {
        for(int i=0; i<msglen; i++)
        {
            enc << encrypted[i];
        }
        enc.close();
    }
    else
        cout << "Failed to Open File";


    //xor decryption
    char decrypted[100];
    for(int i=0; i<msglen; i++)
    {
        decrypted[i] = encrypted[i] ^ xorKey;
    }
    decrypted[msglen] = '\0';

    ofstream dec("DecryptedText.txt");
    if(dec.is_open())
    {
        dec << decrypted;
        dec.close();
    }
    else
        cout << "Failed to open dec file";

    // Show results
    cout << "\n=== RESULTS ===" << endl;
    cout << "Original message: " << PlainText << endl;
    cout << "Encrypted message: " << encrypted << " (looks scrambled)" << endl;
    cout << "Decrypted message: " << decrypted << endl;
    
}



//Manual modulus
int modulusFinder(int a, int b) 
{
    while (a >= b) 
        a -= b;

    while (a < 0) 
        a += b;

    return a;
}

// Manual modular exponentiation without %
int modExp(int base, int exp, int mod) 
{
    int result = 1;
    for (int i = 0; i < exp; i++) 
    {
        result *= base;
        while (result >= mod) 
            result -= mod;
    }
    return result;
}

int prime()
{
	//prime numbers between 1 and 50
	int primes[15] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};
	int n = modulusFinder(rand(),15);	
	
	return primes[n];
}


