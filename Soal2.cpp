/*
 Nama : Wilson Angelie Tan, Stan F., Theophilus Samuel G.
 NPM :140810230024, 140810230046, 140810230054
 Tanggal Buat :13/10/2024
 Deskripsi :penjumlahan matriks menggunakan array dua dimensi dalam bentuk OOP2 class bahasa C++
*/

#include <iostream>
using namespace std;

class Matriks {
private:
    int baris;
    int kolom;
    int nilai[100][100];

public:
    Matriks() : baris(0), kolom(0) {}

    void setBaris(int baris) {
        this->baris = baris;
    }

    void setKolom(int kolom) {
        this->kolom = kolom;
    }

    void inputMatriks() {
        cout << "Masukkan Besar baris matriks: ";
        cin >> this->baris;
        cout << "Masukkan Besar kolom matriks: ";
        cin >> this->kolom;

        for (int i = 0; i < this->baris; i++) {
            for (int j = 0; j < this->kolom; j++) {
                cout << "Masukkan Matriks baris ke-" << (i + 1) << " kolom ke-" << (j + 1) << ": ";
                cin >> this->nilai[i][j];
            }
        }
    }

    void outputMatriks() {
        if (this->baris == 0 || this->kolom == 0) {
            cout << "Matriks belum diinput!!" << endl;
            return;
        }
        for (int i = 0; i < this->baris; i++) {
            for (int j = 0; j < this->kolom; j++) {
                cout << this->nilai[i][j] << " ";
            }
            cout << endl;
        }
    }

    void penjumlahanVoid(const Matriks& m1, const Matriks& m2) {
        this->setBaris(m1.baris);
        this->setKolom(m1.kolom);
        if (m1.baris != m2.baris || m1.kolom != m2.kolom) {
            cout << "Ukuran Ordo Matriks 1 dan 2 tidak sama, Oleh karena itu Penjumlahan tidak dapat dilakukan!" << endl;
            return;
        }
        for (int i = 0; i < this->baris; i++) {
            for (int j = 0; j < this->kolom; j++) {
                this->nilai[i][j] = m1.nilai[i][j] + m2.nilai[i][j];
            }
        }
    }

    Matriks penjumlahanFungsi(const Matriks& m2) {
        Matriks m3;
        m3.setBaris(this->baris);
        m3.setKolom(this->kolom);
        if (this->baris != m2.baris || this->kolom != m2.kolom) {
            cout << "Ukuran Ordo Matriks 1 dan 2 tidak sama, Oleh karena itu Penjumlahan tidak dapat dilakukan!" << endl;
            return m3;
        }
        for (int i = 0; i < this->baris; i++) {
            for (int j = 0; j < this->kolom; j++) {
                m3.nilai[i][j] = this->nilai[i][j] + m2.nilai[i][j];
            }
        }
        return m3;
    }
};

void menu(Matriks& m1, Matriks& m2) {
    int pilihan = 1;
    while (pilihan != 0) {
        cout << "\n\tMenu" << endl;
        cout << "===============" << endl;
        cout << "1. Input Matriks 1" << endl;
        cout << "2. Input Matriks 2" << endl;
        cout << "3. Output Matriks 1" << endl;
        cout << "4. Output Matriks 2" << endl;
        cout << "5. VOID Penjumlahan Matriks 1 dan 2" << endl;
        cout << "6. FUNGSI Penjumlahan Matriks 1 dan 2" << endl;
        cout << "0. Exit Program!!" << endl;
        cout << "> ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                m1.inputMatriks();
                break;
            case 2:
                m2.inputMatriks();
                break;
            case 3:
                m1.outputMatriks();
                break;
            case 4:
                m2.outputMatriks();
                break;
            case 5: {
                Matriks m3;
                m3.penjumlahanVoid(m1, m2);
                m3.outputMatriks();
                break;
            }
            case 6: {
                Matriks m4 = m1.penjumlahanFungsi(m2);
                m4.outputMatriks();
                break;
            }
            case 0:
                cout << "Exit Program!!" << endl;
                break;
            default:
                cout << "Pilihan tidak ada pada menu!!" << endl;
                break;
        }
    }
}

int main() {
    Matriks m1, m2;
    menu(m1, m2);
    return 0;
}
