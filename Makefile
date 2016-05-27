INCLUDEDIR= \
		 -I ./include \
		 -I ./src

LIBDIR=	\
		-lcrypto -lpthread -lm -lstdc++

GCC = g++

SRCWILD    = $(wildcard src/*.cc)
OBJS       = $(patsubst %.cc, %_release.o, $(SRCWILD))
LIBS       = libglog.a

all : clean output

CPPFLAGS       = -g -finline-functions -Wall -Winline -pipe -Wno-deprecated -Wunused-variable

$(LIBS) : $(OBJS)
	ar rcv $@ $^


clean:
	rm -rf $(OBJS)
	rm -fr $(LIBS)
	rm -fr output

output: $(LIBS)
	mkdir output
	mkdir output/include
	cp -r include/glog output/include
	mkdir output/lib
	mv $(LIBS) output/lib

src/%_release.o	: src/%.cc
	$(GCC) $(CPPFLAGS) -c $< -o $@ $(INCLUDEDIR)

