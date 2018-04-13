gcc -c -o Benchmark.o Benchmark.c -lm -std=c99 
gcc -c -o Datacreator.o Datacreator.c -lm -std=c99 
gcc -c -o TUI.o TUI.c -lm -std=c99 
gcc -c -o Algorithm.o Algorithm.c -lm -std=c99 
gcc -c -o Dataorganizer.o Dataorganizer.c -lm -std=c99 
gcc -c -o main.o main.c -lm -std=c99 
gcc -o main Benchmark.o Datacreator.o TUI.o Algorithm.o Dataorganizer.o main.o -lm -std=c99
