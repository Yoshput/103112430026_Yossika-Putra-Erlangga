#include <iostream>
#include <iomanip> 
#include "QueuePengiriman.h"


using namespace std;

int main() {
    QueueEkspedisi Q;
    int pilihan;
    Paket paketBaru;

    createQueue(Q);

    cout << "=== INISIALISASI SOAL (OTOMATIS) ===" << endl;
    enQueue(Q, {"123456", "Hutao", 14, "Sumeru"});
    enQueue(Q, {"234567", "Ayaka", 10, "Fontaine"});
    enQueue(Q, {"345678", "Bennet", 7, "Natlan"});
    enQueue(Q, {"456789", "Furina", 16, "Liyue"});
    enQueue(Q, {"567890", "Nefer", 6, "Inazuma"});

    cout << "\n[Output Soal No 4] Menampilkan Queue Awal:" << endl;
    viewQueue(Q);

    cout << "\n[Output Soal No 5] Melakukan DeQueue 1x:" << endl;
    deQueue(Q); 

    cout << "\n[Output Soal No 6] Queue setelah DeQueue:" << endl;
    viewQueue(Q);
    
    cout << "\n=== MASUK KE MENU INTERAKTIF ===" << endl;

    do {
        cout << "\n--- Komaniya Express ---" << endl;
        cout << "1. Input Data Paket" << endl;
        cout << "2. Hapus Data Paket" << endl;
        cout << "3. Tampilkan Queue Paket" << endl;
        cout << "4. Hitung Total Biaya Pengiriman" << endl;
        cout << "0. Keluar" << endl;
        cout << "Pilihan anda : ";
        cin >> pilihan;
        cout << endl;

        switch (pilihan) {
        case 1:
            cout << "Masukan Kode Resi   : "; cin >> paketBaru.KodeResi;
            cout << "Masukan Nama Pengirim : "; cin >> paketBaru.NamaPengirim;
            cout << "Masukan Berat (kg)    : "; cin >> paketBaru.BeratBarang;
            cout << "Masukan Tujuan        : "; cin >> paketBaru.Tujuan;
            enQueue(Q, paketBaru);
            break;

        case 2:
            deQueue(Q);
            break;

        case 3:
            viewQueue(Q);
            break;

        case 4:
            cout << "Total Biaya Pengiriman (Semua Paket): Rp. " 
                 << fixed << setprecision(2) << TotalBiayaPengiriman(Q) << endl;
            break;

        case 0:
            cout << "Terima kasih telah menggunakan Komaniya Express." << endl;
            break;

        default:
            cout << "Pilihan tidak valid." << endl;
        }

    } while (pilihan != 0);

    return 0;
}