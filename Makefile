regular:
	gcc -o tinker.out consume_memory.c node.c tmalloc.c

tinker:
	gcc -D TINKER -o tinker.out consume_memory.c node.c tmalloc.c

debug_regular:
	gcc -g -o debug.out consume_memory.c node.c tmalloc.c

debug_tinker:
	gcc -g -D TINKER -o debug.out consume_memory.c node.c tmalloc.c

run:
	ulimit -S -v 10240; ./tinker.out 10

run_debug:
	ulimit -S -v 10240; gdb ./debug.out 10
