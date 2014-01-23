#include "plasm.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(void) {
    // init assembler with space for up to 4096 bytes
    plasm as;
    plasm_init(&as, 4096);
    
    // remember starting address of the function
    int (*func)() = (int(*)())plasm_get_current_ptr(&as);
    
    // set return value to 42
    plasm_put_op(&as, MOV, EAX, IMM32(42));

    // encode jump and remember address of jump offset so we can set it later
    int8_t *reloff_ptr;
    plasm_put_op(&as, JMP, VALUE_PTR(REL8(0), &reloff_ptr));
    // jmp_base is the address to which the rel offset is added when jumping
    uint8_t *jmp_base = plasm_get_current_ptr(&as);
    
    // set return value to 23 (we want to jump over this)
    plasm_put_op(&as, MOV, EAX, IMM32(23));

    // set the jumps relative offset to this point in the code
    *reloff_ptr = plasm_get_current_ptr(&as)-jmp_base;
    
    // return
    plasm_put_op(&as, RET);

    // change access from writable to executable
    plasm_protect(&as, 1);
    
    // dump the binary to a file and disassemble it
    FILE *fp = fopen("out.bin", "wb");
    fwrite(as.buffer, 1, as.position, fp);
    fclose(fp);
    if(system("ndisasm -b 64 out.bin")) {
        printf("system returned != 0\n");
    }

    // call the function we assembled (should print 42)
    printf("\n\n%d\n", func());
    
    // free the assemblers store
    plasm_free(&as);
    return 0;
}
