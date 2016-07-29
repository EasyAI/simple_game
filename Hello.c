#include <iostream>
#include <string>

using namespace std;

void DrawMap(int HEIGHT, int WIDTH, int hIndex, int wIndex, int& playerY, int& playerX, int& itemY, int& itemX, int score){

cout << "\033[2J\033[1;1H";
//system("clear");

cout << "score: ";
cout << score << endl;

	for(int i = 1; i <= HEIGHT; i++){

		hIndex ++;

		for(int i = 1; i <= WIDTH; i++){
			wIndex ++;
			if (wIndex == 1 || wIndex == WIDTH || hIndex == 1 || hIndex == HEIGHT){
				cout << "\033[0;1;37m#";
			}
			else if (playerY == hIndex && playerX == wIndex){
				cout << "\033[0;1;36m@";
			}
			else if (itemY == hIndex && itemX == wIndex){
				cout << "\033[0;1;33;5m$";
			}
			else{
				cout << "\033[0m ";
			}
		}
		wIndex = 0;
		cout << endl;
	}
}

void print(string Text){
	cout << "\033[2J\033[1;1H";
	cout << "\033[0m";
	cout << Text << endl;
}

int main(){
	int HEIGHT = 8, WIDTH = 8;
	int hIndex = 0, wIndex = 0, playerY = HEIGHT /2, playerX = WIDTH /2, itemY = 0, itemX = 0, score = 0, itemCount = 1;
	char input = ' ';
	bool playing = true;

	string Text[] = {"W,A,S,D to move", "You win!"};

	print(Text[0]);

	while(playing){

		cin >> input;

		switch(input){
			case 'w':
				playerY --;
				break;
			case 'a':
				playerX --;
				break;
			case 's':
				playerY ++;
				break;
			case 'd':
				playerX ++;
				break;
			default:
				break;
		}

		if (playerY >= 8){
			playerY = 7;
		} else if (playerY <= 1){
			playerY = 2;
		}
		if (playerX >= 8){
			playerX = 7;
		} else if (playerX <= 1){
			playerX = 2;
		}

		switch(itemCount){
			case 1:
				itemY = 2;
				itemX = 7;
				break;
			case 2:
				itemY = 7;
				itemX = 2;
				break;
			case 3:
				itemY = 4;
				itemX = 7;
				break;
			case 4:
				itemCount = 1;
				break;
		}

		if(itemY == playerY && itemX == playerX){
			itemCount ++;
			score ++;
		}
		else if(score >= 5){
			playing = !playing;
		}

		DrawMap(HEIGHT, WIDTH, hIndex, wIndex, playerY, playerX, itemY, itemX, score);

	}
	print(Text[1]);
}
	/*
	 00 = normal white
	 30 = gray
	 31 = red
	 32 = green
	 33 = yellow
	 34 = blue
	 35 = purple
	 36 = cyan
	 37 = thick white
	*/
