#include "matriks.h"
#include "UI.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>


/*=======================================================================
						MODUL UNTUK INVERSE
========================================================================*/


int main(){
    MATRIKS A,B;
    ElType K;
    int input, col, row, col2, row2;
    char input2;
    float order;

	menu:
		system("cls");
		printf("====================================================\n");
		printf("\t\tKALKULATOR MATRIKS\t\n");
		printf("====================================================\n");
		printf("[1]\tPenjumlahan dan Pengurangan\n");
		printf("[2]\tPerkalian\n");
		printf("[3]\tOperasi Lain\n");
		printf("[4]\tSolusi SPL\n");
		printf("[0]\tKeluar");
		printf("\nPilih menu: ");
		scanf("%d", &input);
		
		while(input != 0)
		{
			switch(input)
			{
				case 1:
					submenu1:
						system("cls");
						printf("=====================\n");
						printf("[1]\tPenjumlahan\n");
						printf("[2]\tPengurangan\n");
						printf("=====================\n");
						input2 = getchar();
						
						if(input2 == '1'){
							system("cls");
							Show_Penjumlahan();
							printf("Masukkan ordo Matriks 1 (contoh-> 3 3): ");
							scanf("%d %d", &col, &row);
						    printf("================\n");
						    BacaMATRIKS(&A,col, row);
						    printf("==============================================\n");
							printf("Masukkan ordo Matriks 2 (contoh-> 3 3): ");
							scanf("%d %d", &col2, &row2);
						    printf("================\n");
						    BacaMATRIKS(&B,col2, row2);
							printf("==============================================\n");
							printf("Hasil: ");
							printf("\n================\n");
						    TulisMATRIKS(TambahMATRIKS(A,B));
						    getch();
						    goto submenu1;
						}else if(input2 == '2'){
							system("cls");
							Show_Pengurangan();
							printf("==============================================\n");
							printf("Masukkan ordo Matriks 1 (contoh-> 3 3): ");
							scanf("%d %d", &col, &row);
						    printf("================\n");
						    BacaMATRIKS(&A,col, row);
						    printf("==============================================\n");
							printf("Masukkan ordo Matriks 2 (contoh-> 3 3): ");
							scanf("%d %d", &col2, &row2);
						    printf("================\n");
						    BacaMATRIKS(&B,col2, row2);
							printf("==============================================\n");
							printf("Hasil: ");
							printf("\n================\n");
						    TulisMATRIKS(KurangMATRIKS(A,B));
						    getch();
						    goto submenu1;
						}else if(input2 == '0'){
							goto menu;
						}else{
							goto submenu1;
						}
						
					    break;
					    
					case 2:
						submenu2:
							system("cls");
							printf("================================\n");
							printf("[1]\tPerkalian Skalar\n");
							printf("[2]\tPerkalian Dua Matriks\n");
							printf("================================\n");
							input2 = getchar();
							
							if(input2 == '1'){
								system("cls");
								Show_Skalar();
								printf("==============================================\n");
								printf("Masukkan ordo Matriks (contoh-> 3 3): ");
								scanf("%d %d", &col, &row);
							    printf("================\n");
							    BacaMATRIKS(&A,col, row);
							    printf("==============================================\n");
								printf("Masukkan Konstanta (contoh-> 3): ");
								scanf("%d", &K);
								printf("================\n");
								TulisMATRIKS(KaliKons(A, K));
								getch();
								goto submenu2;
							}else if(input2 == '2'){
								system("cls");
								Show_DuaMatriks();
								printf("==============================================\n");
								printf("Masukkan ordo Matriks 1 (contoh-> 3 3): ");
								scanf("%d %d", &col, &row);
							    printf("================\n");
							    BacaMATRIKS(&A,col, row);
							    printf("==============================================\n");
								printf("Masukkan ordo Matriks 2 (contoh-> 3 3): ");
								scanf("%d %d", &col2, &row2);
							    printf("================\n");
							    BacaMATRIKS(&B,col2, row2);
								printf("==============================================\n");
								printf("Hasil: ");
								printf("\n================\n");
							    TulisMATRIKS(KaliMATRIKS(A,B));
							    getch();
						    	goto submenu2;
							}else if(input2 == '0'){
								goto menu;
							}else{
								goto submenu2;
							}
							
							break;
							
						case 3:
							submenu3:
								system("cls");
								printf("=====================\n");
								printf("[1]\tTranspose\n");
								printf("[2]\tDeterminan\n");
								printf("[3]\tInvers\n");
								printf("=====================\n");
								input2 = getchar();
								
								if(input2 == '1'){
									system("cls");
									Show_Transpose();
									printf("==============================================\n");
									printf("Masukkan ordo Matriks (contoh-> 3 3): ");
									scanf("%d %d", &col, &row);
								    printf("================\n");
								    BacaMATRIKS(&A,col, row);
								    printf("==============================================\n");
									printf("Hasil: ");
									printf("\n================\n");
									Transpose(&A);
									TulisMATRIKS(A);
									getch();
									goto submenu3;
								}else if(input2 == '2'){
									system("cls");
									Show_Determinan();
									printf("==============================================\n");
									printf("Masukkan ordo Matriks (contoh-> 3 3): ");
									scanf("%d %d", &col, &row);
								    printf("================\n");
								    BacaMATRIKS(&A,col, row);
								    printf("==============================================\n");
									printf("Hasil determinan matriks: %.2f", Determinan(A));
									printf("\n================\n");
									getch();
								}else if(input2 == '3'){
									system("cls");
									Show_Inverse();
									inverseMatriks();
									getch();
									goto submenu3;
								}else if(input2 == '0'){
									goto menu;
								}else{
									goto submenu3;
								}
								break;
								
						case 4:
							system("cls");
							Show_OBE();
							SPL_OBE();									
							getch ();
							break;
				default:
					goto menu;
			}
		}
		
    return 0;
}