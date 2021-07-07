default:
	${CC} main.c -O2 -Wall -Wextra -Wpedantic -o dtg-stats

install:
	cp dtg-stats /bin/dtg-stats
	chmod a+x /bin/dtg-stats
