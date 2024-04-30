#include<iostream>
#include<random>
#include<conio.h>
using namespace std;

bool setapple(char **field){
	
}
struct snakePart{
	int x,y;
	snakePart* next;
	snakePart* prev;
};

void printField(char** field, int fieldwidth, int fieldheight){
	for(int i=0;i<fieldheight;i++){
		for(int j=0;j<fieldwidth;j++){
			cout << field[i][j];
		}
		cout << endl;
	}
}
//опусташаем поле
void clearField(char** field, int fieldwidth, int fieldheight){
	for(int i=0;i<fieldheight;i++){
		for(int j=0;j<fieldwidth;j++){
			field[i][j]=' ';
		}
	}
}



int main(){
	int fieldwidth, fieldheight;
	do{
	system("cls");
	cout <<"Say width ";
	cin >> fieldwidth;
	cout<< "Say height ";
	cin >> fieldheight;
	}while((fieldwidth<2) || (fieldheight<2));	
	char ** field = new char*[fieldheight];
	//создаем поле
	for (int i=0; i<fieldheight;i++){
		field[i]=new char[fieldwidth];
	}
	
	clearField(field, fieldwidth, fieldheight);
	
	system("cls");
	//выводим поле
	for(int i=0;i<fieldheight;i++){
		for(int j=0;j<fieldwidth;j++){
			cout << field[i][j];
		}
		cout << endl;
	}
	//Инициализация змейки
	snakePart snake;
	snakePart* snakeHead = &snake;
	//Ставим голову змейки в случайное место
	snake.x=rand() % fieldwidth;
	snake.y=rand() % fieldheight;
	snake.next=NULL;
	snake.prev=NULL;
	
	bool alive = true;
	char symbol; //Считывание с клавиатуры символ
	int currentLength=0;
	
	while(alive){
		symbol=_getch();
		if(symbol=='w' || symbol=='W'){
			snake.y-=1;
			if (snake.y<0) snake.y=fieldheight -1;
		}
		if(symbol=='s' || symbol=='S'){
			snake.y=(snake.y + 1) % fieldheight;
		}
		if(symbol=='a' || symbol=='A'){
			snake.x-=1;
			if (snake.x<0) snake.x=fieldwidth -1;
		}
		if(symbol=='d' || symbol=='D'){
			snake.x=(snake.x + 1) % fieldwidth;
		}
		
		snakePart* snakeCurrent = snakeHead;
		
		currentLength = 0;
		clearField(field, fieldwidth, fieldheight);
		while(snakeCurrent!=NULL){
			
			if(currentLength==0)field[snakeCurrent->y][snakeCurrent->x]='O';
			else field[snakeCurrent->y][snakeCurrent->x]='@';
			currentLength++;
			snakeCurrent = snakeCurrent->next;
		}
		system("cls");
		printField(field, fieldwidth, fieldheight);
	}
	
	
	return 0;
}