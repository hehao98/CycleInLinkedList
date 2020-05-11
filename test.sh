g++ -std=c++11 main.cpp -o main.out
echo "testing correctness of the algorithm"
./main.out 0 10000000 0
test $? -eq 0 || echo "something bad happened when testing 0 10000000 0"
./main.out 0 10000000 10000
test $? -eq 0 || echo "something bad happened when testing 0 10000000 10000"
./main.out 0 10000 10000
test $? -eq 0 || echo "something bad happened when testing 0 10000 10000"
./main.out 1 10000000 0
test $? -eq 0 || echo "something bad happened when testing 1 10000000 0"
./main.out 1 10000000 10000
test $? -eq 0 || echo "something bad happened when testing 1 10000000 10000"
./main.out 1 10000 10000
test $? -eq 0 || echo "something bad happened when testing 1 10000 10000"
./main.out 2 10000000 0
test $? -eq 0 || echo "something bad happened when testing 2 10000000 0"
./main.out 2 10000000 10000
test $? -eq 0 || echo "something bad happened when testing 2 10000000 10000"
./main.out 2 10000 10000
test $? -eq 0 || echo "something bad happened when testing 2 10000 10000"
echo "finish"

