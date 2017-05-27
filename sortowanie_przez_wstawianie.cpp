#include <iostream>
#include <cstdlib>
#include <time.h>
#include <windows.h>
using namespace std;

int main(){
	
	int ilosc_liczb;
    int i, j, x;
    
    cout << "Podaj ilosc liczb do posortowania: ";
    cin >> ilosc_liczb;

    int * d = new int[ilosc_liczb];
    
    
    srand(time(NULL));

    for (i = 0; i < ilosc_liczb; i++){
    	
    	d[i] = rand();
	}
	
	DWORD dw1 = GetTickCount();
	
    for (j = ilosc_liczb - 2; j >= 0; j--){
    	
        x = d[j];
        i = j + 1;
        
        while ((i < ilosc_liczb) && (x > d[i])){
        	
            d[i - 1] = d[i];
            i++;
        }
        
        d[i - 1] = x;
    }

	DWORD dw2 = GetTickCount();
	
	cout << "Czas: " << (dw2 - dw1) / 1000.0 << " sekund." << endl;
	
	for(i = 0; i < ilosc_liczb; i++) cout << "d[" << i << "] = " << d[i] << endl;
	
    return 0;
}
