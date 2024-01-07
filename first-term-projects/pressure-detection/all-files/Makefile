#makefile for CORTEX M3


#this line is for the error that doesn't recognize make 
SHELL=C:/Windows/System32/cmd.exe


CC=arm-none-eabi-
#added -mthumb to CFLAGS for error: target CPU does not support ARM mode -mthumb or include PATH of stm32 ide ( which has  arm-none-eabi- included )
CFLAGS= -gdwarf-2 -g -mcpu=cortex-m3 
INCS= -I .
LIBS=
SRC= $(wildcard *.c)
OPJ= $(SRC:.c=.o)
#As= $(wildcard *.s)
#AsOPJ= $(As:.s=.o)

projectname=pressure_detect


all: $(projectname).bin
	@echo "build is done"
	ls
	
%.o: %.c
	$(CC)gcc.exe -c $(CFLAGS) $(INCS) $< -o $@

	
$(projectname).elf: $(OPJ) 
	$(CC)ld.exe -T linker_script.ld  $(LIBS)  $(OPJ)  -o $@ -Map=output.map
	cp $(projectname).elf $(projectname).axf

$(projectname).bin: $(projectname).elf 
	$(CC)objcopy.exe -O binary $<  $@
	
clean:
	rm *.elf *.bin

clean_all: 
	rm *.elf *.bin *.o 
	ls
	
dumpelf:
	arm-none-eabi-objdump.exe: -h  $(projectname).elf 


	

	