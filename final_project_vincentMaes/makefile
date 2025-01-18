all: main

main: main.o Car.o Sensor.o SpeedSensor.o TemperatureSensor.o FuelSensor.o RaceEvent.o Weather.o Tyre.o RaceStrategy.o
	g++ -std=c++17 main.o Car.o Sensor.o SpeedSensor.o TemperatureSensor.o FuelSensor.o RaceEvent.o Weather.o Tyre.o RaceStrategy.o -o main

main.o: main.cpp
	g++ -std=c++17 -c main.cpp

Car.o: Car.cpp
	g++ -std=c++17 -c Car.cpp

Sensor.o: Sensor.cpp
	g++ -std=c++17 -c Sensor.cpp

SpeedSensor.o: SpeedSensor.cpp
	g++ -std=c++17 -c SpeedSensor.cpp

TemperatureSensor.o: TemperatureSensor.cpp
	g++ -std=c++17 -c TemperatureSensor.cpp

FuelSensor.o: FuelSensor.cpp
	g++ -std=c++17 -c FuelSensor.cpp

RaceEvent.o: RaceEvent.cpp
	g++ -std=c++17 -c RaceEvent.cpp

Weather.o: Weather.cpp
	g++ -std=c++17 -c Weather.cpp

Tyre.o: Tyre.cpp
	g++ -std=c++17 -c Tyre.cpp

RaceStrategy.o: RaceStrategy.cpp
	g++ -std=c++17 -c RaceStrategy.cpp

clean:
	rm -f *.o main
