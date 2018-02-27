CXX=g++

CXX := g++
CFLAGS += -g -Wall -fpermissive
CFLAGS += -I/usr/local/cftlib/openssl/include -I/usr/local/cftlib/qpayencryptclient
LDFLAGS += -L/usr/local/cftlib/openssl/lib -lssl -lcrypto -L/usr/local/cftlib/qpayencryptclient -lqpayencryptclient

all = demo

demo: demo.o rsa.o
	$(CXX) $(CFLAGS) -o $@ $^ $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CFLAGS) -c $< -o $@
