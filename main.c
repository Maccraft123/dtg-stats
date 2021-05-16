#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main(void)
{
	FILE *batfd;
	int vol, soc, tmp;
	char out[7];

	batfd = fopen("/sys/class/power_supply/rk817-battery/voltage_now/", "r");
	tmp = fscanf(batfd, "%d", &vol);
	if(tmp)
		return 1;
	fclose(batfd);

	soc = (vol - 3500000) / 6000;

	switch(soc)
	{
		case 91 ... 100: // [FUL]+
			strcpy(out, "[FUL]+");
			break;
		case 76 ... 80:  // [---]+
			strcpy(out, "[---]+");
			break;
		case 36 ... 75:  // [-- ]+
			strcpy(out, "[-- ]+");
			break;
		case 11 ... 35:  // [-  ]+
			strcpy(out, "[-  ]+");
			break;
		case 0 ... 10:	 // [   ]+
			strcpy(out, "[   ]+");
			break;
	}
	printf("%s\n", out);
	return 0;
}
