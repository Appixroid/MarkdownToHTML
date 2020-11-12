CC=g++
CFLAGS=-Wall
LDFLAGS=-lcurl
EXEC=mdtohtml

${EXEC}: main.o ioutils.o markdownconverter.o
	${CC} bin/*.o ${LDFLAGS} -o ${EXEC}

main.o: src/Main.cpp
	${CC} -c src/Main.cpp ${CFLAGS} -o bin/main.o
	
ioutils.o: src/IOUtils.cpp
	${CC} -c src/IOUtils.cpp ${CFLAGS} -o bin/ioutils.o
	
markdownconverter.o: src/MarkdownConverter.cpp
	${CC} -c src/MarkdownConverter.cpp ${CFLAGS} -o bin/markdownconverter.o	
	
clean:
	rm -f bin/*.o ${EXEC}
