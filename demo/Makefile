GLOG=../output/

INCLUDEDIR= \
		 -I $(GLOG)/include\
		 -I./

LIBDIR=	\
		-L $(GLOG)/lib -l glog\
		-lpthread -lm -lstdc++ -lcrypto

GCC = g++
#CPPFLAGS = -g -finline-functions -Wall -Winline -pipe -ffast-math
CPPFLAGS = -DNDEBUG -g -finline-functions -Wall -Winline -pipe -ffast-math

TARGET1 = test_glog

OBJ1 = test_glog.o

all: $(TARGET1)
	rm -f *.o

$(TARGET1) : $(OBJ1)
	$(GCC) -g -o $@ $^ $(LIBDIR) $(INCLUDEDIR)

%.o	: %.cpp
	$(GCC) $(CPPFLAGS) -c $< -o $@ $(INCLUDEDIR)

clean:
	rm -f $(TARGET1)
	rm -f *.o


