# CXX = g++ --std=c++17 -O2 -lm -g 
CXX = clang++ --std=c++17 -O2 -lm -g 
OUT = obj/compiler
OBJ = obj/*.o
MAIN = src/compiler.cpp
SCANNER = src/FBRawCode/scanner.l
SCANNERC = src/FBGenerateCode/lex.yy.c
PARSER = src/FBRawCode/parser.y
PARSERC = src/FBGenerateCode/parser.tab.c
MYTREE = src/MyTree/MyTree.cpp
TOKEN = src/Token/Token.cpp
GENERATE_DIR = src/FBGenerateCode
OBJ_DIR	= obj
ASM_DIR = asm
BACKANA = src/back/*.cpp
SYMBOLTABLE = src/back/SymbolTable/*.cpp
FUNTESTSCRIPT = script/funtest.sh
PERTESTSCRIPT = script/pertest.sh
build: $(OUT)

run: $(OUT) $(ASM_DIR)
	./$(OUT) ./testcode/testcase.sy -S -o $(ASM_DIR)/testcase.s

debug: $(OUT) $(ASM_DIR)
	./$(OUT) ./testcode/testcase.sy -S -o $(ASM_DIR)/testcase.s -debug -O1

# funtest: $(OUT) $(FUNTESTSCRIPT) $(ASM_DIR)
# 	chmod +x ./$(FUNTESTSCRIPT)
# 	./$(FUNTESTSCRIPT)

# pertest: $(OUT) $(PERTESTSCRIPT) $(ASM_DIR)
# 	chmod +x ./$(PERTESTSCRIPT)
# 	./$(PERTESTSCRIPT)

clean:
	rm -rf $(OBJ_DIR) $(ASM_DIR)

clean_all:
	rm -rf $(GENERATE_DIR) $(OBJ_DIR) $(ASM_DIR)

$(OUT): $(MAIN) $(SCANNERC) $(PARSERC) $(OBJ)
	$(CXX) -o $(OUT) $(OBJ) $(MAIN) $(BACKANA) $(SYMBOLTABLE) $(SCANNERC) $(PARSERC)

$(SCANNERC): $(SCANNER) $(PARSERC)
	flex --outfile=src/FBGenerateCode/lex.yy.c $< 

$(PARSERC): $(PARSER) $(GENERATE_DIR)
	bison -vdty $< --file-prefix=src/FBGenerateCode/parser

lex: $(SCANNERC)

bison: $(PARSERC)

$(GENERATE_DIR): 
	$(shell if [ ! -e $(GENERATE_DIR) ];then mkdir -p $(GENERATE_DIR); fi)

$(OBJ_DIR):
	$(shell if [ ! -e $(OBJ_DIR) ];then mkdir -p $(OBJ_DIR); fi)

$(ASM_DIR):
	$(shell if [ ! -e $(ASM_DIR) ];then mkdir -p $(ASM_DIR); fi)
	
$(OBJ) : $(MYTREE) $(TOKEN) $(OBJ_DIR)
	$(CXX) -o obj/MyTree.o -c $(MYTREE)
	$(CXX) -o obj/Token.o -c $(TOKEN)
