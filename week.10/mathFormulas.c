// mathFormulas.c
#include <stdio.h>
#include <stdlib.h> // atoi() �Լ� �ִ� -> arrayTolnt() �ۼ�
#include <ctype.h> // isdigit() �Լ� �ִ� -> numCheck() �ۼ�

int numCheck(char ch) {
	return (int) ch >= '0' && ch <= '9'; // 1�̳� 0 ��ȯ
}

int checkOp(char op) {
	return op == '+' || op == '-' || op == '*' || op == '/';
}

int arrayTolnt(char str[]) {
	int i = 0,
		num = 0;

	// ���ڿ��� �ݺ��ϰ� ��� ���ڸ� ���ڷ� �����ϱ�
	while (str[i] != '\0') {
		// �������� Ȯ���ϱ� 
		if (numCheck(str[i])) { // 1
			num = num * 10 + (str[i] - '0'); // ASCII 48 ���� ��� ���ڷ� ����
		}
		else { // 0
			break;
		} 
		i++; // ���� ���ڷ� �̵��ϱ�
	}

	return num;
}

int main(void) {
	char input[100],
		numStr1[50], numStr2[50],		
		operator = '\0'; // �����ڰ� NULL�� �ʱ�ȭ�ϱ�
	int i = 0, // ���� �Է��� ���ڿ��� �ε���
		j = 0; // �ް� ���� ������ �ε��� 

	// ��������� �����Լ� �ޱ� (��: "12+34")
	printf("Enter a simple math forumla (12+34):\n");
	fgets(input, sizeof(input), stdin);

	// #1: ù��° ���ڸ� �����ϱ�
	while (input[i] != '\0' && numCheck(input[i])) {
		numStr1[j++] = input[i++];
	}
	numStr1[j] = '\0';

	// #2: ���� �����ڸ� ã��
	if (checkOp(input[i])) { // 1
		operator = input[i++];
	}
	else {
		printf("Error: Invalid operator!\n");
		return 1; // main �Լ��� ���� �ְ� ����
	}

	j = 0; // �� ��° ���ڸ� �ޱ����� �ʱ�ȭ�ϱ�

	// #3: �ι�° ���ڸ� �����ϱ�
	while (input[i] != '\0' && numCheck(input[i])) {
		numStr2[j++] = input[i++];
	}
	numStr2[j] = '\0';

	/*
	��:
	input = "123+456"
	numStr1 = "123"
	operator = '+'
	numStr2 = "456"
	*/

	// �� numStr�� ���ڷ� �����ϱ�
	int num1 = arrayTolnt(numStr1);
	int num2 = arrayTolnt(numStr2);
	int result = 0;

	// ����ϱ�
	switch (operator) {
	case '+':
		result = num1 + num2;
		break;
	case '-':
		result = num1 - num2;
		break;
	case '*':
		result = num1 * num2;
		break;
	case '/':
		if (num2 != 0)
			result = num1 / num2; // x/0 �ϸ� �ȵ�
		else{
			printf("Error:division by 0!\n");
			return 1;
		}
		break;
	default:
		printf("Error: Invalid operator. Use +, -, *, /. \n");
		return 1; // �����߻�
	}

	printf("Result: %d %c %d = %d\n", num1, operator, num2, result);

	return 0; // main �Լ��� ���� ���� ����
}