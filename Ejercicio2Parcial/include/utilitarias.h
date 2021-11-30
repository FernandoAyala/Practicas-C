#ifndef UTILITARIAS_H_INCLUDED
#define UTILITARIAS_H_INCLUDED
#include<stdio.h>
#include<lista.h>

void restaurar_prueba_res(char * path_arch_alu, char* path_arch_ind);

int alta_res (t_alumno * alu, FILE * arch, t_lista* pa);
int alta (t_alumno * alu, FILE * arch, t_lista* pa);

int baja_res (t_alumno * alu, FILE * arch, t_lista* pa);
int baja (t_alumno * alu, FILE * arch, t_lista* pa);

int baja_ultimo_res (FILE * arch, t_lista* pa);
int baja_ultimo (FILE * arch, t_lista* pa);

int agregar_materia_res(FILE * arch, t_lista * pindice);
int agregar_materia(FILE * arch, t_lista * pindice);

int compactar_y_reindexar_res(FILE ** arch, t_lista * pindice, const char * path);
int compactar_y_reindexar(FILE ** arch, t_lista * pindice, const char * path);

void ingresar_alumno_res(t_alumno* alu);
void ingresar_alumno(t_alumno* alu);
void ingresar_dni_alumno_res(t_alumno* alu);
void ingresar_dni_alumno(t_alumno* alu);
void ingresar_nueva_materia_res(t_alumno* alu);
void ingresar_nueva_materia(t_alumno* alu);
void imprimir_alumno_res(const t_alumno* alu);
void imprimir_alumno(const t_alumno* alu);
void mostrar_dni_res(const t_reg_ind* r);
void mostrar_dni(const t_reg_ind* r);
void imprimir_archivo_res(FILE * arch);
void imprimir_archivo(FILE * arch);

void imprimir_archivo_ordenado_res(FILE * arch, t_lista* pa);
void imprimir_archivo_ordenado(FILE * arch, t_lista* pa);

int cmp_alumno(const t_reg_ind *r1, const t_reg_ind *r2);
void buscar_y_mostrar_alumno(t_reg_ind *reg_ind, void *arch);
#endif // UTILITARIAS_H_INCLUDED
