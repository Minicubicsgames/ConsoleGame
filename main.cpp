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

	cout << "��� ���� 'Dice', ��� ��� ��������� ������ ��������� ������!\n�������� 100 ����� �� 25 �����, ����� ��������!\n�� ������� �� ����� �����!\n\n";

	while (!isExit) {

		if (moves == 0 || score >= score_to_win) {
			system("cls");
			cout << "���� ���������!";
			if (score >= score_to_win) {
				cout << "\n\n�� ��������!\n\n";
			}
			else {
				cout << "\n\n�� ���������!\n\n";
			}
			cout << "������� �� ����!";
			Sleep(5000);
			return 0;
		}

		cout << "������ ������ �����?(y or n)\n";
		cin >> dice;
		if (dice == "y" || dice == "yes") {
			dice_current_count = 1 + rand() % 6;
			cout << "\n������ �����...\n";
			Sleep(2000);
			cout << "\n��� ���������: ";
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
			cout << "\n���� ����: ";
			cout << score;
			cout << "\n�������� �����: ";
			cout << moves;
			cout << "\n��������� 5 ������...";
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