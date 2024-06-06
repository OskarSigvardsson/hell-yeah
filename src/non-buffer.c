#include <unistd.h>

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int do_write(int fd, char *begin, int count) {
	char *end = begin + count;
	char *ptr = begin;

	do {
		int ret = write(fd, ptr, count);
		if (ret < 0) return 0;
		ptr += ret;
		count -= ret;
	} while (ptr < end);

	return 1;
}

int main(int argc, char **argv) {
	char *str = argc > 1 ? argv[1] : "y";
	int len = strlen(str) + 1;
	char *buf;

	buf = malloc(len);
	memcpy(buf, str, len-1);
	buf[len-1] = '\n';
	
	while (do_write(1, buf, len));
}
