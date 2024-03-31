FLAGS = -Werror

main.exe: main.o cmd.o database.o
	g++ -o main.exe main.o cmd.o database.o

main.o: src/main.cpp
	g++ ${FLAGS} -c src/main.cpp

cmd.o: src/cmd.cpp
	g++ ${FLAGS} -c src/cmd.cpp

database.o: src/database.cpp
	g++ ${FLAGS} -c src/database.cpp

clean:
	rm *.o
	rm main.exe
