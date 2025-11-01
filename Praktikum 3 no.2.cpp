#include <iostream>
using namespace std;

int main() {
    int n = 5;

    // D
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j == 0 || i == 0 || i == n - 1 || j == n - 1 && i > 0 && i < n - 1)
                cout << "D";
            else
                cout << " ";
        }
        cout << endl;
    }
    cout << endl;

    // Z
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0 || i == n - 1 || j == n - 1 - i)
                cout << "Z";
            else
                cout << " ";
        }
        cout << endl;
    }
    cout << endl;

    // A
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0 || i == n / 2 || j == 0 || j == n - 1)
                cout << "A";
            else
                cout << " ";
        }
        cout << endl;
    }
    cout << endl;

    // K
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j == 0 || (i <= n/2 && j == n/2 - i) || (i >= n/2 && j == i - n/2))
                cout << "K";
        else
            cout << " ";
    }
    cout << endl;
}
cout << endl;

    // Y
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if ((i <= n/2 && (j == i || j == n - 1 - i)) || (i > n/2 && j == n/2))
                cout << "Y";
            else
                cout << " ";
        }
        cout << endl;
    }
    cout << endl;

    return 0;
}