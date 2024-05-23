#include "lerHd.h"
#include "printf.h"

void verificar_hd(){

    printc('1');

    //Mandar 0xA0 para a porta 0x1F6
    outb(0xa0, 0x1f6);

    //Zerar 0x1F2 até 0x1F5 (Portas de IO LBAlo, LBAmid, LBAhi)
    outb(0x0, 0x1f2);

    outb(0x0, 0x1f3);

    outb(0x0, 0x1f4);

    outb(0x0, 0x1f5);

    int res;

    while (1) {
        //Porta de comando de IO(0x1F7)
        outb(0xec, 0x1f7);

        //??
        res = inb(0x1f7);
        if (((res & 1) ^ 1) != 0) {
            break;
        }
    }

    printc('2');

    //Lendo LBAhi e LBAmid, se forem diferentes de 0, erro (por que?)
    res = inb(0x1f4);
    if (res != 0x0){
        printf("Erro 1");
    }

    res = inb(0x1f5);
    if (res != 0x0){
        printf("Erro 2");
    }

    //pooling para descobrir se a leitura esta pronta
    while (1) {
        res = inb(0x1f7);
        //Testando o flag DRQ qie indica que os dados estão prontos
        if ((0x8 & res) != 0) {
            break;
        }

        //Testando o flag ERR qie indica que erro
        if ((0x1 & res) != 0) {
            printf("Erro 3");
            break;
        }
    }

    printf("3");

    // Leitura HD

    outb(0xe0, 0x1f6);

    //ignorado
    outb(0x0, 0x1f1);

    //quantidade de setores
    outb(0x1, 0x1f2);

    //LBAlow
    outb(0x0, 0x1f3);

    //LBAMid
    outb(0x0, 0x1f4);

    //LBAhigh
    outb(0x0, 0x1f5);

    //read sector command
    outb(0x20, 0x1f7);

    //pooling
    while (1) {
        res = inb(0x1f7);
        if ((0x8 & res) != 0) {
            break;
        }

        if ((0x1 & res) != 0) {
            printf("Erro 4");
            break;
        }
    }

    printc('4');

    while (1) {
        res = inb(0x1f0);
        printf(res);
    }




}