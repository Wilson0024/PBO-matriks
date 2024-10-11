import java.util.Scanner;

class Matriks{
    private int baris;
    private int kolom;
    private int[][] nilai;

    public Matriks(){
        this.baris = 0;
        this.kolom = 0;
        this.nilai = new int[baris][kolom];
    }

    public Matriks(int baris, int kolom, int[][] nilai){
        this.baris = baris;
        this.kolom = kolom;
        this.nilai = nilai;
    }

    static Scanner sc = new Scanner(System.in);

    public void setBaris(int baris) {
        this.baris = baris;
        this.nilai = new int[this.baris][this.kolom];
    }

    public void setKolom(int kolom) {
        this.kolom = kolom;
        this.nilai = new int[this.baris][this.kolom];
    }

    public void setNilai(int[][] nilai) {
        this.nilai = nilai;
    }

    public void inputBaris(){
        System.out.print("Masukkan Besar baris matriks : ");
        this.baris = sc.nextInt();
        this.nilai = new int[this.baris][this.kolom];
    }

    public void inputKolom(){
        System.out.print("Masukkan Besar kolom matriks : ");
        this.kolom = sc.nextInt();
        this.nilai = new int[this.baris][this.kolom];
    }

    public void inputBK(){
        inputBaris();
        inputKolom();
    }

    public void inputMatriks(){
        inputBK();

        for(int a = 0; a < this.baris; a++){
            for(int b = 0; b < this.kolom; b++){
                System.out.print("Masukkan Matriks baris ke-" + (a+1) + " kolom ke-" + (b+1) + " : ");
                this.nilai[a][b] = sc.nextInt();
            }
        }
    }

    public void outputMatriks(){
        if(this.baris == 0 || this.kolom == 0){
            System.out.println("Matriks belum diinput!!");
            return;
        }
        for(int a = 0; a < this.baris; a++){
            for(int b = 0; b < this.kolom; b++){
                System.out.print(this.nilai[a][b] + " ");
            }
            System.out.print("\n");
        }
    }

    public void penjumlahanVoid(Matriks m1, Matriks m2){
        setBaris(m1.baris);
        setKolom(m1.kolom);

        if(m1.baris != m2.baris || m1.kolom != m2.kolom){
            System.out.println("Ukuran Ordo Matriks 1 dan 2 tidak sama, Oleh karena itu Penjumlahan tidak dapat dilakukan!");
            return;
        }

        for(int a = 0; a < this.baris; a++){
            for(int b = 0; b < this.kolom; b++){
                this.nilai[a][b] = m1.nilai[a][b] + m2.nilai[a][b];
            }
        }
    }

    public Matriks penjumlahanFungsi(Matriks m2){
        Matriks m3 = new Matriks();
        m3.setBaris(this.baris);
        m3.setKolom(this.kolom);

        if(this.baris != m2.baris || this.kolom != m2.kolom){
            System.out.println("Ukuran Ordo Matriks 1 dan 2 tidak sama, Oleh karena itu Penjumlahan tidak dapat dilakukan!");
            return m3;
        }

        
        for(int a = 0; a < this.baris; a++){
            for(int b = 0; b < this.kolom; b++){
                m3.nilai[a][b] = this.nilai[a][b] + m2.nilai[a][b];
            }
        }
        return m3;
    }
}

public class Soal1 {
    static Scanner sc = new Scanner(System.in);

    static void menu(Matriks m1, Matriks m2){
        int pilihan = 1;
        
        while(pilihan != 0){
            System.out.println("\n\tMenu");
            System.out.println("===============");
            System.out.println("1. Input Matriks 1");
            System.out.println("2. Input Matriks 2");
            System.out.println("3. Output Matriks 1");
            System.out.println("4. Output Matriks 2");
            System.out.println("5. VOID Penjumlahan Matriks 1 dan 2");
            System.out.println("6. FUNGSI Penjumlahan Matriks 1 dan 2");
            System.out.println("0. Exit Program!!");
            System.out.print("> ");
            pilihan = sc.nextInt();

            switch(pilihan){
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
                case 5:
                    Matriks m3 = new Matriks();
                    m3.penjumlahanVoid(m1, m2);
                    m3.outputMatriks();
                    break;
                case 6:
                    Matriks m4 = m1.penjumlahanFungsi(m2);
                    m4.outputMatriks();
                    break;
                case 0:
                    System.out.println("Exit Program!!");
                    break;
                default:
                    System.out.println("Pilihan tidak ada pada menu!!");
                    break;
            }
        }
    }

    public static void main(String[] args) {
        Matriks m1 = new Matriks();
        Matriks m2 = new Matriks();
        menu(m1, m2);
    }
}
