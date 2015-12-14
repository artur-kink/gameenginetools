
CC=g++

TIMESOURCES= Time.cpp \
			../Time/Timer.cpp \
			../Time/CarryTimer.cpp

TIMEOBJECTS=$(TIMESOURCES:.cpp=.o)

all: time

time: $(TIMEOBJECTS)
	$(CC) -Wall -g -o time $(TIMEOBJECTS)
	./time

$(TIMEOBJECTS): %.o: %.cpp
	$(CC) -c -g -Wall -std=c++11 -o $@ $<


clean:
	rm $(TIMEOBJECTS)
	rm time
