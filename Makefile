CFLAGS = -Wall -Werror -Wextra
CPPFLAGS = -MMD


main: main.o
	$(CC) $(CFLAGS) -o $@ $^

main.o: geometry.c
	$(CC) -c $(CFLAGS) $(CPPFLAGS) -o $@ $<
	
-include main.d
