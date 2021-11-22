COMPILER = g++

$(nom).exe: file1.o libSys.a
	$(COMPILER) -s -o $(nom).exe file1.o -L ./ -lSys;
	make clean

file1.o: file1.cxx ../include/notreEntete.h
	$(COMPILER) -c file1.cxx -I ../include

libSys.a: file2.cxx ../include/notreEntete.h
	$(COMPILER) -c file2.cxx -I ../include;
	ar -cqs libSys.a file2.o;
	rm file2.o

clean:
	rm file1.o;
	rm libSys.a
