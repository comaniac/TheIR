BIN_PATH  = bin
PROJ_PATH = src/main
TEST_PATH = src/test

all: compile

compile:
	make -C $(PROJ_PATH)

install:
	make -C $(PROJ_PATH) install

test:
	make -C $(TEST_PATH)/
	make -C $(TEST_PATH)/ test

clean: clean_bin
	make -C $(PROJ_PATH) clean
	make -C $(TEST_PATH) clean

clean_bin:	
	rm -f $(BIN_PATH)/*
