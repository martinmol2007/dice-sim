DIR_TO_CHECK = out

program: main.cc src/dado.cc
	mkdir -p $(DIR_TO_CHECK)
	g++ main.cc src/dado.cc -o program.exe

clean:
	rm -r out/*
