/* File : stackt.h */
/* deklarasi stack yang diimplementasi dengan tabel kontigu dan ukuran sama */
/* TOP adalah alamat elemen puncak */
/* Implementasi dalam bahasa C dengan alokasi statik */
#ifndef stackt_H
#define stackt_H

#include "booleans.h"

#define Nil -1
#define MaxEl 10
/* Nil adalah stack dengan elemen kosong . */

typedef int infotype;
typedef int address;   /* indeks tabel */

/* Belom fix */
typedef struct {
     int aksi;
     int waktu; 
} Aksi;


/* Contoh deklarasi variabel bertype stack dengan ciri TOP : */
/* Versi I : dengan menyimpan tabel dan alamat top secara eksplisit*/
typedef struct { 
  infotype T[MaxEl]; /* tabel penyimpan elemen */
  address TOP;  /* alamat TOP: elemen puncak */
} Stack;
/* Definisi stack S kosong : S.TOP = Nil */
/* Elemen yang dipakai menyimpan nilai Stack T[0]..T[MaxEl-1] */
/* Jika S adalah Stack maka akses elemen : */
   /* S.T[(S.TOP)] untuk mengakses elemen TOP */
   /* S.TOP adalah alamat elemen TOP */

/* Definisi akses dengan Selektor : Set dan Get */
#define Top(S) (S).TOP
#define InfoTop(S) (S).T[(S).TOP]

/* ************ Prototype ************ */
/* *** Konstruktor/Kreator *** */
void CreateEmpty (Stack *S);
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxEl */
/* jadi indeksnya antara 0.. MaxEl */
/* Ciri stack kosong : TOP bernilai Nil */

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsEmptyStack (Stack S);
/* Mengirim true jika Stack kosong: lihat definisi di atas */
boolean IsFullStack (Stack S);
/* Mengirim true jika tabel penampung nilai elemen stack penuh */

/* ************ Menambahkan sebuah elemen ke Stack ************ */
void Push (Stack * S, infotype X);
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */

/* ************ Menghapus sebuah elemen Stack ************ */
void Pop (Stack * S, infotype* X);
/* Menghapus X dari Stack S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */

void CopyStack (Stack Sin, Stack *Sout);
/* Membuat salinan Sin */
/* I.S. Sin terdefinisi, Sout sembarang */
/* F.S. Sout berisi salinan Sin yang identik */

void InverseStack (Stack S);

void PrintStack (Stack S); /* Buat membantu aja ini */

int SumOfStack (Stack S, infotype X);
/* Me-return sum waktu pada setiap aksi (untuk saat ini baru int aja) */

void Undo (Stack *S, infotype *X);
/* Undo pada eksekusi terakhir */
/* Sama aja kayak nge-POP stack yang kumpulan aksi */

void Execute (Stack S);
/* Eksekusi mulai command terakhir, berarti POP */
/* Kalo sambil pop, sambil jalanin fungsinya */

void mainmain (Stack * S, infotype * X);
/* Mengosongkan stack tanpa melakukan perintah */

#endif
