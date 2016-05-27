all: main.o rc4.o x1.o x2.o x3.o x5.o
	gcc -g  main.o rc4.o x1.o x2.o x3.o x5.o -L/home/scf-22/csci551b/openssl/lib -lcrypto -lm -o hw7

main.o: main.c hw7.h
	gcc -c -g -Wall main.c  -I/home/scf-22/csci551b/openssl/include

rc4.o: rc4.c hw7.h
	gcc -c -g -Wall rc4.c -I/home/scf-22/csci551b/openssl/include

x1.o: x1.c hw7.h
	gcc -c -g -Wall x1.c -I/home/scf-22/csci551b/openssl/include

x2.o: x2.c hw7.h
	gcc -c -g -Wall x2.c -I/home/scf-22/csci551b/openssl/include

x3.o: x3.c hw7.h
	gcc -c -g -Wall x3.c -I/home/scf-22/csci551b/openssl/include

x5.o: x5.c hw7.h
	gcc -c -g -Wall x5.c -I/home/scf-22/csci551b/openssl/include


clean:
	rm *.o
	rm hw7
