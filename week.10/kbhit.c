// kbhit.c
#include <stdio.h>
#include <conio.h>

int main(void) {
	int ch;

	printf("Presss any key to see ASCII value (ESC to quit): \n");

	while (1) {
		if (_kbhit()) {
			ch = _getch();

			if (ch == 27) {
				printf("ESC pressed! Exiting...");
				break;
			}

			// ��� ������ Ű
			if (ch >= 32 && ch <= 126) {
				printf("Key: %c, ASCII: %d\n", ch, ch);
			}

			// ��� �Ұ����� Ű (F1=F12, ��)
			else {
				printf("ASCII: %d\n", ch);
			}
		}
	}

	return 0;
}