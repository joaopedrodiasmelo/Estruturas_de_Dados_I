all:
	gcc -c contatinho.c -o contatinho.o
	gcc teste.c contatinho.o -o teste

run:
	./teste

clear:	
	rm ./teste ./contatinho.o