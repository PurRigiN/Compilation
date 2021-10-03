XX = g++
OUT = compiler
MAIN = main.cpp
SCANNER = scanner.l
PARSER = parser.y

build: $(OUT)

run: $(OUT)
	./$(OUT) ./testcase.sy

clean:
	rm -f *.o lex.yy.c y.tab.c y.tab.h y.output $(OUT)

$(OUT): $(MAIN) lex.yy.c y.tab.c
	$(XX) -o $(OUT) $(MAIN)

lex.yy.c: $(SCANNER) y.tab.c
	flex $<

y.tab.c: $(PARSER)
	bison -vdty $<

lex: lex.yy.c