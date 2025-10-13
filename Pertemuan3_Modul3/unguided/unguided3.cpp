#include <iostream>
using namespace std;

// Fungsi untuk menampilkan isi array 2D
void tampilArray(int arr[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
}

// Fungsi untuk menukar dua elemen array 2D pada posisi tertentu
void tukarPosisi(int arr1[3][3], int arr2[3][3], int baris, int kolom) {
    int temp = arr1[baris][kolom];
    arr1[baris][kolom] = arr2[baris][kolom];
    arr2[baris][kolom] = temp;
}

// Fungsi untuk menukar dua variabel menggunakan pointer
void tukarPointer(int *ptr1, int *ptr2) {
    int temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
}

int main() {
    int A[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int B[3][3] = {
        {9, 8, 7},
        {6, 5, 4},
        {3, 2, 1}
    };

    int x = 10, y = 20;
    int *ptrX = &x;
    int *ptrY = &y;

    cout << "Array A sebelum pertukaran:\n";
    tampilArray(A);
    cout << "\nArray B sebelum pertukaran:\n";
    tampilArray(B);

    // Menukar isi A dan B di posisi [1][2]
    tukarPosisi(A, B, 1, 2);

    cout << "\nArray A setelah pertukaran elemen [1][2]:\n";
    tampilArray(A);
    cout << "\nArray B setelah pertukaran elemen [1][2]:\n";
    tampilArray(B);

    // Menukar isi variabel melalui pointer
    cout << "\nNilai sebelum ditukar (x dan y):\n";
    cout << "x = " << x << ", y = " << y << endl;

    tukarPointer(ptrX, ptrY);

    cout << "Nilai setelah ditukar:\n";
    cout << "x = " << x << ", y = " << y << endl;

    return 0;
}
