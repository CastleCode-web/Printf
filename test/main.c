#include <limits.h>
#include <stdio.h>
#include "main.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
        /**int len;
         * int len2;
         * unsigned int ui;
         * void *addr;
         */

        _printf("Let's try to printf a simple sentence.\n");
        _printf("Percent: [%%]\n");
        printf("Let's try to printf a simple sentence.\n");
        printf("Percent: [%%]\n");
        _printf("Character: [%c] House\n", 'H');
        printf("Character: [%c] House\n", 'H');
        _printf("String:[%s]\n", "I am a string !");
        printf("String:[%s]\n", "I am a string !");
        _printf("No percentage: %z, %v, %c, %s\n", 'A', "Feyi");
        printf("No percentage: %v, %v, %c, %s\n", 'A', "Feyi");
        _printf(NULL);
        printf(NULL);
        _printf("Sheeda %");
        printf("Sheeda %");
        _printf("%s\n", "NULL");
        printf("%s\n", "NULL");
        _printf("%s\n", NULL);
        printf("%s\n", NULL);

        return (0);
}
