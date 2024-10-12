class Matriks:
    def __init__(self, baris=0, kolom=0, nilai=None):
        self.__baris = baris
        self.__kolom = kolom
        if nilai is None:
            self.__nilai = [[0 for _ in range(self.__kolom)] for _ in range(self.__baris)]
        else:
            self.__nilai = nilai
    
    def setBaris(self, baris):
        self.__baris = baris
        self.__nilai = [[0 for _ in range(self.__kolom)] for _ in range(self.__baris)]
        
    def setKolom(self, kolom):
        self.__kolom = kolom
        self.__nilai = [[0 for _ in range(self.__kolom)] for _ in range(self.__baris)]
        
    def setNilai(self, nilai):
        self.__nilai = nilai
    
    def inputBaris(self):
        self.__baris = int(input("Masukkan Besar baris matriks : "))
        self.__nilai = [[0 for _ in range(self.__kolom)] for _ in range(self.__baris)]
        
    def inputKolom(self):
        self.__kolom = int(input("Masukkan Besar kolom matriks : "))
        self.__nilai = [[0 for _ in range(self.__kolom)] for _ in range(self.__baris)]
        
    def inputBK(self):
        self.inputBaris()
        self.inputKolom()
        
    def inputMatriks(self):
        self.inputBK()
        
        for a in range(self.__baris):
            for b in range(self.__kolom):
                self.__nilai[a][b] = int(input(f"Masukkan Matriks baris ke-{a+1} kolom ke-{b+1} : "))
                
    def outputMatriks(self):
        if(self.__baris == 0 | self.__kolom == 0):
            print("Matriks belum diinput!!")
            return
        for a in range(self.__baris):
            for b in range(self.__kolom):
                print(self.__nilai[a][b], " ", end="")
            print("")

    def penjumlahanVoid(self, m1, m2):
        self.setBaris(m1.__baris)
        self.setKolom(m1.__kolom)
        
        if(m1.__baris != m2.__baris or m1.__kolom != m2.__kolom):
            print("Ukuran Ordo Matriks 1 dan 2 tidak sama, Oleh karena itu Penjumlahan tidak dapat dilakukan!")
            return
        
        for a in range(self.__baris):
            for b in range(self.__kolom):
                self.__nilai[a][b] = m1.__nilai[a][b] + m2.__nilai[a][b]
                
    def penjumlahanFungsi(self, m2):
        m3 = Matriks()
        m3.setBaris(self.__baris)
        m3.setKolom(self.__kolom)
        
        if(self.__baris != m2.__baris or self.__kolom != m2.__kolom):
            print("Ukuran Ordo Matriks 1 dan 2 tidak sama, Oleh karena itu Penjumlahan tidak dapat dilakukan!")
            return m3
        
        for a in range(self.__baris):
            for b in range(self.__kolom):
                m3.__nilai[a][b] = self.__nilai[a][b] + m2.__nilai[a][b]
                
        return m3
    
def menu(m1, m2):
    pilihan = 1
    
    while(pilihan != 0):
        print("\n\tMenu")
        print("===============")
        print("1. Input Matriks 1")
        print("2. Input Matriks 2")
        print("3. Output Matriks 1")
        print("4. Output Matriks 2")
        print("5. VOID Penjumlahan Matriks 1 dan 2")
        print("6. FUNGSI Penjumlahan Matriks 1 dan 2")
        print("0. Exit Program!!")
        pilihan = int(input("> "))
        
        if(pilihan == 1):
            m1.inputMatriks()
        elif(pilihan == 2):
            m2.inputMatriks()
        elif(pilihan == 3):
            m1.outputMatriks()
        elif(pilihan == 4):
            m2.outputMatriks()
        elif(pilihan == 5):
            m3 = Matriks()
            m3.penjumlahanVoid(m1, m2)
            m3.outputMatriks()
        elif(pilihan == 6):
            m4 = m1.penjumlahanFungsi(m2)
            m4.outputMatriks()
        elif(pilihan == 0):
            print("Exit Program!!")
        else:
            print("Pilihan tidak ada pada menu!!")

m1 = Matriks()
m2 = Matriks()
menu(m1, m2)