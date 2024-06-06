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
	const int bufsize = 4096;

	char *begin = malloc(bufsize);
	char *end = begin + bufsize;

	char *ptr = begin;

	while (ptr + len < end) {
		memcpy(ptr, str, len-1);
		ptr[len-1] = '\n';
		ptr += len;
	}

	int finalLen = ptr - begin;

	while (do_write(1, begin, finalLen));
}
