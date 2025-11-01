#include <iostream>
using namespace std;

int main() {
    float skn[] = {
        0.1, 0.2, 0.2, 0.5, 0.6, 0.1, 0.2, 0.3,
        0.1, 0.2, 0.2, 0.5, 0.6, 0.1, 0.2, 0.3
    };

    float skr[] = {
        0.2, 0.2, 0.0, 0.6, 0.5, 0.2, 0.9, 0.5,
        0.1, 0.2, 0.2, 0.5, 0.6, 0.1, 0.2, 0.3
    };

    int n = sizeof(skn) / sizeof(skn[0]);

    cout << "=== 1. Deteksi Arah Gerak Robot ===" << endl;
    for (int t = 0; t < n; t++) {
        if (skn[t] > 0.5 && skr[t] > 0.5) {
            cout << "t = " << t << " → Tetap lurus / Jalan normal" << endl;
        } 
        else if (skn[t] > 0.5) {
            cout << "t = " << t << " → Perintah belok kanan" << endl;
        } 
        else if (skr[t] > 0.5) {
            cout << "t = " << t << " → Perintah belok kiri" << endl;
        } 
        else {
            cout << "t = " << t << " → Tidak ada perintah khusus" << endl;
        }
    }

    cout << "\n=== 2. Deteksi Peningkatan / Penurunan Signifikan ===" << endl;
    for (int t = 1; t < n; t++) {
        if (skn[t] >= 2 * skn[t-1]) {
            cout << "t = " << t << "  Sensor kiri MENINGKAT signifikan ("
                 << skn[t-1] << "  " << skn[t] << ")" << endl;
        } 
        else if (skn[t] <= skn[t-1] / 2) {
            cout << "t = " << t << "  Sensor kiri MENURUN signifikan ("
                 << skn[t-1] << " " << skn[t] << ")" << endl;
        }

        if (skr[t] >= 2 * skr[t-1]) {
            cout << "t = " << t << "  Sensor kanan MENINGKAT signifikan ("
                 << skr[t-1] << "  " << skr[t] << ")" << endl;
        } 
        else if (skr[t] <= skr[t-1] / 2) {
            cout << "t = " << t << "  Sensor kanan MENURUN signifikan ("
                 << skr[t-1] << "  " << skr[t] << ")" << endl;
        }
    }

    return 0;
}