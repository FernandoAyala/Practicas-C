#ifndef UTILITARIAS_H
#define UTILITARIAS_H



void generar_archivo_productos();
void mostrar_archivo_prod(FILE* arch_prod);
void mostrar_mat_prima_art(t_mat_prima_art* pmat_prima_art);
void procesar_arch_productos(FILE* arch_prod, FILE* arch_prod_mas_1000, FILE* arch_prod_menos_1000);
void procesar_arch_productos2(FILE* arch_prod, FILE* arch_prod_mas_1000, FILE* arch_prod_menos_1000);
int mi_strcmp(const char *s1, const char *s2);

#endif // UTILITARIAS_H
