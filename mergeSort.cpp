// Name: Katherine Sandoval
// This program is the implementation of the Merge Sort algorithm

#include <iostream>
using namespace std;

int list[20];
void mergesort(int, int);
void merge(int, int, int);

int main()
{
    int num;
    
    cout << "Enter total numbers to sort:" << endl;
    cin >> num;
    
	cout << "Enter the ("<< num <<") numbers to sort:" << endl;
    for(int i = 1; i <= num; i++){
        cin >> list[i] ;
    }
    
	mergesort(1, num);
    
	cout << endl;
    
	cout << "Sorted list:" << endl;
      
    for(int i = 1; i <= num; i++)
        cout << list[i] <<"   ";

	cout << endl;

    return 0;
}

void mergesort(int low, int high)
{
    int middle;

    if(low < high){
        middle = (low + high) / 2;
        mergesort(low, middle);
        mergesort(middle + 1, high);
        merge(low, middle, high);
    }
}

void merge(int low, int middle, int high)
{
    int h = low, i = low, j = middle + 1, k, b[50];
     
    while( (h <= middle) && (j <= high) ){
        if(list[h] <= list[j]){
            b[i] = list[h];
            h++;
        }
        else{
            b[i] = list[j];
            j++;
        }
        
        i++;
    }
    
	if(h > middle){
        for(k = j; k <= high; k++){
            b[i] = list[k];
            i++;
        }
    }
    else{
        for(k = h; k <= middle; k++){
            b[i] = list[k];
            i++;
        }
    }
    for(k = low; k <= high; k++) 
		list[k] = b[k];
}