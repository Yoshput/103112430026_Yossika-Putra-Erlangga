#include <iostream>
using namespace std;

const int N = 3;

void jumlahMatriks(int A[N][N], int B[N][N]) {
    cout << "Hasil Penjumlahan Matriks:\n";
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            cout << A[i][j] + B[i][j] << " ";
        }
        cout << endl;
    }
}

void kurangMatriks(int A[N][N], int B[N][N]) {
    cout << "Hasil Pengurangan Matriks:\n";
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            cout << A[i][j] - B[i][j] << " ";
        }
        cout << endl;
    }
}

void kaliMatriks(int A[N][N], int B[N][N]) {
    cout << "Hasil Perkalian Matriks:\n";
    int C[N][N] = {0};
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            for (int k=0; k<N; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
            cout << C[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int matriksA[N][N] = {{7,12,22},{31,6,41},{15,19,36}};
    int matriksB[N][N] = {{11,34,7},{3,25,41},{5,18,33}};
    int pilihan;

    do {
        cout << "\n--- Menu Program Matriks ---\n";
        cout << "1. Penjumlahan Matriks\n";
        cout << "2. Pengurangan Matriks\n";
        cout << "3. Perkalian Matriks\n";
        cout << "4. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch(pilihan) {
            case 1: jumlahMatriks(matriksA, matriksB); break;
            case 2: kurangMatriks(matriksA, matriksB); break;
            case 3: kaliMatriks(matriksA, matriksB); break;
        }
    } while(pilihan != 4);

    return 0;
}
