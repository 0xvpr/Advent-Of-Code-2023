all: a.exe
a.exe: main.c
	gcc -std=c99 -Wall -Wextra -Werror -Ofast main.c -o a.exe

run: a.exe
	chmod +x run.py
	./run.py | awk '{sum+=$$1} END {print sum}'
