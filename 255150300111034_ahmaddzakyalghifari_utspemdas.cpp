#include <iostream>
#include <string>
using namespace std;

const int Kapasitas=10;

    string nomorpolisi[Kapasitas];
    int jam[Kapasitas];
    bool terisi[Kapasitas];
    
    int tarif(int durasi) {
    if (durasi <= 1) return 0;
    else if (durasi <= 5) return 3000;
    else if (durasi <= 10) return 5000;
    else return 10000;
}
int main() {
    for (int i = 0; i < Kapasitas; i++) {
        nomorpolisi[i] = "";
        jam[i] = 0;
    }

   int pilihan;
    do {
        cout << "=== SISTEM PARKIR SEDERHANA ==="<<endl;
        cout << "1. Mobil Masuk"<<endl;
        cout << "2. Mobil Keluar"<<endl;
        cout << "3. Tampilkan Kapasitas Parkir"<<endl;
        cout << "4. Exit Program"<<endl;
        cout << "Pilih menu: ";
        cin >> pilihan;

        if (pilihan == 1) {
            int tempat = -1;
            for (int i = 0; i < Kapasitas; i++) {
                if (!terisi[i]) { tempat = i; break; }
            }
            if (tempat == -1) {
                cout << "Parkiran penuh!"<<endl;
            } else {
                string plat;
                int lama;
                cout << "Masukkan nomor polisi: ";
                cin >> plat;
                cout << "Masukkan jam masuk (1-24): ";
                cin >> lama;
                nomorpolisi[tempat] = plat;
                jam[tempat] = lama;
                terisi[tempat] = true;
                cout << "Mobil " << plat << " diparkir di tempat " << tempat + 1 << endl;
            }
        } else if (pilihan == 2) {
            string plat;
            cout << "Masukkan nomor polisi yang akan keluar: ";
            cin >> plat;
            bool terdapat = false;
            for (int i = 0; i < Kapasitas; i++) {
                if (terisi[i] && nomorpolisi[i] == plat) {
                    int jamKeluar;
                    cout << "Masukkan jam keluar (1-24): ";
                    cin >> jamKeluar;
                    int durasi = jamKeluar - jam[i];
                    if (durasi < 0) durasi += 24;
                    int biaya = tarif(durasi);
                    cout << "Lama parkir: " << durasi << " jam"<<endl;
                    cout << "Tarif parkir: Rp " << biaya << endl;
                    terisi[i] = false;
                    nomorpolisi[i] = "";
                    jam[i] = 0;
                    cout << "Mobil " << plat << " telah keluar dari tempat " << i + 1 << endl;
                    terdapat = true;
                    break;
                }
            }
            if (!terdapat) {
                cout << "Mobil dengan nopol tersebut tidak ditemukan!"<<endl;
            }
        } else if (pilihan == 3) { 
            cout << "\n=== Kondisi Parkiran ==="<<endl;
            for (int i = 0; i < Kapasitas; i++) {
                cout << "Tempat " << i + 1 << ": ";
                if (terisi[i]) {
                    cout << nomorpolisi[i] << " (Masuk: " << jam[i] << ")"<<endl;
                } else {
                    cout << "[Kosong]"<<endl;
                }
            }
            cout << "========================="<<endl;

        } else if (pilihan == 4) {
            cout << "Program selesai. Terima kasih!"<<endl;
        } else {
            cout << "Pilihan tidak valid!\n";
}
} while (pilihan != 4);
return 0;
}
