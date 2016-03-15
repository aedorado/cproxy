CC=gcc
CFLAGS= -g -Wall -Werror

all: proxy

proxy: proxy.c
	#$(CC) $(CFLAGS) -o proxy_parse.o -c proxy_parse.c
	#$(CC) $(CFLAGS) -o proxy.o -c proxy.c
	$(CC) $(CFLAGS) proxy.c -o proxy

clean:
	rm -f proxy *.o

tar:
	tar -cvzf irm2013017.tgz proxy.c README Makefile
