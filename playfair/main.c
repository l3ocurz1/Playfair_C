#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "controller.h"


void printInfo() {
    printf("Inserire i seguenti comandi\n");
    printf("./playfair encode keyfile <outputdir> file1 ... filen\n");
    printf("./playfair decode keyfile <outputdir> file1 ... filen\n");

}

int main(int argc, char *argv[]) {
    if (argc < 5) {
        printf("I parametri da inserire sono 4\n");
        printf("Parametri inseriti %d\n", argc - 1);
        printInfo();
        return -1;
    }

    if (strcmp(argv[1], "encode") == 0) {
        setUpData(argc, argv, true);
        printf("Il messaggio è stato cifrato correttamente\n");
        return 0;
    }

    if (strcmp(argv[1], "decode") == 0) {
        setUpData(argc, argv, false);
        printf("Il messaggio è stato decifrato correttamente\n");
        return 0;
    }

    printf("Comando sconosciuto\n");
    printInfo();
}
