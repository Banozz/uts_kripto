#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> createInverse(const vector<int>& perm) {
    vector<int> inv(perm.size());
    for (int i = 0; i < perm.size(); i++) {
        inv[perm[i]] = i;
    }
    return inv;
}

int main() {
    vector<int> pi = {
        23, 13, 24, 0, 7, 15, 14, 6, 25, 16, 
        22, 1, 19, 18, 5, 11, 17, 2, 21, 12, 
        20, 4, 10, 9, 3, 8
    };
    
    vector<int> pi_inv = createInverse(pi);
    
    string ciphertext = "WRTCNRLDSAFARWKXFTXCZRNHNYPDTZUUKMPLUSOXNEUDOKLXRMCBKGRCCURR";
    
    int K;
    cout << "Masukkan nilai K (0-25): ";
    cin >> K;
    
    string plaintext = "";
    
    for (int i = 0; i < ciphertext.length(); i++) {
        int y = ciphertext[i] - 'A';
        
        int z_i = (K + i) % 26;  

        // cout << "y = " << y << " ";
        
        int s = (y - z_i) % 26;


        if (s < 0) {
            s += 26;
        }

        // cout << "x1 = " << s << "";
        
        int x = pi_inv[s];
        
        char plain_char = 'A' + x;
        plaintext += plain_char;
    }
    
    cout << "K = " << K << ": " << plaintext << endl;
    
    return 0;
}