PROJECT = prj4
COURSE = cs220f14

TARGET = fn-trace

CPPFLAGS = -I $(HOME)/$(COURSE)/include
CFLAGS = -g -Wall -m32 -std=c99

LIBDIR = $$HOME/$(COURSE)/lib
LIB = cs220

LDFLAGS = -ldl -L $(LIBDIR) -l$(LIB) -l BeaEngine -m32

SRC_FILES = \
  fn-trace.c \
  fn-trace.h \
  main.c \
  x86-32_lde.c \
  x86-32_lde.h \
  Makefile \
  README

OBJS = \
  fn-trace.o \
  main.o \
  x86-32_lde.o 

$(TARGET):	$(OBJS)
		$(CC) $(OBJS) $(LDFLAGS) -o $@

clean:		
		rm -f $(OBJS) $(TARGET) fns fns.o *~

$(PROJECT).tar.gz \
dist:		$(SRC_FILES)
		tar -cvf $(PROJECT).tar $(SRC_FILES)
		gzip -f $(PROJECT).tar
