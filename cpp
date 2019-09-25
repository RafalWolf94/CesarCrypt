#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h>

int Choose()
{
	char Pick;
	do {
		system("CLS");
		std::cout << "Hello" << std::endl;
		std::cout << "1.Encrypt" << std::endl;
		std::cout << "2.Decrypt" << std::endl;
		std::cout << "3.Encrypt text to new File" << std::endl;
		std::cout << "4.Decrypt File" << std::endl;
		std::cout << "5.Exit" << std::endl;

		std::cin >> Pick;

	} while (!(Pick <= '5' && Pick >= '1'));
	Pick = Pick - '0';
	return Pick;
}
std::string GetText() // Enter text to Crypt/Decrypt.
{
	std::string TextToCrypt;
	std::cout << "Enter you text" << std::endl;
	std::string input = "";
	std::cin >> TextToCrypt;
	std::getline(std::cin, input);
	TextToCrypt += input;
	return TextToCrypt;
}
std::string Cryptography(std::string Text) //Crypting text.
{
	system("CLS");
	char InArray[1024];
	strcpy_s(InArray, Text.c_str());
	int Array = strlen(InArray);
	char* OutArray = new char[Array + 1];
	char* input = InArray;
	char* output = OutArray;
	int change = 1;
	while (*input)
	{
		if (*output % 2 == 0) {
			*output++ = *(input++) + change++;
		}
		else if (*output % 3 == 0) {
			change += 1;
			*output++ = *(input++) + change++;
		}
		else {
			change += 2;
			*output++ = *(input++) + change++;
		}
	}
	*output = '\0';
	system("CLS");
	std::cout << OutArray << std::endl;
	std::getchar();
	return OutArray;
	delete OutArray;
}
std::string DeCryptography(std::string Text) //Decrypting text
{
	system("CLS");
	char InArray[1024];
	strcpy_s(InArray, Text.c_str());
	int Array = strlen(InArray);
	char* OutArray = new char[Array + 1];
	char* input = InArray;
	char* output = OutArray;
	int change = 1;
	while (*input)
	{
		if (*output % 2 == 0) {
			*output++ = *(input++) - change++;
		}
		else if (*output % 3 == 0) {
			change += 1;
			*output++ = *(input++) - change++;
		}
		else {
			change += 2;
			*output++ = *(input++) - change++;
		}

	}
	*output = '\0';

	system("CLS");
	std::cout << OutArray << std::endl;
	std::getchar();
	return OutArray;
	delete OutArray;
}
std::string Filename() // Enter the name of the file and path(path is imporat when your file isn't in program files.
{
	std::string fname;
	std::cout << "Enter the name of the file" << std::endl << "that you want to encrypt" << std::endl;
	std::cin >> fname;
	fname += ".txt";
	system("CLS");
	return fname;
}
std::string OperatingOnfile(std::string msg) // loading all data from file, and saving them in the CPU memory
{
	char filename[1024];
	strcpy_s(filename, msg.c_str());
	char* input = filename;

	std::string name = msg;
	std::fstream file;
	file.open(msg);

	std::string data;
	if (file.is_open() == true)
	{
		while (!file.eof())
		{
			getline(file, data);
			std::cout << "Succes" << std::endl;;
		}
	}
	else
		std::cout << "Fail" << std::endl;;
	
	std::getchar();
	file.close();
	system("CLS");
	remove(filename);
	return DeCryptography(data);
	delete &data;	
}
void CreateNewFile(std::string text) //Creating new .txt file
{

	std::string filename = Filename();


	std::fstream newfile;
	newfile.open(filename, std::ios::out);
	if (newfile.is_open() == true)
	{
		newfile << text;
		std::cout << "Succes" << std::endl;;
	}
	else
		std::cout << "Fail" << std::endl;;

	newfile.close();
}
void Menu()
{
	int choice;
	do {
		choice = Choose();
		switch (choice)
		{
		case 1:
			Cryptography(GetText());
			break;
		case 2:
			DeCryptography(GetText());
			break;
		case 3:
			CreateNewFile(Cryptography(GetText()));
			break;
		case 4:
			OperatingOnfile(Filename());
			break;
		case 5:
			system("cls");
			break;
		default:
			std::cout << "You Have to Choose";
		}
	} while (choice != 5);
}

int main()
{
	Menu();

	return 0;
}
