#include "libs/arc/1lib.h"
#include "libs/dearc/2lib.h"

int main()
{
	FILE *fin = fopen("in.txt", "rb");
	unsigned char a;

	fread(&a, 1, 1, fin);
	fseek(fin, 3, SEEK_SET);
	if (a == 'c')
		arc(fin);
	else if (a == 'd')
		dearc(fin);

	return 0;
}