#ifndef CADENAS_H_INCLUDED
#define CADENAS_H_INCLUDED

typedef struct{
    char cod_cta[9];
    char tipo_mov;
    float importe;
}t_movimiento_banco;

char *mi_strstr(const char *s1, const char *s2);
int mi_strlen(const char *s);
char *mi_strchr(char *s, int c);
char *mi_strrchr(char *s, int c);
char *mi_strcpy(char *s1, const char *s2);
int mi_strcmp(const char *s1, const char *s2);
int validar_nro_cuenta(t_movimiento_banco * c1);
// void *mi_memcpy(void *s1, const void *s2, size_t n);
#endif // CADENAS_H_INCLUDED
