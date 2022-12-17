
#Makefile


CXX = clang++ $(CXXFLAGS)
CXXFLAGS=-Wall -o2
DEBUG=-g

TARGETS = huffmanenc.o huffmanNode.o heap.o

a.out: $(TARGETS)
	$(CXX) $(DEBUG) $(TARGETS) -o a.out


huffmanenc.o: huffmanenc.cpp
huffmanNode.o: huffmanNode.h huffmanNode.cpp
heap.o: heap.h heap.cpp



.PHONY: clean
clean:
	-rm -f *.o *~a.out
