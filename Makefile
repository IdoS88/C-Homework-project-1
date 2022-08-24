CC=gcc
OBJS= main.o mat.o q1.o q2.o q3.o 
EXEC= matala1
DEBUG = -g
CFLAGS = -std=c99  -Wall -Werror $(DEBUG)

$(EXEC) : $(OBJS)
	$(CC) $(OBJS) -o $@


main.o: main.c q3.h mat.h q1.h q2.h
mat.o: mat.c mat.h
q1.o: q1.c q1.h mat.h
q2.o: q2.c q2.h mat.h
q3.o: q3.c mat.h q3.h



clean: 
	rm -f $(EXEC) $(OBJS)
	
