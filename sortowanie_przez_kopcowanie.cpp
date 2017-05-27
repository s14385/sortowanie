#include <iostream>
#include <cstdlib>
#include <time.h>
#include <windows.h>
using namespace std;

int main(){

    int ilosc_liczb;
    int i, j, k, m, x;

    cout << "Podaj ilosc liczb do posortowania: ";
    cin >> ilosc_liczb;

    int * d = new int[ilosc_liczb];

    srand(time(NULL));

    for (i = 0; i < ilosc_liczb; i++){
    	
        d[i] = rand();
    }
    
    DWORD dw1 = GetTickCount();
    
    for (i = 2; i < ilosc_liczb; i++){
    	
        j = i;
        k = j / 2;
        x = d[i];
        
        while ((k > 0) && (d[k] < x)){
        	
            d[j] = d[k];
            j = k;
            k = j / 2;
        }
        
        d[j] = x;
    }

    for (i = ilosc_liczb - 1; i > 1; i--){
    	
        swap(d[1], d[i]);
        j = 1;
        k = 2;
        
        while (k < i) {
        	
            if ((k + 1 < i) && (d[k + 1] > d[k])){
            	
            	m = k + 1;
			}
            else{
            	
            	m = k;
			}
            
            if (d[m] <= d[j]){
			
				break;	
            }
                
            swap(d[j], d[m]);
            j = m;
            k = j + j;
        }
    }
	
	DWORD dw2 = GetTickCount();
	
	cout << "Czas: " << (dw2 - dw1) / 1000.0 << " sekund." << endl;
	
	//for(i = 0; i < ilosc_liczb; i++) cout << "d[" << i << "] = " << d[i] << endl;
	
    return 0;
}
