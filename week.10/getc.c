// getc.c
#include <stdio.h>

int main(void) {
	// �Է� ���ڰ� ������ ��� �а� ����ϴ� ���α׷�
	// @���� ���� �� �ִ�.
	char ch;

	printf("Enter char to read (@ to stop): \n");

	// ���� ���� ��
	// while((ch = getc(filename)) != 'EOF')
	while ((ch = getc(stdin)) != '@') {
		// ���� ���ڸ� �ٽ� ����ϱ�
		putchar(ch);
	}

	printf("\nEnd of input.\n");


	return 0;
}