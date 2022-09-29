all: clean broken memleaks fixed

broken: 
	gcc gdb_lab.c csbrk.o -o _broken

memleaks: 
	gcc gdb_lab_memleaks.c csbrk.o -o _memleaks

fixed: 
	gcc gdb_lab_allfixed.c csbrk.o -o _fixed

clean: 
	rm -f _broken _memleaks _fixed