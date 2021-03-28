// 크로아티아 알파벳
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main() {
	int cnt = 0;
	char str[105];
	scanf("%s", str);
	for (int i = 0; i < strlen(str); i++) {
		if (str[i] == 'c') {
			if (str[i + 1] == '=') continue;
			if (str[i + 1] == '-') continue;
		}
		if (str[i] == 'd') {
			if (str[i + 1] == 'z' && str[i + 2] == '=') continue;
			if (str[i + 1] == '-') continue;
		}
		if (str[i] == 'l' && str[i + 1] == 'j') continue;
		if (str[i] == 'n' && str[i + 1] == 'j') continue;
		if (str[i] == 's' && str[i + 1] == '=') continue;
		if (str[i] == 'z' && str[i + 1] == '=') continue;
		cnt++;
	}
	printf("%d\n", cnt);
	return 0;
}