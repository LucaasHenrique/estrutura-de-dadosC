#include <stdio.h>

#ifndef _genericlist_h_
#define _genericlist_h_

struct retangulo {
    float h;
    float b;
};

typedef struct retangulo Retangulo;

struct triangulo {
    float b;
    float h;
};

typedef struct triangulo Triangulo;

struct circulo {
    float r;
};

typedef struct circulo Circulo;

#endif
