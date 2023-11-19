#include <stdio.h>

void Metropolis(char* input) {
    int val;
    int angka1;
    int angka2;
    
    val = sscanf(input,"%d %d",&angka1,&angka2);
    if (val < 2) {
        illegal_move();
    }
    
    switch(angka1) {
        case 0:
            val = 0x750;
            val = val - 0x3a8;
            break;
        case 1:
            val = 0x161;
            val = val - 0x161;
            break;
        case 2:
            val = 0x0 ;
            val = val - 0x161;
            val = val - 0x3a8;
            break
        case 4:
            val = 0x114;
            val = val + 0x18a
            val = val - 0x3a8;
            break;
        case 5:
            val = 0x0;
            val = val + 0x18a;
            val = val - 0x3a8;
            break;
        case 6:
            val = 0xfffffe76;
            val = val + 0x2ac;
            val = val - 0x18a;
            val = val - 0x3a8;
            break;
        case 7:
            val = 0xfffff8b0;
            val = val - 0x3a8;
            break;
        case 8:
            val = 0xffffff86;
            val = val - 0x3a8;
            break;
        default:
            val = 0;
            illegal_move();
    }

    val = val - 0x3a8;

    if (val - 0x3a8 != angka2) {
        illegal_move();
    }
    
    return;
}

/* 2 -266 */