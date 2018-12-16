all: directories pid execl fork atexit wait

directories:
	 mkdir -p bin

pid: 
	gcc pid.c -o bin/pid

execl: pid
	gcc execl.c -o bin/execl

fork: pid
	gcc fork.c -o bin/fork

atexit:
	gcc atexit.c -o bin/atexit

wait:
	gcc wait.c -o bin/wait
