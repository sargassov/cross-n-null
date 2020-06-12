#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>
using namespace std;

void myGame();

class Game {
public:
	short answer;

	short welcome(short& answer) {
		cout << "\n\t\t\tКРЕСТИКИ-НОЛИКИ v 1.1 UpGrade\n\n";
		answer = 0;

		choose(answer);

		isAnswerCorrect(answer);

		return answer;
	}
private:
	short isAnswerCorrect(short x) {
		if (x != 1 && x != 2)
			answerIncorrect(x);
		else
			return x;
	}


	short choose(short& answer) {
		cout << "\t\t\tПривет! Я хочу сыграть с тобой в игру!\n\n\t\t\tЧтобы научиться играть надо нажать: 1\n\n"
			"\t\t\tЧтобы пропустить этот этап и перейти сразу к игре надо нажать: 2\n\n";
		cin >> answer;
		return answer;
	}

	void answerIncorrect(short x) {
		cout << "\n\t\t\tТы вводишь что-то неправильно! Попробуй еще раз!\n\n";

		welcome(x);
	}


};

class XO : public Game {
public:
	char array[10][10];
	string move;
	char side, artificial, science = ' ';
	short count, complication, x = 0, y = 0;
	short marker = 0;
	void teachMeToPlay(short& marker) {

#define const1 array[x][y] == side
#define artificial_arguments array, side, move, artificial, science, complication, x, y, choise
#define reply_arguments char array[][10], char side, string& move, char& artificial, char science, short complication, short x, short y, short choise = 0
		
		cout << "Начнем с того, что вот так выглядит поле, на котором тебе надо сыграть.\n"
			"Размер 10 Х 10: \n";
		for (short x = 0; x < 21; x++) {
			cout << "\t\t\t";
			for (short y = 0; y < 21; y++) {
				if (x % 2 == 0 && y == 20)
					cout << "~";
				else if (x % 2 == 0)
					cout << "~~";
				else if (y % 2 == 0)
					cout << "| ";
				else if (y % 2 == 1)
					cout << "  ";
			}
			cout << "\n";
		}

		cout << "\nВсё как в шахматной доске! У нас есть буквы по горизонтали и цифры по вертикали\n\n";

		aboutBoard(marker);

		crossOrNull(marker);

		everythingIsSimple(marker);
	}

	void aboutBoard(short& marker) {
		cout << "\t\t\t";
		for (short x = 0; x < 22; x++) {
			for (short y = 0; y < 22; y++) {
				if (x == 0 && y % 2 == 0)
					cout << "  ";
				else if (marker == 1 && x == 4 && y == 4)
					cout << "X ";
				else if (marker == 2 && x == 4 && y != 0 && y % 2 == 0 && y < 11)
					cout << "X ";
				else if (marker == 3 && x != 0 && x % 2 == 0 && x < 11 && y == 4)
					cout << "X ";
				else if (marker == 4 && x != 0 && y != 0 && x == y && x % 2 == 0 && x < 11)
					cout << "X ";
				else if (x == 0 && y == 1)
					cout << "  A";
				else if (x == 0 && y == 3)
					cout << " B ";
				else if (x == 0 && y == 5)
					cout << "C ";
				else if (x == 0 && y == 7)
					cout << "D ";
				else if (x == 0 && y == 9)
					cout << "E ";
				else if (x == 0 && y == 11)
					cout << "F ";
				else if (x == 0 && y == 13)
					cout << "G ";
				else if (x == 0 && y == 15)
					cout << "H ";
				else if (x == 0 && y == 17)
					cout << "I ";
				else if (x == 0 && y == 19)
					cout << "J ";
				else if (x % 2 == 1 && y == 9)
					cout << "~";
				else if (x % 2 == 1)
					cout << "~~";
				else if (x == 20 && y == 0)
					cout << x / 2;
				else if (x % 2 == 0 && y == 0)
					cout << x / 2 << " ";
				else if (x == 0 && y == 9)
					cout << " ";
				else if (x == 0 && y == 21)
					cout << "  ";
				else if (x % 2 == 0 && y % 2 == 1)
					cout << "| ";
				else if (x != 0 && x % 2 == 0 && y != 0 && y % 2 == 0)
					cout << "  ";
			}
			cout << "\n\t\t\t";
		}
		marker++;
	}

	void crossOrNull(short& marker) {
		cout << "\nТы выбираешь на чьей стороне ты будешь играть! Ты за \"X\", или тебе ближе \"O\" \n"
			"Чтобы сделать очередной ход ты вводишь в консоль букву латиницей и цифру. Твой ход становится виден на консоли "
			"и дальше уже ходит твой соперник. Например, ты хочешь поставить крестик на поле B2. Вот так это будет выглядеть: \n\n";

		aboutBoard(marker);

	}
	void everythingIsSimple(short& marker) {
		cout << "\n\nКак ты можешь видеть все легко и просто.\nУсловия победы такие же: тебе нужно заполнить "
			"крестиками пять соседних клеток по горизонтали: \n\n";
		aboutBoard(marker);
		cout << "\n\nвертикали: \n\n";
		aboutBoard(marker);
		cout << "\n\nили диагонали: \n\n";
		aboutBoard(marker);
		cout << "\nКонечно, побеждает тот, кто раньше заполнит свою линию и не даст этого сопернику\n\n"
			"Вводить команды с клавиатуры возможно только с латинской раскладки. Подойдут как заглавные так и "
			"строчные буквы. Причем \"нолик\ можно вводить еще и цифрой. Вводить команды нужно ввиде \"B2\","
			"то есть сначала буква, потом цифра. Формат \"2B\" \nсистема посчитает как за ошибку\n\n";
		cout << "\n\n\t\t\tНУ ЧТО? СЫГРАЕМ? ;-) ";

	}

	void initialize(char array[][10]) {
		for (short x = 0; x < 10; x++) {
			for (short y = 0; y < 10; y++) {
				array[x][y] = ' ';
			}
		}
	}

	short isComplicationCorrect(char& side, char array[][10], char& artificial, char& science, short& complication) {
		if (complication != 1 && complication != 2 && complication != 3)
			badComplication(side, array, move, artificial, science, complication);
		else
			return complication;
	}

	short complicationz(char& side, char array[][10], char& artificial, char& science, short& complication) {
		cout << "\n\t\t\tBыбери сложность: \n\n\t\t\t1. \"Легко, как в бою!\"\n\n\t\t\t2. \"Тяжело, как в учении!\"\n\n";
			//"3. Нереально, как в кошмаре!\n\n";
		cin >> complication;
		isComplicationCorrect(side, array, artificial, science, complication);
		return complication;
	}

	char playTheGame(char& side, char array[][10], char& artificial) {

		cout << "\n\t\t\tВыбери на чьей ты стороне \"X\" vs. \"O\"\n\n";
		initialize(array);
		cin >> side;
		cout << "\n";
		isSideCorrect(side, artificial);
		return side, artificial;
	}

	char playTheGame(char& side, char array[][10], char& artificial, char& science) {
		cout << "\n\t\t\tНа этой сложности кроме привычных Крестиков и Ноликов на доске появится новый игрок\n";
		cout << "\n\t\t\tВыбери на чьей ты стороне \"X\" vs. \"O\" vs. \"@ # % ^ & * < > ?\"...";
		initialize(array);
		cin >> side;
		cout << "\n\n";
		isSideCorrect(side, artificial, science);
		return side, artificial, science;


	}

	char isSideCorrect(char& x, char& y) {
		if (x != 'X' && x != 'x' && x !='O' && x != 'o' && x != '0')
			bug(x);
		else
			if (x == 'X' || x == 'x')
				x = 'X', y = 'O';
			else if (x == 'O' || x == 'o' || x == '0')
				x = 'O', y = 'X';
			return x, y;

	}

	char chooseThird(char& z) {
		srand(time(NULL));
		short third = rand() % 5;
		if (third == 0) z = '@';
		else if (third == 1) z = '#';
		else if (third == 2) z = '%';
		else if (third == 3) z = '$';
		else if (third == 4) z = '&';
		cout << "\t\t\tТретий игрок: " << z<<"\n\n";
		return z;
	}

	char isSideCorrect(char& x, char& y, char& z) {
		if (x != '@' && x != '#' && x != '%' && x != '^' && x != '*' && x != '<' && x != '>' && x != '?' && x != 'X' &&
			x != 'x' && x != '0' && x != 'o' && x != 'O')
			bug(x, y, z);
		else
			if (x == 'X' || x == 'x') {
				x = 'X', y = 'O', chooseThird(z);
			}
			else if (x == 'O' || x == 'o' || x == '0')
				x = 'O', y = 'X', chooseThird(z);
			else
				y = 'X', z = 'O';
		return x, y;


	}

	/*void hardOrHeavy(short& complication) {
		cout << "Выбери сложность игры: \n\n1 - \"Легкая прогулка\"\n\n2 - \"Думать всё-таки придется\"\n\n"
			"3 - \"Полный отрыв\"!!!";
		cin >> complication;


	}*/



	void desk(char array[][10], char side, string& move, char& artificial,  char& science, short complication, short x, short y) {
		cout << "\t\t\t";
		for (short x = 0, a = 0, b = 0; x < 22; x++) {
			for (short y = 0; y < 22; y++) {
				if (x == 0 && y % 2 == 0)
					cout << "  ";
				else if (x == 0 && y == 1)
					cout << "  A";
				else if (x == 0 && y == 3)
					cout << " B ";
				else if (x == 0 && y == 5)
					cout << "C ";
				else if (x == 0 && y == 7)
					cout << "D ";
				else if (x == 0 && y == 9)
					cout << "E ";
				else if (x == 0 && y == 11)
					cout << "F ";
				else if (x == 0 && y == 13)
					cout << "G ";
				else if (x == 0 && y == 15)
					cout << "H ";
				else if (x == 0 && y == 17)
					cout << "I ";
				else if (x == 0 && y == 19)
					cout << "J ";
				else if (x % 2 == 1 && y == 21)
					cout << "~";
				else if (x % 2 == 1)
					cout << "~~";
				else if (x == 20 && y == 0)
					cout << x / 2;
				else if (x % 2 == 0 && y == 0)
					cout << x / 2 << " ";
				else if (x == 0 && y == 9)
					cout << " ";
				else if (x == 0 && y == 21)
					cout << "  ";
				else if (x % 2 == 0 && y % 2 == 1)
					cout << "| ";
				else if (x != 0 && x % 2 == 0 && y != 0 && y % 2 == 0)
					if (b < 10)
						cout << array[a][b]<<" ", b++;
					else
						b -= 10, a += 1, cout << array[a][b]<<" ", b++;
			}
			cout << "\n\t\t\t";
		}

		areYouWin(array, side, artificial, science, complication, x, y);

		yourMove(array, side, move, artificial, science, complication);
	}

	void yourMove(char array[][10], char side, string& move, char& artificial, char science, short complication) {
		char pre_move;
		short post_move, choise = 0;
		cout << "\n\t\t\tТвой ход: ";
		cin >> pre_move>>post_move;
		move = pre_move + post_move;


		isMoveCorrect(array, side, move, artificial, science, complication, pre_move, post_move);

		short x, y;
		enteredMove(array, side, move, artificial, science, pre_move, post_move, x, y, complication);

		if(complication == 1)
			intellect(array, side, move, artificial, science, x, y, choise = 0);
		else
			computerMove(array, side, move, artificial, science, x, y, complication);

		desk(array, side, move, artificial, science, complication, x, y);

	}



	void choiseReply(reply_arguments) {
		short count = 1, ride = 1;
		if (choise == 0 && array[x + 1][y + 1] == ' ' && x + 1 < 10 && y + 1 < 10)
			array[x + 1][y + 1] = artificial, x += 1, y += 1, decoder(x, y);
		else if (choise == 1 && array[x - 3][y - 3] == ' ' && (x - 3) > -1 && (y - 3) > -1)
			array[x - 3][y - 3] = artificial, x -= 3, y -= 3, decoder(x, y);
		else if (count != 0)
			count--, choiseReply(array, side, move, artificial, science, complication, x, y, choise +1);
		else if (count == 0)
			intellect(array, side, move, artificial, science, x, y, choise);
		if (complication == 3) {
			if (array[x - 3][y - 3] == ' ' && (x - 3) > -1 && (y - 3) > -1)
				array[x - 3][y - 3] = science, x -= 3, y -= 3, decoder(x, y);
			else
				intellect_2(array, side, move, artificial, science, x, y, choise, ride);

		}
	}

	void choiseReply_2(reply_arguments) {
		short count = 1, ride = 1;
		if (choise == 0 && array[x + 2][y + 2] == ' ' && x + 2 < 10 && y + 2 < 10)
			array[x + 2][y + 2] = artificial, x += 2, y += 2, decoder(x, y);
		else if (choise == 1 && array[x - 2][y - 2] == ' ' && x - 2 > -1 && y - 2 > -1)
			array[x - 2][y - 2] = artificial, x -= 2, y -= 2, decoder(x, y);
		else if (count != 0)
			count--, choiseReply_2(array, side, move, artificial, science, complication, x, y, choise + 1);
		else if (count == 0)
			intellect(array, side, move, artificial, science, x, y, choise);
		if (complication == 3) {
			if (array[x - 2][y - 2] == ' ' && x - 2 > -1 && y - 2 > -1)
				array[x - 2][y - 2] = science, x -= 2, y -= 2, decoder(x, y);
			else
				intellect_2(array, side, move, artificial, science, x, y, choise, ride);

		}
	
	}

	void choiseReply_3(reply_arguments) {
		short count = 1, ride = 1;
		if (choise == 0 && array[x + 3][y + 3] == ' ' && x + 3 < 10 && y + 3 < 10)
			array[x + 3][y + 3] = artificial, x += 3, y += 3, decoder(x, y);
		else if (choise == 1 && array[x - 1][y - 1] == ' ' && x - 1 > -1 && y - 1 > -1)
			array[x - 1][y - 1] = artificial, x -= 1, y -= 1, decoder(x, y);
		else if (count != 0)
			count--, choiseReply_3(array, side, move, artificial, science, complication, x, y, choise + 1);
		else if (count == 0)
			intellect(array, side, move, artificial, science, x, y, choise);
		if (complication == 3) {
			if (array[x - 1][y - 1] == ' ' && x - 1 > -1 && y - 1 > -1)
				array[x - 1][y - 1] = science, x -= 1, y -= 1, decoder(x, y);
			else
				intellect_2(array, side, move, artificial, science, x, y, choise, ride);
		}

	}

	void choiseReply_4(reply_arguments) {
		short count = 1, ride = 1;
		if (choise == 0 && array[x][y - 1] == ' ' && x - 1 > -1 && y - 1 > -1)
			array[x][y - 1] = artificial, y -= 1, decoder(x, y);
		else if (choise == 1 && array[x][y + 3] == ' ' && y + 3 < 10)
			array[x][y + 3] = artificial, y += 3, decoder(x, y);
		else if (count != 0)
			count--, choiseReply_4(array, side, move, artificial, science, complication, x, y, choise + 1);
		else if (count == 0)
			intellect(array, side, move, artificial, science, x, y, choise);
		if (complication == 3) {
			if (array[x][y + 3] == ' ' && y + 3 < 10)
				array[x][y + 3] = science, y += 3, decoder(x, y);
			else
				intellect_2(array, side, move, artificial, science, x, y, choise, ride);
		}

	}

	void choiseReply_5(reply_arguments) {
		short count = 1, ride = 1;
		if (choise == 0 && array[x][y - 2] == ' ' && y - 2 > -1)
			array[x][y - 1] = artificial, y -= 1, decoder(x, y);
		else if (choise == 1 && array[x][y + 2] == ' ' && y + 2 < 10)
			array[x][y + 2] = artificial, y += 2, decoder(x, y);
		else if (count != 0)
			count--, choiseReply_5(array, side, move, artificial, science, complication, x, y, choise + 1);
		else if (count == 0)
			intellect(array, side, move, artificial, science, x, y, choise);
		if (complication == 3) {
			if (array[x][y + 2] == ' ' && y + 2 < 10)
				array[x][y + 2] = science, y += 2, decoder(x, y);
			else
				intellect_2(array, side, move, artificial, science, x, y, choise, ride);
		}

	}

	void choiseReply_6(reply_arguments) {
		short count = 1, ride = 1;
		if (choise == 0 && array[x][y - 3] == ' ' && y - 3 > -1)
			array[x][y - 3] = artificial, y -= 3, decoder(x, y);
		else if (choise == 1 && array[x][y + 1] == ' ' && y + 1 < 10)
			array[x][y + 1] = artificial, y += 1, decoder(x, y);
		else if (count != 0)
			count--, choiseReply_6(array, side, move, artificial, science, complication, x, y, choise + 1);
		else if (count == 0)
			intellect(array, side, move, artificial, science, x, y, choise);
		if (complication == 3) {
			if (array[x][y + 1] == ' ' && y + 1 < 10)
				array[x][y + 1] = science, y += 1, decoder(x, y);
			else
				intellect_2(array, side, move, artificial, science, x, y, choise, ride);

		}

	}


	void choiseReply_7(reply_arguments) {
		short count = 1, ride = 1;
		if (choise == 0 && array[x + 3][y] == ' ' && x + 3 < 10)
			array[x + 3][y] = artificial, x += 3, decoder(x, y);
		else if (choise == 1 && array[x - 1][y] == ' ' && x - 1 > -1)
			array[x - 1][y] = artificial, x -= 1, decoder(x, y);
		else if (count != 0)
			count--, choiseReply_7(array, side, move, artificial, science, complication, x, y, choise + 1);
		else if (count == 0)
			intellect(array, side, move, artificial, science, x, y, choise);
		if (complication == 3) {
			if (array[x - 1][y] == ' ' && x - 1 > -1)
				array[x - 1][y] = science, x -= 1, decoder(x, y);
			else
				intellect_2(array, side, move, artificial, science, x, y, choise, ride);
		}
	}

	void choiseReply_8(reply_arguments) {
		short count = 1, ride = 1;
		if (choise == 0 && array[x + 2][y] == ' ' && x + 2 < 10)
			array[x + 2][y] = artificial, x += 2, decoder(x, y);
		else if (choise == 1 && array[x - 2][y] == ' ' && x - 2 > -1)
			array[x - 2][y] = artificial, x -= 2, decoder(x, y);
		else if (count != 0)
			count--, choiseReply_8(array, side, move, artificial, science, complication, x, y, choise + 1);
		else if (count == 0)
			intellect(array, side, move, artificial, science, x, y, choise);
		if (complication == 3) {
			if (array[x - 2][y] == ' ' && x - 2 > -1)
				array[x - 2][y] = science, x -= 2, decoder(x, y);
			else
				intellect_2(array, side, move, artificial, science, x, y, choise, ride);
		}
	}

	void choiseReply_9(reply_arguments) {
		short count = 1, ride = 1;
		if (choise == 0 && array[x - 3][y] == ' ' && x - 3 > -1)
			array[x - 3][y] = artificial, x -= 3, decoder(x, y);
		else if (choise == 1 && array[x + 1][y] == ' ' && x + 1 < 10)
			array[x + 1][y] = artificial, x += 1, decoder(x, y);
		else if (count != 0)
			count--, choiseReply_9(array, side, move, artificial, science, complication, x, y, choise + 1);
		else if (count == 0)
			intellect(array, side, move, artificial, science, x, y, choise);
		if (complication == 3) {
			if (array[x + 1][y] == ' ' && x + 1 < 10)
				array[x + 1][y] = science, x += 1, decoder(x, y);
			else
				intellect_2(array, side, move, artificial, science, x, y, choise, ride);
		}

	}

	void choiseReply_10(reply_arguments) {
		short count = 1, ride = 1;
		if (choise == 0 && array[x - 3][y + 3] == ' ' && x - 3 > -1 && y + 3 < 10)
			array[x - 3][y + 3] = artificial, x -= 3, y += 3, decoder(x, y);
		else if (choise == 1 && array[x + 1][y - 1] == ' ' && x + 1 < 10 && y - 1 > -1)
			array[x + 1][y - 1] = artificial, x += 1, y -= 1, decoder(x, y);
		else if (count != 0)
			count--, choiseReply_10(array, side, move, artificial, science, complication, x, y, choise + 1);
		else if (count == 0)
			intellect(array, side, move, artificial, science, x, y, choise);
		if (complication == 3) {
			if (array[x + 1][y - 1] == ' ' && x + 1 < 10 && y - 1 > -1)
				array[x + 1][y - 1] = science, x += 1, y -= 1, decoder(x, y);
			else
				intellect_2(array, side, move, artificial, science, x, y, choise, ride);
		}
	}

	void choiseReply_11(reply_arguments) {
		short count = 1, ride = 1;
		if (choise == 0 && array[x - 2][y + 2] == ' ' && x - 2 > -1 && y + 2 < 10)
			array[x - 2][y + 2] = artificial, x -= 2, y += 2, decoder(x, y);
		else if (choise == 1 && array[x + 2][y - 2] == ' ' && x + 2 < 10 && y - 2 > -1)
			array[x + 2][y - 2] = artificial, x += 2, y -= 2, decoder(x, y);
		else if (count != 0)
			count--, choiseReply_11(array, side, move, artificial, science, complication, x, y, choise + 1);
		else if (count == 0)
			intellect(array, side, move, artificial, science, x, y, choise);
		if (complication == 3) {
			if (array[x + 2][y - 2] == ' ' && x + 2 < 10 && y - 2 > -1)
				array[x + 2][y - 2] = science, x += 2, y -= 2, decoder(x, y);
			else
				intellect_2(array, side, move, artificial, science, x, y, choise, ride);
		}

	}

	void choiseReply_12(reply_arguments) {
		short count = 1, ride = 1;
		if (choise == 0 && array[x + 3][y - 3] == ' ' && x + 3 < 10 && y - 3 > -1)
			array[x + 3][y - 3] = artificial, x += 3, y -= 3, decoder(x, y);
		else if (choise == 1 && array[x - 1][y + 1] == ' ' && x - 1 > -1 && y + 1 < 10)
			array[x - 1][y + 1] = artificial, x -= 1, y += 1, decoder(x, y);
		else if (count != 0)
			count--, choiseReply_12(array, side, move, artificial, science, complication, x, y, choise + 1);
		else if (count == 0)
			intellect(array, side, move, artificial, science, x, y, choise);
		if (complication == 3) {
			if (array[x - 1][y + 1] == ' ' && x - 1 > -1 && y + 1 < 10)
				array[x - 1][y + 1] = science, x -= 1, y += 1, decoder(x, y);
			else
				intellect_2(array, side, move, artificial, science, x, y, choise, ride);
		}
	}

	void choiseReply_13(reply_arguments) {
		short count = 1, ride = 1;
		if (choise == 0 && array[x - 2][y] == ' ' && x - 2 > -1)
			array[x - 2][y] = artificial, x -= 2, decoder(x, y);
		else if (choise == 1 && array[x + 1][y] == ' ' && x + 1 < 10)
			array[x + 1][y] = artificial, x += 1, decoder(x, y);
		else if(count != 0)
			count --, choiseReply_13(array, side, move, artificial, science, complication, x, y, choise + 1);
		else if(count == 0)
			intellect(array, side, move, artificial, science, x, y, choise);
		if (complication == 3) {
			if (array[x + 1][y] == ' ' && x + 1 < 10)
				array[x + 1][y] = science, x += 1, decoder(x, y);
			else
				intellect_2(array, side, move, artificial, science, x, y, choise, ride);
		}
	}


	void choiseReply_14(reply_arguments) {
		short count = 1, ride = 1;
		if (choise == 0 && array[x + 2][y] == ' ' && x + 2 < 10)
			array[x + 2][y] = artificial, x += 2, decoder(x, y);
		else if (choise == 1 && array[x - 1][y] == ' ' && x - 1 > -1)
			array[x - 1][y] = artificial, x -= 1, decoder(x, y);
		else if (count != 0)
			count--, choiseReply_14(array, side, move, artificial, science, complication, x, y, choise + 1);
		else if (count == 0)
			intellect(array, side, move, artificial, science, x, y, choise);
		if (complication == 3) {
			if (array[x - 1][y] == ' ' && x - 1 > -1)
				array[x - 1][y] = science, x -= 1, decoder(x, y);
			else
				intellect_2(array, side, move, artificial, science, x, y, choise, ride);
		}
	}

	void choiseReply_15(reply_arguments) {
		short count = 1, ride = 1;
		if (choise == 0 && array[x][y - 1] == ' ' && y - 1 > -1)
			array[x][y - 1] = artificial, y -= 1, decoder(x, y);
		else if (choise == 1 && array[x][y + 2] == ' ' && y + 2 < 10)
			array[x][y + 2] = artificial, y += 2, decoder(x, y);
		else if (count != 0)
			count--, choiseReply_15(array, side, move, artificial, science, complication, x, y, choise + 1);
		else if (count == 0)
			intellect(array, side, move, artificial, science, x, y, choise);
		if (complication == 3) {
			if (array[x][y + 2] == ' ' && y + 2 < 10)
				array[x][y + 2] = science, y += 2, decoder(x, y);
			else
				intellect_2(array, side, move, artificial, science, x, y, choise, ride);
		}

	}

	void choiseReply_16(reply_arguments) {
		short count = 1, ride = 1;
		if (choise == 0 && array[x][y - 2] == ' ' && y - 2 > -1)
			array[x][y - 2] = artificial, y -= 2, decoder(x, y);
		else if (choise == 1 && array[x][y + 1] == ' ' && y + 1 < 10)
			array[x][y + 1] = artificial, y += 1, decoder(x, y);
		else if (count != 0)
			count--, choiseReply_16(array, side, move, artificial, science, complication, x, y, choise + 1);
		else if (count == 0)
			intellect(array, side, move, artificial, science, x, y, choise);
		if (complication == 3) {
			if (array[x][y + 1] == ' ' && y + 1 < 10)
				array[x][y + 1] = science, y += 1, decoder(x, y);
			else
				intellect_2(array, side, move, artificial, science, x, y, choise, ride);
		}

	}

	void choiseReply_17(reply_arguments) {
		short count = 1, ride = 1;
		if (choise == 0 && array[x - 1][y - 1] == ' ' && y - 1 > -1 && x - 1 > -1)
			array[x - 1][y - 1] = artificial, x -= 1, y -= 1, decoder(x, y);
		else if (choise == 1 && array[x + 2][y + 2] == ' ' && y + 2 < 10 && x + 2 < 10)
			array[x + 2][y + 2] = artificial, x += 2, y += 2, decoder(x, y);
		else if (count != 0)
			count--, choiseReply_17(array, side, move, artificial, science, complication, x, y, choise + 1);
		else if (count == 0)
			intellect(array, side, move, artificial, science, x, y, choise);
		if (complication == 3) {
			if (array[x + 2][y + 2] == ' ' && y + 2 < 10 && x + 2 < 10)
				array[x + 2][y + 2] = science, x += 2, y += 2, decoder(x, y);
			else
				intellect_2(array, side, move, artificial, science, x, y, choise, ride);
		}
	}

	void choiseReply_18(reply_arguments) {
		short count = 1, ride = 1;
		if (choise == 0 && array[x - 2][y - 2] == ' ' && y - 2 > -1 && x - 2 > -1)
			array[x - 2][y - 2] = artificial, x -=2, y -= 2, decoder(x, y);
		else if (choise == 1 && array[x + 1][y + 1] == ' ' && y + 1 < 10 && x + 1 < 10)
			array[x + 1][y + 1] = artificial, x += 1, y += 1, decoder(x, y);
		else if (count != 0)
			count--, choiseReply_18(array, side, move, artificial, science, complication, x, y, choise + 1);
		else if (count == 0)
			intellect(array, side, move, artificial, science, x, y, choise);
		if (complication == 3) {
			if (array[x + 1][y + 1] == ' ' && y + 1 < 10 && x + 1 < 10)
				array[x + 1][y + 1] = science, x += 1, y += 1, decoder(x, y);
			else
				intellect_2(array, side, move, artificial, science, x, y, choise, ride);
		}

	}

	void choiseReply_19(reply_arguments) {
		short count = 1, ride = 1;
		if (choise == 0 && array[x - 2][y + 2] == ' ' && x - 2 > -1 && y + 2 < 10)
			array[x - 2][y + 2] = artificial, x -= 2, y += 2, decoder(x, y);
		else if (choise == 1 && array[x + 1][y - 1] == ' ' && y - 1 > -1 && x + 1 < 10)
			array[x + 1][y - 1] = artificial, x += 1, y -= 1, decoder(x, y);
		else if (count != 0)
			count--, choiseReply_19(array, side, move, artificial, science, complication, x, y, choise + 1);
		else if (count == 0)
			intellect(array, side, move, artificial, science, x, y, choise);
		if (complication == 3) {
			if (array[x + 1][y - 1] == ' ' && y - 1 > -1 && x + 1 < 10)
				array[x + 1][y - 1] = science, x += 1, y -= 1, decoder(x, y);
			else
				intellect_2(array, side, move, artificial, science, x, y, choise, ride);
		}

	}

	void choiseReply_20(reply_arguments) {
		short count = 1, ride = 1;
		if (choise == 0 && array[x + 2][y - 2] == ' ' && y - 2 > -1 && x + 2 < 10)
			array[x + 2][y - 2] = artificial, x += 2, y -= 2, decoder(x, y);
		else if (choise == 1 && array[x - 1][y + 1] == ' ' && x - 1 > -1 && y + 1 < 10)
			array[x - 1][y + 1] = artificial, x -= 1, y += 1, decoder(x, y);
		else if (count != 0)
			count--, choiseReply_20(array, side, move, artificial, science, complication, x, y, choise + 1);
		else if (count == 0)
			intellect(array, side, move, artificial, science, x, y, choise);
		if (complication == 3) {
			if (array[x - 1][y + 1] == ' ' && x - 1 > -1 && y + 1 < 10)
				array[x - 1][y + 1] = science, x -= 1, y += 1, decoder(x, y);
			else
				intellect_2(array, side, move, artificial, science, x, y, choise, ride);
		}
	}

	void choiseReply_21(reply_arguments) {
		short count = 7, ride = 1;
		if (choise == 0 && array[x + 1][y] == ' ' && x + 1 < 10)
			array[x + 1][y] = artificial, x += 1, decoder(x, y);
		else if (choise == 1 && array[x - 1][y] == ' ' && x - 1 > -1)
			array[x - 1][y] = artificial, x -= 1, decoder(x, y);
		else if (choise == 2 && array[x][y + 1] == ' ' && y + 1 < 10)
			array[x][y + 1] = artificial, y += 1, decoder(x, y);
		else if (choise == 3 && array[x][y - 1] == ' ' && y - 1 > -1)
			array[x][y - 1] = artificial, y -= 1, decoder(x, y);
		else if (choise == 4 && array[x + 1][y + 1] == ' ' && y + 1 < 10 && x + 1 < 10)
			array[x + 1][y + 1] = artificial, y += 1, x += 1, decoder(x, y);
		else if (choise == 5 && array[x - 1][y - 1] == ' ' && y - 1 > -1 && x - 1 > -1)
			array[x + 1][y + 1] = artificial, y -= 1, x -= 1, decoder(x, y);
		else if (choise == 6 && array[x + 1][y - 1] == ' ' && y - 1 > -1 && x + 1 < 10)
			array[x + 1][y - 1] = artificial, y -= 1, x += 1, decoder(x, y);
		else if (choise == 7 && array[x - 1][y + 1] == ' ' && y + 1 < 10 && x - 1 > -1)
			array[x - 1][y + 1] = artificial, y += 1, x -= 1, decoder(x, y);
		else if (count != 0)
			count--, choiseReply_21(array, side, move, artificial, science, x, y, complication, choise + 1);
		else if (count == 0)
			intellect(array, side, move, artificial, science, x, y, choise);
		if (complication == 3) {
			intellect_2(array, side, move, artificial, science, x, y, choise, ride);
		}
	}

	void choiseReply_22(reply_arguments) {
		short count = 1, ride = 1;
		if (choise == 0 && array[x - 4][y - 4] == ' ' && y - 4 > -1 && x - 4 > -1)
			array[x - 4][y - 4] = artificial, x -= 4, y -= 4, decoder(x, y);
		else if (choise == 1 && array[x + 1][y + 1] == ' ' && x + 1 < 10 && y + 1 < 10)
			array[x + 1][y + 1] = artificial, x += 1, y += 1, decoder(x, y);
		else if (count != 0)
			count--, choiseReply_22(array, side, move, artificial, science, complication, x, y, choise + 1);
		else if (count == 0)
			intellect(array, side, move, artificial, science, x, y, choise);
		if (complication == 3) {
			if (array[x + 1][y + 1] == ' ' && x + 1 < 10 && y + 1 < 10)
				array[x + 1][y + 1] = science, x += 1, y += 1, decoder(x, y);
			else
				intellect_2(array, side, move, artificial, science, x, y, choise, ride);
		}
	}

	void choiseReply_23(reply_arguments) {
		short count = 1, ride = 1;
		if (choise == 0 && array[x + 2][y + 2] == ' ' && y + 2 < 10 && x + 2 < 10)
			array[x + 2][y + 2] = artificial, x += 2, y += 2, decoder(x, y);
		else if (choise == 1 && array[x - 3][y - 3] == ' ' && x - 3 > -1 && y - 3 > -1)
			array[x - 3][y - 3] = artificial, x -= 3, y -= 3, decoder(x, y);
		else if (count != 0)
			count--, choiseReply_23(array, side, move, artificial, science, complication, x, y, choise + 1);
		else if (count == 0)
			intellect(array, side, move, artificial, science, x, y, choise);
		if (complication == 3) {
			if (array[x - 3][y - 3] == ' ' && x - 3 > -1 && y - 3 > -1)
				array[x - 3][y - 3] = science, x -= 3, y -= 3, decoder(x, y);
			else
				intellect_2(array, side, move, artificial, science, x, y, choise, ride);
		}
	}

	void choiseReply_24(reply_arguments) {
		short count = 1, ride = 1;
		if (choise == 0 && array[x - 2][y - 2] == ' ' && y - 2 > -1 && x - 2 > -1)
			array[x - 2][y - 2] = artificial, x -= 2, y -= 2, decoder(x, y);
		else if (choise == 1 && array[x + 3][y + 3] == ' ' && x + 3 < 10 && y + 3 < 10)
			array[x + 3][y + 3] = artificial, x += 3, y += 3, decoder(x, y);
		else if (count != 0)
			count--, choiseReply_24(array, side, move, artificial, science, complication, x, y, choise + 1);
		else if (count == 0)
			intellect(array, side, move, artificial, science, x, y, choise);
		if (complication == 3) {
			if (array[x + 3][y + 3] == ' ' && x + 3 < 10 && y + 3 < 10)
				array[x + 3][y + 3] = science, x += 3, y += 3, decoder(x, y);
			else
				intellect_2(array, side, move, artificial, science, x, y, choise, ride);
		}
	}

	void choiseReply_25(reply_arguments) {
		short count = 1, ride = 1;
		if (choise == 0 && array[x - 1][y - 1] == ' ' && y - 1 > -1 && x - 1 > -1)
			array[x - 1][y - 1] = artificial, x -= 1, y -= 1, decoder(x, y);
		else if (choise == 1 && array[x + 4][y + 4] == ' ' && x + 4 < 10 && y + 4 < 10)
			array[x + 4][y + 4] = artificial, x += 4, y += 4, decoder(x, y);
		else if (count != 0)
			count--, choiseReply_25(array, side, move, artificial, science, complication, x, y, choise + 1);
		else if (count == 0)
			intellect(array, side, move, artificial, science, x, y, choise);
		if (complication == 3) {
			if (array[x + 4][y + 4] == ' ' && x + 4 < 10 && y + 4 < 10)
				array[x + 4][y + 4] = science, x += 4, y += 4, decoder(x, y);
			else
				intellect_2(array, side, move, artificial, science, x, y, choise, ride);
		}
	}

	void choiseReply_26(reply_arguments) {
		short count = 1, ride = 1;
		if (choise == 0 && array[x + 1][y - 1] == ' ' && y - 1 > -1 && x + 1 < 10)
			array[x + 1][y - 1] = artificial, x += 1, y -= 1, decoder(x, y);
		else if (choise == 1 && array[x - 4][y + 4] == ' ' && x - 4 > -1 && y + 4 < 10)
			array[x - 4][y + 4] = artificial, x -= 4, y += 4, decoder(x, y);
		else if (count != 0)
			count--, choiseReply_26(array, side, move, artificial, science, complication, x, y, choise + 1);
		else if (count == 0)
			intellect(array, side, move, artificial, science, x, y, choise);
		if (complication == 3) {
			if (array[x - 4][y + 4] == ' ' && x - 4 > -1 && y + 4 < 10)
				array[x - 4][y + 4] = science, x -= 4, y += 4, decoder(x, y);
			else
				intellect_2(array, side, move, artificial, science, x, y, choise, ride);
		}
	}

	void choiseReply_27(reply_arguments) {
		short count = 1, ride = 1;
		if (choise == 0 && array[x + 2][y - 2] == ' ' && y - 2 > -1 && x + 2 < 10)
			array[x + 2][y - 2] = artificial, x += 2, y -= 2, decoder(x, y);
		else if (choise == 1 && array[x - 3][y + 3] == ' ' && x - 3 > -1 && y + 3 < 10)
			array[x - 3][y + 3] = artificial, x -= 3, y += 3, decoder(x, y);
		else if (count != 0)
			count--, choiseReply_27(array, side, move, artificial, science, complication, x, y, choise + 1);
		else if (count == 0)
			intellect(array, side, move, artificial, science, x, y, choise);
		if (complication == 3) {
			if (array[x - 3][y + 3] == ' ' && x - 3 > -1 && y + 3 < 10)
				array[x - 3][y + 3] = science, x -= 3, y += 3, decoder(x, y);
			else
				intellect_2(array, side, move, artificial, science, x, y, choise, ride);
		}
	}

	void choiseReply_28(reply_arguments) {
		short count = 1, ride = 1;
		if (choise == 0 && array[x + 3][y - 3] == ' ' && y - 3 > -1 && x + 3 < 10)
			array[x + 3][y - 3] = artificial, x += 3, y -= 3, decoder(x, y);
		else if (choise == 1 && array[x - 2][y + 2] == ' ' && x - 2 > -1 && y + 2 < 10)
			array[x - 2][y + 2] = artificial, x -= 2, y += 2, decoder(x, y);
		else if (count != 0)
			count--, choiseReply_28(array, side, move, artificial, science, complication, x, y, choise + 1);
		else if (count == 0)
			intellect(array, side, move, artificial, science, x, y, choise);
		if (complication == 3) {
			if (array[x - 2][y + 2] == ' ' && x - 2 > -1 && y + 2 < 10)
				array[x - 2][y + 2] = science, x -= 2, y += 2, decoder(x, y);
			else
				intellect_2(array, side, move, artificial, science, x, y, choise, ride);
		}
	}

	void choiseReply_29(reply_arguments) {
		short count = 1, ride = 1;
		if (choise == 0 && array[x + 4][y - 4] == ' ' && y - 4 > -1 && x + 4 < 10)
			array[x + 4][y - 4] = artificial, x += 4, y -= 4, decoder(x, y);
		else if (choise == 1 && array[x - 1][y + 1] == ' ' && x - 1 > -1 && y + 1 < 10)
			array[x - 1][y + 1] = artificial, x -= 1, y += 1, decoder(x, y);
		else if (count != 0)
			count--, choiseReply_29(array, side, move, artificial, science, complication, x, y, choise + 1);
		else if (count == 0)
			intellect(array, side, move, artificial, science, x, y, choise);
		if (complication == 3) {
			if (array[x - 1][y + 1] == ' ' && x - 1 > -1 && y + 1 < 10)
				array[x - 1][y + 1] = science, x -= 1, y += 1, decoder(x, y);
			else
				intellect_2(array, side, move, artificial, science, x, y, choise, ride);
		}
	}

	void choiseReply_30(reply_arguments) {
		short count = 1, ride = 1;
		if (choise == 0 && array[x][y - 4] == ' ' && y - 4 > -1)
			array[x][y - 4] = artificial, y -= 4, decoder(x, y);
		else if (choise == 1 && array[x][y + 1] == ' ' && y + 1 < 10)
			array[x][y + 1] = artificial, y += 1, decoder(x, y);
		else if (count != 0)
			count--, choiseReply_30(array, side, move, artificial, science, complication, x, y, choise + 1);
		else if (count == 0)
			intellect(array, side, move, artificial, science, x, y, choise);
		if (complication == 3) {
			if (array[x][y + 1] == ' ' && y + 1 < 10)
				array[x][y + 1] = science, y += 1, decoder(x, y);
			else
				intellect_2(array, side, move, artificial, science, x, y, choise, ride);
		}
	}

	void choiseReply_31(reply_arguments) {
		short count = 1, ride = 1;
		if (choise == 0 && array[x][y - 3] == ' ' && y - 3 > -1)
			array[x][y - 3] = artificial, y -= 3, decoder(x, y);
		else if (choise == 1 && array[x][y + 2] == ' ' && y + 2 < 10)
			array[x][y + 2] = artificial, y += 2, decoder(x, y);
		else if (count != 0)
			count--, choiseReply_31(array, side, move, artificial, science, complication, x, y, choise + 1);
		else if (count == 0)
			intellect(array, side, move, artificial, science, x, y, choise);
		if (complication == 3) {
			if (array[x][y + 2] == ' ' && y + 2 < 10)
				array[x][y + 2] = science, y += 2, decoder(x, y);
			else
				intellect_2(array, side, move, artificial, science, x, y, choise, ride);
		}
	}

	void choiseReply_32(reply_arguments) {
		short count = 1, ride = 1;
		if (choise == 0 && array[x][y - 2] == ' ' && y - 2 > -1)
			array[x][y - 2] = artificial, y -= 2, decoder(x, y);
		else if (choise == 1 && array[x][y + 3] == ' ' && y + 3 < 10)
			array[x][y + 3] = artificial, y += 3, decoder(x, y);
		else if (count != 0)
			count--, choiseReply_32(array, side, move, artificial, science, complication, x, y, choise + 1);
		else if (count == 0)
			intellect(array, side, move, artificial, science, x, y, choise);
		if (complication == 3) {
			if (array[x][y + 3] == ' ' && y + 3 < 10)
				array[x][y + 3] = science, y += 3, decoder(x, y);
			else
				intellect_2(array, side, move, artificial, science, x, y, choise, ride);
		}
	}

	void choiseReply_33(reply_arguments) {
		short count = 1, ride = 1;
		if (choise == 0 && array[x][y - 1] == ' ' && y - 1 > -1)
			array[x][y - 1] = artificial, y -= 1, decoder(x, y);
		else if (choise == 1 && array[x][y + 4] == ' ' && y + 4 < 10)
			array[x][y + 4] = artificial, y += 4, decoder(x, y);
		else if (count != 0)
			count--, choiseReply_33(array, side, move, artificial, science, complication, x, y, choise + 1);
		else if (count == 0)
			intellect(array, side, move, artificial, science, x, y, choise);
		if (complication == 3) {
			if (array[x][y + 4] == ' ' && y + 4 < 10)
				array[x][y + 4] = science, y += 4, decoder(x, y);
			else
				intellect_2(array, side, move, artificial, science, x, y, choise, ride);
		}
	}

	void choiseReply_34(reply_arguments) {
		short count = 1, ride = 1;
		if (choise == 0 && array[x + 4][y] == ' ' && x + 4 < 10)
			array[x + 4][y] = artificial, x += 4, decoder(x, y);
		else if (choise == 1 && array[x - 1][y] == ' ' && x - 1 > -1)
			array[x - 1][y] = artificial, x -= 1, decoder(x, y);
		else if (count != 0)
			count--, choiseReply_34(array, side, move, artificial, science, complication, x, y, choise + 1);
		else if (count == 0)
			intellect(array, side, move, artificial, science, x, y, choise);
		if (complication == 3) {
			if (array[x - 1][y] == ' ' && x - 1 > -1)
				array[x - 1][y] = science, x -= 1, decoder(x, y);
			else
				intellect_2(array, side, move, artificial, science, x, y, choise, ride);
		}
	}

	void choiseReply_35(reply_arguments) {
		short count = 1, ride = 1;
		if (choise == 0 && array[x + 3][y] == ' ' && x + 3 < 10)
			array[x + 3][y] = artificial, x += 3, decoder(x, y);
		else if (choise == 1 && array[x - 2][y] == ' ' && x - 2 > -1)
			array[x - 2][y] = artificial, x -= 2, decoder(x, y);
		else if (count != 0)
			count--, choiseReply_35(array, side, move, artificial, science, complication, x, y, choise + 1);
		else if (count == 0)
			intellect(array, side, move, artificial, science, x, y, choise);
		if (complication == 3) {
			if (array[x - 2][y] == ' ' && x - 2 > -1)
				array[x - 2][y] = science, x -= 2, decoder(x, y);
			else
				intellect_2(array, side, move, artificial, science, x, y, choise, ride);
		}
	}

	void choiseReply_36(reply_arguments) {
		short count = 1, ride = 1;
		if (choise == 0 && array[x + 2][y] == ' ' && x + 2 < 10)
			array[x + 2][y] = artificial, x += 2, decoder(x, y);
		else if (choise == 1 && array[x - 3][y] == ' ' && x - 3 > -1)
			array[x - 3][y] = artificial, x -= 3, decoder(x, y);
		else if (count != 0)
			count--, choiseReply_36(array, side, move, artificial, science, complication, x, y, choise + 1);
		else if (count == 0)
			intellect(array, side, move, artificial, science, x, y, choise);
		if (complication == 3) {
			if (array[x - 3][y] == ' ' && x - 3 > -1)
				array[x - 3][y] = science, x -= 3, decoder(x, y);
			else
				intellect_2(array, side, move, artificial, science, x, y, choise, ride);
		}
	}


	void choiseReply_37(reply_arguments) {
		short count = 1, ride = 1;
		if (choise == 0 && array[x + 1][y] == ' ' && x + 1 < 10)
			array[x + 1][y] = artificial, x += 1, decoder(x, y);
		else if (choise == 1 && array[x - 4][y] == ' ' && x - 4 > -1)
			array[x - 4][y] = artificial, x -= 4, decoder(x, y);
		else if (count != 0)
			count--, choiseReply_37(array, side, move, artificial, science, complication, x, y, choise + 1);
		else if (count == 0)
			intellect(array, side, move, artificial, science, x, y, choise);
		if (complication == 3) {
			if (array[x - 4][y] == ' ' && x - 4 > -1)
				array[x - 4][y] = science, x -= 4, decoder(x, y);
			else
				intellect_2(array, side, move, artificial, science, x, y, choise, ride);
		}
	}

	void intellect(char array[][10], char side, string move, char artificial, char science, short x,
		short y, short choise) {
		short a, b;
		srand(time(NULL));
		a = rand() % 10, b = rand() % 10;
		if (array[a][b] == ' ') {
			array[a][b] = artificial; 
			decoder(a, b);
		}
		else
			intellect(array, side, move, artificial, science, x, y, choise);
		
	}

	void intellect_2(char array[][10], char side, string move, char artificial, char science, short x,
		short y, short choise, short ride) {
		short a, b, check = 1, point = 1;
		srand(time(NULL));
		a = rand() % 10, b = rand() % 10;
		if (array[a][b] == ' ') {
			array[a][b] = science;
			decoder(a, b);
		}
		else
			intellect_2(array, side, move, artificial, science, x, y, choise, ride);
		
		

	}


	void computerMove(char array[][10], char side, string& move, char& artificial, char science, short x, short y,
		short complication) {
		short choise = 0;

		if (const1 && array[x - 1][y - 1] == side && array[x - 2][y - 2] == side && array[x - 3][y - 3] == side)
			choiseReply_22(artificial_arguments);

		else if (const1 && array[x + 1][y + 1] == side && array[x - 1][y - 1] == side && array[x - 2][y - 2] == side)
			choiseReply_23(artificial_arguments);

		else if (const1 && array[x + 2][y + 2] == side && array[x + 1][y + 1] == side && array[x - 1][y - 1] == side)
			choiseReply_24(artificial_arguments);

		else if (const1 && array[x + 3][y + 3] == side && array[x + 2][y + 2] == side && array[x + 1][y + 1] == side)
			choiseReply_25(artificial_arguments);

		else if (const1 && array[x - 1][y + 1] == side && array[x - 2][y + 2] == side && array[x - 3][y + 3] == side)
			choiseReply_26(artificial_arguments);

		else if (const1 && array[x + 1][y - 1] == side && array[x - 1][y + 1] == side && array[x - 2][y + 2] == side)
			choiseReply_27(artificial_arguments);

		else if (const1 && array[x + 2][y - 2] == side && array[x + 1][y - 1] == side && array[x - 1][y + 1] == side)
			choiseReply_28(artificial_arguments);

		else if (const1 && array[x + 3][y - 3] == side && array[x + 2][y - 2] == side && array[x + 1][y - 1] == side)
			choiseReply_29(artificial_arguments);

		else if (const1 && array[x][y - 1] == side && array[x][y - 2] == side && array[x][y - 3] == side)
			choiseReply_30(artificial_arguments);

		else if (const1 && array[x][y + 1] == side && array[x][y - 1] == side && array[x][y - 2] == side)
			choiseReply_31(artificial_arguments);

		else if (const1 && array[x][y + 2] == side && array[x][y + 1] == side && array[x][y - 1] == side)
			choiseReply_32(artificial_arguments);

		else if (const1 && array[x][y + 3] == side && array[x][y + 2] == side && array[x][y + 1] == side)
			choiseReply_33(artificial_arguments);

		else if (const1 && array[x + 3][y] == side && array[x + 2][y] == side && array[x + 1][y] == side)
			choiseReply_34(artificial_arguments);

		else if (const1 && array[x + 2][y] == side && array[x + 1][y] == side && array[x - 1][y] == side)
			choiseReply_35(artificial_arguments);

		else if (const1 && array[x + 1][y] == side && array[x - 1][y] == side && array[x - 2][y] == side)
			choiseReply_36(artificial_arguments);

		else if (const1 && array[x - 1][y] == side && array[x - 2][y] == side && array[x - 3][y] == side)
			choiseReply_37(artificial_arguments);



		else if (const1 && array[x - 1][y - 1] == side && array[x - 2][y - 2] == side)
			choiseReply(artificial_arguments);
		else if (const1 && array[x - 1][y - 1] == side && array[x + 1][y + 1] == side)
			choiseReply_2(artificial_arguments);
		else if (const1 && array[x + 1][y + 1] == side && array[x + 2][y + 2] == side)
			choiseReply_3(artificial_arguments);
		else if (const1 && array[x][y + 1] == side && array[x][y + 2] == side)
			choiseReply_4(artificial_arguments);
		else if (const1 && array[x][y + 1] == side && array[x][y - 1] == side)
			choiseReply_5(artificial_arguments);
		else if (const1 && array[x][y - 2] == side && array[x][y - 1] == side)
			choiseReply_6(artificial_arguments);
		else if (const1 && array[x + 1][y] == side && array[x + 2][y] == side)
			choiseReply_7(artificial_arguments);
		else if (const1 && array[x - 1][y] == side && array[x + 1][y] == side)
			choiseReply_8(artificial_arguments);
		else if (const1 && array[x - 1][y] == side && array[x - 2][y] == side)
			choiseReply_9(artificial_arguments);
		else if (const1 && array[x - 1][y + 1] == side && array[x - 2][y + 2] == side)
			choiseReply_10(artificial_arguments);
		else if (const1 && array[x - 1][y + 1] == side && array[x + 1][y - 1] == side)
			choiseReply_11(artificial_arguments);
		else if (const1 && array[x + 1][y - 1] == side && array[x + 2][y - 2] == side)
			choiseReply_12(artificial_arguments);




		else if (const1 && array[x - 1][y] == side)
			choiseReply_13(artificial_arguments);
		else if (const1 && array[x + 1][y] == side)
			choiseReply_14(artificial_arguments);
		else if (const1 && array[x][y + 1] == side)
			choiseReply_15(artificial_arguments);
		else if (const1 && array[x][y - 1] == side)
			choiseReply_16(artificial_arguments);
		else if (const1 && array[x + 1][y + 1] == side)
			choiseReply_17(artificial_arguments);
		else if (const1 && array[x - 1][y - 1] == side)
			choiseReply_18(artificial_arguments);
		else if (const1 && array[x - 1][y + 1] == side)
			choiseReply_19(artificial_arguments);
		else if (const1 && array[x + 1][y - 1] == side)
			choiseReply_20(artificial_arguments);

		else
			choiseReply_21(array, side, move, artificial, science, x, y, choise, complication);
		
		
	}



	void decoder(short x, short y) {

		char letter;
		if (y == 0) letter = 'A';
		if (y == 1) letter = 'B';
		if (y == 2) letter = 'C';
		if (y == 3) letter = 'D';
		if (y == 4) letter = 'E';
		if (y == 5) letter = 'F';
		if (y == 6) letter = 'G';
		if (y == 7) letter = 'H';
		if (y == 8) letter = 'I';
		if (y == 9) letter = 'J';

		x += 1;


		cout << "\n\t\t\tХод компьютера: " <<letter<<x<< "\n\n";

	
	}

	string isMoveCorrect(char array[][10], char side, string& move, char& artificial, char science,
		short complication, char a, short b) {
		if (a != 'A' && a != 'a' && a != 'B' && a != 'b' && a != 'C' && a != 'c' && a != 'D' && a != 'd' && a != 'E' 
			&& a != 'e' && a != 'F' && a != 'f' && a != 'G' && a != 'g' && a != 'H' && a != 'h' && a != 'I' && a != 'i'
			&& a != 'J' && a != 'j')
			badMove(array, side, move, artificial, science, complication);
		if (b < 1 || b > 10)
			badMove(array, side, move, artificial, science, complication);
		else
			return move;

	}

	void badMove(char array[][10], char side, string move, char artificial, char science, short complication) {
		cout<<"\n\t\t\tТы вводишь что - то неправильно!Попробуй еще раз!\n\n";

		yourMove(array, side, move, artificial, science, complication);
	}
	
	void badComplication(char side, char array[][10], string move, char artificial, char science, short complication) {
		cout << "\n\t\t\tТы вводишь что - то неправильно!Попробуй еще раз!\n\n";

		complicationz(side, array, artificial, science, complication);
	}
	
			
	void bugMove(char array[][10], char side, string& move, char& artificial, char& science, short complication) {
		cout << "\n\t\t\tТакой ход уже был! Сделай другой ход!\n\n";

		yourMove(array, side, move, artificial, science, complication);

	}

	
	void bug(char x) {
		cout << "\n\t\t\tТы вводишь что-то неправильно! Попробуй еще раз!\n\n";

		playTheGame(x, array, artificial);

	}

	void bug(char x, char y, char z) {
		cout << "\n\t\t\tТы вводишь что-то неправильно! Попробуй еще раз!\n\n";

		playTheGame(x, array, artificial, science);

	}






	short enteredMove(char array[][10], char side, string& move, char artificial, char science, char a, short b, short& x, 
		short& y, short complication) {
		if (a == 'A' || a == 'a') y = 0;
		if (a == 'B' || a == 'b') y = 1;
		if (a == 'C' || a == 'c') y = 2;
		if (a == 'D' || a == 'd') y = 3;
		if (a == 'E' || a == 'e') y = 4;
		if (a == 'F' || a == 'f') y = 5;
		if (a == 'G' || a == 'g') y = 6;
		if (a == 'H' || a == 'h') y = 7;
		if (a == 'I' || a == 'i') y = 8;
		if (a == 'J' || a == 'j') y = 9;

		x = b - 1;


		if (array[x][y] == ' ')
			array[x][y] = side;
		else
			bugMove(array, side, move, artificial, science, complication);

		return x, y;
	}

#define text1 cout << "\n\n\t\t\tТЫ ПОБЕДИЛ!!! Я повержен :-(((((\n\n", authorise();
#define text2 cout << "\n\n\t\t\tЯ ВЫИГРАЛ!!! Ты сегодня не в ударе!! ;-)))))\n\n", authorise();
#define const_2 array[x][y] == artificial
#define light_1 array[x][y - 1] ==
#define light_2 array[x][y - 2] ==
#define light_3 array[x][y - 3] ==
#define heavy_1 array[x][y + 1] ==
#define heavy_2 array[x][y + 2] ==
#define heavy_3 array[x][y + 3] ==
	
	void areYouWin(char array[][10], char& side, char& artificial, char science, short complication, short x, short y) {
		
		if (const1 && light_1 side && light_2 side && light_3 side && array[x][y - 4] == side && (y - 4) > -1) 
			text1
		else if (const_2 && light_1 artificial && light_2 artificial && light_3 artificial && array[x][y - 4] == artificial && (y - 4) > -1)
			text2
		else if (const1 && heavy_1 side && light_1 side && light_2 side && light_3 side && (y - 3) > -1)
			text1
		else if (const_2 && heavy_1 artificial && light_1 artificial && light_2 artificial && light_3 artificial && (y - 3) > -1)
			text2
		else if (const1 && heavy_2 side && heavy_1 side && light_1 side && light_2 side && (y - 2) > -1 && (y + 2) < 10)
			text1
		else if (const_2 && heavy_2 artificial && heavy_1 artificial && light_1 artificial && light_2 artificial && (y - 2) > -1 && (y + 2) < 10)
			text2
		else if (const1 && heavy_3 side && heavy_2 side && heavy_1 side && light_1 side && (y - 1) > -1 && (y + 3) < 10)
			text1
		else if (const_2 && heavy_3 artificial && heavy_2 artificial && heavy_1 artificial && light_1 artificial && (y - 1) > -1 && (y + 3) < 10)
			text2
		else if (const1 && array[x][y + 4] == side && heavy_3 side && heavy_2 side && heavy_1 side && (y + 4) < 10)
			text1
		else if (const_2 && array[x][y + 4] == artificial && heavy_3 artificial && heavy_2 artificial && heavy_1 side && (y + 4) < 10)
			text2


#define soft_1 array[x - 1][y] ==
#define soft_2 array[x - 2][y] ==
#define soft_3 array[x - 3][y] ==
#define hard_1 array[x + 1][y] ==
#define hard_2 array[x + 2][y] ==
#define hard_3 array[x + 3][y] ==


		else if (const1 && soft_1 side && soft_2 side && soft_3 side && array[x - 4][y] == side && (x - 4) > -1) text1
		else if (const_2 && soft_1 artificial && soft_2 artificial && soft_3 artificial && array[x - 4][y] == artificial && (x - 4) > -1) text2
		else if (const1 && hard_1 side && soft_1 side && soft_2 side && soft_3 side && (x - 3) > -1) text1
		else if (const_2 && hard_1 artificial && soft_1 artificial && soft_2 artificial && soft_3 artificial && (x - 3) > -1) text2
		else if (const1 && hard_2 side && hard_1 side && soft_1 side && soft_2 side && (x - 2) > -1 && (x + 2) < 10) text1
		else if (const_2 && hard_2 artificial && hard_1 artificial && soft_1 artificial && soft_2 artificial && (x - 2) > -1 && (x + 2) < 10) text2
		else if (const1 && hard_3 side && hard_2 side && hard_1 side && soft_1 side && (x - 1) > -1 && (x + 3) < 10) text1
		else if (const_2 && hard_3 artificial && hard_2 artificial && hard_1 artificial && soft_1 artificial && (x - 1) > -1 && (x + 3) < 10) text2
		else if (const1 && array[x + 4][y] == side && hard_3 side && hard_2 side && hard_1 side && (x + 4) < 10) text1
		else if (const_2 && array[x + 4][y] == artificial && hard_3 artificial && hard_2 artificial && hard_1 side && (x + 4) < 10) text2


		else if (const1 && array[x - 1][y - 1] == side && array[x - 2][y - 2] == side && array[x - 3][y - 3]
			== side && array[x - 4][y - 4] == side && (x - 4) > -1 && (y - 4) > -1)
			text1
		else if (const_2 && array[x - 1][y - 1] == artificial && array[x - 2][y - 2] == artificial
			&& array[x - 3][y - 3] == artificial && array[x - 4][y - 4] == artificial && (x - 4) > -1 && (y - 4) > -1)
			text2
		else if (const1 && array[x + 1][y + 1] == side && array[x - 1][y - 1] == side && array[x - 2][y - 2]
			== side && array[x - 3][y - 3] == side && (x - 3) > -1 && (y - 3) > -1)
			text1
		else if (const_2 && array[x + 1][y + 1] == artificial && array[x - 1][y - 1] == artificial &&
			array[x - 2][y - 2] == artificial && array[x - 3][y - 3] == artificial && (x - 3) > -1 && (y - 3) > -1)
			text2
		else if (const1 && array[x + 2][y + 2] == side && array[x + 1][y + 1] == side && array[x - 1][y - 1]
			== side && array[x - 2][y - 2] == side && (x - 2) > -1 && (x + 2) < 10 && (y - 2) > -1 && (y + 2) < 10)
			text1
		else if (const_2 && array[x + 2][y + 2] == artificial && array[x + 1][y + 1] == artificial &&
			array[x - 1][y - 1] == artificial && array[x - 2][y - 2] == artificial && (x - 2) > -1 && (x + 2) < 10 
			&& (y - 2) > -1 && (y + 2) < 10)
			text2
		else if (const1 && array[x + 3][y + 3] == side && array[x + 2][y + 2] == side && array[x + 1][y + 1]
			== side && array[x - 1][y - 1] == side && (x - 1) > -1 && (x + 3) < 10 && (y - 1) > -1 && (y + 3) < 10)
			text1
		else if (const_2 && array[x + 3][y + 3] == artificial && array[x + 2][y + 2] == artificial &&
			array[x + 1][y + 1] == artificial && array[x - 1][y - 1] == artificial && (x - 1) > -1 && (x + 3) < 10 
			&& (y - 1) > -1 && (y + 3) < 10)
			text2
		else if (const1 && array[x + 4][y + 4] == side && array[x + 3][y + 3] == side && array[x + 2][y + 2]
			== side && array[x + 1][y + 1] == side && (x + 4) < 10 && (y + 4) < 10)
			text1
		else if (const_2 && array[x + 4][y + 4] == artificial && array[x + 3][y + 3] == artificial &&
			array[x + 2][y + 2] == artificial && array[x + 1][y + 1] == side && (x + 4) < 10 && (y + 4) < 10)
			text2

		else if (const1 && array[x + 1][y - 1] == side && array[x + 2][y - 2] == side && array[x + 3][y - 3]
			== side && array[x + 4][y - 4] == side && (x + 4) < 10 && (y - 4) > -1)
			text1
		else if (const_2 && array[x + 1][y - 1] == artificial && array[x + 2][y - 2] == artificial
			&& array[x + 3][y - 3] == artificial && array[x + 4][y - 4] == artificial && (x + 4) < 10 && (y - 4) > -1)
			text2
		else if (const1 && array[x - 1][y + 1] == side && array[x + 1][y - 1] == side && array[x + 2][y - 2]
			== side && array[x + 3][y - 3] == side && (x + 3) < 10 && (y - 3) > -1)
			text1
		else if (const_2 && array[x - 1][y + 1] == artificial && array[x + 1][y - 1] == artificial &&
			array[x + 2][y - 2] == artificial && array[x + 3][y - 3] == artificial && (x + 3) < 10 && (y - 3) > -1)
			text2
		else if (const1 && array[x - 2][y + 2] == side && array[x - 1][y + 1] == side && array[x + 1][y - 1]
			== side && array[x + 2][y - 2] == side && (x - 2) > -1 && (x + 2) < 10 && (y - 2) > -1 && (y + 2) < 10)
			text1
		else if (const_2 && array[x - 2][y + 2] == artificial && array[x - 1][y + 1] == artificial &&
			array[x + 1][y - 1] == artificial && array[x + 2][y - 2] == artificial && (x - 2) > -1 && (x + 2) < 10
			&& (y - 2) > -1 && (y + 2) < 10)
			text2
		else if (const1 && array[x - 3][y + 3] == side && array[x - 2][y + 2] == side && array[x - 1][y + 1]
			== side && array[x + 1][y - 1] == side && (x - 1) > -1 && (x + 3) < 10 && (y - 1) > -1 && (y + 3) < 10)
			text1
		else if (const_2 && array[x - 3][y + 3] == artificial && array[x - 2][y + 2] == artificial &&
			array[x - 1][y + 1] == artificial && array[x + 1][y - 1] == artificial && (x - 1) > -1 && (x + 3) < 10
			&& (y - 1) > -1 && (y + 3) < 10)
			text2
		else if (const1 && array[x - 4][y + 4] == side && array[x - 3][y + 3] == side && array[x - 2][y + 2]
			== side && array[x - 1][y + 1] == side && (x - 4) > -1 && (y + 4) < 10)
			text1
		else if (const_2 && array[x - 4][y + 4] == artificial && array[x - 3][y + 3] == artificial &&
			array[x - 2][y + 2] == artificial && array[x - 1][y + 1] == side && (x - 4) > -1 && (y + 4) < 10)
			text2
	
	
	
	
	}
	
	void authorise() {
		cout<<"\n\t\t\twritten by[Sergey Pedenko]\n\n\n\n\t\t\t";
		short target;
		cout << "Сыграем еще раз? На этот раз посложнее! (1 - да, 0 - нет)";
		cin >> target;
		if (target != 1 && target != 0)
			cout << "Ты вводишь что-то неправильно! Попробуй еще раз!", authorise();
		else if (target == 1)
			myGame();
		else
			cout << "\n\n\t\t\tНу, пока!\n\n", exit(0);
	}

};


void myGame() {
	XO player;

	player.complicationz(player.side, player.array, player.artificial, player.science, player.complication);

	if(player.complication == 1 || player.complication == 2)
		player.playTheGame(player.side, player.array, player.artificial);
	else
		player.playTheGame(player.side, player.array, player.artificial, player.science);

	player.desk(player.array, player.side, player.move, player.artificial, player.science, player.complication, player.x, player.y);
}

int main() {

	setlocale(LC_ALL, "Rus");

	Game game;

	XO player;

	game.welcome(game.answer);
	if (game.answer == 1)
		player.teachMeToPlay(player.marker);

	myGame();
}