#include <iostream>
#define MAX 10

using namespace std;

struct stack{
	int top;
	int data[MAX];
}tumpukan;//tumpukan menjadi member struct

void init(){
	tumpukan.top = -1;
}//memastikan indeks top berada pada indeks ke=0

bool isempty(){
	if (tumpukan.top == -1){
		return true;
	}//mengembalikan nilai true jika kosong
	return false;
}

bool isfull(){
	if (tumpukan.top == MAX - 1){
		return true;
	}//mengembalikan nilai true juka indeks dari top bernilai n-1
	return false;
}

void push(){
	if(isfull() == true){
		cout << "Penuh" << endl;
	}
	else{
		tumpukan.top++;
		cout << "Masukkan data = "; cin >> tumpukan.data[tumpukan.top];
		cout << "Data " << tumpukan.data[tumpukan.top] << " masuk stack" << endl;
	}
}

void pop(){
	if(isempty()){
		cout << "Kosong" << endl;
	}
	else{
		cout << "Data " << tumpukan.data[tumpukan.top] << " sudah terambil" << endl;
		tumpukan.top--;
	}
}

void printstack(){
	if(isempty()){
		cout << "Tumpukan kosong\n";
	}
	else{
		cout << "Tumpukan : ";
		for (int i = tumpukan.top; i>=0; i--){
			cout << tumpukan.data[i] << ((i == 0) ? "\n" : ",") ;
		}
	}
}

int main()
{
	int pilihan;
	init();
	do{
		cout << "1. Input (Push)\n"
		<< "2. Hapus (Pop)\n"
		<< "3. Print\n"
		<< "4. Keluar\n"
		<< "Masukkan Pilihan : ";
		cin >> pilihan;
		switch(pilihan){
			case 1:
				push();
				break;
			case 2:
				pop();
				break;
			case 3:
				printstack();
				break;
			case 4:
				return 0;
			default:
				cout << "Botol" << endl;
				break;	
		}
	}while (true);
}
