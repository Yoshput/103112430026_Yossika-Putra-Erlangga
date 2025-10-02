#include <iostream>
using namespace std;

// Fungsi dengan parameter pointer
void ubahNilai(int* ptr) {
    *ptr = 20;  // Mengubah nilai yang ditunjuk pointer
}

int main() {
    int x = 10;

    cout << "Nilai sebelum diubah: " << x << endl;

    // Kirim alamat x ke fungsi
    ubahNilai(&x); //Mengirimkan alamat memory ke x ke fungsi

    cout << "Nilai setelah diubah: " << x << endl;

    return 0;
}