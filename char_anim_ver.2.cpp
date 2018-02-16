
	//setlocale(LC_ALL, "Russian");

#include <iostream>
#include <cstdio>
#include <math.h>
#include <time.h> //nanosleep
#include <clocale>



#define HEART 10084
#define SOLID 0x2588

wchar_t Sym1 = L'$';
wchar_t Sym2= L'♡';
wchar_t Space = L' ';


// nanosleep parametrs:
	timespec tw = {0, 100000000 };
	timespec tr;
	
	// Display dimensions
const int Cols = 60;
const int Rows = 40;

// Letter dimensions
const int LCols = 26;
const int LRows = 20;

// letter start
int LColsS = 16;  //(Cols - LCols)/2;
int LRowsS = 10; //(Rows - LRows)/2;

char MaskHeart1 [20][27] = {
"      111        111",
"     11111      11111",
"    1111111    1111111",
"   111111111  111111111",
"  1111111111111111111111",
" 111111111111111111111111",
"11111111111111111111111111",
"11111111111111111111111111",
" 111111111111111111111111",
"  1111111111111111111111",
"   11111111111111111111",
"    111111111111111111",
"     1111111111111111",
"      11111111111111",
"       111111111111",
"        1111111111",
"         11111111",
"          111111",
"           1111",
"            11"
};
char MaskHeart2[20][27] = {
"        ",
"              ",
"      111        111",
"     11111      11111",
"    1111111    1111111",
"   111111111  111111111",
"  1111111111111111111111",
"  1111111111111111111111",
"   11111111111111111111",
"    111111111111111111",
"     1111111111111111",
"      11111111111111",
"       111111111111",
"        1111111111",
"         11111111",
"          111111",
"           1111",
"            11",
"           ",
"            "
};

void PrintArr(wchar_t Arr[][Cols], int Rows, int Cols );
void FillArr( wchar_t Arr[][Cols], int Rows, int Cols );
void Square( wchar_t Arr[][Cols], int Rows, int Cols );
void Heart1( wchar_t Arr[][Cols], int Rows, int Cols );
void Heart2( wchar_t Arr[][Cols], int Rows, int Cols );
void PrintArrInt(int Arr[][Rows][Cols], int Rows, int Cols );
void SwapHBreak(int Arr[][Rows][Cols], int Rows, int Cols );
void HBFill(int HBreak[][Rows][Cols], wchar_t Disp[][Cols], int Rows, int Cols );

using namespace std;

int main(){
	srand(time(0));
   
	// display
	wchar_t Disp[Rows][Cols];
	while (true ){
    for (int repeat = 0; repeat < 6; repeat++){
    	
    	// big heart
       system("cls");
   	FillArr(Disp, Rows, Cols);
   	PrintArr(Disp, Rows, Cols);
   	nanosleep(&tw, &tr);
   	
   	system("cls");
       Heart1 (Disp, Rows, Cols);
   	PrintArr(Disp, Rows, Cols);
   	for (int i =0; i < 1; i++){
   	   nanosleep(&tw, &tr);
   	}
   	
   	// small heart
   	          system("cls");
   	FillArr(Disp, Rows, Cols);
   	PrintArr(Disp, Rows, Cols);
   	nanosleep(&tw, &tr);
   	
   	system("cls");
       Heart2 (Disp, Rows, Cols);
   	PrintArr(Disp, Rows, Cols);
   	for (int i =0; i < 6; i++){
   	   nanosleep(&tw, &tr);
        }
   }	
  
    

    // heartbreak
    	// exploited heart's  directions
	int HBreak[2][Rows][Cols] = {0};
	// choose direction of exploition
	for (int i = 0; i < Rows; i++){
		for (int j = 0; j < Cols; j++){
			if (Disp[i][j] == Sym1){
				int dir = 1 + rand()%8;
				HBreak[0][i][j] = dir;
			}
		}
	}
	
//	PrintArrInt(HBreak, Rows,Cols);
	// nanosleep(&tw, &tr);
	 bool HaveSym = true;
	 
	 while (HaveSym){
	 	HaveSym = false;
 	for (int i = 0; i < Rows; i++){
		for (int j = 0; j < Cols; j++){
			if (HBreak[0][i][j] !=0 ){
				HaveSym = true;
			switch (HBreak[0][i][j] ){
				case 1:   // right	
		if (j < Cols-1){ 
		HBreak[1][i][j+1] = 1;	
		HBreak[0][i][j] = 0;
		}	
				break;
				
				case 2:   // down
		if (i < Rows-1) {
		HBreak[1][i+1][j] = 2;	
		HBreak[0][i][j] = 0;
		}
				break;
				
				case 3:   // left
  	if (j > 0){
  		 HBreak[1][i][j-1] = 3;	
  		 HBreak[0][i][j] = 0;
  	}
				break;
				
				case 4:   // up
			
		if (i > 0) {
			HBreak[1][i-1][j] = 4;	
			HBreak[0][i][j] = 0;
		}
				break;
					case 5:   // right-up
		if (j < Cols-1 && i >0){ 
		HBreak[1][i-1][j+1] = 5;	
		HBreak[0][i][j] = 0;
		}	
				break;
					case 6:   // right-down
		if (j < Cols-1 && i < Rows -1){ 
		HBreak[1][i+1][j+1] = 6;
		HBreak[0][i][j] = 0;
		}	
				break;
				case 7:   // left-up
  	if (j > 0 && i > 0){
  		 HBreak[1][i-1][j-1] = 7;	
  		 HBreak[0][i][j] = 0;
  	}
				break;
				case 8:  // left-down
  	if (j > 0 && i < Rows -1){
  		 HBreak[1][i+1][j-1] = 8;	
  		 HBreak[0][i][j] = 0;
  	}
				break;
			
		 	}
			}
		}
	}
	
	   SwapHBreak(HBreak, Rows,Cols);
	   system("cls");
    //	PrintArrInt(HBreak, Rows,Cols);
    
      HBFill(HBreak, Disp, Rows, Cols);
   	PrintArr(Disp, Rows, Cols);
    	 nanosleep(&tw, &tr);
	 }
	}
	return 0;
}

void Heart1( wchar_t Arr[][Cols], int Rows, int Cols ){
	
	for (int i = LRowsS; i < LRowsS+LRows; i++){
		for (int j = LColsS; j < LColsS+LCols; j++){
			if (MaskHeart1 [i - LRowsS] [ j - LColsS] == '1') Arr[ i ][ j ] = Sym1;
			else Arr[i][j] = Space;
		}
	}
}

void Heart2( wchar_t Arr[][Cols], int Rows, int Cols ){
	
	for (int i = LRowsS; i < LRowsS+LRows; i++){
		for (int j = LColsS; j < LColsS+LCols; j++){
			if (MaskHeart2 [i - LRowsS] [ j - LColsS] == '1') Arr[ i ][ j ] = Sym1;
			else Arr[i][j] = Space;
		}
	}
}


void Square( wchar_t Arr[][Cols], int Rows, int Cols ){
	
	for (int i = LRowsS; i < LRowsS+LRows; i++){
		for (int j = LColsS; j < LColsS+LCols; j++){
			Arr[ i ][ j ] = Sym1;
		}
	}
}


void FillArr( wchar_t Arr[][Cols], int Rows, int Cols ){
		// fill Disp 
	wchar_t* p = Arr[0];
	for (int i = 0; i < Rows*Cols; i++){
		*p = Space;
		p++;
	}
}

void PrintArr(wchar_t Arr[][Cols], int Rows, int Cols ){
	for (int i = 0; i < Rows; i++){
		for (int j = 0; j < Cols; j++){
			wcout << Arr[i][j] ;
		//	nanosleep(&tw, &tr);
		}
		cout << endl;
	}
}

void PrintArrInt(int Arr[][Rows][Cols], int Rows, int Cols ){
	for (int i = 0; i < Rows; i++){
		for (int j = 0; j < Cols; j++){
			cout << Arr[0][i][j] ;
		//	nanosleep(&tw, &tr);
		}
		cout << endl;
	}
}

void SwapHBreak(int Arr[][Rows][Cols], int Rows, int Cols ){
	for (int i = 0; i < Rows; i++){
		for (int j = 0; j < Cols; j++){
			 Arr[0][i][j] = Arr[1][i][j] ;
			 Arr[1][i][j] = 0;
		}
	}
}

void HBFill(int HBreak[][Rows][Cols], wchar_t Disp[][Cols], int Rows, int Cols ){
	for (int i = 0; i < Rows; i++){
		for (int j = 0; j < Cols; j++){
			 if (HBreak[0][i][j] == 0){
			 	Disp[i][j] = Space;
			 }
			 else{
			 	Disp[i][j] = Sym2;
			 }
		}
	}
}
