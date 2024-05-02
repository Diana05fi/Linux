/* В базе данных планово-экономического отдела хранятся сведения о выпуске
изделий и затратах (по статьям калькуляции) на каждое изделие.
Структура входного файла in.txt (Шифр статьи затрат Изделие Затраты на единицу
(условных единиц) План(шт.))
2 Принтер 200 5
1 Монитор 100 5
2 Картридж 10 20
Определить суммарную себестоимость по каждой статье затрат, упорядочив по номеру
статьи
Структура выходного файла out.txt
Шифр статьи затрат Себестоимость (условных единиц)
1 500
2 1200
*/


#include <stdio.h>
#include <string.h>
#include "func.h"
 
int main()
{
    FILE* f = fopen("in.txt", "r");
    FILE* fo = fopen("out.txt", "w");
    ROW a[10];
    int c = 0, ch;
    while(fscanf(f, "%d %s %d %d", &a[c].id, a[c].name, &a[c].price, &a[c].amount) == 4){
        a[c].sum = a[c].price * a[c].amount;
        c++;
    }
    
    while(1){
        printf("1. Выход\n2. Добавить\n3. Удалить\n4. Редактировать\n5. Распечатать все\n6. Запрос\n");
        scanf("%d", &ch);
        
        switch(ch){
            case 1: return 1;
            case 2: add(a, &c); break;
            case 3: delete(a, &c); break;
            case 4: change(a); break;
            case 5: write_to_file(a, c, f); break;
            case 6: zap(a, c, fo); break;
            default: printf("Не верно введённое значение"); break;
        }
    }
    
    fclose(f);
    fclose(fo);
    return 0;
}
