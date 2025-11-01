#include <iostream>
using namespace std;

int main() {
    int saldo, pilihan, jumlah, pin;
    string nama;

    string menu[] = {"Ayam Geprek", "Nasi Goreng", "Tahu Telor"};
    int harga[]   = {10000, 12000, 13000};
    int jumlahMenu = 3;

    string pesanan[100];
    int totalPesanan = 0;
    int totalHarga = 0;

    cout << "Masukkan Nama Customer: ";
    getline(cin, nama);
    cout << "Topup GoPay: ";
    cin >> saldo;

    cout << "\n=========== MENU GOFOOD ===========" << endl;
    for (int i = 0; i < jumlahMenu; i++) {
        cout << i + 1 << ". " << menu[i] << " \t= " << harga[i] << endl;
    }
    cout << "0. Selesai" << endl;

    do {
        cout << "\nPilih menu (0 untuk selesai): ";
        cin >> pilihan;

        if (pilihan > 0 && pilihan <= jumlahMenu) {
            cout << "Jumlah " << menu[pilihan - 1] << ": ";
            cin >> jumlah;

            int total = jumlah * harga[pilihan - 1];
            if (saldo - (totalHarga + total) >= 2000) {
                pesanan[totalPesanan] = to_string(jumlah) + " " + menu[pilihan - 1];
                totalPesanan++;
                totalHarga += total;
                cout << "Pesanan " << jumlah << " " << menu[pilihan - 1] << " ditambahkan." << endl;
            } else {
                cout << "Saldo tidak cukup untuk menambah pesanan ini!" << endl;
            }
        } else if (pilihan == 0) {
            cout << "\nPesanan selesai, silakan masukkan PIN." << endl;
        } else {
            cout << "Pilihan tidak valid!" << endl;
        }
    } while (pilihan != 0);

    cout << "Masukkan PIN (123): ";
    cin >> pin;

    if (pin == 123) {
        saldo -= totalHarga;
        cout << "\n=========== STRUK ============" << endl;
        cout << "Customer: " << nama << endl;
        cout << "Pesanan :" << endl;
        for (int i = 0; i < totalPesanan; i++) {
            cout << "- " << pesanan[i] << endl;
        }
        cout << "Total Harga: " << totalHarga << endl;
        cout << "Saldo Akhir: " << saldo << endl;
        cout << "==============================" << endl;
    } else {
        cout << "PIN salah, semua transaksi dibatalkan!" << endl;
    }

    return 0;
}
