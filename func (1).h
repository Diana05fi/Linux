#ifndef FUNC_H
#define FUNC_H

typedef struct{
    int id, price, amount, sum;
    char name[50];
}ROW;

void zap(ROW* a, int c, FILE* fo);
void add(ROW* a, int* c);
void write_to_file(ROW* a, int c, FILE* f);
void delete(ROW* a, int* len);
void change(ROW* a);

#endif
