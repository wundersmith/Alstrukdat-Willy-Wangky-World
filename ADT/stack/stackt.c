/* NIM: 13519040
Nama: Shafira Naya Aprisadianti
Tanggal: 21 Oktober 2020
Topik: Pra praktikum 8
Deskripsi: implementasi stack
*/

/* File : stackt.h */
/* deklarasi stack yang diimplementasi dengan tabel kontigu dan ukuran sama */
/* TOP adalah alamat elemen puncak */
/* Implementasi dalam bahasa C dengan alokasi statik */


#include "../boolean/boolean.h"
#include <stdio.h>
#include "stackt.h"

Stack stackExecute;

//#define Nil -1
//#define MaxEl 10
/* Nil adalah stack dengan elemen kosong . */

//typedef int aksi;
//typedef int address;   /* indeks tabel */

/* Contoh deklarasi variabel bertype stack dengan ciri TOP : */
/* Versi I : dengan menyimpan tabel dan alamat top secara eksplisit*/
//typedef struct { 
 // aksi T[MaxEl]; /* tabel penyimpan elemen */
 // address TOP;  /* alamat TOP: elemen puncak */
//} Stack;
/* Definisi stack S kosong : S.TOP = Nil */
/* Elemen yang dipakai menyimpan nilai Stack T[0]..T[MaxEl-1] */
/* Jika S adalah Stack maka akses elemen : */
   /* S.T[(S.TOP)] untuk mengakses elemen TOP */
   /* S.TOP adalah alamat elemen TOP */

/* Definisi akses dengan Selektor : Set dan Get */
//#define Top(S) (S).TOP
//#define InfoTop(S) (S).T[(S).TOP]

/* ************ Prototype ************ */
/* *** Konstruktor/Kreator *** */
void CreateEmpty (Stack *S)
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxEl */
/* jadi indeksnya antara 0.. MaxEl */
/* Ciri stack kosong : TOP bernilai Nil */
{
    Top(*S)=Nil;
}
/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsEmptyStack (Stack S)
/* Mengirim true jika Stack kosong: lihat definisi di atas */
{
    return(Top(S)==Nil);
}
boolean IsFullStack (Stack S)
/* Mengirim true jika tabel penampung nilai elemen stack penuh */
{
    return(Top(S)==(MaxEl-1));
}
/* ************ Menambahkan sebuah elemen ke Stack ************ */
void Push (Stack * S, aksi X)
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */
{
    Top(*S)++;
    InfoTop(*S)=X;
}
/* ************ Menghapus sebuah elemen Stack ************ */
void Pop (Stack * S, aksi* X)
/* Menghapus X dari Stack S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */
{
    *X=InfoTop(*S);
    Top(*S)--;
}

/* Operasi-operasi lain */
void CopyStack (Stack Sin, Stack *Sout)
/* Membuat salinan Sin */
/* I.S. Sin terdefinisi, Sout sembarang */
/* F.S. Sout berisi salinan Sin yang identik */
{
    Stack Stemp;
    aksi X;
    CreateEmpty(&Stemp);
    CreateEmpty(Sout);
    while (!IsEmptyStack(Sin)) {
        Pop(&Sin,&X);
        Push(&Stemp,X);
    }
    while (!IsEmptyStack(Stemp)) {
        Pop(&Stemp,&X);
        Push(Sout,X);
    }
}

void InverseStack (Stack S) {
    Stack Stemp1;
    Stack Stemp2;
    aksi X;
    CreateEmpty(&Stemp1);
    CreateEmpty(&Stemp2);
    while (!IsEmptyStack(S)) {
        Pop(&S,&X);
        Push(&Stemp1,X);
    }
    while (!IsEmptyStack(Stemp1)) {
        Pop(&Stemp1,&X);
        Push(&Stemp2,X);
    }
    while (!IsEmptyStack(Stemp2)) {
        Pop(&Stemp2,&X);
        Push(&S,X);
    }
}
void PrintStack (Stack S) { // Ini biar ngebantu aja
    aksi X;
    if (IsEmptyStack(S)) {
        printf("\nStacknya kosong\n") ; 
    }
    else {
        while (!IsEmptyStack(S)) {
            aksi top = InfoTop(S);
            printf("%d\n", top.durasi);
            Pop(&S,&X);
            //Push(&S,top);
        }
    }
}

int SumDurasiStack (Stack S) {
    int sum=0;
    aksi X;
    while (!IsEmptyStack(S)) {
        sum += (InfoTop(S)).durasi;
        Pop(&S,&X);
    }
    return sum;
}

int SumUangStack (Stack S) {
    int sum=0;
    aksi X;
    while (!IsEmptyStack(S)) {
        sum += (InfoTop(S)).uang;
        Pop(&S,&X);
    }
    return sum;
}

int NbElmtStack (Stack S) {
    int count=0;
    aksi X;
    while (!IsEmptyStack(S)) {
        count += 1;
        Pop(&S,&X);
    }
    return count;
}

void mainmain (Stack *S, aksi *X) {
    //aksi buang;
    while (!IsEmptyStack(*S)) {
        Pop(S,X);
    }
}

void Undo (Stack *S, aksi *X) {
    Pop(S,X);
}

void Upgrade (Stack *S, player *P, TreeWahanaS T) {
    // Cek resource

    // Cek uang
    /* 
    if ((Money(*P) > 250)) {
        Money(*P) = -250; // misal biaya upgrade itu 250 (kalo mencukupi baru kurangin)
    
    }
    */
    printf("Ingin melakukan upgrade apa?\n List: \n");
   // PrintKata(&Root(T));
    //PrintKata(Left(T));
    //PrintKata(Right(T));
    // List Wahana yang bisa di upgrade ke sana
    //PrintKata(Left(TreeWahanaS));
    //PrintKata(Right(TreeWahanaS));
    // Ketik nama wahana
    // Wahana pada lokasi (X,Y) berubah menjadi ...
    // ngecek kanan kiri atas bawah yg mana
    // terus ngereturn addresswahana
    // if kanan kiri atas bawah bkn wahana print error

}

void PrintInfoStack (Stack S) {
    printf("Total aksi yang akan dilakukan: %d",NbElmtStack(S));
    printf("\n");
    printf("Total waktu yang akan dibutuhkan: ");
    TulisTimeRemaining(SumDurasiStack(S));
    printf("\n");   
    printf("Total uang yang dibutuhkan: %d",SumUangStack(S));
    printf("\n");    
}