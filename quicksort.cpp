#include <iostream>
#include <cstdlib>
#include <time.h>
#include <windows.h>
using namespace std;

int partition(int tablica[], int p, int r){
	
    int x = tablica[p];
    int i = p, j = r, w;
    
    while(true){
    	
        while (tablica[j] > x) j--;
        while (tablica[i] < x) i++;
        
        if (i < j){
        	
            w = tablica[i];
            tablica[i] = tablica[j];
            tablica[j] = w;
            i++;
            j--;
        }
        else
            return j;
    }
}

void quicksort(int tablica[], int p, int r){
    int q;
    
    if (p < r){
    	
        q = partition(tablica, p, r);
        quicksort(tablica, p, q);
        quicksort(tablica, q + 1, r);
    }
}

int main(){
	
    int ilosc_liczb, i;
    
    cout << "Podaj ilosc liczb do posortowania: ";
    cin >> ilosc_liczb;
    
    int* tablica = new int[ilosc_liczb];
    
    srand(time(NULL));
    
    for (i = 0; i < ilosc_liczb; i++){
    	
    	tablica[i] = rand();
    }
    
    DWORD dw1 = GetTickCount();
    
    quicksort(tablica, 0, ilosc_liczb - 1);
    
    DWORD dw2 = GetTickCount();
    
    cout << "Czas: " << (dw2 - dw1) / 1000.0 << " sekund." << endl;
    
    //for(i = 0; i < ilosc_liczb; i++) cout << "tablica[" << i << "] = " << tablica[i] << endl;
        
    delete[] tablica;
    return 0;
}
