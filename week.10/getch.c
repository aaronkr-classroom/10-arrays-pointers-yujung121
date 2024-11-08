// getch.c
#include <stdio.h>
#include <conio.h> // ����ũ�μ���Ʈ�� ǥ�� C ��Ÿ�� ���̺귯�� 

int main(void) {
	char input_data;
	int count = 1;

	printf("Enter chars ('q', 'Q', or ESC to quit); \n");

	// DRY = Don't Repeat Yourself
	while (1) {	
		if (_kbhit()) { // Ű���� ġ�� �Լ�
			input_data = _getch(); // �� ���� ���ڸ� �Է� ����
			
			// 'q', 'Q', ESC �Է������� �����ϱ�
			if (input_data == 'q' || input_data == 'Q' || input_data == 27) {
				printf("\nExiting program...\n");
				break;
			}
			rewind(stdin); // ǥ�� �Է� ���ۿ� �ִ� ��� �Է� ���� ������
			printf("Input %d: %c\n", count++, input_data);
		}
	}

	return 0;
}