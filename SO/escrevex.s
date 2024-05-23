/*
* \author: Éder Augusto Penharbel
* \date: February, 2022
* \version: February, 2022
*/

# generate 16-bit code
.code16 			   
# executable code location
.text 				   

.globl _start

# entry point
_start:				    

    # character to print
    movb $'1', %al
    # bios service code to print

    movb $0x0e, %ah
    # bios service (interrupt) 
    int  $0x10	


    movb $0xa0, %al

    movw $0x1f6, %dx
    out %al, %dx        #Mandar 0xA0 para a porta 0x1F6
    
    xorb %al, %al       #Zerar al

    movw $0x1f2, %dx    #Zerar 0x1F2 até 0x1F5 (Portas de IO LBAlo, LBAmid, LBAhi)
    out %al, %dx

    movw $0x1f3, %dx
    out %al, %dx

    movw $0x1f4, %dx
    out %al, %dx

    movw $0x1f5, %dx
    out %al, %dx

    movb $0xec, %al     #Mandar o comando IDENTIFY(0xEC) para 
loop:    
    movw $0x1f7, %dx    #Porta de comando de IO(0x1F7)
    out %al, %dx
    inb %dx, %al        #Resultado
    shrb $7, %al
    xorb $1, %al
    jz loop


    movb $'2', %al
    # bios service code to print

    movb $0x0e, %ah
    # bios service (interrupt) 
    int  $0x10	


    #Lendo LBAhi LBAmid
    movw $0x1f4, %dx
    inb %dx, %al  
    cmp $0, %al
    jne msg_erro

     movw $0x1f5, %dx
    inb %dx, %al  
    cmp $0, %al
    jne msg_erro

    #pooling para descobrir se a leitura esta pronta
loop_test:
    movw $0x1f7, %dx
    inb %dx, %al
    movb %al, %bl
    #Testando o flag DRQ qie indica que os dados estão prontos
    andb $0x8 , %bl
    jnz leitura_dado

    movb %al, %bl
    #Testando o flag ERR qie indica que erro
    andb $0x1 , %bl
    jnz msg_erro
    jmp loop_test

leitura_dado:

    movb $0xff, %cl
    movw $0xb800, %ax 
    movw %ax, %ds
    movw $0, %bx

leitura_dado_loop:
    movw $0x1f0, %dx
    in %dx, %ax
    movb %al, (%bx)
    incw %bx
    incw %bx
    movb %ah, (%bx)
    incw %bx
    incw %bx
    dec %cl
    jnz leitura_dado_loop

    movb $'3', %al
    # bios service code to print

    movb $0x0e, %ah
    # bios service (interrupt) 
    int  $0x10

hd_leitura:
    # Enviando E para master e 0 para os 4 msb do lba
    movb $0xE0, %al
    movw $0x1f6, %dx
    out %al, %dx

    # Mandar byte nulo para 1F1

    xorb %al, %al       #Zerar al
    movw $0x1f1, %dx
    out %al, %dx        #Mandar 0xA0 para a porta 0x1F6

    # Ler apenas 1 sector count

    movb $0x1, %al
    movw $0x1f2, %dx
    out %al, %dx        #Mandar 0xA0 para a porta 0x1F6

    # Mandar 8 bits lsb para 1F3

    xorb %al, %al       #Zerar al
    movw $0x1f3, %dx
    out %al, %dx        #Mandar 0xA0 para a porta 0x1F6

    # Mandar proximos 8 bits para 1F4

    xorb %al, %al       #Zerar al
    movw $0x1f4, %dx
    out %al, %dx        #Mandar 0xA0 para a porta 0x1F6

     # Mandar proximos 8 bits para 1F5

    xorb %al, %al       #Zerar al
    movw $0x1f5, %dx
    out %al, %dx        #Mandar 0xA0 para a porta 0x1F6

    # Enviar comando ler setores em 1F7

    movb $0x20, %al
    movw $0x1f7, %dx
    out %al, %dx        #Mandar 0xA0 para a porta 0x1F6


    #pooling para descobrir se a leitura esta pronta
hd_leitura_loop_test:
    movw $0x1f7, %dx
    inb %dx, %al
    movb %al, %bl
    #Testando o flag DRQ qie indica que os dados estão prontos
    andb $0x8 , %bl
    jnz hd_leitura_ler_dado

    movb %al, %bl
    #Testando o flag ERR qie indica que erro
    andb $0x1 , %bl
    jnz msg_erro
    jmp hd_leitura_loop_test

hd_leitura_ler_dado:

    movb $'4', %al
    # bios service code to print

    movb $0x0e, %ah
    # bios service (interrupt) 
    int  $0x10

    movb $0xff, %cl
    movw $0xb800, %ax 
    movw %ax, %ds
    movw $0, %bx

hd_leitura_dado_loop:
    movw $0x1f0, %dx
    in %dx, %ax
    movb %al, (%bx)
    incw %bx
    incw %bx
    movb %ah, (%bx)
    incw %bx
    incw %bx
    dec %cl
    jnz hd_leitura_dado_loop

    movb $'5', %al
    # bios service code to print

    movb $0x0e, %ah
    # bios service (interrupt) 
    int  $0x10



    hlt


msg_erro:
     movb $'!', %al
    # bios service code to print

    movb $0x0e, %ah
    # bios service (interrupt) 
    int  $0x10
    # mov to 510th byte from 0 pos
    . = _start + 510	    
    
    # MBR boot signature 
    .byte 0x55		        
    # MBR boot signature 
    .byte 0xaa		        
