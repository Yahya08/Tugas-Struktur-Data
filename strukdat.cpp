#include <iostream>
#include <stdlib.h>
#include <stdlib.h>
using namespace std;
#define n 10

float nilai_pointer(float *TOT, float *ipk) // Fungsi pointer IPK
{ 	
	return *ipk=*TOT/5/25;	// array untuk menghitung nilai IPK		
}

struct mahasiswa{
    string nama;
    int nim;
    
}Mhs[n];

struct queue{
    int awal, akhir;
}Queue;

void deQueue();
void menu();
void inQueue();
void tampil();

void init(){
    Queue.awal = -1;
    Queue.akhir = -1;
    cout << "Data berhasil di reset" << endl << endl;
    menu();
}

bool isFull(){
    if(Queue.akhir == n - 1){
        return true;
    } else {
        return false;
    }
}

bool isEmpty(){
    if(Queue.akhir == -1){
        return true;
    }else {
        return false;
    }
}

void inQueue(){
    if(!isFull()){
        string nama;
        int nim;
        cout << "Masukkan nama mahasiswa:";
        cin >> nama;
        cout << "Masukkan NIM mahasiswa:";
        cin >> nim;
        Mhs[Queue.akhir].nama = nama;
        Mhs[Queue.akhir].nim = nim;
        ++Queue.akhir;
        cout << endl;
        menu();
    }else {
        cout << "Data penuh";
        menu();
    }
}

void menu(){
    int pilih, databaru;
    cout << "1. masukkan data\n";
    cout << "2. Hapus satu data\n";
    cout << "3. Reset data\n";
    cout << "4. tampil data\n";
	cout<<"  5. Insert Depan          ="<<endl;
    cout<<"  6. Delete Depan          ="<<endl;
    cout<<"  7. Tampil Data           ="<<endl;
    cout<<"  8. Clear                 ="<<endl;
    cout<<"  9. Exit                  ="<<endl;
    cout << "Masukkan pilihan anda:";
    cin >> pilih;
    cout << endl;
    if(pilih == 1){
        inQueue();
    }else if(pilih == 2){
        deQueue();
    } else if(pilih == 3){
        init();
    }else if(pilih == 4){
        tampil();
	}else if(pilih == 5) {
		cout<<"Masukan Data = ";cin>>databaru;
        insertDepan(databaru);
        break;
    }else if(pilih == 6){
        hapusDepan();
    	break;
    }else if(pilih == 7){
        tampil();
        break;
    }else if(pilih == 8){
        clear();
        break;
    }else if(pilih == 9){
    	return 0;
        break;
    }else {
        menu();
    }
}

void deQueue(){
    if(!isEmpty()){
        for(int i = Queue.awal; i < Queue.akhir; i++){
            Mhs[i].nama = Mhs[i+1].nama;
            Mhs[i].nim = Mhs[i+1].nim;
        }Queue.akhir--;
        cout << "Data berhasil dihapus" << endl;
        cout << endl;
        menu();
    }else{
        cout << "antrian kosong" << endl;
    }
}

void tampil(){
    if(!isEmpty()){
        for(int i = 0; i < Queue.akhir; i++){
        cout << "Nama Mahasiswa: " << Mhs[i].nama << endl;
        cout << "NIM : " << Mhs[i].nim << endl; 
        cout << endl;
        }
    }else {
        cout << "data kosong";
        cout << endl << endl;
    }
    menu();
}


void bubble(float *ipk, string *nama, string *nim, int jumlah){ //Fungsi Pointer Bubble Sorting IPK
	string temp;
	float sort;
	int loot,maks;
	
	//Sorting Peringkat IPK 
	for(int i=0;i<(jumlah-1);i++){
		for(int j=0;j<(jumlah-1);j++){
			if(ipk[j]<ipk[j+1]){
				// Proses Bubble Sort IPK
				sort=ipk[j];
				ipk[j]=ipk[j+1];
				ipk[j+1]=sort;
				// Proses Bubble Sort NIM
				temp=nim[j];
				nim[j]=nim[j+1];
				nim[j+1]=temp;
				// Proses Bubble Sorting Nama
				temp=nama[j];
				nama[j]=nama[j+1];
				nama[j+1]=temp;
			}
		}
	}
}
		
void insertion(float *ipk, string *nama, string *nim, int jumlah){
	string temp;
	float sort;
	int loot;
	for(int i=0; i<jumlah; i++){
		// Proses insertion Sort IPK
		sort = ipk[i];
		loot = i-1;
		while(ipk[loot] < sort && loot>=0)
		{
			ipk[loot+1] = ipk[loot];
			loot--;	
		}
		ipk[loot+1] = sort;
		// Proses Insertion sort NIM
		temp = nim[i];
		loot = i-1;
		while(nim[loot] < temp && loot>=0)
		{
			nim[loot+1] = nim[loot];
			loot--;	
		}
		nim[loot+1] = temp;
		// Proses Insertion sort Nama
		temp = nama[i];
		loot = i-1;
		while(nama[loot] < temp && loot>=0)
		{
			nama[loot+1] = nama[loot];
			loot--;	
		}
		nama[loot+1] = temp;		
	}
}
	
struct TNode{
    int data;
    TNode *next;
};

TNode *head, *tail;

void init (){
    head = NULL;
    tail = NULL;
}

int isEmpty(){
    if(tail==NULL)return 1;
    else return 0;
}

void insertDepan(int databaru)
{
    TNode *baru;
    baru = new TNode;
    baru->data = databaru;
    baru->next = NULL;
    if(isEmpty()==1)
    {
        head=tail=baru;
        tail->next=NULL;
    }else
    {
        baru->next = head;
        head=baru;
    }
    cout<<"Data masuk\n";
}

void tampil(){
    TNode *bantu;
    bantu=head;
        if(isEmpty()==0)
        {
            while(bantu!=NULL)
            {
                cout<<bantu->data<<" ";
                bantu=bantu->next;
            }
        }else cout <<"Masih kosong\n";
}

void hapusDepan()
{

    TNode *hapus;
    int d;
    if (isEmpty()==0)
    {
        if(head!=tail)
        {
            hapus=head;
            d=hapus->data;
            head=head->next;
            delete hapus;
        }else
        {
            d=tail->data;
            head=tail=NULL;
        }
    cout<<d<<"terhapus";
    }else cout<<"Masih kosong\n";
}

void clear()
{
    TNode *bantu, *hapus;
    bantu =head;
    while(bantu!=NULL)
    {
        hapus=bantu;
        bantu=bantu->next;
        delete hapus;
    }
    head = NULL;
    printf("clear");
}


void selection(float *ipk, string *nama, string *nim, int jumlah){
	string temp;
	float sort;
	int loot,maks;
	for(int i=0; i<jumlah; i++)
	{	// Proses selection Sort IPK
		maks = i;
		for(int j=i+1; j<jumlah; j++){
			if(ipk[maks] < ipk[j])
			maks=j;
		}
		if(ipk[i] != ipk[maks])
		{
			sort=ipk[i];
			ipk[i]=ipk[maks];
			ipk[maks]=sort;	
		}
		// Proses selection Sort NIM	
		maks = i;
		for(int j=i+1; j<jumlah; j++){
			if(nim[maks] < nim[j])
			maks=j;
		}
		if(nim[i] != nim[maks])
		{
			temp=nim[i];
			nim[i]=nim[maks];
			nim[maks]=temp;	
		}
		// Proses selection Sort Nama
		maks = i;
		for(int j=i+1; j<jumlah; j++){
			if(nama[maks] < nama[j])
			maks=j;
		}
		if(nama[i] != nama[maks])
		{
			temp=nama[i];
			nama[i]=nama[maks];
			nama[maks]=temp;	
		}		
	}						
}
void input(string *nama, string *nim, float *ipk, int jumlah ){ // Fungsi Input Mahasiswa
	// Deklarasi Variable	
	float *nilai = new float[jumlah*5];
	float tot[jumlah];
	string matkul[5]={"Pemrograman","Sistem Operasi","Struktur Data","Bahasa Inggris","Hardware/Software"};
	int total; 					
	// proses Perulangan input data Mahasiswa
	for (int i=0; i<jumlah; i++){
		total=0; 				// Variable Reset total
		cout<<endl;
			cout << "Inputkan Nama Mahasiswa: ";
			cin.ignore();
			getline(cin,*(nama+i));
			cout << "Inputkan NIM Mahasiswa: ";
			cin>>*(nim+i);
				
		for(int j=0; j<5; j++){
			cout << "Nilai Mata kuliah "<<matkul[j]<<": ";
			cin>>*(nilai+(i*5+j));
			total = total + nilai[(i*5+j)];	
		}
		tot[i]=total; // Array untuk menyimpan nilai total per mahasiswa
		nilai_pointer(&tot[i],&ipk[i]); // Alamat Pointer IPK
	}
	delete[] nilai;
		
}
int main(){	
	int jumlah,jika;
	cout<<"Inputkan jumlah data yang akan dimasukan: "; // Inputkan Jumlah Mahasiswa
	cin>>jumlah;
	string nama[jumlah], nim[jumlah];
	float ipk[jumlah];
	input(nama, nim, ipk, jumlah);
	
	balik:
	cout<<endl;
	Menu:
	int pil;
	

switch(pil) {

	case 1:
	system("cls");
 	cout << endl;
 	cout << "Bubble sort"<<endl;
 	cout << "=============="<<endl;
 	int t1,t2;

	bubble(ipk, nama, nim, jumlah ); // Fungsi bubble Sorting Peringkat IPK	
	cout<<endl;
 	cout << endl <<"Lama proses = " << (int)(t2 - t1) << " ms";
 	cout<<endl;
 
 	break;

	 case 2:
 	system("cls");
 	cout << "Insertion sort";
 	cout <<endl<<"============="<<endl;
 	cout<<endl;
 	int t3,t4;

	insertion(ipk, nama, nim, jumlah ); // Fungsi insertion Sorting Peringkat IPK	
	cout << endl<<endl <<"Lama proses = " << (int)(t4 - t3) << " ms";
 	cout<<endl;

 	break;

	case 3:
 	system("cls");
 	cout << "Selection sort";
 	cout <<endl<< "================="<<endl<<endl;
 	int t5,t6;
	selection(ipk, nama, nim, jumlah ); // Fungsi Selection Sorting Peringkat IPK	
	cout << endl<<endl <<"Lama proses = " << (int)(t6 - t5) << " ms";
 	cout<<endl;
 	break;
	
	default:
 	system("cls");
	cout<<"Input yang anda masukan tidak sesuai, silahkan di input ulang"<<endl;
	goto Menu;
}

	
	// mencetak Data mahasiswa
	system("cls");
	cout<<"Peringkat Nilai Mahasiswa Tertinggi"<<endl;
	if(jika==1)
	{
	cout<<"(dengan menggunakan Metode Bubble Sorting)"<<endl;
	}if(jika==2)
	{
	cout<<"(dengan menggunakan Metode Insertion Sorting)"<<endl;
	}if(jika==3)
	{
	cout<<"(dengan menggunakan Metode Selection Sorting)"<<endl;	
	}
	cout<<endl;	
	for (int i=0; i<jumlah; i++){
		cout<<"Data nilai mahasiswa ke-"<<(i+1)<<endl;
		cout <<"Nama Mahasiswa: "<< nama[i]<<endl;
		cout << "NIM: "<<nim[i]<<endl;	
    	cout<<"IPK : "<<ipk[i]<<endl;	
		cout<<endl;			
	}

    menu();
	return 0;
}








