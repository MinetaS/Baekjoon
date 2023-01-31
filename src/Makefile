ifeq ($(OS), Windows_NT)
	EXE = Main.exe
else
	EXE = Main
endif

ifeq ($(CXX),)
	CXX = g++
endif

ifeq ($(CXX), g++)
	CXXFLAGS = -std=gnu++20 -O2 -Wall -lm -static
endif

%:
	$(CXX) $(CXXFLAGS) -o $(EXE) ./$*.cc

clean:
	@rm -f $(EXE)

.PHONY: clean
