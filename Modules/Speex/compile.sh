g++ -c -fPIC *.cpp -L/usr/lib/ -lspeex
g++ *.o -o libDataDecoder.so -shared
