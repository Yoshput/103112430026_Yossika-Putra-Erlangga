#include <iostream>
using namespace std;

// Fungsi untuk mencari nilai maksimum dalam array
int cariMax(int arr[], int ukuran) {
    int MAX = arr[0];
    for (int i = 1; i < ukuran; i++) {
        if (arr[i] > MAX) {
            MAX = arr[i];
        }
    }
    return MAX;
}

// Prosedur untuk menghitung total penjumlahan
void operasiAritmatika(int arr[], int ukuran) {
    int totalJumlah = 0;
    for (int i = 0; i < ukuran; i++) {
        totalJumlah += arr[i];
    }
    cout << "Total penjumlahan : " << totalJumlah << endl;
}

// Prosedur untuk menghitung total perkalian
void operasiPerkalian(int arr[], int ukuran) {
    int totalKali = 1;
    for (int i = 0; i < ukuran; i++) {
        totalKali *= arr[i];
    }
    cout << "Total perkalian   : " << totalKali << endl;
}

int main() {
    const int ukuran = 5;
    int arr[ukuran];

    // Input elemen array
    for (int i = 0; i < ukuran; i++) {
        cout << "Masukan nilai array ke-" << i + 1 << " : ";
        cin >> arr[i];
    }

    cout <<endl;
    cout << "nilai terbesar dalam array : " << cariMax(arr, ukuran) << endl;
   
    operasiAritmatika(arr, ukuran);
    return 0;
}
