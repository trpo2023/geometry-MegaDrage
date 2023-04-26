CFLAGS = -Wall -Werror -Wextra
CPPFLAGS = -MMD

.PHONY: clean

bin/main: bin/main.o bin/geometrysearch.a bin/parser.a
	$(CC) $(CFLAGS) -o $@ $^
	
bin/main.o: src/geometry/main.c
	$(CC) -c $(CFLAGS) $(CPPFLAGS) -o $@ $< -I src

bin/geometrysearch.a: bin/geometrysearch.o
	ar rsc $@ $^

bin/parser.a: bin/parser.o
	ar rsc $@ $^

bin/geometrysearch.o: src/libgeometry/geometrysearch.c
	$(CC) -c $(CFLAGS) $(CPPFLAGS) -o $@ $<

bin/parser.o: src/libgeometry/parser.c
	$(CC) -c $(CFLAGS) $(CPPFLAGS) -o $@ $<

main: main.o
	$(CC) $(CFLAGS) -o $@ $^

main.o: main.c
	$(CC) -c $(CFLAGS) $(CPPFLAGS) -o $@ $<

clean: 
	rm -rf bin/*.o
	rm -rf bin/*.d
	rm -rf bin/*.a
