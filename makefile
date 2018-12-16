all: directories pid

directories:
	 mkdir -p bin

pid: 
	gcc pid.c -o bin/pid
