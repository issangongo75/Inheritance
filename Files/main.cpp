#include<iostream>
#include<fstream>
using std::cin;
using std::cout;
using std::endl;

//#define WRITE_TO_FILE
#define READ_FROM_FILE

void main()
{
	setlocale(LC_ALL, "");
#ifdef WRITE_TO_FILE
	cout << "Hello Files" << endl;

	std::ofstream fout; //1)Faire поток
	fout.open("File.txt", std::ios_base::app);//2) Ouvrir поток

	//std::ios_base::app(append)


	fout << "Hello Files" << endl;//пишем поток
	fout << "Hello" << endl;
	fout.close(); //4) Fermer поток

	system("notepad File.txt");
#endif // WRITE_TO_FILE

	std::ifstream fin("File.txt");
	if (fin.is_open())
	{
		//TO DO read from file
		
		while (!fin.eof())
		{
			
			const int SIZE = 1024000;
			char buffer[SIZE]{};
			//fin >> buffer;
			fin.getline(buffer, SIZE);
			cout << buffer << endl;
		}
		fin.close();
	}
	else
	{
		std::cerr << "Error: File not found" << endl; 
	}

}