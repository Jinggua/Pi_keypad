/*
 * File: keyled.c
 * Author: Yao
 * Date: 30 Jan 2026
 * Description: Controlling Num Lock, Caps Lock, Scroll Lock Led with keypad
 * */
#include <stdio.h>
#include <linux/kd.h> // KDSETLED
#include <sys/ioctl.h>
#include <unistd.h> // sleep

int main () {
    // int keybitson = 0x7;
    // int keybitsoff = 0x0;
    int ledarr[] = {0x00, 0x01, 0x04, 0x05, 0x02, 0x03, 0x06, 0x07}; // led pattern
    int num;
    printf("Enter a number from 0 to 7 \n");  
    scanf("%d",&num);
    if(num < 0 || num > 7) {
        printf("Invalid input");
    } else {
        ioctl (1, KDSETLED, ledarr[num]);
    }
    return 1;
}

