
OBJECTS = View.o Control.o FarmData.o  #put any other objects you make here

a5: $(OBJECTS)
	g++ -o a5 main.cc $(OBJECTS)

#************compile your object files here**************



#************do not adjust the lines below***************

TESTOBJECTS = TestControl.o AnimalData2.o FarmData2.o Tester.o $(OBJECTS)

#test executable used to test your code
test: test.cc $(TESTOBJECTS)
	g++ -o test test.cc $(TESTOBJECTS)

TestControl.o: TestControl.cc TestControl.h
	g++ -c TestControl.cc

FarmData2.o: FarmData2.cc FarmData2.h  
	g++ -c FarmData2.cc

AnimalData2.o: AnimalData2.cc AnimalData2.h
	g++ -c AnimalData2.cc

Tester.o: Tester.cc Tester.h
	g++ -c Tester.cc

View.o: View.cc View.h
	g++ -c View.cc

Control.o: Control.cc Control.h
	g++ -c Control.cc

clean:
	rm -f a5 *.o