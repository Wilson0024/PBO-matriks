/*
 Nama : Wilson Angelie Tan, Stan F., Theophilus Samuel G.
 NPM :140810230024, 140810230046, 140810230054
 Tanggal Buat :13/10/2024
 Deskripsi :Cari nilai rata-rata nilai, nilai
           terbesar dan terkecilmenggunakan array satu dimensi dalam
           bentuk OOP 2 class bahasapython
*/
#include <iostream>
using namespace std;

class Logika {
private:
    int arr[100];
    int ukuran;

public:
    Logika() {
        this->ukuran = 10;
        for (int i = 0; i < this->ukuran; i++) {
            this->arr[i] = 0;
        }
    }

    Logika(int ukuran) {
        this->ukuran = ukuran;
        for (int i = 0; i < this->ukuran; i++) {
            this->arr[i] = 0;
        }
    }

    void setUkuran(int ukuran) {
        this->ukuran = ukuran;
    }

    void inputUkuran() {
        cout << "Masukkan Ukuran Array: ";
        cin >> this->ukuran;
    }

    int getUkuran() {
        return this->ukuran;
    }

    void isiArr() {
        for (int i = 0; i < this->ukuran; i++) {
            cout << "Masukkan nilai ke-" << (i + 1) << " = ";
            cin >> arr[i];
        }
    }

    float cariRata2() {
        float jumlah = 0;

        for (int i = 0; i < this->ukuran; i++) {
            jumlah += arr[i];
        }

        return (float)jumlah / this->ukuran;
    }

    int nilaiMax() {
        int highest = -99999;
        for (int i = 0; i < this->ukuran; i++) {
            if (highest < arr[i])
                highest = arr[i];
        }
        return highest;
    }

    int nilaiMin() {
        int lowest = 99999;
        for (int i = 0; i < this->ukuran; i++) {
            if (lowest > arr[i])
                lowest = arr[i];
        }
        return lowest;
    }

    void jumlahMatriks(Logika m1, Logika m2) {
        if (m1.ukuran != m2.ukuran) {
            cout << "Ukuran Larik 1 dan larik 2 tidak sama. Oleh karena itu, Penjumlahan tidak dapat dilakukan." << endl;
            return;
        }

        for (int i = 0; i < m1.ukuran; i++) {
            this->arr[i] = m1.arr[i] + m2.arr[i];
        }
    }

    void output() {
        for (int i = 0; i < this->ukuran; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

void menu() {
    int pilihan = 1;
    Logika data, data2, data3;

    while (pilihan != 0) {
        cout << "\n\n\tMENU" << endl;
        cout << "====================" << endl;
        cout << "1. Input Matriks Sebagai Data pilihan 2, 3, dan 4" << endl;
        cout << "2. Mencari Rata Rata" << endl;
        cout << "3. Mencari Nilai Maks" << endl;
        cout << "4. Mencari Nilai Min" << endl;
        cout << "5. Mencari jlh matriks" << endl;
        cout << "0. Exit" << endl;
        cout << "> ";

        cin >> pilihan;

        switch (pilihan) {
            case 1:
                data.inputUkuran();
                data.isiArr();
                break;
            case 2:
                cout << "Nilai rata-rata = " << data.cariRata2() << endl;
                break;
            case 3:
                cout << "Nilai Maks = " << data.nilaiMax() << endl;
                break;
            case 4:
                cout << "Nilai Min = " << data.nilaiMin() << endl;
                break;
            case 5:
                data2.inputUkuran();
                cout << "Matriks 1: " << endl;
                data2.isiArr();

                cout << "\nMatriks 2: " << endl;
                data3.setUkuran(data2.getUkuran());
                data3.isiArr();

                cout << "\nHasil Jumlah Matriks: " << endl;
                data3.jumlahMatriks(data2, data3);
                data3.output();
                break;
            case 0:
                cout << "Program selesai!!" << endl;
                break;
            default:
                cout << "Pilihan tidak ada di Menu!!" << endl;
                break;
        }
    }
}

int main() {
    menu();
    return 0;
}
