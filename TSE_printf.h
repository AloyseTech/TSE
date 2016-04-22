//
//  TSE_printf.h
//  
//
//  Created by Théo Meyer on 20/04/2016.
//
//

#ifndef _TSE_printf_h
#define _TSE_printf_h
#include <Arduino.h>
#include <cstdarg>

void TSEprintf(char *format, ...) {
    va_list pa;
    int n;
    char *s, c;
    float f;
    
    va_start(pa, format);
    while (*format != '\0') {
        if ( *format == '%' ) {
            switch (*++format) {
                case '%' : SerialUSB.print("%"); break;
                case 'c' : /* affichage d'un caractère */
                    c = va_arg(pa, char);
                    SerialUSB.print(c);
                    break;
                case 'd' : /* affichage d'un entier */
                    n = va_arg(pa, int);
                    SerialUSB.print(n);
                    break;
                case 'f' : /* affichage d'un float */
                    f = va_arg(pa, float);    /* !!!!! */
                    SerialUSB.print(f);
                    break;
                case 's' : /* affichage d'une chaîne */
                    s = va_arg(pa, char *);
                    SerialUSB.print(s);
                    break;
            } /* end switch */
        }
        else 
            SerialUSB.print(char(*format));
        format++;
    }   
    va_end(pa);
}

#endif
