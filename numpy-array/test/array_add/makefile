include ../variables.mk

TARGETS = main template-test

all: $(TARGETS)

array_add.o: $(C_SRC_DIR)/array_add.c
	$(CC) $^ -I$(INCLUDE_DIR) -o $@ -c

main: array_add.o main.c
	$(CC) $^ -o $@ -I$(INCLUDE_DIR)

template-test: template-test.cc $(C_SRC_DIR)/array_add.cc
	$(CXX) $^ -o $@ -I$(INCLUDE_DIR)

clean:
	rm -rf *.o $(TARGETS)

