CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -I/usr/local/Cellar/cunit/2.1-3/include

mot_cache: mot_cache.c
	$(CC) $(CFLAGS) mot_cache.c -o mot_cache $(LDFLAGS)

html: README.md sujet.md
	pandoc -s --metadata title="Readme" -c misc/github-pandoc.css -o README.html README.md

test: mot_cache
	bats tests.bats
	$(CC) $(CFLAGS) -c Unittests.c -o Unittests.o

clean:
	rm -f mot_cache *.o *.html

