#include <stdio.h>
#include <stdlib.h>
#include "arraydinmap.h"
#include "../mesinkata/mesinkata.h"
#include "../mesinkar/mesinkar.h"

/* ********** SELEKTOR ********** */
// #define Neff(T) (T).Neff
// #define TI(T) (T).TI
// #define Elmt(T, i) (T).TI[(i)]
// #define MaxEl(T) (T).MaxEl

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong  */
void MakeEmptyDin(Tab *T, int maxel)
/* I.S. T sembarang, maxel > 0 */
/* F.S. Terbentuk tabel T kosong dengan kapasitas maxel */
{

    // Kamus

    // ALGORITMA
    MaxEl(*T) = maxel;
    Neff(*T) = 0;
    TI(*T) = (MapEntry *) malloc(maxel * sizeof(MapEntry));
}

void Dealokasi(Tab *T)
/* I.S. T terdefinisi; */
/* F.S. TI(T) dikembalikan ke system, MaxEl(T)=0; Neff(T)=0 */
{
    MaxEl(*T) = 0;
    Neff(*T) = 0;
    free(TI(*T));
}

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int NbElmtDin(Tab T)
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */
/* *** Daya tampung container *** */
{
    return Neff(T);
}

int MaxElement(Tab T)
/* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */
{
    return MaxEl(T);
}
/* *** Selektor INDEKS *** */
IdxType GetFirstIdxDin(Tab T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T pertama */
{
    return IdxMin;
}

IdxType GetLastIdxDin(Tab T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T terakhir */
{
    return Neff(T)-1;
}

/* ********** Test Indeks yang valid ********** */
boolean IsIdxValidDin(Tab T, IdxType i)
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran tabel */
/* yaitu antara indeks yang terdefinisi utk container*/
{
    return i >= 0 && i < MaxEl(T);
}

boolean IsIdxEffDin(Tab T, IdxType i)
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel */
/* yaitu antara FirstIdx(T)..LastIdx(T) */
{
    return i >= GetFirstIdxDin(T) && i <= GetLastIdxDin(T);
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean IsEmptyDin(Tab T)
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
{
    return Neff(T) == 0;
}

/* *** Test tabel penuh *** */
boolean IsFullDin(Tab T)
/* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */
{
    return Neff(T) == MaxEl(T);
}

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi tabel dari pembacaan *** */
void BacaIsi(Tab *T)
/* I.S. T sembarang dan sudah dialokasikan sebelumnya */
/* F.S. Tabel T terdefinisi */
/* Proses : membaca banyaknya elemen T dan mengisi nilainya */
/* 1. Baca banyaknya elemen diakhiri enter, misalnya N */
/*    Pembacaan diulangi sampai didapat N yang benar yaitu 0 <= N <= MaxElement(T) */
/*    Jika N tidak valid, tidak diberikan pesan kesalahan */
/* 2. Jika 0 < N <= MaxElement(T); Lakukan N kali: Baca elemen mulai dari indeks
      IdxMin satu per satu diakhiri enter */
/*    Jika N = 0; hanya terbentuk T kosong */
/* NOTE: PROSEDUR INI BUAT BACA FILE EXTERNAL TERUS BIKIN TABELNYA */
{
    MakeEmptyDin(T,30);
    STARTKATAFILE("../../Files/material.txt");
	int count = 0;
    int i=0;
	SalinKataFile();
	while (!EndKata){
		Kata k;
		int v;
		if (i % 2 == 0) {
			CopyKata(CKata, &k);
		} 
        else {
			v = convToInt(CKata);
		}
		if (CC == EOL){
            AddAsLastEl(T, k, v);
			ADV();
		}
		i ++; 
		ADVKATAFILE();
    }
/* 
    for (i=IdxMin; i<IdxMin+N; i++){
        printf("Masukkan key: ");
  //
    }
    
    for (i=IdxMin; i<IdxMin+N; i++){
            printf("masukkan value:" );
            scanf("%d", &Elmt(*T,i).value);
    }
*/
}
/* 
	Map File_Buy;
	CreateEmptyMap (&File_Buy);
	STARTKATAFILE("../../Files/material.txt");
	int count = 0;
	SalinKataFile();

	while( ! EndKata){
		Kata keyKata;
		int val;
		if (count % 2 == 0 ){
			CopyKata (CKata, &keyKata);
			
		} else{
			val = convToInt (CKata);
			Insert (&File_Buy, keyKata, val);
		}
		if (CC == EOL){
			ADV();
		}
		count ++;
		ADVKATAFILE();
	} */
void TulisIsiTab(Tab T)
/* Proses : Menuliskan isi tabel dengan traversal, tabel ditulis di antara kurung siku;
   antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan karakter di depan,
   di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. T boleh kosong */
/* F.S. Jika T tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika tabel kosong : menulis [] */
{
    // Kamus Lokal
    int i;
    // Algoritma
    //printf("[");
    printf("<NamaBahan> <Harga>\n");
    if(!IsEmptyDin(T)){
        for (i=GetFirstIdxDin(T); i<=GetLastIdxDin(T); i++){
            PrintKata(Elmt(T,i).key);
            printf(" %d",Elmt(T,i).value);
            printf("\n");
            //if(i!=GetLastIdxDin(T)) printf(",");
        }
    }

    //printf("]");
}


/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan tabel : < =, > *** */
boolean IsEQ(Tab T1, Tab T2)
/* Mengirimkan true jika T1 sama dengan T2 yaitu jika Neff T1 = T2 dan semua elemennya sama */
{
    // Kamus Lokal
    boolean ans;
    int i;

    // Algoritma
    if (NbElmtDin(T1) != NbElmtDin(T2)) return false;
    
    // else
    ans = true;
    i = GetFirstIdxDin(T1);

    while (i<=GetLastIdxDin(T1) && ans){
        if (!IsKataSamaKata(Elmt(T1,i).key,Elmt(T2,i).key)) ans=false;
        //if(Elmt(T1,i).key != Elmt(T2,i).key) ans=false;
        if(Elmt(T1,i).value != Elmt(T2,i).value) ans=false;
        i++;
    }
    
    return ans;
}

/* ********** SEARCHING ********** */
/* ***  Perhatian : Tabel boleh kosong!! *** */
IdxType Search1(Tab T, MapEntry X)
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = X */
/* Jika tidak ada, mengirimkan IdxUndef */
/* Menghasilkan indeks tak terdefinisi (IdxUndef) jika tabel T kosong */
/* Skema Searching yang digunakan bebas */
{
    // Kamus Lokal
    int ans;
    int i;

    // Algoritma
    if(NbElmtDin(T) == 0) return IdxUndef;

    // else
    ans = IdxUndef;
    i = GetFirstIdxDin(T)-1;

    do{
        i++;
        if (IsKataSamaKata(Elmt(T,i).key,X.key)){
            ans = i;
        }
    } while (i<=GetLastIdxDin(T)&& (!IsKataSamaKata(Elmt(T,i).key,X.key)));
    
    return ans;
}

boolean SearchB(Tab T, keyType k, valType v)
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan true, jika tidak ada menghasilkan false */
/* Skema searching yang digunakan bebas */
/* NOTE: NANTI BAKAL BIKIN FUNGSI UNTUK NGECEK PERSEDIAAN, JADI CEK VALUENYA JUGA. */
{
    // Kamus Lokal
    boolean ans;
    int i;

    // Algoritma
    ans=false;
    i=GetFirstIdxDin(T)-1;

    do{
        i++;
        if(IsKataSamaKata(Elmt(T,i).key,k)) {
            ans = true;
        }
    } while (i<=GetLastIdxDin(T) && (!IsKataSamaKata(Elmt(T,i).key,k)));

    return ans;

    /* 
    // Kamus Lokal
    boolean ans;
    int i;

    // Algoritma
    ans=false;
    i=GetFirstIdxDin(T)-1;

    do{
        i++;
        if(IsKataSamaKata(Elmt(T,i).key,k) && (Elmt(T,i).val>=v)) {
            ans = true;
        }
    } while (i<=GetLastIdxDin(T) && (!IsKataSamaKata(Elmt(T,i).key,k) && (Elmt(T,i).val<v)));

    return ans;
    */
}


/* ********** OPERASI LAIN ********** */
void CopyTab(Tab Tin, Tab *Tout)
/* I.S. Tin terdefinisi tidak kosong, Tout sembarang */
/* F.S. Tout berisi salinan dari Tin (identik, Neff dan MaxEl sama) */
/* Proses : Menyalin isi Tin ke Tout */
{
    // Kamus
    int i;

    // Algoritma
    MakeEmptyDin(Tout, MaxEl(Tin));
    for (i=0; i< Neff(Tin); i++){
        Elmt(*Tout, i).key = Elmt(Tin, i).key;
        Elmt(*Tout, i).value = Elmt(Tin, i).value;
        Neff(*Tout)++;
    }
}

/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void AddAsLastEl(Tab *T, keyType k, valType v)
/* Proses: Menambahkan X sebagai elemen terakhir tabel */
/* I.S. Tabel T boleh kosong, tetapi tidak penuh */
/* F.S. X adalah elemen terakhir T yang baru */

{
    // Algoritma
    if(IsEmptyDin(*T)) {
        Elmt(*T, IdxMin).key = k;
        Elmt(*T, IdxMin).value = v;
    }
    else{
        Elmt(*T, Neff(*T)).key = k;
        Elmt(*T, Neff(*T)).value = v;
    }

    Neff(*T)++;
}

/* ********** MENGHAPUS ELEMEN ********** */
void DelLastEl(Tab *T, keyType *k, valType *v)
/* Proses : Menghapus elemen terakhir tabel */
/* I.S. Tabel tidak kosong */
/* F.S. X adalah nilai elemen terakhir T sebelum penghapusan, */
/*      Banyaknya elemen tabel berkurang satu */
/*      Tabel T mungkin menjadi kosong */
{
    // Algoritma
    k = &Elmt(*T, GetLastIdxDin(*T)).key;
    v = &Elmt(*T, GetLastIdxDin(*T)).value;
    Neff(*T)--;

}