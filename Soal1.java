/*
 Nama : Wilson Angelie Tan, Stan F., Theophilus Samuel G.
 NPM :140810230024, 140810230046, 140810230054
 Tanggal Buat :13/10/2024
 Deskripsi :Cari nilai rata-rata nilai, nilai
           terbesar dan terkecilmenggunakan array satu dimensi dalam
           bentuk OOP 2 class bahasapython
*/

import java.util.Scanner;

class Logika {
    static Scanner sc = new Scanner(System.in);

    private int[] arr;
    private int ukuran;

    public Logika(){
        this.ukuran = 10;
        this.arr = new int[ukuran];
    }

    public Logika(int ukuran){
        this.arr = new int[ukuran];
    }

    public void setUkuran(int ukuran) {
        this.ukuran = ukuran;
        this.arr = new int[this.ukuran];
    }

    public void inputUkuran(){
        System.out.print("Masukkan Ukuran Array : ");
        this.ukuran = sc.nextInt();
        this.arr = new int[this.ukuran];
    }

    public int getUkuran() {
        return ukuran;
    }

    public void setArr(int[] arr) {
        this.arr = arr;
    }

    public int[] getArr() {
        return arr;
    }

    public void isiArr(){
        for(int a = 0; a < this.ukuran; a++){
            System.out.print("Masukkan nilai ke-" + (a+1) + " = ");
            arr[a] = sc.nextInt();
        }
    }

    public float cariRata2(){
        float jumlah = 0;

        for(int a : arr){ // foreach
            jumlah += a;
        }

        return jumlah/this.ukuran;
    }

    public int nilaiMax(){
        int highest = -99999;
        for(int a : arr){
            if(highest < a)
                highest = a;
        }
        return highest;
    }

    public int nilaiMin(){
        int lowest = 99999;
        for(int a : arr){
            if(lowest > a)
                lowest = a;
        }
        return lowest;
    }

    public void jumlahMatriks(Logika m1, Logika m2){
        if(m1.ukuran != m2.ukuran){
            System.out.println("Ukuran Larik 1 dan larik 2 tidak sama. Oleh karena itu, Penjumlahan tidak dapat dilakukan.");
            return;
        }

        for(int a = 0; a < m1.ukuran; a++){
            this.arr[a] = m1.arr[a] + m2.arr[a];
        }
    }
    
    public void output(){
        for(int a : this.arr){
            System.out.print(a + " ");
        }
    }
    
}

public class Soal1{
    static Scanner sc = new Scanner(System.in);
    
    static void menu(){
        int pilihan = 1;
        Logika data = new Logika();
        Logika data2 = new Logika();
        Logika data3 = new Logika();


        while(pilihan != 0){
            System.out.println("\n\n\tMENU");
            System.out.println("====================");
            System.out.println("1. Input Matriks Sebagai Data pilihan 2, 3, dan 4");
            System.out.println("2. Mencari Rata Rata");
            System.out.println("3. Mencari Nilai Maks");
            System.out.println("4. Mencari Nilai Min");
            System.out.println("5. Mencari jlh matriks");
            System.out.println("0. Exit");
            System.out.print("> ");

            pilihan = sc.nextInt();

            switch(pilihan){
                case 1 :
                    data.inputUkuran();
                    data.isiArr();
                    break;
                case 2:
                    System.out.println("Nilai rata-rata = " + data.cariRata2());
                    break;
                case 3:
                    System.out.println("Nilai Maks = " + data.nilaiMax());
                    break;
                case 4:
                    System.out.println("Nilai Min = " + data.nilaiMin());
                    break;
                case 5:          
                    data2.inputUkuran();
                    System.out.println("Matriks 1 : ");
                    data2.isiArr();

                    System.out.println("\nMatriks 2 : ");
                    data3.setUkuran(data2.getUkuran());
                    data3.isiArr();

                    System.out.println("\nHasil Jumlah Matriks : ");
                    data3.jumlahMatriks(data2, data3);
                    data3.output();
                    break;
                case 0:
                    System.out.println("Program selesai!!");                    
                    break;
                default:
                    System.out.println("Pilihan tidak ada diMenu!!");
                    break;
            }
        }
    }
    public static void main(String[] args) {
        menu();
    }
}
