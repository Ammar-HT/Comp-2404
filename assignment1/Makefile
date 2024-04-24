all: a1

a1: Date.o Event.o PlannerDate.o Planner.o Tester.h
	g++ -o a1 main.cc Date.o Event.o PlannerDate.o Planner.o
	
Date.o: Date.cc Date.h
	g++ -c Date.cc

Event.o: Event.cc Event.h
	g++ -c Event.cc

PlannerDate.o: PlannerDate.cc PlannerDate.h 
	g++ -c PlannerDate.cc

Planner.o: Planner.cc Planner.h PlannerDate.h
	g++ -c Planner.cc

clean:
	rm -f a1 *.o
