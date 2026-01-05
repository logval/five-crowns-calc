CXX = g++
CXXFLAGS = -std=c++17 -Wall 

TARGET = fccalc
OFILES = game.o hand.o user.o nonUser.o gameUtils.o
HFILES = $(shell ls -1 *.h)

all: $(TARGET)

$(TARGET): $(HFILES) $(OFILES) main.o
	$(CXX) $(CXXFLAGS) -o $@ main.o $(OFILES)

%.o: %.cpp $(HFILES)
	$(CXX) $(CXXFLAGS) -c -o $@ $<


.PHONY: clean all
clean: 
	rm -f *.o
	rm -f $(TARGET)
