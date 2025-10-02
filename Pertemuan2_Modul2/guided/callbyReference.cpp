#include <iostream>
using namespace std;

// Fungsi dengan parameter reference
void ubahNilai(int& ref) {
    ref = 20;  // Mengubah nilai melalui referensi
}

int main() {
    int x = 10;

    cout << "Nilai sebelum diubah: " << x << endl;

    // Mengirimkan referensi ke x
    ubahNilai(x);

    cout << "Nilai setelah diubah: " << x << endl;
    
    return 0;
}