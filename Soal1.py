 # Nama : Wilson Angelie Tan, Stan F., Theophilus Samuel G.
 # NPM :140810230024, 140810230046, 140810230054
 # Tanggal Buat :13/10/2024
 # Deskripsi :Cari nilai rata-rata nilai, nilai
 #          terbesar dan terkecilmenggunakan array satu dimensi dalam
 #          bentuk OOP 2 class bahasapython
class Logika:        
    def __init__(self, ukuran=10):
        self.__ukuran = ukuran
        self.__arr = [0 for _ in range(self.__ukuran)]
        
    def setUkuran(self, ukuran):
        self.__ukuran = ukuran
        self.__arr = [0 for _ in range(self.__ukuran)]
        
    def inputUkuran(self):
        self.__ukuran = int(input("Masukkan Ukuran Array : "))
        self.__arr = [0 for _ in range(self.__ukuran)]
        
    def getUkuran(self):
        return self.__ukuran
    
    def setArr(self, arr):
        self.__arr = arr
    
    def getArr(self):
        return self.__arr
    
    def isiArr(self):
        for a in range(self.__ukuran):
            self.__arr[a] = int(input(f"Masukkan nilai ke-{a+1} = "))
            
    def cariRata2(self):
        jumlah = 0
        
        for a in self.__arr:
            jumlah += a
        
        return (jumlah/self.__ukuran)
    
    def nilaiMax(self):
        highest = -99999
        
        for a in self.__arr:
            if(highest < a):
                highest = a
                
        return highest
    
    def nilaiMin(self):
        lowest = 99999
        
        for a in self.__arr:
            if(lowest > a):
                lowest = a
                
        return lowest
    
    def jumlahMatriks(self, m1, m2):
        if(m1.__ukuran != m2.__ukuran):
            print("Ukuran Larik 1 dan larik 2 tidak sama. Oleh karena itu, Penjumlahan tidak dapat dilakukan.")
            return
        
        for a in range(m1.__ukuran):
            self.__arr[a] = m1.__arr[a] + m2.__arr[a]
            
    def output(self):
        for a in self.__arr:
            print(a, " ", end="")
            
def menu():
    pilihan = 1
    data = Logika()
    data2 = Logika()
    data3 = Logika()
    
    while(pilihan != 0):
        print("\n\tMENU")
        print("====================")
        print("1. Input Matriks Sebagai Data pilihan 2, 3, dan 4")
        print("2. Mencari Rata Rata")
        print("3. Mencari Nilai Maks")
        print("4. Mencari Nilai Min")
        print("5. Mencari jlh matriks")
        print("0. Exit")
        pilihan = int(input("> "))
        
        if(pilihan == 1):
            data.inputUkuran()
            data.isiArr()
        elif(pilihan == 2):
            print("Nilai rata-rata = ", data.cariRata2())
        elif(pilihan == 3):
            print("Nilai Maks = ", data.nilaiMax())
        elif(pilihan == 4):
            print("Nilai Min = ", data.nilaiMin())
        elif(pilihan == 5):
            data2.inputUkuran()
            print("Matriks 1 : ")
            data2.isiArr()
            
            print("\nMatriks 2 : ")
            data3.setUkuran(data2.getUkuran())
            data3.isiArr()
            
            print("\nHasil Jumlah Matriks : ")
            data3.jumlahMatriks(data2, data3)
            data3.output()
        elif(pilihan == 0):
            print("Program selesai!!")
        else:
            print("Pilihan tidak ada di Menu!!")
            
menu()