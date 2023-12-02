all: a.exe
a.exe:
	gcc -std=c99 -Wall -Wextra -Werror -Ofast main.c -o a.exe

run: a.exe
	./a.exe `python3 -c "for line in open('input').read().split('\n'): print(line.strip(), sep=' ', end=' ')"`
