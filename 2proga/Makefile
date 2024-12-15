.PHONY: all debug release clean
RELEASE_EXEC = isp 
RELEASE_DBG = isp-dbg
TEST = test_1.cpp 
Libary = -lUnitTest++

all: debug release
debug: $(DEBUG_EXEC)

$(DEBUG_EXEC): $(TEST)
	g++ $(TEST) -o $@ $(Libary)

release: $(RELEASE_EXEC)

$(RELEASE_EXEC): $(TEST)
	g++ $(TEST) modAlphaCipher.cpp -o $@ $(Libary)
	
clean:
	rm -f *.o $(RELEASE_EXEC) $(RELEASE_DBG) 
