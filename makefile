all: directories pid execl

directories:
	 mkdir -p bin

pid: 
	gcc pid.c -o bin/pid

execl: pid
	gcc execl.c -o bin/execl
