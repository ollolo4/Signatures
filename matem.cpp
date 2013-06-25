#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define N 20001


int  add ( char *, char *, char * );
int  sub ( char *, char *, char * );
int  mul ( char *, char *, char * );
int  div ( char *, char *, char *, char * );
int poW ( char *t, char *k, char *res );
int poWmod ( char *t, char *k, char *mod, char *res );
int cmp(char *a, char *b);
int RobinTest(char *n);
char *randomstr(char *bound);
void del_zero ( char * a, char * b );
int NOD( char * ,char * , char * );
int NOD_rash ( char * a, char * b, char * d, char * x, char * y );

int add ( char *aa, char *bb, char * res )
{
        int i, j, k;	//индексы массивов операндов и результата
        int cr;			//признак переноса в старший разряд
        int tmp;			//буфер результата поразрядного сложения
    char * a, * b;

    a = new char [N];
    b = new char [N];
        * res = '\0';					//зануляем строку с результатом
        del_zero (aa,bb);
    strcpy (a,aa);
    strcpy (b,bb);
        i = strlen(a);		//движемся с конца операндов
        j = strlen(b);		//
        k = 0;				//массив результата заполнием с начала
        cr = 0;				//обнуляем признак переноса

        //Цикл поразрядного сложения
        do
        {
                //Движемся по массиву цифр первого операнда к началу
                if ( i )	i--;
                //Если массив завершился, считаем цифры нулями
                //Аналогично для второго операнда
                else		a[i] = '0';
                if ( j )	j--;
                else		b[j] = '0';

                //Складываем поразрядно операнды с учетом переноса
                //и коррекции цифр и их кодов
                tmp = a[i]+b[j]+cr-96;
                res[k] = tmp%10+48;		//младший разряд суммы - в результат
                cr = tmp/10;				//старший разряд - перенос
                k++;							//смещаемся по массиву результата
        }
        //Выполнять, пока не завершиолись разряды операндов и есть признак переноса
        while ( i || j || cr );
        res[k] = '\0';			//ставим знак конца стоки в конце массива результата
        strrev(res);

    free (a);
    free (b);

        return 0;
}

int sub ( char *aa, char *bb, char * res )
{
        char * a, * b;		//указатели на строки (массивы) уменьшаемого и вычитаемого
        int i, j, k;		//индексы массивов уменьшаемого, вычитаемого и разности
        int tmp;				//буфер результата поразрядного вычитаения
        int flg;				//признак отрицательности разности
        int cr;				//признак займа из старшего разряда

        a = new char [N];		//Выделяем память под строку уменьшаемого
        b = new char [N];		//и вычитаемого
        * a = * b = '\0';		//Изначально строки пусты
        del_zero (aa,bb);

        //Распределяем операнды (менжду уменьшаемым и вычитаемым)
        flg = 0;				//Предполагаем, что разность положительна
        //Если длина 1-го операнда меньше длины 2-го, торазность отрицательна
        if ( strlen(aa)<strlen(bb) )
                flg = 1;
        else
                //Иначе, если длины совпадают, сравниваем цифры операндов поразрядно
                //от старших к младшим
                if ( strlen(aa)==strlen(bb) )
                        for ( i=0; i<strlen(aa); i++ )
                        {
                                //Если находим цифру 1-го операнда, большую, чем цифра 2-го
                                //Завершаем сравнение, разность положительна
                                if ( aa[i]>bb[i] )
                                        break	;
                                //Если же находим цифру 2-го операнда, большую, чем цифра 1-го
                                //Так же завершаем дальнейшее сравнение, разность отрицательна
                                if ( aa[i]<bb[i] )
                                {
                                        flg = 1;		//ставим признак отрицательности разности
                                        break;
                                }
                        }

        //Если разность отрицательна, за уменьшаемое принимаем 2-й (больший)
        //операнд, а за вычитаемое 1-й
        if ( flg )
        {
                strcpy (a,bb);		//копируем строку со 2-м операндом в строку уменьшаемого
                i = strlen(bb);	//запоминаем его длину
                strcpy (b,aa);		//копируем строку с 1-м операндом в строку вычитаемого
                j = strlen(aa);	//запоминаем его длину
        }
        //Если разность неотрицательна
        else
        {
                strcpy (a,aa);		//1-й операнд принимаем за уменьшаемое
                i = strlen(aa);	//
                strcpy (b,bb);		//2-й - за вычитаемое
                j = strlen(bb);	//
        }

        k = 0;		//изначально срока с разностью пуста
        cr = 0;		//признак займа снят
        //Цикл поразрядного вычитания
        do
        {
                //Аналогично циклу сложения движемся
                //по массивам уменьшаемого и вычитаемого
                if ( i )	i--;
                else		a[i] = 48;
                if ( j )	j--;
                else		b[j] = 48;
                //Производим поразрядное вычитаение с учетом займа из младших разрядов
                tmp = a[i]-b[j]-cr;
                //Если результат поразрядного вычитания отрицателен, делаем займ
                //из старшего разряда
                if ( tmp<0 )
                {
                        cr = 1;			//поднимаем признак займа
                        tmp = 10+tmp;	//корректируем результат с учетом займа
                }
                else
                        //Если же результат неотрицателен, брасываем признок займа,
                        //если он был сделан из текущего разряда
              if ( a[i]!='0' )	cr = 0;
                res[k] = tmp+48;		//записываем результат в массив разности
                k++;						//переходим к следующему разряду массива
        }
        while ( i || j );			//Выполняем, пока не завершились разряды операндов
        res[k] = '\0';				//Дописываем в res код конца строки

        //Убираем нули перед значащими цифрами
        k--;			//Смещаемся до последней цифры массива результатов
                                        //(цифры записаны в обратном порядке)
        //Пока видим нули и длина массива разности больше 1, стираем их
        while ( res[k]=='0' && k )
        {
                res[k] = '\0';			//заменяем текущий символ на символ конца строки
                k--;						//движемся к началу массива
        }
        strrev(res);
    free (a);
    free (b);
        return flg;					//Возвращаем признак отрицательности
}

int mul ( char *aa, char *bb, char * res )
{
        char * a, * b;				//Указатели подстроки с множителями
        int na, nb;					//Переменные для хранения длин множителей
        int i, j, k;				//Индексы массивов множителей и произведения
        int tmp;						//буфер результата поразрядного умножения
        int cr;						//буфер переноса в старшие разряды
        char * buf1, * buf2;		//указатели на буферные строки
        char *A, *B;

        A = new char [N];
        B = new char [N];
        strcpy(A,aa);
        strcpy(B,bb);
        * res = '\0';					//зануляем строку с результатом
        buf1 = new char [N*2];	//Выделяем память под буферные строки
        buf2 = new char [N*2];	//
        * buf1 = * buf2 = '\0';	//значально строки пусты
        del_zero (A,B);
        //Определяем операнд, на который будет производиться умножение
        //Критерий - длина операндов. Умножаем на тот, что короче
        i = strlen(B)-strlen(A);		//Вычисляем разность длин операндов

        //Если короче 1-й, по умножаем на него
        if ( i>0 )
        {
                a = B;              //Устанавливаем указатель на 1-й множитель
                           //на начало строки с 2-м операндом
                na = strlen(B)-1;	//Запомиинаем длину 1-го множителя
                b = A;					//Устанавливаем указатель на 2-й множитель
                                                                        //на начало строки с 1-м операндом
                nb = strlen(A)-1;	//Запоминаем длину 2-го множителя
        }
        //Если же 2-й операнд не длиннее 1-го, то делаем его первым множителем
        else
        {
                a = A;					//1-й операнд делаем 1-м множителем
                na = strlen(A)-1;	//Запоминаем его длину
                b = B;					//2-й операнд делаем 2-м множителем
                nb = strlen(B)-1;	//Запоминаем его длину
        }

        //ЦИКЛ ПОСЛЕДДОВАТЕЛЬНО УМНОЖЕНИЯ ПО СХЕМЕ "СТОЛБИКОМ"
        //Движемся по 2-му множителю от конца к начату,
        //умножая каждую цифру на 1-й множитель
        for ( j=nb; j>=0; j-- )
        {
                //Заполняем нулями разряды промежуточного результат
                //находящиеся справа от текущего разряда 2-го множителя
                for ( k=0; k<nb-j; k++ )
                        buf1[k] = '0';
                cr = 0;						//Обнуляем буфер переноса в старшие разряды

                //Цикл поразрядного умножения
                for ( i=na; i>=0; i-- )
                {
                        //Перемножаем цифры первого множителя с текущей цифрой второго
                        //с учетом смещения кодов цифр и переноса из младших разрядов
                        tmp = (a[i]-48)*(b[j]-48)+cr;
                        //Младший разряд произведения пишем в массив промежут. результата
                        buf1[k] = tmp%10+48;
                        k++;						//Смещаемся по массиву промежут. результат
                        cr = tmp/10;			//Стираем из буфера перенос в текущий разряд
                }
                //Делаем, если требуется, перенос в старший разряд
                if (cr)
                {
                        buf1[k] = cr+48;	//Записываем перенос в следующий разряд
                        k++;					//Смещаемся по массиву промежут. результата
                }
                buf1[k] = '\0';	//Формируем из массива промежут. результата строку
                strrev (buf1);			//Переписываем ее в правильном (обратном) порядке
                add (buf1,buf2,res);		//Складываем с результатом, накапливаемым в res
                strcpy (buf2,res);	//Копируем в вспомогат. буфер накопленный результат
        }
        return 0;
}

int div ( char *a, char *b, char * res, char * rem )
{
        char * buf1, * buf2;			//Указатели на буферные строки
        char c;							//Буферная символьная переменная
        int i, j;							//Индекс буферного массива
        int q;							//Признак привязывания 1-го символа с
                                                                                //промежуточным уменьшаемым
                                                                                //каждый последующий привязанный символ
                                                                                //сопровождается дописыванием нулей в результат
        int nb;							//Переменная для хранения длины строки делителя

        * res = '\0';					//зануляем строку с результатом
        * rem = '\0';

        del_zero (a,b);
        if ((strlen(b)==1) && (b[0])=='0')
        {
                return 666;
        }
        if ((strlen(a)==1) && (a[0])=='0')
        {
                strcat (res,"0");
                strcpy (rem,a);
                return 0;
        }
        //Если длина делимого меньше длины делителя, то частное равно нулю
        if ( strlen(a)<strlen(b) )
        {
                strcat (res,"0");			//Пишем в строку результата ноль
                strcpy (rem,a);			//операнд целиком составляем остаток
                return 0;					//деление не произошло
        }
        else
        {
                buf1 = new char [N];		//Выделяем память под буферные строки
                buf2 = new char [N];		//
                * buf1 = * buf2 = '\0';	//Изначально строки пусты
                nb = strlen(b);			//Запоминаем длину делителя

                //Заполняем буфер для промежуточного  делимого
                //для первого цикла деления
                strncat (buf1,a,nb);	//Копируем из делимого необходимое количество символов
                a += nb;					//Смещаемся по сткоке с делимым на нужное число символовов
                int fuck = 0;
                //ЦИКЛ ДЕЛЕНИЯ "СТОЛБИКОМ"
                do
                {
                        fuck ++;
                        if (fuck==43)
                                fuck++;
            q = 1;					//Первого привязывания не было
            //Определяем длину остатка от деления
                                i = strlen (buf1);
                                //Убираем из буфера единственный ноль,
                                //если он там есть
            if ( strlen(buf1)==1 && buf1[0]=='0' )
            {
               * buf1 = '\0';		//Делаем буферную строку пустой
               i--;					//Уменьшаем ее длину
            }
            //Если строка с делимым еще не пуста и
            //буфер с промежуточным делимым не заполнен
            //дополняем его из строки с делимум
            if ( strlen(a)>0 && i<nb )
            {
                 strncat (buf1,a,1);		//Копируем в буфер 1-й символ
                 a++;							//Смещаемся по строке с делимым
                 i++;
                 q = 0;								//Увеличиваем индекс массива буфера
                 if ( strcmp(buf1,"0")==0 )
                 {
                    * buf1 = '\0';
                    i--;
                    strcat (res,"0");
                    q = 1;
                 }
                                                                //Снимаем признак q
                 //Далее копируем по одному символы из строки с делимым
                 //в буфер, пока не скопируем нужное количество, либо
                 //пока не закончится строка с делимым
                 while ( i<nb && strlen(a) )
                 {
                    strncat (buf1,a,1);	//Копируем символ в буфер
                    if ( !q )
                        strcat (res,"0");		//Дописываем к результату ноль
                    q = 0;
                    a++;						//Смещаемся по строке сделимым
                    i++;						//Увеличиваем индекс массива буфера
                    if ( buf1[0]=='0' )
                    {
                        * buf1 = '\0';
                        i--;
                        //buf1[--i] = '\0';
                    }
                 }
                 if ( strlen(buf1)<strlen(b) && strlen(a)==0 )
                 {
                                                        if ( !q )
                                                          strcat (res,"0");
                                                        if ( strlen(res)==0 )
                                                                strcat (res,"0");
                            if ( strlen(buf1)!=0 )
                                                            strcpy (rem,buf1);
                            else
                                strcpy (rem,"0");
                            free (buf1);
                            free (buf2);
                                                        return 1;
                                                }
            }

         //Проверяем, нужно ли копировать в буфер дополнительный символ
                        for ( i=0; i<strlen(buf1); i++ )
                        {
                                //Если в текущем разряде символ в буфере меньше, чем в делителе
                                //Необходимо скопировать в буфер дополнительный символ
                                if ( buf1[i]<b[i] /*&& buf1[0]!='0'*/ )
                                {
                                        if ( strlen(a) )
                                        {
                                                strncat (buf1,a,1);			//Копируем символ в буфер
                                                if ( strlen(res) && !q )	//Если это не первый символ
                                                {									//
                                                strcat (res,"0");	//дополняем результат нулем
                                                        q = 0;				//Снимаем признак q
                        }
                                                a++;								//Смещаемся по строке с делимым
                                                break;							//Заканчиваем сравнивать
                                        }
                                        else
                                        {
                                                if ( strlen(res)==0 )
                                                        strcpy (res,"0");
                                                if ( !q )
                                                          strcat (res,"0");
                                                strcpy (rem,buf1);
                        free (buf1);
                        free (buf2);
                                                return 0;
                                        }
                                }
                                else
                                        //Если же в текущем разряде символ в буфере больше
                                        if ( buf1[i]>b[i] )			//
                                        break;						//Заканчиваем сравнение
            }
                        i = 0;									//Обнуляем счетчик для частного
                        //Цикл вычитания делителя из делимого
                        //Условие выхода: разность отрицательна, либо равно нулю
                        while ( !sub(buf1,b,buf2) )
                        {
                                strcpy (buf1,buf2);	//Копируем разность в 1-й буфер
                                i++;						//Увеличиваем счетчик частного
                        }

                        c = i+48;					//Смещаем результат по таблице символов
                        strncat (res,&c,1);		//Дописываем результат в строку с результатом
                }
                while ( strlen(a) );
                strcpy (rem,buf1);			//записываем остаток
                if ( strlen(rem)==0 )
                        strcpy (rem,"0");
        }

    free (buf1);
    free (buf2);

        return 1;
}

//Функция удаления лишних нулей в старших разрядах операндов
void del_zero ( char * a, char * b )
{
        int j;
        while(1)
        {
                if ((a[0]!='0') || (strlen(a)==1)) break; //если встретили не 0, заканчиваем проверку
                for (j=0; j<strlen(a)-1; j++)   //Сдвигаем число на  один разряд влево
                {
                        a[j]=a[j+1];
                }
                a[strlen(a)-1]='\0';    //Удаляем ставший лишним разряд в конце числа

        }

        while(1)
        {
                if ((b[0]!='0') || (strlen(b)==1)) break;  //если встретили не 0, заканчиваем проверку
                for (j=0; j<strlen(b)-1; j++)   //Сдвигаем число на  один разряд влево
                {
                        b[j]=b[j+1];
                }
                b[strlen(b)-1]='\0';   //Удаляем ставший лишним разряд в конце числа
        }
}

char *randomstr(char *bound)
{
        int k = strlen(bound), n = rand()%k + 1;
        char * randstr = new char [N];
        char * buf = new char [N];

        char character[2]="";
        strcpy(randstr,"");
        while(1)
        {
                char character[2]="";
                strcpy(randstr,"");
                for (int i=0; i<n; i++)
                {
                        int a = rand()%10;
                        itoa(a,character,10);
                        strcat(randstr,character);
                }
                strcpy(buf,randstr);
                if (n < k)
                {
                        del_zero(randstr,buf);
                        return randstr;
                }
                if (!cmp(buf,bound))
                {
                        del_zero(randstr,buf);
                        return randstr;
                }
        }
}

int poW ( char *t, char *k, char *res )
{
        char *buf1 = new char [N];
    char *buf2 = new char [N];
    char *r = new char [N];
        char *a = new char [N];
        char *b = new char [N];
    strcpy(buf1,"");
    strcpy(buf2,"");
    strcpy(r,"");
    strcpy(res,"1");
        strcpy(a,t);
        strcpy(b,k);
    while(strcmp(b,"0")!=0)
    {
                div(b,"2",buf1,buf2);
        if (buf2[0] == '1')
        {
                        mul(res,a,buf1);
            strcpy(res,buf1);
        }
        mul(a,a,buf1);
        strcpy(a,buf1);
        div(b,"2",buf1,buf2);
        strcpy(b,buf1);
    }
        return 1;
}

int poWmod ( char *t, char *k, char *mod, char *res )
{
        char *buf1 = new char [N];
        char *buf2 = new char [N];
        char *r = new char [N];
        char *a = new char [N];
        char *n = new char [N];
        strcpy(r,"1");
        strcpy(a,t);
        strcpy(n,k);
        long long i=0;

        while(strcmp(n,"0")!=0)
        {
                i++;
                if (int(n[strlen(n)-1])%2==0)
                {
                        div(n,"2",buf1,buf2);
                        strcpy(n,buf1);
                        mul(a,a,buf1);
                        div(buf1,mod,buf2,a);
                }
                else
                {
                        sub(n,"1",buf1);
                        strcpy(n,buf1);
                        mul(r,a,buf1);
                        div(buf1,mod,buf2,r);
                }
        }
        strcpy(res,r);
        return 1;
}

int cmp(char *a, char *b)
{
        if (strlen(a)>strlen(b))
                return 1;
        if (strlen(b)>strlen(a))
                return 0;
    int n = strlen(a) >= strlen(b)? strlen(a): strlen(b);

        for (int i=0; i<n; i++)
        {
                if (a[i]>b[i])
                        return 1;
                else if (b[i]>a[i])
                        return 0;
        }
        return 2;
}

int RobinTest(char *n)
{
        char *buf, *buf1, *buf2, *s, *r, *j, *nn, *a, *y;
        y = new char [N];
        buf1 = new char [N];
        buf2 = new char [N];
        buf = new char [N];
        s = new char [N];
        r = new char [N];
        j = new char [N];
        nn = new char [N];
        a = new char [N];
        sub(n,"2",buf);
        strcpy(a,"1");
        while(strcmp(a,"1")==0 || strcmp(a,"0")==0)
                a = randomstr(buf);
        sub(n,"1",nn);
        strcpy(s,"2");
        while(2)
        {
                poW("2",s,buf);
                if (cmp(buf,nn) == 1)
                {
                        strcpy(s,"1");
                        div(nn,"2",r,buf2);
                        break;
                }
                div(nn,buf,buf1,buf2);
                if (buf2[0]=='0')
                {
                        div(buf1,"2",buf,buf2);
                        if (strcmp(buf2,"0")!=0)
                        {
                                strcpy(r,buf1);
                                break;
                        }
                }
                add(s,"1",buf);
                strcpy(s,buf);
        }
        poWmod(a,r,n,y);
        if (strcmp(y,"1")!=0 && strcmp(y,nn)!=0)
        {
                strcpy(j,"1");
                sub(s,"1",buf);
                while(cmp(j,buf)!=1 && strcmp(y,nn)!=0)
                {
                        poWmod(y,"2",n,buf1);
                        if (strcmp(buf1,"1")==0)
                                return 0;
                        strcpy(y,buf1);
                        add(j,"1",buf1);
                        strcpy(j,buf1);
                }
                if(strcmp(y,nn)!=0)
                        return 0;
        }
        return 1;
}

//Вычисление НОД по алгоритму Евклида
int NOD ( char * a, char * b, char * res )
{
        char * buf1, * buf2, *aa, *bb;
                long long iter = 0;
        buf1 = new char [N];		//Выделяем память под буферные строки
        buf2 = new char [N];
                aa = new char [N];
                bb = new char [N];
                strcpy(aa,a);
                strcpy(bb,b);
        mul(aa,bb,buf2);
        while(strcmp(buf2,"0")!=0)  //Пока a или b не равны 0
        {
                if(sub(aa,bb,buf1)==0)  //Если a <= b
                {
                        div (aa,bb,buf1,buf2);  //a = a % b
                        strcpy (aa,buf2);
                }
                else
                {
                        div (bb,aa,buf1,buf2);  //b = b % a
                        strcpy (bb,buf2);
                }
                mul(aa,bb,buf2);   //Проверка a и b на равенство 0
                                iter ++;
        }
        add(aa,bb,res);         // Одно + ноль
        return 1;
}

int NOD_rash ( char * a, char * b, char * d, char * x, char * y )
{
        char *r0, *r1, *r2, *x0, *x1, *y0, *y1, *q, *A, *B;
        char * buf1, * buf2;
        buf1 = new char [N];		//Выделяем память под буферные строки
        buf2 = new char [N];
        A = new char [N];
        B = new char [N];
        r0 = new char [N];
        r1 = new char [N];
        r2 = new char [N];
        x0 = new char [N];
        x1 = new char [N];
        y0 = new char [N];
        y1 = new char [N];
        q = new char [N];
        bool X1flg = false, X0flg = false, Y1flg = false, Y0flg = false;

        strcpy(A,a);
        strcpy(B,b);

        if(sub(A,B,buf1))
        {
                strcpy(buf1,A);
                strcpy(A,B);
                strcpy(B,buf1);
        }

        strcpy(r0,A);
        strcpy(r1,B);
        strcpy(x0,"1");
        strcpy(x1,"0");
        strcpy(y0,"0");
        strcpy(y1,"1");
        strcpy(q,"");
        strcpy(r2,"");

        for (;;)
        {
                div(r0,r1,q,buf1);
                mul(q,r1,buf1);
                sub(r0,buf1,r2);
                if (strcmp(r2,"0")==0)
                        break;
                else
                {
                        mul(q,x1,buf1);
                        strcpy(buf2,x1);
                        if (X0flg == X1flg)
                        {
                                if (!X0flg && sub(x0,buf1,x1))
                                {
                                        X0flg = X1flg;
                                        X1flg = true;
                                }
                                else if (X0flg && sub(x0,buf1,x1))
                                {
                                        X0flg = X1flg;
                                        X1flg = false;
                                }
                        }
                        else
                                add(x0,buf1,x1);

                        strcpy(x0,buf2);

                        mul(q,y1,buf1);
                        strcpy(buf2,y1);
                        if (Y0flg == Y1flg)
                        {
                                if (!Y0flg && sub(y0,buf1,y1))
                                {
                                        Y0flg = Y1flg;
                                        Y1flg = true;
                                }
                                else if (Y0flg && sub(y0,buf1,y1))
                                {
                                        Y0flg = Y1flg;
                                        Y1flg = false;
                                }
                        }
                        else
                                add(y0,buf1,y1);

                        strcpy(y0,buf2);

                        strcpy(r0,r1);
                        strcpy(r1,r2);
                }
        }

        mul(x1,A,buf1);
        mul(y1,B,buf2);
        if (sub(buf1,buf2,x0) && strcmp(x0,r1)==0)
        {
                strcpy(x,"-");
                strcat(x,x1);
                strcpy(y,y1);
        }
        else if (sub(buf2,buf1,x0) && strcmp(x0,r1)==0)
        {
                strcpy(x,x1);
                strcpy(y,"-");
                strcat(y,y1);
        }

        strcpy(d,r1);

        return 1;
}

