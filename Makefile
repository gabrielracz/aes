CFLAGS= -g -O0
LIBS= 

aes: entry.c aes.c
	gcc ${CFLAGS} -o aes entry.c

clean:
	rm aes
