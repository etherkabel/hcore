CC = clang
LIM_ENABLE = 1

ifdef LIM_ENABLE
hcore : logging.o clsmem.o hcore.o warexit.o lim.o
	$(CC) $^ -o $@
else
hcore : logging.o clsmem.o hcore.o warexit.o
	$(CC) $^ -o $@
endif

logging.o : src/logging.c
	$(CC) -c $< -o $@

clsmem.o : src/clsmem.c
	$(CC) -c $< -o $@

hcore.o : src/hcore.c
	$(CC) -c $< -o $@

warexit.o: src/warexit.c
	$(CC) -c $< -o $@

ifdef LIM_ENABLE
lim.o : src/lim.c
	$(CC) -c $< -o $@
endif

clean:
	rm -f hcore hcore.o clsmem.o logging.o warexit.o lim.o
