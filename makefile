all: directories pid execl fork

directories:
	 mkdir -p bin

pid: 
	gcc pid.c -o bin/pid

execl: pid
	gcc execl.c -o bin/execl

fork: pid
	gcc fork.c -o bin/fork
