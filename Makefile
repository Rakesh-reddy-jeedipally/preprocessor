a.out: main.o comment.o headerinc.o macroreplace.o
	gcc main.o comment.o headerinc.o macroreplace.o

main.o : main.c
	gcc -c main.c

commnet.o: comment.c
	gcc -c commnet.c

headerinc.o : headerinc.c
	gcc -c headerinc.c

macroreplace.o : macroreplace.c
	gcc -c macroreplace.c



