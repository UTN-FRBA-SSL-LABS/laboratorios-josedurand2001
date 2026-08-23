#include <stdio.h>
#include "../src/carrito.h"
#include "minunit/minunit.h"

void test_compra_con_descuento(void) {
    printf("\n[compra con descuento]\n");
    Carrito c;
    carrito_init(&c);
    Producto p = {"Pan", 200, 3};
    carrito_agregar(&c, p);
    Producto m = {"Leche", 350, 2};
    carrito_agregar(&c, m);
    int total = carrito_total(&c);
    int resultado = carrito_descuento(total, 10);
    ASSERT_IGUAL(1300, total);
    ASSERT_IGUAL(1170, resultado);
}

void test_agregar_hasta_llenar(void) {
    Carrito c;
    carrito_init(&c);
    Producto p = {"Leche", 350, 1};
    carrito_agregar(&c, p);
    carrito_agregar(&c, p);
    carrito_agregar(&c, p);
    carrito_agregar(&c, p);
    ASSERT_IGUAL(MAX_ITEMS, carrito_contar(&c));
    int resultado = carrito_agregar(&c, p);
    ASSERT_IGUAL(0, resultado);
    ASSERT_IGUAL(MAX_ITEMS, carrito_contar(&c));
}

int main(void) {
    printf("=== Tests de integracion ===");
    test_compra_con_descuento();
    test_agregar_hasta_llenar();
    RESUMEN();
    return EXIT_CODE();
}
