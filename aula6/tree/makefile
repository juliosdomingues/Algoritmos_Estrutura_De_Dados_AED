index:
	gcc -g tree.c -c -g
	gcc -g main.c tree.o -o exec -g
compila_roda:
	gcc -g tree.c -c
	gcc -g main.c tree.o -o exec
	./exec > saida.txt
clean:
	rm tree.o
	rm exec
