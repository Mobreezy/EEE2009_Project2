program: main.cpp Sensor.o Person.o
	g++ -o $@ main.cpp Sensor.o Person.o

Sensor.o: Sensor.cpp
	g++ -o $@ -c Sensor.cpp

Person.o: Person.cpp
	g++ -o $@ -c Person.cpp

clean:
	rm -rf *.o
	rm -rf program

cleandata:
	rm -rf *.dat
