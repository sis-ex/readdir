
readdir: main.c
	cc main.c -o readdir

clean:
	@rm -f readdir *.o

