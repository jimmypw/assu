
assu: assu.o
		gcc -o assu assu.o

assu.o: assu.c
		gcc -c -o assu.o assu.c

install: assu
		install -m 4755 -T assu /usr/bin/assu


clean:
	rm -f *.o assu
