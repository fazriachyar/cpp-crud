#include <iostream>
#include <windows.h>
#include <stdio.h>
#include <conio.h>

using namespace std;

int jumlah, ganti, hapus, cari, ketemu = 0;
char lagi;


void gotoxy(int x, int y){
	COORD k = {x,y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),k);
}
struct mahasiswa
{
	string nama;
	int id;
	
}; mahasiswa m[10];

void tambah()
{
	system("cls");
	gotoxy(10,3);cout << "Menu Tambahkan Data Mahasiswa Baru" << endl;
	gotoxy(10,6);cout << "jumlah data mahasiswa yang akan dimasukan :" << endl;
	gotoxy(60,6);cin >> jumlah;
	
	for (int i = 0; i < jumlah; i++)
	{
		system("cls");
		gotoxy(10,2);cout << "Input Data Baru " << endl;
		gotoxy(10,4);cout << "masukan nama                  :";
		gotoxy(10,5);cout << "Masukan ID mahasiswa          :";
		cin.ignore();
		gotoxy(45,4);getline(cin, m[i].nama);
		gotoxy(45,5);cin >> m[i].id;
	}
}

void tambahdata()
{
	system("cls");
	int k1;
	jumlah++;
	k1 = jumlah - 1;
	
	gotoxy(10,2);cout << "Tambah Data Mahasiswa " << endl << endl << endl;
	gotoxy(10,6);cout << "Masukan ID Mahasiswa";
	gotoxy(10,7);cout << "Masukan Nama Mahasiswa";
	gotoxy(35,6);cin >> m[k1].id;
	cin.ignore();
	gotoxy(35,7);getline(cin, m[k1].nama);
}

void judul()
{
	gotoxy(2,3);cout << "|\t ID \t | Nama \t\t\t\t\t| ";
}
void tampil()
{
	system("cls");
	int i = 0;
	
	judul();
	for (int i = 0; i < jumlah; i++)
	{
		gotoxy(40,6);gotoxy(20,11+i);cout << m[i].nama << endl;
		gotoxy(10,11+i);cout << m[i].id << endl;
	}
	_getch();
}

void edit()
{
	system("cls");
	gotoxy(10,2);cout << " Masukan ID mahasiswa yang akan di edit";
	gotoxy(65,2);cin >> ganti;
	
	for (int g = 0; g < jumlah; g++)
	{
		if(m[g].id == ganti)
		{
			system("cls");
			ketemu = 1;
			
			gotoxy(10,6);cout << "ID mahasiswa      :" << endl;
			gotoxy(10,7);cout << "Nama Mahasiswa    :" << endl;
			gotoxy(35,6);cout << m[g].id << endl;
			gotoxy(35,7);cout << m[g].nama << endl;
			
			gotoxy(10,9);cout << "Yakin Ingin Di edit [ Y / T ] :";
			gotoxy(45,9);cin >> lagi;
			
			if (lagi == 'y' || lagi == 'Y')
			{
				system("cls");
				
				gotoxy(10,2);cout << "data pengganti" << endl;
				
				gotoxy(10,5);cout << "ID Mahasiswa            :";
				gotoxy(10,6);cout << "Masukan Nama Mahasiswa  :";
				gotoxy(35,5);cin >> m[g].id;
				cin.ignore();
				gotoxy(35,6);getline(cin, m[g].nama);
			}
			else
			{
				break;
			}
		}
	}
	if (ketemu == false)
	{
		cout << "data yang anda cari tidak ada";
		_getch();
	}
}

void hapuss()
{
	system("cls");
	gotoxy(10,2);cout << "Masukan ID Buku yang akan di hapus :";
	gotoxy(50,2);cin >> hapus;
	
	for(int k = 0; k < jumlah; k++)
	{
		if(hapus == m[k].id)
		{
			ketemu = 1;
			
			gotoxy(10,6);cout << "hapus data" << endl;
			
			gotoxy(10,7);cout << "ID mahasiswa      :" << endl;
			gotoxy(10,8);cout << "Nama Mahasiswa    :" << endl;
			gotoxy(35,7);cout << m[k].id << endl;
			gotoxy(35,8);cout << m[k].nama << endl;
			
			gotoxy(10,10);cout << "yakin ingin di hapus [ y / t ]";
			gotoxy(45,10);cin >> lagi;
			
			if(lagi == 'y' || lagi == 'Y')
			{
				for (int l = k; l < jumlah; l++)
				{
					m[l].id = m[l + 1].id;
					m[l].nama = m[l+1].nama;
					
				}
				jumlah -= 1;
				break;
			}
			else
			{
				break;
			}
		}
	}
	if (ketemu == false)
	{
		cout << "ID Buku yang anda cari tidak ada";
		_getch();
	}
}

void carii()
{
	system("cls");
	
	gotoxy(10,3);cout << "Masukan ID Buku :";
	gotoxy(45,3);cin >> cari;
	
	for(int n = 0; n < jumlah; n++)
	{
		if (cari == m[n].id)
		{
			ketemu = 1;
			
			gotoxy(10,5);cout << "View data" << endl;
			
			gotoxy(10,6);cout << "ID mahasiswa :" << endl;
			gotoxy(10,7);cout << "Nama Mahasiswa :" << endl;
			gotoxy(35,6);cout << m[n].id << endl;
			gotoxy(35,7);cout << m[n].nama << endl;
			
			_getch();
			break;
		}
		
	}
	if (ketemu == 0)
	{
		cout << "ID Buku yang anda cari tidak ada";
		_getch();
	}
}

int main()
{
	int pilihan;
	do
	{
		system("cls");
		gotoxy(10,2);cout<< "+==================================+"<<endl;				
		gotoxy(10,3);cout<< "|    SELAMAT DATANG @fazriachyar   |"<<endl;
		gotoxy(10,4);cout<< "+==================================+"<<endl;
		gotoxy(10,5);cout<< "|[1] Data mahasiswa Baru           |" << endl;
		gotoxy(10,6);cout<< "|[2] Tambah Data mahasiswa         |" << endl;
		gotoxy(10,7);cout<< "|[3] Cari Data mahasiswa           |" << endl;
		gotoxy(10,8);cout<< "|[4] Edit Data mahasiswa           |" << endl;
		gotoxy(10,9);cout<< "|[5] Hapus Data mahasiswa          |" << endl;
		gotoxy(10,10);cout<< "|[6] List Data mahasiswa           |" << endl;
		gotoxy(10,11);cout<< "|[7] Exit                          |" << endl;
		gotoxy(10,12);cout<<"+==================================+"<<endl;
		gotoxy(10,13);cout<< "|Masukan Pilihan :                 |" << endl;
		gotoxy(10,14);cout<<"+==================================+"<<endl;
		gotoxy(30,13);cin >> pilihan;
		
		if (pilihan == 1)
		{
			tambah();
		}
		else if (pilihan == 2)
		{
			tambahdata();	
		}
		else if (pilihan == 3)
		{
			carii();
		}
		else if (pilihan == 4)
		{
			edit();
		}
		else if(pilihan == 5)
		{
			hapuss();
		}
		else if(pilihan == 6)
		{
			tampil();
		}
		
	} while(pilihan != 0);
	
	return 0;
}
