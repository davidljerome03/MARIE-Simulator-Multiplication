# MARIE-Simulator-Multiplication
Authors: David Jerome | Korey Mena

This project provides a tiny virtual machine that can execute simple programs in the style of
The Marie Coding language

### Features

**Simple Instruction Set:** The VM supports a small set of instructions, making it easy to learn and understand. They are listed as follows and are read first in the elf.txt file:

| Opcode | Operation |
|--------|-----------|
| 1      | LOAD      |
| 2      | ADD       |
| 3      | STORE     |
| 4      | SUB       |
| 5      | IN        |
| 6      | OUT       |
| 7      | HALT      | 
| 8      | JMP       | 
| 9      | SKIPZ     |
| 10     | SKIPG     |
| 11     | SKIPL     |



**Modular design:** The VM is designed to be modular, allowing for easy extension and customization.
**Well-documented:** The code is well-documented, making it easy to understand and maintain.

### FILES
* elf.txt
* tinyvm.c

### Instructions


1. Download the files and make sure elf.txt and tinyvm.c are in the same directory before running. Currently, the elf.txt file is configured to perform a simple multiplication between input 1 and input 2.

2. Run the program once everything is set up correctly. During Input a Vaule 1 & 2 the user may put any two numbers they wish to multiply together, for this project we will be doing 2 * 3 so input those two numbers first.

3. After the first TWO inputs, there will be a third one asked. **Please ensure that this is set to 1**. This will be needed for the loops to run correctly.

