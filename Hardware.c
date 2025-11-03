#include "Hardware.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void write_File(const char *path, const char *value){
    FILE *fp = fopen(path, "w");
    if (fp == NULL) {
        perror("Error al abrir archivo");
        exit(1);
    }
    fprintf(fp, "%s", value);
    fclose(fp);
}

static char read_File(const char *path){
    FILE *fp = fopen(path, "r");
    if (fp == NULL) {
        perror("Error al leer archivo");
        exit(1);
    }
    char value;
    fscanf(fp, "%c", &value);
    fclose(fp);
    return value;
}

static void export_pin(const char *pin){
    write_File("/sys/class/gpio/export", pin);
}

void release_pin(const char *pin){
    write_File("/sys/class/gpio/unexport", pin);
}

static void set_pin(const char *pin, const char *dir){
    char path[50]="/sys/class/gpio/gpio";
    strcat(path, pin);
    strcat(path, "/direction");
    write_File(path, dir);
}

void write_pin(const char *pin, const char*state){
    char path[50]="/sys/class/gpio/gpio";
    strcat(path, pin);
    strcat(path, "/value");
    write_File(path, state);
}

char read_pin(const char *pin){
    char path[50]="/sys/class/gpio/gpio";
    strcat(path, pin);
    strcat(path, "/value");
    char lecture=read_File(path);
    return lecture;
}

void init_pin(const char *pin, const char *dir){
    export_pin(pin);
    set_pin(pin, dir);
}