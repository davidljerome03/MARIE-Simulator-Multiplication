#include <stdio.h>
#include <stdlib.h>
#define INPUT_FILE_NAME "elf.txt"

#define IM_SIZE 128
#define DM_SIZE 10

typedef struct //creates a struct for the instruction register
{ 
    int op;
    int addr;
} InstructionRegister;

int IM[IM_SIZE]; //instruction memory
int DM[DM_SIZE] = {0}; //data memory
int PC = 0; //program counter
int A = 0; //accumulator
InstructionRegister IR; //instruction register
int running = 1; //flag to keep the VM running

void run_vm(); //function prototypes
void fetch(); //function prototypes
void execute(); //function prototypes
int readFile(const char *filename); //function prototypes

int main() //main function
{
    if (!readFile(INPUT_FILE_NAME)) //reads the file and checks if it was successful
    { 
        printf("Error reading file\n");
        return 1;
    }
    run_vm(); //runs the VM
}

int readFile(const char *filename) //reads the file and stores the instructions in the instruction memory
{ 
    FILE *file = fopen(filename, "r");
    
    if (file == NULL)  //checks if the file was opened successfully
    { 
        printf("Error opening file\n");
        return 0;
    }
    
    int i = 0;
    while (fscanf(file, "%d %d", &IM[i], &IM[i+1]) == 2) //reads the instructions and stores them in the instruction memory
    { 
        i+=2;
    }
    
    fclose(file);
    return 1;
}
void fetch() // fetches the next instruction from the instruction memory and stores it in the instruction register
{
    IR.op = IM[PC]; //stores the operation code in the instruction register
    IR.addr = IM[PC + 1]; //stores the address in the instruction register
    PC += 2; //increments the program counter
}

void run_vm() //runs the VM
{ 
    printf("Initial state:\n");
    int runOff = 0;
    printf("PC = %d | A = NULL | DM = [", PC); //prints the initial state of the VM
    for(int i = 0; i < DM_SIZE - 1; i++) //prints the data memory
    {
        printf("%d", DM[i]);
        runOff = i;
        if (i < DM_SIZE - 1) printf(",");
    }
    printf("%d", DM[runOff + 1]);
    printf("]\n\n");
    
    while (running) //keeps the VM running until the halt instruction is executed
    {
        
        fetch(); //fetches the next instruction
        execute(); //executes the instruction
        
        if(!running) //checks if the halt instruction was executed
        {
            break;
        }
        
        
        printf("PC = %d | A = %d | DM = [", PC, A); //prints the state of the VM after each instruction is executed
        for(int i = 0; i < DM_SIZE - 1; i++)
        {
            printf("%d, ", DM[i]);
            runOff = i;
        }
        printf("%d", DM[runOff + 1]);
        printf("]\n\n");
        
    }
    printf("End of Program."); //prints the end of the program
}
void execute() //executes the instruction stored in the instruction register
{
    switch(IR.op) //switch statement to execute the instruction based on the operation code
    {
        case 1: //load
        printf("LOAD <%d>\n", IR.addr);
        A = DM[IR.addr];
        break;

        case 2: //add
        printf("ADD <%d>\n", IR.addr);
        A += DM[IR.addr];
        break;

        case 3: //store
        printf("STORE <%d>\n", IR.addr);
        DM[IR.addr] = A;
        break;

        case 4: //sub
        printf("SUB <%d>\n", IR.addr);
        A -= DM[IR.addr];
        break;

        case 5: //in
        printf("IN <5>\n");
        printf("Input a value: ");
        scanf("%d", &A);
        printf("\n");
        break;

        case 6: //out
        printf("OUT <6>\n");
        printf("Result is: %d\n\n", A);
        break;

        case 7: //halt
        printf("HALT\n");
        running = 0;
        break;

        case 8: //jmp
        printf("JMP <%d>\n", IR.addr);
        PC = IR.addr;
        break;

        case 9: //skipz
        printf("SKIPZ\n");
        if(A == 0) PC += 2;
        break;

        case 10: //skipg
        printf("SKIPG\n");
        if(A > 0) PC += 2;
        break;

        case 11: //skipl
        printf("SKIPL\n");
        if(A < 0) PC += 2;
        break;
    }
}
