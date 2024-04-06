#include <iostream>
#include <Windows.h>
#include <mmsystem.h>

using namespace std;

bool isExit = false;
int dice_current_count;
int score = 0;
int moves = 25;
int const score_to_win = 100;
int all_results[24];

int main() {
	string dice;
	string prosto;
	setlocale(LC_ALL, "RU");
	srand(time(NULL));

	cout << "Эта игра 'Dice', где вам предстоит кидать игральные кубики!\nНаберите 100 очков за 25 ходов, чтобы победить!\nВсё зависит от вашей удачи!\n\n";

	while (!isExit) {

		if (moves == 0 || score >= score_to_win) {
			system("cls");
			cout << "Игра закончена!";
			if (score >= score_to_win) {
				cout << "\n\nВЫ ПОБЕДИЛИ!\n\n";
			}
			else {
				cout << "\n\nВЫ ПРОИГРАЛИ!\n\n";
			}
			cout << "Спасибо за игру!";
			Sleep(5000);
			return 0;
		}

		cout << "Хотите кинуть кость?(y or n)\n";
		cin >> dice;
		if (dice == "y" || dice == "yes") {
			dice_current_count = 1 + rand() % 6;
			cout << "\nКидаем кость...\n";
			Sleep(2000);
			cout << "\nВаш результат: ";
			cout << dice_current_count;
			switch (dice_current_count) {
			case 1: score++; break;
			case 2: score += 2; break;
			case 3: score += 3; break;
			case 4: score += 4; break;
			case 5: score += 5; break;
			case 6: score += 10; break;
			}
			moves -= 1;
			cout << "\nВаши очки: ";
			cout << score;
			cout << "\nОсталось ходов: ";
			cout << moves;
			cout << "\nПодождите 5 секунд...";
			all_results[moves - 1] = dice_current_count;
			Sleep(5000);
			system("cls");
		}
		else {
			isExit = true;
		}
	}
	return 0;
}