#include<stdio.h>
#include<stdlib.h>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Song{
	string name;
	string artist;
	string duration;
	struct Song *next;
	struct Song *prev;
} *Head, *End;

int Menu();
void InsertSong(Song *newSong);
void ShowList();
void chargeSongs();
void persistList(Song *newSong);

int main(){
	struct Song *newSong;
	string _name, _artist, _duration;
	int option;

	Head = NULL;
	End = NULL;
	chargeSongs();

	while (1)
	{
		option = Menu();
		switch (option)
		{
			case 1:

				newSong = (Song*) calloc(1, sizeof(Song));

				cout << "Qual o nome da musica: ";
				cin.ignore();
				getline(cin>>ws, _name);
				newSong->name = _name;

				cout << "Qual o artista/banda: ";
				getline(cin>>ws, _artist);
				newSong->artist = _artist;

				cout << "Qual a duracao da musica (segundos): ";
				getline(cin>>ws, _duration);
				newSong->duration = _duration;

				InsertSong(newSong);

				persistList(newSong);

				break;
			case 2:
				ShowList();
				break;
			case 3:
				return 1;
			default:
				break;
		}
	}
	return 1;
}

int Menu(){

	int option;

	system("cls");

	printf("Por favor, faca sua opcao\n");
	printf("1- Inserir uma musica na playlist\n");
	printf("2- Mostrar a playlist\n");
	printf("3- Encerrar o programa\n");
	printf("Qual sua opcao: ");
	scanf("%d", &option);

	system("cls");

	return option;

}

void InsertSong(Song *newSong){
	if(Head == NULL){
		Head = newSong;
		End = newSong;
	}else{
		newSong->next = Head;
		Head->prev = newSong;
		Head = newSong;
	}
}

void ShowList(){

	if(Head == NULL){
		cout << "Não existe nenhum elemento na lista" << endl;
	}else{
		struct Song *actual;
		actual = (Song*) calloc(1, sizeof(Song));
		actual = Head;
		while(actual != NULL){
			cout << actual->name << endl;
			cout << actual->artist << endl;
			cout << actual->duration << endl;
			actual = actual->next;
		}
	}

	system("pause");
}

void chargeSongs(){
	struct Song *actual;
	string linha, auxWord="", auxList[3] = {"","",""};
	ifstream lista("list.txt");
	int k;

	if(!lista.is_open())
		cout << "Erro na leitura do arquivo";

	while (getline(lista,linha))
	{
		k=0;
		for(unsigned int i=0; i <= linha.length() ; i++){
			if(linha[i] != ','){
				if(linha[i]=='\0'){
					auxList[k] = auxWord;
					k++;
					auxWord="";
				}else{
					auxWord += linha[i];
				}
			}else{
				auxList[k] = auxWord;
				k++;
				auxWord="";
			}
		}

		actual = (Song*) calloc(1, sizeof(Song));
		
		cout<<auxList[0]<<endl;
		cout<<auxList[1]<<endl;
		cout<<auxList[2]<<endl;
		actual->name = auxList[0];
		actual->artist = auxList[1];
		actual->duration = auxList[2];

		system("pause");

		InsertSong(actual);

		auxList[0] ="";
		auxList[1] ="";
		auxList[2] ="";
	}
	lista.close();
}

void persistList(Song *newSong){
	ofstream out("list.txt", ios::app);
	string writeLine = "";
	if(newSong != NULL){
		writeLine = newSong->name + "," + newSong->artist + "," + newSong->duration + '\n';
		out << writeLine << endl;
		out.close();
	}else{
		cout<< "Erro ao salvar";
	}
}