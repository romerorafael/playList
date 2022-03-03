#include<stdio.h>
#include<stdlib.h>
#include <iostream>
#include <string>
using namespace std;

struct Song{
	string name;
	string artist;
	int duration;
	struct Song *next;
	struct Song *prev;
} *Head, *End;

int Menu();
void InsertSong(Song *newSong);
void ShowList();

int main(){
	struct Song *newSong;
	string _name, _artist;
	int option;

	Head = NULL;
	End = NULL;
	// chargePlayList();

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
				cin >> newSong->duration;

				InsertSong(newSong);
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
