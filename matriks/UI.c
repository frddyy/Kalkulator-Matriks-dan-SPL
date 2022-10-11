#include <stdio.h>
#include <conio.h>
#include "UI.h"

void charToASCII(char c) 
{
	/* Modul yang mengkonversi char ke char tertentu berdasarkan ASCII */
	switch(c)
	{
		case '=' :
			printf ("%c", 254);
			break;
		case '|' :
			printf ("%c", 222);
			break;
		case '#' :
			printf ("%c", 206);
			break;
		case '/' :
			printf ("%c", 221);
			break;
		case '&' :
			printf ("%c", 203);
			break;
		case '<' :
			printf ("%c", 204);
			break;
		case '>' :
			printf ("%c", 185);
			break;
		case 'Z' :
			printf ("%c", 075);
			break;
		case 'Q' :
			printf ("%c", 057);
			break;
		case '{' :
			printf ("%c", 201);
			break;
		case '}' :
			printf ("%c", 187);
			break;
		case '@' :
			printf ("%c", 200);
			break;
		case '~' :
			printf ("%c", 188);
			break;
		case 'X' :
			printf ("%c", 174);
			break;
		case '$' :
			printf("%c", 47);
			break;
		default :
			printf ("%c", c);		
	}
}

void Show_Penjumlahan(){
		char title[] = 
		"\t\t\t\t\t    {===================}\n\
		  \t\t\t    /Penjumlahan Matriks|\n\
	 	    \t\t\t    @===================~\n\
		";
	
		for(int i = 0; i < strlen(title); i++)
	{
		charToASCII(title[i]);
	}
	printf("\n\n");
}

void Show_Pengurangan(){
		char title[] = 
		"\t\t\t\t\t    {===================}\n\
		  \t\t\t    /Pengurangan Matriks|\n\
	 	    \t\t\t    @===================~\n\
		";
	
		for(int i = 0; i < strlen(title); i++)
	{
		charToASCII(title[i]);
	}
	printf("\n\n");
	
}

void Show_Skalar(){
	char title[] = 
		"\t\t\t\t\t    {========================}\n\
		  \t\t\t    /Perkalian Matriks Skalar|\n\
	 	    \t\t\t    @========================~\n\
		";
	
		for(int i = 0; i < strlen(title); i++)
	{
		charToASCII(title[i]);
	}
	printf("\n\n");
}

void Show_DuaMatriks(){
	char title[] = 
		"\t\t\t\t\t    {=====================}\n\
		  \t\t\t    /Perkalian Dua Matriks|\n\
	 	    \t\t\t    @=====================~\n\
		";
	
		for(int i = 0; i < strlen(title); i++)
	{
		charToASCII(title[i]);
	}
	printf("\n\n");
}

void Show_Inverse(){
	char title[] = 
		"\t\t\t\t\t    {===========================}\n\
		  \t\t\t    /Perhitungan Inverse Matriks|\n\
	 	    \t\t\t    @===========================~\n\
		";
	
		for(int i = 0; i < strlen(title); i++)
	{
		charToASCII(title[i]);
	}
	printf("\n\n");
}


void Show_OBE(){
		char title[] = 
		"\t\t\t\t    {===========================================}\n\
		  \t\t    /Perhitungan SPL Matriks dengan Gauss Jordan|\n\
	 	    \t\t    @===========================================~\n\
		";
	
		for(int i = 0; i < strlen(title); i++)
	{
		charToASCII(title[i]);
	}
	printf("\n\n");
}

void Show_Transpose(){
	char title[] = 
		"\t\t\t\t\t    {=============================}\n\
		  \t\t\t    /Perhitungan Transpose Matriks|\n\
	 	    \t\t\t    @=============================~\n\
		";
	
		for(int i = 0; i < strlen(title); i++)
	{
		charToASCII(title[i]);
	}
	printf("\n\n");
}

void Show_Determinan(){
	char title[] = 
		"\t\t\t\t\t    {==============================}\n\
		  \t\t\t    /Perhitungan Determinan Matriks|\n\
	 	    \t\t\t    @==============================~\n\
		";
	
		for(int i = 0; i < strlen(title); i++)
	{
		charToASCII(title[i]);
	}
	printf("\n\n");
}