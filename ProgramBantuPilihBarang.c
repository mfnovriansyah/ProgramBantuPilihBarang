#include <stdio.h> 
#include <stdlib.h> 
#include <windows.h>
#define PROGRESS_BAR_SIZE 40

int list[5][2];			// array yang digunakan untuk menyimpan kombinasi cost dan value yang memiliki total value tertinggi
int hitung = 0; // inisiasi dengan angka 0 untuk menghitung maksimal percobaan login masuk yaitu 3
char pilihan; // untuk  memilih pilihan
void menu(); //prototype
void judulprogram();//prototype
int cost[3] = {1,3,3}; // inisialisasi harga 
int value[3] = {1,7,8}; // inisialisasi kegunaan

struct Node 							//inisialisasi struktur dari node yang digunakan
{ 
  int data1,data2; 
  struct Node *next; 
}; 
  
void helpprogram()
{
	system("cls"); // membuat layar menjadi bersih 
	printf("\n\n-------------------------------------------------------------------------------\n");
	printf("\t\tPETUNJUK Bantu Pilih Barang				               \n");               
	printf("-------------------------------------------------------------------------------\n");
	printf("Program ini bertujuan untuk mencari kemungkinan kombinasi dan nilai tertinggi\nyang didapat dari 2 barang yang ada\n\n");
	printf("Dengan maksimal harga 5\n\n");
	printf("[1] Program Secara Default akan menambahkan barang 0 dengan harga 1 kegunaan 1 \n\n");
	printf("[2] Barang 1 Masukan  Harga  yang akan digunakan\n\n");
	printf("[3] Barang 1 Masukan Kegunaan  yang didapat\n\n");
	printf("[4] Barang 2 Masukan Harga 2 yang akan digunakan \n\n");
	printf("[5] Barang 2 Masukan Kegunaan 2 yang didapat \n\n");
	printf("[6] Akan didapat Value Teritinggi dan hasil kombinasinya \n\n");
	printf("[7] Tekan Apapun Untuk Kembali \n\n");
	system("pause");// mendelay program sampai ada inputan
	system("cls"); // membuat layar menjadi bersih 
	judulprogram(); // memanggil fungsi judulprogram
	menu(); // memanggil fungsi EDAscii
}

int add_node(struct Node** head_ref, int new_data1, int new_data2) 			//digunakan untuk menambah node baru pada linked list
																			// penambahan node digunakan dengan metode queue
{ 
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node)); 
    struct Node *last = *head_ref;  
    new_node->data1  = new_data1; 
    new_node -> data2 = new_data2;
    new_node->next = NULL; 
    if (*head_ref == NULL) 
    { 
       *head_ref = new_node; 
       return; 
    } 
    while (last->next != NULL) 
        last = last->next; 
    last->next = new_node; 
    return; 
} 


  
	FILE * baca;	
int printList(struct Node *node) { 							//digunakan untuk menampilkan kondisi sementara dari linked list setiap ditambah node baru
	int hasil=0;
	if(node==NULL){
		printf("NULL");
	}
	else{
	    while (node != NULL) { 
	  	baca = fopen("linkedlist.txt","a");
		
	     printf("Harga %d  Kegunaan %d -> ", node->data1,node->data2);
	     fprintf(baca," Harga %d  Kegunaan %d -> ", node->data1,node->data2);
		 hasil = hasil + node->data2 ;
	     node = node->next; 
	     fclose(baca);
	 	} 
	}	
	baca = fopen("linkedlist.txt","a");
	fprintf(baca,"\n");
	printf ("\n");
	fclose(baca);
 
} 


int login()// fungsi login untuk verifikasi data supaya lebih aman
{
	char username[15],password[10],c; // type char untuk username maks 15 dan password dengan ukuran data maks 10  
	int i=0; //Variabel membantu Looping
	printf("==================================================================================================\n");
	printf("                              Program Bantu Pilih Barang\n");
	printf("                                        Login\n");
	printf("                             Dibuat Oleh Fahriza dan Samuel\n");
	printf("==================================================================================================\n");
    printf("\n\tMasukan Username : ");
    scanf("%s",&username);
	printf("\n\tMasukan Password : ");
	while (i<=9){
    password[i]=getch();
    c=password[i];
    if(c==13) break;
    else printf("*");
    i++;
	}
	password[i]='\0';
	i=0;
    if(strcmp(username,"fahrizasamuel")==0 && strcmp(password,"keren")==0)//strcmp yaitu membandingkan isi yang ada pada dua data
	{
        printf("\n\t\t[Login sukses]\n");
        system("pause");
        system("cls");
    }
    else
	{
		hitung = hitung+1;
        printf("\n\t[ Username dan Password tidak sama [%d] ] \n", hitung);
        if(hitung < 3)
        {
        	printf("\n\t[ Percobaan Login Maksimal 3 kali ]\n");
        	system("pause"); // mendelay program sampai ada inputan
        	system("cls"); // membuat layar menjadi bersih lagi
        	login();       
		}
		else
		{
			printf("\t[ Percobaan Login Sudah Melebihi Batas Maksimal ] \n");
			printf("\n\t[ Anda akan Keluar Otomatis ]");
			exit(1);
		}
    }	
}


int deletelist(struct Node** head) 						// digunakan untuk menghapus linkedlist
{ 
   struct Node* temp = *head; 
   struct Node* next; 
   while (temp != NULL)  
   { 
       next = temp->next; 
       free(temp); 
       temp = next; 
   }  
   *head = NULL; 
} 



int p=0;
int store(struct Node *node){					//berguna untuk menyimpan kombinasi dari linked list setiap ditemukan kombinasi dengan value tertinggi yang baru
  	p=0;
  	while (node != NULL) { 
  	list[p][0] = node->data1;
  	list[p][1] = node->data2; 
    node = node->next; 
    p=p+1;
  	} 
} 

void print_n_chars(int n, int c) {
    while (n-- > 0) putchar(c);
}

void loading(int p) { 							// fungsi  loading
    putchar('\r');
    putchar('|');
    print_n_chars(PROGRESS_BAR_SIZE * p / 20, '|');
}

void judulprogram(){
	printf("==================================================================================================\n");
	printf("                              Program Bantu Pilih Barang\n");
	printf("                             Dibuat Oleh Fahriza dan Samuel\n");
	printf("==================================================================================================\n");
}

int inputdata(){
	int x;
	system("cls"); // membuat layar menjadi bersih 
	judulprogram();
	sleep(1);
	printf("\t -----------------------------------------------------------------------------\n");
	printf("\n\t\tProgram Bantu Pilih Barang akan menyediakan 2 Opsi Input Barang\n");
	printf("\t\tdengan Tambahan default barang 0 dimana memiliki harga 1 untuk \n");
	printf("\t\tpelengkap jika kombinasi tidak memenuhi harga yang ada.\n");
	printf("\t\tAkan ada Inputan Barang Berupa Harga dan Kegunaan dengan range\n");
	printf("\t\t- Harga untuk 2 Barang Maksimal 5.\n");
	printf("\t\t- Kegunaan untuk 2 Barang Tidak Terbatas/Unlimited.\n\n");
	printf("\t ----------------------------------------------------------------------------\n\n");
	sleep(3);
	int harga;	
	for(x=1;x<=2;x++){
		printf("\t\tMasukan Barang %d\n",x);
		printf("\t\tMasukan Harga(range Maksimal 5) :");
		scanf("%d",&cost[x]);
		if (cost[x]<6 && cost[x]>0)
		{
			printf("\t\tMasukan Kegunaan:");
			scanf("%d",&value[x]);
		}
		else{
			printf("\t\tMasukan Harga dengan range 1 sampai 5 saja %d\n",x);
			system("pause");
			return inputdata();
		}
		
	}
	printf("\t\tList Barang:\n");
		for(x=0;x<=2;x++){
		printf("\t\tBarang %d Harga %d	Kegunaan %d\n\n",x,cost[x],value[x]);
	}
}


int programbacktracking()				//bagian yang berfungsi untuk mencari setiap kombinasi serta s
{	
	inputdata();
	system("pause");
	int batas = 5;					// jumlah cost tertinggi yang dapat dikandung oleh kombinasi (linked kust)
	int i=0;						// variabel yang digunakan untuk iterasi pada array yang berisi cost dan value
	int last_cost=0	;				//	Cost terkahir yang ditambahkan ke dalam kombinasi (Linked list yang dibentuk)
	int last_value=0;				// Value terakhir yang ditambahkan ke dalam kombinasi (linked list yang dibentuk)
	int temp_value=0;				// Total value sementara yang sudah ditambahkan ke kombinasi (linked list yang dibentuk)
	int temp_cost =0;  				//	Total Cost sementara yang sudah ditambahkan ke kombinasi (linked list yang dibentuk)
	int k,l,z;						// variable - variable ini digunakan untuk mengiterasi program knapsack dibawah
			
	int prev_value=0;				// Value sementara sebelum penambahan value dilakukan ke linked list
	
	int highest_value=0;			// variable ini digunakan untuk menyimpan nilai tertinggi
		
  	struct Node* head = NULL; 		//linked list dibukan dan di set NULL
 	for (l=5;l>=0;l--){  	
 		for (z=0;z<l;z++){
 			printList(head);
 			add_node(&head,cost[0],value[0]);			//pertama program akan memasukan data pertama yaitu cost[0],value[0] ke linked list
  			temp_cost = temp_cost + cost[0];			
  			temp_value = temp_value + value[0];
  			last_cost = cost[0];
  			last_value = value[0];
 			
	
		 }	 
		 while(temp_cost<5){						//Cek apakah cost sementara lebih kecil dari 5
		 	
		 	if(temp_cost + cost[i+2] <=5 && prev_value != temp_value + value[i+2]){		//cek jika cost sementara ditambah dengan data ketiga, hasinya lebih dari 5 atau tidak
		 	printList(head);							
		 	add_node(&head,cost[2],value[2]);
  			temp_cost = temp_cost + cost[2];
  			temp_value = temp_value + value[2];
  			last_cost = cost[2];
  			last_value = value[2];
  			prev_value= temp_value;
 		
			 }
			else if(temp_cost + cost[i+1] <= 5 && prev_value != temp_value + value[i+1]){	//cek jika cost sementara ditambah dengan data kedua, hasinya lebih dari 5 atau tidak
				
			printList(head);	
			add_node(&head,cost[1],value[1]);
  			temp_cost = temp_cost + cost[1];
  			temp_value = temp_value + value[1];
  			last_cost = cost[1];
  			last_value = value[1];
  			prev_value= temp_value;
 				
			}
			else if(temp_cost + cost[0] <= 5){												//cek jika cost sementara ditambah dengan data pertama, hasinya lebih dari 5 atau tidak
			printList(head);	
			add_node(&head,cost[0],value[0]);
  			temp_cost = temp_cost + cost[1];
  			temp_value = temp_value + value[0];
  			last_cost = cost[0];
  			last_value = value[0];
 			
			}			 				 				 	
		 }
		 if(temp_value >highest_value){		 	
		 	highest_value = temp_value;		 
		 	baca = fopen("linkedlist.txt","a");
			fprintf(baca,"NEW HIGHEST ");						
			fclose(baca);
  			printf("\nNEW HIGHEST ");		 			 		 	
		 	store(head);
		 	
		 }		 	
		printList(head);
		deletelist(&head);
		temp_value = 0;
		temp_cost = 0;
		
		
	}
  	printf("\n Nilai Tertingginya  %d",highest_value);
  	printf("\n Dengan kombinasi Barang  ");
  	int a=0;								//variable sementara yang digunakan untuk iterasi ketinga print
  	for (a=0;a<p;a++){													//menampilkan kombinasi tertinggi yang ada pada linked list
    printf("Harga %d Kegunaan %d ->",list[i][0],list[i][1]);	
	}
	printf("\n");
	system("pause"); // mendelay program sampai ada inputan
	menu(); // memanggil fungsi menu
	system("pause");	
	return 0; 
}


void menu() // fungsi menu pada program dekripsi dan enkripsi
{
	int p;
    printf("\nLOADING\n\n");
    for (p = 0; p <= 20; ++p) {
        loading(p);
        Sleep(50);
    }
	system("cls"); // membuat layar menjadi bersih 
	judulprogram();
	printf("\t      ---------------------------------------------------------------\n");
	printf("\n\t\tProgram Bantu Pilih Barang akan membantu memilih kombinasi\n");
	printf("\t\tyang tepat untuk memilih 2 barang yang anda inginkan.\n\n\n");
	printf("\t      ---------------------------------------------------------------\n\n");	
	printf("\tSilahkan Pilih\n");
	printf("\t\t[1] Program Bantu Pilih Barang\n");
	printf("\t\t[2] Help\n");
	printf("\t\t[3] Keluar\n");
	printf("\n\t\tPilihan  :");
	scanf("%d",&pilihan);
	switch(pilihan)
	{
		case 1:
			programbacktracking();
			break;
		case 2:
			helpprogram();
			break;
		case 3:
			exit(1); // keluar dari program
			break;
		default : 
			printf("\n\tHarap Masukan Pilihan Yang Benar!\n");
			system("Pause"); // mendelay program sampai ada inputan
			system("cls"); // membuat layar menjadi bersih lagi
			fflush(stdin); // menghapus input sebelumnya 
			menu();
			break;
	}
}

int main(){
	login();
	menu();
	return 0;
}
