#include "pch.h"
#include <Windows.h>
#include <iostream>
#include <string>
#include <locale>
#include <cctype>
#include <algorithm>
#include <sstream> 
#include <regex>
#include <conio.h>

using namespace std;
string g = "-";
int alf[95] = { 69, 122, 81, 35, 57, 44, 48, 99, 53, 101, 90, 64, 33, 72, 98, 75, 89, 111, 46, 93, 60, 41, 126, 109, 66, 83, 50, 69, 118, 70, 87, 68, 65, 115, 36, 92, 120, 76, 100, 119, 43, 82, 58, 104, 117, 121, 114, 42, 96, 108, 106, 95, 88, 47, 38, 49, 55, 62, 32, 113, 51, 40, 105, 78, 94, 56, 125, 54, 73, 34, 110, 63, 103, 39, 80, 116, 84, 61, 67, 77, 91, 124, 85, 97, 52, 59, 79, 37, 112, 123, 86, 74, 45, 71, 102 };

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
string tolow(string str) {
	locale loc;
	string n;
	for (string::size_type i = 0; i < str.length(); ++i) {

		n += tolower(str[i], loc);
	}


	return n;
}

string temizle(string str) {
	string n;
	int ascChar;
	for (size_t i = 0; i < str.length(); i++)
	{
		ascChar = str[i];
		if (ascChar > 64 && ascChar < 91) {
			n += str[i];
		}
		else if (ascChar > 96 && ascChar < 123)
		{
			n += str[i];
		}
	}
	return n;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////

void affine() {
	string sonuc;
	string metin;
	int a, b, sıra;
	int cc = 0;
	int* aa = new int[500];
	for (size_t i = 0; i < 500; i++)
	{
		aa[i] = 0;
	}
	for (size_t i = 0; i < 4; i++)
	{
		aa[0] = rand() % 100 + 1;
		aa[1] = rand() % 100 + 1;
	}
	a = aa[0];
	b = aa[1];
	system("cls");
	cout << "Lütfen Şifrelenecek Metni Türkçe Karakter Olmadan Girin(Max 140 karakter)" << endl;
	cin.ignore(256, '\n');
	getline(cin, metin, '\n');
	system("cls");

	for (size_t i = 0; i < metin.length(); i++)
	{
		for (size_t j = 0; j <= 94; j++)
		{
			if (metin[i] == char(j+32)) {
				sıra = j + 1;
				break;
			}
		}
		bool durum = true;
		sıra = (sıra*a) + b;
		while (sıra > 94)
		{
			sıra = sıra - 94;
			aa[i + 2] = aa[i + 2] + 1;
		}
		if (sıra == 0)
		{
			sıra = sıra + 94;
		}
	//	cout << sıra + 32 << endl;
		sonuc += char(sıra+32);
	}
	for (size_t i = 0; i < 500; i++)
	{

		if (aa[i] == 0 && aa[i + 1] == 0)
		{
			cc = i;
			break;
		}
	}
	//sonuc += alf[sıra];
	cout << "Şifreli Mesaj: " << sonuc << " Anahtar : ";

	for (size_t i = 0; i < cc; i++)
	{
		cout << aa[i];
		if (cc < i + 2) {

		}
		else
		{
			cout << "-";
		}
	}
	printf("\n\n\n");
	system("pause");

}


////////////////////////////////////////////////////////////////////////////

void affine2() {
	string sonuc;
	string metin, metin2;
	int a, b;
	int aa[500];
	for (size_t i = 0; i < 500; i++)
	{
		aa[i] = 0;
	}
	system("cls");
	cout << "Lütfen Çözümlenecek Metni Başında ve Sonunda Boşluk Olmadan Girin" << endl;
	cin.ignore(256, '\n');
	getline(cin, metin, '\n');
	system("cls");
	cout << "Lütfen Anahtar Giriniz" << endl;
	cin >> metin2;
	system("cls");
	int ss = 0;
	bool gg = true;
	for (size_t i = 0; i < metin2.length(); i++)
	{
		if (metin2[i] != g[0]) {
			stringstream geek(&metin2[i]);
			int x = 0;
			geek >> x;

			if (gg)
			{
				aa[ss] = x;
				gg = false;
			}
		}
		else
		{
			gg = true;
			ss++;
		}
	}
	a = aa[0];
	b = aa[1];
	int sıra = 0;
	for (size_t i = 0; i < metin.length(); i++)
	{
		for (size_t j = 0; j <= 94; j++)
		{
			if (metin[i] == char(j + 32)) {
				sıra = j + 1;
				break;
			}

		}
		try
		{
			sıra = (sıra + (aa[i + 2] * 94)) - b;
			sıra = sıra / a;
		}
		catch (int e)
		{
			system("cls");
			cout << "Anahtar Yanlış" << endl;
			system("pause");
		}
		if (sıra == 0)
		{
			sıra = sıra + 94;
		}

			sonuc += char((sıra -1) + 32);
		
	}


	if (sonuc == "")
	{
		cout << "Anahtar Hatalı" << "\n\n";
	}
	else
	{
		cout << "Ana Mesaj: " << sonuc << "\n\n";
	}

	system("pause");

}


////////////////////////////////////////////////////////////////////////////////////////////

void Caesar() {
	string sonuc;
	string metin;
	int a, sıra;
	int cc = 0;
	int aa[500];
	for (size_t i = 0; i < 500; i++)
	{
		aa[i] = 0;
	}
	for (size_t i = 0; i < 4; i++)
	{
		aa[0] = rand() % 300 + 1;
	}
	a = aa[0];
	system("cls");
	cout << "Lütfen Şifrelenecek Metni Türkçe Karakter Olmadan Girin(Max 140 karakter)" << endl;
	cin.ignore(256, '\n');
	getline(cin, metin, '\n');
	system("cls");

	for (size_t i = 0; i < metin.length(); i++)
	{
		for (size_t j = 0; j <= 94; j++)
		{
			if (metin[i] == char(j + 32)) {
				sıra = j + 1;
				break;
			}
		}
		bool durum = true;
		sıra = sıra + a;
		while (sıra > 94)
		{
			sıra = sıra - 94;
			aa[i + 1] = aa[i + 1] + 1;

		}
		if (sıra == 0)
		{
			sıra = sıra + 94;
		}
		//	cout << sıra + 32 << endl;
		sonuc += char(sıra + 32);
	}
	for (size_t i = 0; i < 500; i++)
	{

		if (aa[i] == 0 && aa[i + 1] == 0)
		{
			cc = i;
			break;
		}
	}
	//sonuc += alf[sıra];
	cout << "Şifreli Mesaj: " << sonuc << " Anahtar : ";

	for (size_t i = 0; i < cc; i++)
	{
		cout << aa[i];
		if (cc < i + 2) {

		}
		else
		{
			cout << "-";
		}
	}
	printf("\n\n\n");
	system("pause");

}


void Caesar2() {
	string sonuc;
	string metin, metin2;
	int a;
	int aa[500];
	for (size_t i = 0; i < 500; i++)
	{
		aa[i] = 0;
	}
	system("cls");
	cout << "Lütfen Çözümlenecek Metni Başında ve Sonunda Boşluk Olmadan Girin" << endl;
	cin.ignore(256, '\n');
	getline(cin, metin, '\n');
	system("cls");
	cout << "Lütfen Anahtar Giriniz" << endl;
	cin >> metin2;
	system("cls");
	int ss = 0;
	bool gg = true;
	for (size_t i = 0; i < metin2.length(); i++)
	{
		if (metin2[i] != g[0]) {
			stringstream geek(&metin2[i]);
			int x = 0;
			geek >> x;

			if (gg)
			{
				aa[ss] = x;
				gg = false;
			}
		}
		else
		{
			gg = true;
			ss++;
		}
	}
	a = aa[0];
	int sıra = 0;
	for (size_t i = 0; i < metin.length(); i++)
	{
		for (size_t j = 0; j <= 94; j++)
		{
			if (metin[i] == char(j + 32)) {
				sıra = j + 1;
				break;
			}

		}
		try
		{
			sıra = (sıra + (aa[i + 1] * 94)) - a;
		}
		catch (int e)
		{
			system("cls");
			cout << "Anahtar Yanlış" << endl;
			system("pause");
		}
		if (sıra == 0)
		{
			sıra = sıra + 94;
		}

		sonuc += char((sıra - 1) + 31);

	}


	if (sonuc == "")
	{
		cout << "Anahtar Hatalı" << "\n\n";
	}
	else
	{
		cout << "Ana Mesaj: " << sonuc << "\n\n";
	}

	system("pause");

}


////////////////////////////////////////////////////////////////////////////////////////////////////////


void affine_custom() {
	string sonuc;
	string metin;
	int a, b, sıra;
	int cc = 0;
	int aa[500];
	for (size_t i = 0; i < 500; i++)
	{
		aa[i] = 0;
	}

	system("cls");
	cout << "Lütfen Şifrelenecek Metni Türkçe Karakter Olmadan Girin(Max 140 karakter)" << endl;
	cin.ignore(256, '\n');
	getline(cin, metin, '\n');
	system("cls");
	cout << "Lütfen ilk Anahtarı Girin" << endl;
	cin >> aa[0];
	system("cls");
	cout << "Lütfen İkinci Anahtarı Girin" << endl;
	cin >> aa[1];
	a = aa[0];
	b = aa[1];
	system("cls");

	for (size_t i = 0; i < metin.length(); i++)
	{
		for (size_t j = 0; j <= 94; j++)
		{
			if (metin[i] == char(j + 32)) {
				sıra = j + 1;
				break;
			}
		}
		bool durum = true;
		sıra = (sıra*a) + b;
		while (sıra > 95)
		{
			sıra = sıra - 95;
			aa[i + 2] = aa[i + 2] + 1;
		}
		/*if (sıra == 0)
		{
			sıra = sıra + 94;
		}*/
		//	cout << sıra + 32 << endl;
		sonuc += char(alf[sıra]);
	}
	for (size_t i = 0; i < 500 ; i++)
	{

		if (aa[i] == 0 && aa[i + 1] == 0)
		{
			cc = i;
			break;
		}
	}
	//sonuc += alf[sıra];
	cout << "Şifreli Mesaj: " << char(127) << sonuc << char(127) << " Anahtar : ";

	for (size_t i = 2; i < cc ; i++)
	{
		cout << aa[i];
		if (cc < i +2) {

		}
		else
		{
			cout << "-";
		}
	}
	printf("\n\n\n");
	system("pause");

}


////////////////////////////////////////////////////////////////////////////


void affine2_custom() {
	string sonuc;
	string metin, metin2;
	int a, b;
	int aa[500];
	for (size_t i = 0; i < 500; i++)
	{
		aa[i] = 0;
	}
	system("cls");
	cout << "Lütfen Çözümlenecek Metni Başında ve Sonunda Boşluk Olmadan Girin" << endl;
	cin.ignore(256, '\n');
	getline(cin, metin, '\n');
	system("cls");
	cout << "Lütfen Anahtar Giriniz" << endl;
	cin >> metin2;
	system("cls");
	int ss = 0;
	bool gg = true;
	for (size_t i = 0; i < metin2.length(); i++)
	{
		if (metin2[i] != g[0]) {
			stringstream geek(&metin2[i]);
			int x = 0;
			geek >> x;

			if (gg)
			{
				aa[ss] = x;
				gg = false;
			}
		}
		else
		{
			gg = true;
			ss++;
		}
	}
	a = aa[0];
	b = aa[1];
	int sıra = 0;
	for (size_t i = 0; i < metin.length(); i++)
	{
		for (size_t j = 0; j <= 94; j++)
		{
			if (metin[i] == alf[j]) {
				sıra = j;
				break;
			}

		}
		try
		{
			sıra = (sıra + (aa[i + 2] * 95)) - b;
			sıra = sıra / a;
		}
		catch (int e)
		{
			system("cls");
			cout << "Anahtar Yanlış" << endl;
			system("pause");
		}
		if (sıra == 0)
		{
			sıra = sıra + 94;
		}

		sonuc += char((sıra -1 ) +32);

	}


	if (sonuc == "")
	{
		cout  << "Anahtar Hatalı" << "\n\n";
	}
	else
	{
		cout <<  "Ana Mesaj: " << char(127) << sonuc << char(127) << "\n\n";
	}

	system("pause");

}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


int main()
{
	 int giris;
	 setlocale(LC_ALL, "Turkish");
	 /*
	 //Alfabe Oluşturma
	bas:
	 string str;
	string s[128];
	string ss;
	int ssss , sss;
	int aa[129];
	int i= 0;
	while (i != 95)
		{
		bool dr = false;
			ssss = rand() % 95 + 32;
			ssss = rand() % 95 + 32;
			for (size_t j = 0; j < i+1 ; j++)
			{
					if (aa[j +1] == ssss)
					{
						dr = false;
						break;
					}
					else
					{
						dr = true;

				}

			}
			if (dr) {
				aa[i] = ssss;
				i++;
			} 

		}
	for (size_t m = 0; m < i+1; m++)
	{
		cout << aa[m] << ", ";
		
		
	}

		cout << ss;
		system("pause");
		system("cls");
		goto bas;
		*/
	while (true)
	{
		system("cls");
		printf("1. Doğrusal Şifreleme (Affine Cipher)\n");
		printf("2. Doğrusal Şifreleme (Affine Cipher) Çözümlenmesi\n");
		printf("3. Sezar Şifreleme (Caesar cipher)\n");
		printf("4. Sezar Şifreleme (Caesar cipher) Çözümlenmesi\n");
		printf("5. Doğrusal Şifreleme(Affine Cipher) Custom\n");
		printf("6. Doğrusal Şifreleme(Affine Cipher) Custom Çözümlenmesi\n");
		printf("\n");
		printf("Lütfen Yapılacak İşlem Numarasını Giriniz: ");

		try
		{
			giris = getchar();

		}
		catch (const std::exception&)
		{
			
		}
		


		switch (giris)
		{
		default:
			break;
		case 49:
			affine();
			break;
		case 50:
			affine2();
			break;
		case 51:
			Caesar();
			break;
		case 52:
			Caesar2();
			break;
		case 53:
			affine_custom();
			break;
		case 54:
			affine2_custom();
			break;
			
		}
	}


	system("pause");
	return EXIT_SUCCESS;
}
