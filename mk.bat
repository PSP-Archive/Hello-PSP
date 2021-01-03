c:\ps2dev\gcc\ee\bin\ee-gcc -march=r4000 -g -mgp32 -mlong32 -c hellopsp.c
c:\ps2dev\gcc\ee\bin\ee-gcc -march=r4000 -g -mgp32 -mlong32 -c pg.c
c:\ps2dev\gcc\ee\bin\ee-gcc -march=r4000 -g -mgp32 -c -xassembler -O -o startup.o startup.s
c:\ps2dev\gcc\ee\bin\ee-ld -O0 startup.o hellopsp.o pg.o -M -Ttext 8900000 -q -o out > hellopsp.map
outpatch
@echo you got outp as psp elf
