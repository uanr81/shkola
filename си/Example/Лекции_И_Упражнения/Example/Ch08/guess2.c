/* guess.c -- неэффективное и чреватое ошибками угадывание числа */
#include <stdio.h>
int main(void)
{
    int guess = 1;
    char response;
    
    printf("Выберите целое число в интервале от 1 до 100. Я попробую угадать ");
    printf("его.\nНажмить клавишу у, если моя догадка верна и ");
    printf("\nклавишу n в противном случае.\n");
    printf("Вашим числом является %d?\n", guess);
    while ((response = getchar()) != 'y')      /* получить ответ, сравнить с у */
      {
	if (response == 'n')
	printf("Ладно, тогда это %d?\n", ++guess);
	else
	  printf("Принимаются только варианты y и n. ");
	while(getchar() !='\n')
	  continue;//пропускать оставшуюся часть входной строки
    printf("Я знал, что у меня получится!\n");
    
    return 0;
}
