CXX = g++  -g -Wall -std=c++14
OUT = obj/compiler
OBJ = obj/*.o
MAIN = src/main.cpp
SCANNER = src/FBRawCode/scanner.l
PARSER = src/FBRawCode/parser.y
MYTREE = src/MyTree/MyTree.cpp
TOKEN = src/Token/Token.cpp
GENERATE_DIR = src/FBGenerateCode
OBJ_DIR	= obj

build: $(OUT)

run: $(OUT)
	./$(OUT) ./testcode/testcase.sy

clean:
	rm -f  src/FBGenerateCode/* $(OUT) obj/*

$(OUT): $(MAIN) lex.yy.c y.tab.c $(OBJ)
	$(CXX) -o $(OUT) $(OBJ) $(MAIN)

lex.yy.c: $(SCANNER) $(GENERATE_DIR) y.tab.c 
	flex --outfile=src/FBGenerateCode/lex.yy.c $< 

y.tab.c: $(PARSER) $(GENERATE_DIR)
	bison -vdty $< --file-prefix=src/FBGenerateCode/parser

lex: lex.yy.c

bison: y.tab.c

$(GENERATE_DIR): 
	$(shell if [ ! -e $(GENERATE_DIR) ];then mkdir -p $(GENERATE_DIR); fi)

$(OBJ_DIR):
	$(shell if [ ! -e $(OBJ_DIR) ];then mkdir -p $(OBJ_DIR); fi)


$(OBJ) : $(MYTREE) $(TOKEN) $(OBJ_DIR)
	$(CXX) -o obj/MyTree.o -c $(MYTREE)
	$(CXX) -o obj/Token.o -c $(TOKEN)
