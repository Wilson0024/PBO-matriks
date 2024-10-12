#include <iostream>
using namespace std;

class Matriks {
private:
    int baris;
    int kolom;
    int** nilai;

public:
    Matriks() {
        baris = 0;
        kolom = 0;
        nilai = nullptr;
    }

    ~Matriks() {
        if (nilai != nullptr) {
            for (int i = 0; i < baris; i++) {
                delete[] nilai[i];
            }
            delete[] nilai;
        }
    }

    void setBaris(int b) {
        baris = b;
        nilai = new int*[baris];
        for (int i = 0; i < baris; i++) {
            nilai[i] = new int[kolom];
        }
    }

    void setKolom(int k) {
        kolom = k;
        for (int i = 0; i < baris; i++) {
            delete[] nilai[i];
            nilai[i] = new int[kolom];
        }
    }

    void inputBaris() {
        cout << "Masukkan Besar baris matriks: ";
        cin >> baris;
        nilai = new int*[baris];
        for (int i = 0; i < baris; i++) {
            nilai[i] = new int[kolom];
        }
    }

    void inputKolom() {
        cout << "Masukkan Besar kolom matriks: ";
        cin >> kolom;
        for (int i = 0; i < baris; i++) {
            delete[] nilai[i];
            nilai[i] = new int[kolom];
        }
    }

    void inputBK() {
        inputBaris();
        inputKolom();
    }

    void inputMatriks() {
        inputBK();
        for (int a = 0; a < baris; a++) {
            for (int b = 0; b < kolom; b++) {
                cout << "Masukkan Matriks baris ke-" << (a + 1) << " kolom ke-" << (b + 1) << ": ";
                cin >> nilai[a][b];
            }
        }
    }

    void outputMatriks() {
        if (baris == 0 || kolom == 0) {
            cout << "Matriks belum diinput!!" << endl;
            return;
        }
        for (int a = 0; a < baris; a++) {
            for (int b = 0; b < kolom; b++) {
                cout << nilai[a][b] << " ";
            }
            cout << endl;
        }
    }

    void penjumlahanVoid(const Matriks& m1, const Matriks& m2) {
        setBaris(m1.baris);
        setKolom(m1.kolom);

        if (m1.baris != m2.baris || m1.kolom != m2.kolom) {
            cout << "Ukuran Ordo Matriks 1 dan 2 tidak sama, Oleh karena itu Penjumlahan tidak dapat dilakukan!" << endl;
            return;
        }

        for (int a = 0; a < baris; a++) {
            for (int b = 0; b < kolom; b++) {
                nilai[a][b] = m1.nilai[a][b] + m2.nilai[a][b];
            }
        }
    }

    Matriks penjumlahanFungsi(const Matriks& m2) {
        Matriks m3;
        m3.setBaris(baris);
        m3.setKolom(kolom);

        if (baris != m2.baris || kolom != m2.kolom) {
            cout << "Ukuran Ordo Matriks 1 dan 2 tidak sama, Oleh karena itu Penjumlahan tidak dapat dilakukan!" << endl;
            return m3;
        }

        for (int a = 0; a < baris; a++) {
            for (int b = 0; b < kolom; b++) {
                m3.nilai[a][b] = nilai[a][b] + m2.nilai[a][b];
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
