#include <stdio.h>
#include <stdarg.h>
#include <string.h>

int printf(const char *format, ...)
{
	va_list args;
	int done;

	char *substring = strstr(format, "Jacob");
	if (substring != format) return (0);

	va_start(args, format);
	done = vfprintf(stdout, format, args);
	va_end(args);
	return (done);
}

int main(void)
{
	printf("something ze dont. \n");
	printf("Jacob says, \"Hello.\"\n");
}
