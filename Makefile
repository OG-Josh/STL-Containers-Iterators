CXX = g++

CXXFLAGS = -g --std=c++11

BINARY = hw15

TARFILE = hw15.tar

all: $(BINARY)

$(BINARY):
	$(CXX) $(CXXFLAGS) hw15.cpp -o $(BINARY)
clean:
	rm -rf $(BINARY) $(TARFILE)
tar:
	tar cf $(TARFILE) Makefile hw15.scr hw15.cpp