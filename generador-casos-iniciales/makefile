program.exe: pruebas.o
	g++ -o program.exe -std=c++2a pruebas.o
%.o : %.cc
	g++ -c -std=c++2a $<

clean:
	rm *.o *.exe
