exo_03.exe : exo_03.o nsSysteme.o
	g++ -o exo_03.exe exo_03.o -I ../include/;

exo_03.o : exo_03.cxx 
	g++ -c exo_03.cxx -I ../include/;

nsSysteme.o : nsSysteme.cxx
	g++ -c nsSysteme.cxx -I ../include/;

clean :
	rm *.o;
