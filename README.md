![Hcore logo](img/hcore.png)

Hcore is an amateur emulator of a 16-bit microprocessor with 512 bytes of RAM (you can edit this value using a macro in the hcore.h source file). There are several basic opcodes for writing small programs for this microprocessor. To perform arithmetic operations, you need to load the values of the two operands into the registers.





------------------------
ADD register 1, register 2
------------------------
this is the basic addition opcode

------------------------
SUB register 1, register 2
________________________
this is the basic subtraction opcode

NOP is a stub opcode that does nothing.

_______________________
MOV register, value
_______________________
the opcode for moving a value to a register.





For now, you can write programs inside the source code of the microprocessor emulator, but soon I will write a compiler for it.



Sincerely, etherkabel!
