/* ********** Definisi TYPE MATRIKS dengan indeks dan elemen integer ********** */

#include "boolean.h"
#include "matriks.h"
#include "UI.h"
#include <stdio.h>
#include <conio.h>

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */
/* *** Konstruktor membentuk MATRIKS *** */
void MakeMATRIKS (int NB, int NK, MATRIKS * M)
/* Membentuk sebuah MATRIKS "kosong" yang siap diisi berukuran NB x NK di "ujung kiri" memori */
/* I.S. NB dan NK adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks M sesuai dengan definisi di atas terbentuk */
{
  if(IsIdxValid(NB,NK)){
    NBrsEff(*M) = NB;
    NKolEff(*M) = NK;
  }
}
/* *** Selektor "DUNIA MATRIKS" *** */
boolean IsIdxValid (int i, int j)
/* Mengirimkan true jika i, j adalah indeks yang valid untuk matriks apa pun */
{
  return (i>=BrsMin && i<=BrsMax && j>=KolMin && j<=KolMax);
}

/* *** Selektor: Untuk sebuah matriks M yang terdefinisi: *** */
indeks GetFirstIdxBrs (MATRIKS M)
/* Mengirimkan indeks baris terkecil M */
{
  return BrsMin;
}

indeks GetFirstIdxKol (MATRIKS M)
/* Mengirimkan indeks kolom terkecil M */
{
  return KolMin;
}

indeks GetLastIdxBrs (MATRIKS M)
/* Mengirimkan indeks baris terbesar M */
{
  return NBrsEff(M);
}

indeks GetLastIdxKol (MATRIKS M)
/* Mengirimkan indeks kolom terbesar M */
{
  return NKolEff(M);
}

boolean IsIdxEff (MATRIKS M, indeks i, indeks j)
/* Mengirimkan true jika i, j adalah indeks efektif bagi M */
{
  return ( i >= GetFirstIdxBrs(M) && i <= GetLastIdxBrs(M) && j >= GetFirstIdxKol(M) && j <= GetLastIdxKol(M) );
}

ElType GetElmtDiagonal (MATRIKS M, indeks i)
/* Mengirimkan elemen M(i,i) */
{
  return Elmt(M,i,i);
}

/* ********** Assignment  MATRIKS ********** */
void CopyMATRIKS (MATRIKS MIn, MATRIKS * MHsl)
/* Melakukan assignment MHsl  MIn */
{
  /*Kamus*/
  indeks i,j;

  /*Algoritma*/
  NBrsEff(*MHsl) = NBrsEff(MIn);
  NKolEff(*MHsl) = NKolEff(MIn);
  for (i = GetFirstIdxBrs(MIn); i <= GetLastIdxBrs(MIn); i++) {
    for (j = GetFirstIdxKol(MIn); j <= GetLastIdxKol(MIn); j++) {
      Elmt(*MHsl, i, j) = Elmt(MIn, i, j);
    }
  }
}

/* ********** KELOMPOK BACA/TULIS ********** */
void BacaMATRIKS (MATRIKS * M, int NB, int NK)
/* I.S. IsIdxValid(NB,NK) */
/* F.S. M terdefinisi nilai elemen efektifnya, berukuran NB x NK */
/* Proses: Melakukan MakeMATRIKS(M,NB,NK) dan mengisi nilai efektifnya */
/* Selanjutnya membaca nilai elemen per baris dan kolom */
/* Contoh: Jika NB = 3 dan NK = 3, maka contoh cara membaca isi matriks :
1 2 3
4 5 6
8 9 10
*/
{
  /*Kamus*/
  indeks i,j;
  ElType x;

  /*Algpritma*/
  if (IsIdxValid(NB,NK)) {
    MakeMATRIKS(NB, NK, &(*M));
    for (i = GetFirstIdxBrs(*M); i <= GetLastIdxBrs(*M); i++) {
      for (j = GetFirstIdxKol(*M); j <= GetLastIdxKol(*M); j++) {
        scanf("%d",&x);
        Elmt(*M,i,j) = x;
      }
    }
  }
}

void TulisMATRIKS (MATRIKS M)
/* I.S. M terdefinisi */
/* F.S. Nilai M(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris
   dipisahkan sebuah spasi */
/* Proses: Menulis nilai setiap elemen M ke layar dengan traversal per baris dan per kolom */
/* Contoh: menulis matriks 3x3 (ingat di akhir tiap baris, tidak ada spasi)
1 2 3
4 5 6
8 9 10
*/
{
  /*Kamus*/
  indeks i,j;


  /*Algoritma*/
  for (i = GetFirstIdxBrs(M); i <= GetLastIdxBrs(M); i++) {
    for (j = GetFirstIdxKol(M); j <= GetLastIdxKol(M); j++) {
      printf("%d",Elmt(M,i,j));
      if(j<GetLastIdxKol(M)){
        printf(" ");
      }
    }
    if(i!=GetLastIdxBrs(M))
      printf("\n");
  }
}

/* ********** KELOMPOK OPERASI ARITMATIKA TERHADAP TYPE ********** */
MATRIKS TambahMATRIKS (MATRIKS M1, MATRIKS M2)
/* Prekondisi : M1  berukuran sama dengan M2 */
/* Mengirim hasil penjumlahan matriks: M1 + M2 */
{
  /*Kamus*/
  indeks i,j;
  MATRIKS M;

  /*Algoritma*/
  MakeMATRIKS(NBrsEff(M1), NKolEff(M1), &M);
  for (i = GetFirstIdxBrs(M1); i <= GetLastIdxBrs(M1); i++) {
    for (j = GetFirstIdxKol(M1); j <= GetLastIdxKol(M1); j++) {
      Elmt(M,i,j) = Elmt(M1,i,j) + Elmt(M2,i,j);
    }
  }
  return M;
}
MATRIKS KurangMATRIKS (MATRIKS M1, MATRIKS M2)
/* Prekondisi : M berukuran sama dengan M */
/* Mengirim hasil pengurangan matriks: salinan M1 – M2 */
{
  /*Kamus*/
  indeks i,j;
  MATRIKS M;

  /*Algoritma*/
  MakeMATRIKS(NBrsEff(M1), NKolEff(M1), &M);
  for (i = GetFirstIdxBrs(M1); i <= GetLastIdxBrs(M1); i++) {
    for (j = GetFirstIdxKol(M1); j <= GetLastIdxKol(M1); j++) {
      Elmt(M,i,j) = Elmt(M1,i,j) - Elmt(M2,i,j);
    }
  }
  return M;
}

MATRIKS KaliMATRIKS (MATRIKS M1, MATRIKS M2)
/* Prekondisi : Ukuran kolom efektif M1 = ukuran baris efektif M2 */
/* Mengirim hasil perkalian matriks: salinan M1 * M2 */
{
  /*Kamus*/
  indeks i, j, x;
  MATRIKS M;

  /*Algoritma*/
  if (NKolEff(M1)==NBrsEff(M2)){
    MakeMATRIKS(NBrsEff(M1),NKolEff(M2),&M);
    for (i = GetFirstIdxBrs(M1); i <= GetLastIdxBrs(M1); i++) {
      for (j = GetFirstIdxKol(M2); j <= GetLastIdxKol(M2); j++) {
        Elmt(M,i,j) = 0;
        for (x = GetFirstIdxKol(M1); x <= GetLastIdxKol(M1); x++) {
          Elmt(M,i,j) = Elmt(M,i,j)+(Elmt(M1,i,x) * Elmt(M2,x,j));
        }
      }
    }
  }

  return M;
}


MATRIKS KaliKons (MATRIKS M, ElType X)
/* Mengirim hasil perkalian setiap elemen M dengan X */
{
  /*Kamus*/
  indeks i,j;
  MATRIKS Mo;

  /*Algoritma*/
  MakeMATRIKS(NBrsEff(M), NKolEff(M), &Mo);
  for (i = GetFirstIdxBrs(M); i <= GetLastIdxBrs(M); i++) {
    for (j = GetFirstIdxKol(M); j <= GetLastIdxKol(M); j++) {
      Elmt(Mo,i,j) = Elmt(M,i,j)* X;
    }
  }
  return Mo;
}

void PKaliKons (MATRIKS * M, ElType K)
/* I.S. M terdefinisi, K terdefinisi */
/* F.S. Mengalikan setiap elemen M dengan K */
{
  /*Kamus*/
  indeks i,j;

  /*Algoritma*/
  for (i = GetFirstIdxBrs(*M); i <= GetLastIdxBrs(*M); i++) {
    for (j = GetFirstIdxKol(*M); j <= GetLastIdxKol(*M); j++) {
      Elmt(*M,i,j) = Elmt(*M,i,j) * K;
    }
  }
}

/* ********** KELOMPOK OPERASI RELASIONAL TERHADAP MATRIKS ********** */
boolean EQ (MATRIKS M1, MATRIKS M2)
/* Mengirimkan true jika M1 = M2, yaitu NBElmt(M1) = NBElmt(M2) dan */
/* untuk setiap i,j yang merupakan indeks baris dan kolom M1(i,j) = M2(i,j) */
/* Juga merupakan strong EQ karena GetFirstIdxBrs(M1) = GetFirstIdxBrs(M2)
   dan GetLastIdxKol(M1) = GetLastIdxKol(M2) */
{
  /*Kamus*/
  indeks i,j;
  boolean sama = true;

  /*Algoritma*/
  if(EQSize(M1,M2)){
      i = GetFirstIdxBrs(M1);
      while(sama && i<=GetLastIdxBrs(M1)){
        j = GetFirstIdxKol(M2);
        while (sama && j<=GetLastIdxKol(M1)) {

          if (Elmt(M1,i,j)!=Elmt(M2,i,j)) {
            sama = false;
          }else{
            j++;
          }

        }
        i++;
      }
      return sama;
  }else{
      return false;
  }
}

boolean NEQ (MATRIKS M1, MATRIKS M2)
/* Mengirimkan true jika M1 tidak sama dengan M2 */
{
    return !EQ(M1,M2);
}

boolean EQSize (MATRIKS M1, MATRIKS M2)
/* Mengirimkan true jika ukuran efektif matriks M1 sama dengan ukuran efektif M2 */
/* yaitu GetBrsEff(M1) = GetNBrsEff (M2) dan GetNKolEff (M1) = GetNKolEff (M2) */
{
  return (NBrsEff(M1)==NBrsEff(M2) && NKolEff(M1)==NKolEff(M2));
}

/* ********** Operasi lain ********** */
int NBElmt (MATRIKS M)
/* Mengirimkan banyaknya elemen M */
{
  return NKolEff(M)*NBrsEff(M);
}

/* ********** KELOMPOK TEST TERHADAP MATRIKS ********** */
boolean IsBujurSangkar (MATRIKS M)
/* Mengirimkan true jika M adalah matriks dg ukuran baris dan kolom sama */
{
    return (NBrsEff(M)==NKolEff(M));
}

boolean IsSimetri (MATRIKS M)
/* Mengirimkan true jika M adalah matriks simetri : IsBujurSangkar(M)
   dan untuk setiap elemen M, M(i,j)=M(j,i) */
{
  /*Kamus*/
  indeks i,j;
  boolean simetri = true;

  /*Algoritma*/
  if (IsBujurSangkar(M)) {
    i = GetFirstIdxBrs(M);
    while(simetri && i<=GetLastIdxBrs(M)){
      j = GetFirstIdxKol(M);
      while (simetri && j<=GetLastIdxKol(M)) {

        if (Elmt(M,i,j)!=Elmt(M,j,i)) {
          simetri = false;
        }else{
          j++;
        }

      }
      i++;
    }
    return simetri;
  }else{
    return false;
  }

  /* Algoritma 2 : Simetris jika Transpose(M)==M */
  /* Dapat memakan memori lebih banyak karena dibutuhkan MATRIKS tambahan*/
  /*MATRIKS T;
  MakeMATRIKS(NBrsEff(M), NKolEff(M), &T);
  CopyMATRIKS(M, &T);
  Transpose(&T);
  return EQ(M,T);*/
}

boolean IsSatuan (MATRIKS M)
/* Mengirimkan true jika M adalah matriks satuan: IsBujurSangkar(M) dan
   setiap elemen diagonal M bernilai 1 dan elemen yang bukan diagonal bernilai 0 */
{
  if(IsSimetri(M)){
    boolean satuan = true;
    indeks i = GetFirstIdxBrs(M),j;

    while(satuan && i<=GetLastIdxBrs(M)){
      j = GetFirstIdxKol(M);
      while (satuan && j<=GetLastIdxKol(M)) {
        if(i==j){ /*pada diagonal*/
          if(Elmt(M,i,j)!=1)
            satuan = false;
          else
            j++;
        }else{
          if(Elmt(M,i,j)!=0)
            satuan = false;
          else
            j++;
        }
      }
      i++;
    }

    return satuan;
  }else{
    return false;
  }
}

boolean IsSparse (MATRIKS M)
/* Mengirimkan true jika M adalah matriks sparse: mariks “jarang” dengan definisi:
   hanya maksimal 5% dari memori matriks yang efektif bukan bernilai 0 */
{
  float batas = NBElmt(M)*0.05;
  int count = 0;
  indeks i = GetFirstIdxBrs(M),j;
  float stop = false;

  while (!stop && i<=GetLastIdxBrs(M)) {
    j = GetFirstIdxKol(M);
    while (!stop && j <= GetLastIdxKol(M)) {
      if(Elmt(M, i, j)!= 0)
        count++;
      if(count>batas){
        stop = true;
      }else{
        j++;
      }
    }
    i++;
  }

  return !stop;
}

MATRIKS Inverse1 (MATRIKS M)
/* Menghasilkan salinan M dengan setiap elemen "di-invers", yaitu dinegasikan (dikalikan -1) */
{
  indeks i,j;
  MATRIKS Mo;
  MakeMATRIKS(NBrsEff(M),NKolEff(M), &Mo);
  for (i = GetFirstIdxBrs(M); i <= GetLastIdxBrs(M); i++) {
    for (j = GetFirstIdxKol(M); j <= GetLastIdxKol(M); j++) {
      Elmt(Mo, i, j) = Elmt(M, i, j)*(-1);
    }
  }

  return Mo;
}

float Determinan (MATRIKS M)
/* Prekondisi: IsBujurSangkar(M) */
/* Menghitung nilai determinan M */
{
  int x, subi, i, j, subj;
  float det = 0;

  if (GetLastIdxBrs(M) == 1) {
    return Elmt(M,1,1);
  }else if (GetLastIdxBrs(M) == 2) { /* Basis rekursif saat matriks 2x2 */
    return ( (Elmt(M,1,1)*Elmt(M,2,2))-(Elmt(M,1,2)*Elmt(M,2,1)) );
  }else{ /*rekurens*/
    MATRIKS submat;
    MakeMATRIKS(NBrsEff(M)-1,NKolEff(M)-1,&submat);
    for (x = GetFirstIdxKol(M); x <= GetLastIdxKol(M); x++) {
      subi = BrsMin;
      for (i = GetFirstIdxBrs(M)+1; i <=GetLastIdxBrs(M); i++) {
        subj = KolMin;
        for (j = GetFirstIdxKol(M); j <= GetLastIdxKol(M); j++) {
          if( j==x )
            continue;
          Elmt(submat, subi, subj) = Elmt(M,i,j);
          subj++;
        }
        subi++;
      }

      det = det + ( pow(-1,(x-1)) * Elmt(M, GetFirstIdxBrs(M),x) * Determinan(submat));
    }
    return det;
  }

}


void PInverse1 (MATRIKS * M)
/* I.S. M terdefinisi */
/* F.S. M di-invers, yaitu setiap elemennya dinegasikan (dikalikan -1) */
{
  indeks i,j;
  for (i = GetFirstIdxBrs(*M); i <= GetLastIdxBrs(*M); i++) {
    for (j = GetFirstIdxKol(*M); j <= GetLastIdxKol(*M); j++) {
      Elmt(*M, i, j) = Elmt(*M, i, j)*(-1);
    }
  }
}

void Transpose (MATRIKS * M)
/* I.S. M terdefinisi dan IsBujursangkar(M) */
/* F.S. M "di-transpose", yaitu setiap elemen M(i,j) ditukar nilainya dengan elemen M(j,i) */
{

  if (IsBujurSangkar(*M)) {
    int i = GetFirstIdxBrs(*M);
    int j;
    int x = 1;
    ElType temp;
    while (i <= GetLastIdxBrs(*M)) {
      j = GetFirstIdxKol(*M)+x;
      while (j <= GetLastIdxKol(*M)) {
        /*tukar*/
        temp = Elmt(*M,i,j);
        Elmt(*M,i,j) = Elmt(*M,j,i);
        Elmt(*M,j,i) = temp;
        j++;
      }
      i++;
      x++;
    }
  }
}

/*==============MODUL INVERSE=====================*/
/*For calculating Determinant of the Matrix */
float determinant(float a[25][25], float k)
{
  float s = 1, det = 0, b[25][25];
  int i, j, m, n, c;
  if (k == 1)
    {
     return (a[0][0]);
    }
  else
    {
     det = 0;
     for (c = 0; c < k; c++)
       {
        m = 0;
        n = 0;
        for (i = 0;i < k; i++)
          {
            for (j = 0 ;j < k; j++)
              {
                b[i][j] = 0;
                if (i != 0 && j != c)
                 {
                   b[m][n] = a[i][j];
                   if (n < (k - 2))
                    n++;
                   else
                    {
                     n = 0;
                     m++;
                     }
                   }
               }
             }
          det = det + s * (a[0][c] * determinant(b, k - 1));
          s = -1 * s;
          }
    }
 
    return (det);
}
 
void cofactor(float num[25][25], float f)
{
 float b[25][25], fac[25][25];
 int p, q, m, n, i, j;
 for (q = 0;q < f; q++)
 {
   for (p = 0;p < f; p++)
    {
     m = 0;
     n = 0;
     for (i = 0;i < f; i++)
     {
       for (j = 0;j < f; j++)
        {
          if (i != q && j != p)
          {
            b[m][n] = num[i][j];
            if (n < (f - 2))
             n++;
            else
             {
               n = 0;
               m++;
               }
            }
        }
      }
      fac[q][p] = pow(-1, q + p) * determinant(b, f - 1);
    }
  }
  transpose(num, fac, f);
}
/*Finding transpose of matrix*/ 
void transpose(float num[25][25], float fac[25][25], float r)
{
  int i, j;
  float b[25][25], inverse[25][25], d;
 
  for (i = 0;i < r; i++)
    {
     for (j = 0;j < r; j++)
       {
         b[i][j] = fac[j][i];
        }
    }
  d = determinant(num, r);
  for (i = 0;i < r; i++)
    {
     for (j = 0;j < r; j++)
       {
        inverse[i][j] = b[i][j] / d;
        }
    }
   printf("\n\n\nThe inverse of matrix is : \n");
 
   for (i = 0;i < r; i++)
    {
     for (j = 0;j < r; j++)
       {
         printf("\t%f", inverse[i][j]);
        }
    printf("\n");
     }
}

void inverseMatriks(){
	 float a[25][25], k, d;
 	 int i, j;
  
  printf("Masukkan ordo Matriks : ");
  scanf("%f", &k);
  printf("Masukkan elements of %.0fX%.0f Matrix : \n", k, k);
  for (i = 0;i < k; i++)
    {
     for (j = 0;j < k; j++)
       {
        scanf("%f", &a[i][j]);
        }
    }
  d = determinant(a, k);
  if (d == 0)
   printf("\nMatriks yang dimasukkan tidak memungkinkan menggunakan operasi inverse\n");
  else
   cofactor(a, k);
}

/*================SPL GAUSS JORDAN===============*/
void SPL_OBE(){
 int bool = 1;
 while(bool=1){
  //untuk baris dan kolom
  printf("Masukkan jumlah baris matriks : ");
  scanf("%d",&o);
  printf("Masukkan jumlah kolom matriks : ");
  scanf("%d",&p);
  if(p>o){
   printf("\nJumlah persamaan tidak boleh lebih besar dari jumlah variabel, silakan input kembali\n");
  }
  else{
   break; 
  }
   
 }
 printf("\nMasukkan elemen matriks %dx%d : \n",o,p);
 int i=0;
 int j=0;
 for(i=0;i<p;i++){
  for(j=0;j<o;j++){
   //printf(" Input A[%d][%d] : ",i+1,j+1);
   scanf("%f",&a[i][j]);
  }
 }
 for(i=0;i<p;i++){
  printf("Input Hasil[%d] : ",i+1);
  scanf("%f",&b[i]);
 }
 
 printf("\nMatriks Awal : \n");
 printf("========================================================\n");
 TampilMatriks();

//penyelesaian menggunakan metode Gauss-Jordan
 printf("\nPENYELESAIAN : \n");
 printf("========================================================\n");
 for (n=0;n<p;n++) {
  printf("\nTahap %d \n",n+1);
  temp=a[n][n];
   for (j=0;j<o;j++){
    a[n][j]=a[n][j]/temp;
   }
   b[n]=b[n]/temp;
   for (i=0;i<o;i++){
    if (i!=n){
     temp=a[i][n];
     for (j=n;j<o;j++){
      a[i][j]=a[i][j]-(temp*a[n][j]);
     }
     b[i]=b[i]-(temp*b[n]);
    }
   }
  //menampilkan matriks
  TampilMatriks();
 }

//pembuktian
//cout<<"\nDari penyelesaian diatas diperoleh solusi nilai x dari sistem persamaan linier yaitu : \n";
 for (i=0;i<p;i++){
  if(isinf(b[i])||isnan(b[i])){
   printf("\nMatriks tidak konsisten, tidak dapat menghasilkan solusi persamaan linier, silakan input matriks kembali");
   break;
  }
  else{
   printf("\n");
   printf("X%d = %3.4f \n",(i+1),b[i]);
  }
 }
 getch();
}

void TampilMatriks(){
 for (i=0;i<p;i++){
  printf(" | ");
  for (j=0;j<o;j++){
   if (a[i][j]>=0)
    printf(" %3.4f ",a[i][j]);
   else
    printf("%3.4f ",a[i][j]);
  }
  printf("| |x%d|",i+1);
   if (i==3)
    printf(" = ");
   else
    printf("   ");
    printf("| %3.4f |",b[i]);
  printf("\n");
 }
}

