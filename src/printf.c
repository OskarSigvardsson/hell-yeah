#include <stdio.h>
#include <string.h>

int main(int argc, char **argv) {
	char *str = argc > 1 ? argv[1] : "y";
	int len = strlen(str);

	int printed;
	do {
		printed = printf("%s\n", str);
	} while(printed == len + 1);
}
