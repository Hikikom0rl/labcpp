#CC_DIR=./compiler/xpack-riscv-none-elf-gcc-14.2.0-3/bin
CC_DIR=./compiler/xpack-riscv-none-elf-gcc-13.3.0-2/bin
CC=$(CC_DIR)/riscv-none-elf-gcc
#CC=$(CC_DIR)/riscv-none-elf-g++

CFLAGS_PROJ=-I. -O1 -Wall -Wextra
CFLAGS_RISCV_COMPILE=-march=rv32i_zicsr -mabi=ilp32 -mno-div -Wl,--gc-sections 
CFLAGS_RISCV_LINK= $(CFLAGS_RSICV_COMPILE) -nostartfiles -T linker_script.ld

CDECOMP=$(CC_DIR)/riscv-none-elf-objdump
CDECOMP_FLAGS= 

CEXPORT=$(CC_DIR)/riscv-none-elf-objcopy
CEXPORT_FLAGS=-O verilog --verilog-data-width=4

all: compiled_result.elf 

compiled_result.elf: maths.o main.o startup.o vga.o io_vga_ps2.o ps2.o riscv_string.o
	$(CC) $(CFLAGS_RISCV_LINK) $^ $(CFLAGS_PROJ) -o $@

main.o: main.c
	$(CC) -c $(CFLAGS_RISCV_COMPILE) $(CFLAGS_PROJ)  $^ -o $@

maths.o: maths.c
	$(CC) -c $(CFLAGS_RISCV_COMPILE) $(CFLAGS_PROJ)  $^ -o $@

io_vga_ps2.o: io_vga_ps2.c
	$(CC) -c $(CFLAGS_RISCV_COMPILE) $(CFLAGS_PROJ)  $^ -o $@

riscv_string.o: riscv_string.c
	$(CC) -c $(CFLAGS_RISCV_COMPILE) $(CFLAGS_PROJ)  $^ -o $@

vga.o: vga.c
	$(CC) -c $(CFLAGS_RISCV_COMPILE) $(CFLAGS_PROJ)  $^ -o $@

ps2.o: ps2.c
	$(CC) -c $(CFLAGS_RISCV_COMPILE) $(CFLAGS_PROJ)  $^ -o $@


startup.o: startup.S
	$(CC) -c $(CFLAGS_RISCV_COMPILE) $^ -o $@

decompile_full: compiled_result.elf
	$(CDECOMP) $(CDECOMP_FLAGS) -D $^ > $@_code.S

decompile_instruction: compiled_result.elf
	$(CDECOMP) $(CDECOMP_FLAGS) -d $^ > $@_code.S

export_verilog: init_data.mem init_instr.mem

init_data.mem: compiled_result.elf
	$(CEXPORT) $(CEXPORT_FLAGS) -j .data -j .bss -j .sdata $^ $@ 

init_instr.mem: compiled_result.elf
	$(CEXPORT) $(CEXPORT_FLAGS) -j .text $^ $@ 


.PHONY clean:

clean:
	rm -f *.o *.elf decompile* *.mem
