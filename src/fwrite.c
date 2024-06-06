#include <unistd.h>

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int do_write(char *ptr, int count) {
	int ret = fwrite(ptr, 1, count, stdout);
	return ret == count;
}

int main(int argc, char **argv) {
	char *str = argc > 1 ? argv[1] : "y";
	int len = strlen(str) + 1;
	char *buf;

	buf = malloc(len);
	memcpy(buf, str, len-1);
	buf[len-1] = '\n';
	
	while (do_write(buf, len));
}
