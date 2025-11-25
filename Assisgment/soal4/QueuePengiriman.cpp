#include "QueuePengiriman.h"

bool isEmpty(QueueEkspedisi Q) {
    return (Q.Tail == -1);
}

bool isFull(QueueEkspedisi Q) {
    return (Q.Tail == MAX - 1);
}

void createQueue(QueueEkspedisi &Q) {
    Q.Head = -1;
    Q.Tail = -1;
}

void enQueue(QueueEkspedisi &Q, Paket data) {
    if (isFull(Q)) {
        cout << "Antrian Penuh! Paket dari " << data.NamaPengirim << " tidak bisa masuk." << endl;
    } else {
        
        if (isEmpty(Q)) {
            Q.Head = 0;
        }
        Q.Tail++;
        Q.dataPaket[Q.Tail] = data;
        cout << "Berhasil input paket: " << data.NamaPengirim << " (" << data.Tujuan << ")" << endl;
    }
}

void deQueue(QueueEkspedisi &Q) {
    if (isEmpty(Q)) {
        cout << "Antrian Kosong! Tidak ada paket untuk diproses." << endl;
    } else {
        
        cout << "Paket diproses (keluar): " << Q.dataPaket[Q.Head].NamaPengirim << endl;

        for (int i = 0; i < Q.Tail; i++) {
            Q.dataPaket[i] = Q.dataPaket[i + 1];
        }

        Q.Tail--;

        if (Q.Tail == -1) {
            Q.Head = -1;
        }
    }
}

void viewQueue(QueueEkspedisi Q) {
    if (isEmpty(Q)) {
        cout << "Antrian Kosong." << endl;
    } else {
        cout << "\n=== DAFTAR ANTRIAN PAKET ===" << endl;
        for (int i = 0; i <= Q.Tail; i++) {
            cout << i + 1 << ". Resi: " << Q.dataPaket[i].KodeResi
                 << " | Pengirim: " << Q.dataPaket[i].NamaPengirim
                 << " | Berat: " << Q.dataPaket[i].BeratBarang << "kg"
                 << " | Tujuan: " << Q.dataPaket[i].Tujuan << endl;
        }
        cout << "============================" << endl;
    }
}

float TotalBiayaPengiriman(QueueEkspedisi Q) {
    float totalBiaya = 0;
    float hargaPerKg = 8250;

    if (!isEmpty(Q)) {
        for (int i = 0; i <= Q.Tail; i++) {
            totalBiaya += (Q.dataPaket[i].BeratBarang * hargaPerKg);
        }
    }
    return totalBiaya;
}