CC = gcc
CFLAGS = -Wall -Wextra -std=c11
LIBS = -lcunit

mot_cache: mot_cache.c
	$(CC) $(CFLAGS) mot_cache.c -o mot_cache

test: mot_cache.c
	bats tests.bats
	$(CC) $(CFLAGS) $< -o $@ $(LIBS)
	./$@

clean:
	rm -f mot_cache test *.o *.html

test: mot_cache

