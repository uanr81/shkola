// running.c -- A useful program for runners
#include <stdio.h>
const int S_PER_M = 60;         // количество секунд в минуте
const int S_PER_H = 3600;       // количество секунд в часе
const double M_PER_K = 0.62137; // количество миль в километре
int main(void)
{
    double distk, distm;  // дистанция пробега в километрах и милях
    double rate;          // средняя скорость в милях в час
    int min, sec;         // время пробега в минутах и секундах 
    int time;             // время пробега только в секундах
    double mtime;         // время пробега одной мили в секундах
    int mmin, msec;       // время пробега одной мили в минутах и секундах
    
    printf("Эта программа преобразует время пробега дистанции в метрической системе\n");
    printf("во время пробега одной мили и вычесляет вашу среднюю\n");
    printf("скорость в милях в час.\n");
    printf("Введите дистанцию пробега в километрах.\n");
    scanf("%lf", &distk);  // %lf для типа double
    printf("Введите время в минутах и секундах.\n");
    printf("Начните с ввода минут.\n");
    scanf("%d", &min);
    printf("Теперь введите секунды.\n");
    scanf("%d", &sec);
    // переводит время в секунды    
    time = S_PER_M * min + sec;
    // переводит километры в мили  
    distm = M_PER_K * distk;
    // умножение миль в секунду на количество секунд в часе дает количество миль в час
    rate = distm / time * S_PER_H;
    // деление времени на расстояние дает время пробега одной мили
    mtime = (double) time / distm;
    mmin = (int) mtime / S_PER_M; // вычисление полного количества минут
    msec = (int) mtime % S_PER_M; // вычисление остатка в секундах
    printf("Вы пробежали %1.2f км (%1.2f мили) за %d мин, %d сек.\n",
           distk, distm, min, sec);
    printf("Такая скорость соответствует пробегу одной мили за %d мин, ",
           mmin);
    printf("%d сек.\nВаша средняя скорость составили %1.2f миль в час.\n",
           msec, rate);
    
    return 0;
}
