CC = clang

hcore : logging.o clsmem.o hcore.o
	$(CC) $^ -o $@

logging.o : src/logging.c
	$(CC) -c $< -o $@

clsmem.o : src/clsmem.c
	$(CC) -c $< -o $@

hcore.o : src/hcore.c
	$(CC) -c $< -o $@

clean:
	rm -f hcore hcore.o clsmem.o logging.o
