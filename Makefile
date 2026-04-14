all: testa_romano.cpp   romano.cpp romano.hpp romano.o
	g++ -std=c++17 -Wall romano.o testa_romano.cpp -o testa_romano -lgtest -lgtest_main -pthread
	./testa_romano

compile: testa_romano.cpp   romano.cpp romano.hpp romano.o
	g++ -std=c++17 -Wall romano.o testa_romano.cpp -o testa_romano -lgtest -lgtest_main -pthread
	
test: testa_romano	
	./testa_romano
	
cpplint: testa_romano.cpp   romano.cpp romano.hpp
	cpplint   --exclude=catch.hpp  *.*
	
gcov: testa_romano.cpp   romano.cpp romano.hpp 
	g++ -std=c++17 -Wall -Wall -fprofile-arcs -ftest-coverage -c romano.cpp
	g++ -std=c++17 -Wall -fprofile-arcs -ftest-coverage romano.o testa_romano.cpp -o testa_romano -lgtest -lgtest_main -pthread
	./testa_romano
	gcov romano.cpp
	
debug: testa_romano.cpp   romano.cpp romano.hpp 
	g++ -std=c++17 -Wall -Wall -g -c romano.cpp
	g++ -std=c++17 -Wall  -g romano.o testa_romano.cpp -o testa_romano -lgtest -lgtest_main -pthread
	gdb testa_romano
	
	
cppcheck: testa_romano.cpp   romano.cpp romano.hpp
	cppcheck  --enable=warning . 

valgrind: testa_romano
	valgrind --leak-check=yes --log-file=valgrind.rpt testa_romano

romano.o : romano.cpp romano.hpp
	g++ -std=c++17 -Wall -Wall -c romano.cpp
	
testa_romano:  testa_romano.cpp   romano.cpp romano.hpp romano.o
	g++ -std=c++17 -Wall romano.o testa_romano.cpp -o testa_romano -lgtest -lgtest_main -pthread

clean:
	rm -rf *.o *.gc*
	
	
