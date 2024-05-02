#include <stdio.h>
#include <string.h>
#include "func.h"

void zap(ROW* a, int c, FILE* fo)
{
    for(int i = 0; i < c; i++){
        ROW vrem;
        for(int j = i; j < c; j++){
            if(a[i].id > a[j].id){
                vrem = a[i];
                a[i] = a[j];
                a[j] = vrem;
            }
        }
    }
    
    for(int i = 0; i < c; i++){
        for(int j = i+1; j < c; j++){
            if(a[i].id == a[j].id){
                a[i].sum += a[j].sum;
                a[j].id = 0;
            }
        }
    }
    int ssum = 0;
    for(int i = 0; i<c; i++){
        if (a[i].id != 0){
            ssum+=a[i].sum;
            fprintf(fo, "%d %d\n", a[i].id, a[i].sum);
        }
    }
    fprintf(fo, "Сумма: %d", ssum);
}

void add(ROW* a, int* c)
{
    if(*c>=10){
        printf("Максимальное количество записей");
        return;
    }
    printf("Шифр Изделие Затраты План\n");
    scanf("%d %s %d %d", &a[*c].id, a[*c].name, &a[*c].price, &a[*c].amount);
    a[*c].sum = a[*c].price * a[*c].amount;
    (*c)++;
}

void write_to_file(ROW* a, int c, FILE* f)
{
    fclose(f);
    f = fopen("in.txt", "w");
    for(int j = 0; j<c;j++){
        fprintf(f, "%d %s %d %d\n", a[j].id, a[j].name, a[j].price, a[j].amount);
    }
    f = fopen("in.txt", "r");
}

void delete(ROW* a, int* len)
{
    int n;
    printf("Введите какую по счёту строку хотите удалить\n");
    scanf("%d", &n);
    
    for(int i = n-1; i<(*len)-1;i++){
        a[i] = a[i+1];
    }
    (*len)--;
}

void change(ROW* a)
{
    int str, num, vvod;
    char vvod_str[50];
    printf("Выберете какую по счёту строку редактировать\n");
    scanf("%d", &str);
    printf("Выберете какой элемент строки изменить\n1 - Шифр; 2 - Изделие; 3 - Затраты; 4 - План");
    scanf("%d", &num);
    switch(num){
        
        case 1: scanf("%d", vvod); a[str-1].id = vvod; break;
        case 2: scanf("%s", vvod_str); strcpy(a[str-1].name, vvod_str); break;
        case 3: scanf("%d", vvod); a[str-1].price = vvod; break;
        case 4: scanf("%d", vvod); a[str-1].amount = vvod; break;
        default: printf("Введено неверное значение");break;
    }
    a[str-1].sum = a[str-1].price * a[str-1].amount;
}