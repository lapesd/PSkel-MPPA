cmd_output/build/slave_build/slave.cpp.o := /usr/local/k1tools/bin/k1-g++ -Wp,-MD,output/build/slave_build/.slave.cpp.o.d -Wp,-MT,output/build/slave_build/slave.cpp.o -mcluster=node  -Wall    -march=k1b -mboard=developer -mos=nodeos -fopenmp -DITERATIONS=10000  -c -o output/build/slave_build/slave.cpp.o slave.cpp
