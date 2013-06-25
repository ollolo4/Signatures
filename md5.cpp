#include "md5.h"

unsigned int sh(unsigned int a, unsigned int s)
{
    return ((a<<s)|(a>>(32-s)));
}

void hash_once(unsigned int *w, unsigned int &H0, unsigned int &H1, unsigned int &H2, unsigned int &H3)
{
    //Задаем начальные значения
    unsigned int s[64] = {7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22,
                 5,  9, 14, 20, 5,  9, 14, 20, 5,  9, 14, 20, 5,  9, 14, 20,
                 4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23,
                 6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21};

    unsigned int k[64] =
                {0xd76aa478, 0xe8c7b756, 0x242070db, 0xc1bdceee ,
                 0xf57c0faf, 0x4787c62a, 0xa8304613, 0xfd469501 ,
                 0x698098d8, 0x8b44f7af, 0xffff5bb1, 0x895cd7be ,
                 0x6b901122, 0xfd987193, 0xa679438e, 0x49b40821 ,
                 0xf61e2562, 0xc040b340, 0x265e5a51, 0xe9b6c7aa ,
                 0xd62f105d, 0x02441453, 0xd8a1e681, 0xe7d3fbc8 ,
                 0x21e1cde6, 0xc33707d6, 0xf4d50d87, 0x455a14ed ,
                 0xa9e3e905, 0xfcefa3f8, 0x676f02d9, 0x8d2a4c8a ,
                 0xfffa3942, 0x8771f681, 0x6d9d6122, 0xfde5380c ,
                 0xa4beea44, 0x4bdecfa9, 0xf6bb4b60, 0xbebfbc70 ,
                 0x289b7ec6, 0xeaa127fa, 0xd4ef3085, 0x04881d05 ,
                 0xd9d4d039, 0xe6db99e5, 0x1fa27cf8, 0xc4ac5665 ,
                 0xf4292244, 0x432aff97, 0xab9423a7, 0xfc93a039 ,
                 0x655b59c3, 0x8f0ccc92, 0xffeff47d, 0x85845dd1 ,
                 0x6fa87e4f, 0xfe2ce6e0, 0xa3014314, 0x4e0811a1 ,
                 0xf7537e82, 0xbd3af235, 0x2ad7d2bb, 0xeb86d391 };

    unsigned int f, g, a, b, c, d, temp;

    a = H0;
    b = H1;
    c = H2;
    d = H3;

    for(int i = 0; i < 64; i++)
    {
        if (i >= 0 && i <= 15)
        {
            f = (b & c) | ((~ b) & d);
            g = i;
        }
        else if (i >= 16 && i <= 31)
        {
            f = (d & b) | ((~ d) & c);
            g = (5*i + 1)%16;
        }
        else if (i >= 32 && i <= 47)
        {
            f = b ^ c ^ d;
            g = (3*i + 5)%16;
        }
        else if (i >= 48 && i <= 63)
        {
            f = c ^ (b | (~ d));
            g = (7*i)%16;
        }
        temp = d;
        d = c;
        c = b;
        b = b + sh(a + f + k[i] + w[g], s[i]);
        a = temp;
    }

    H0 = H0 + a;
    H1 = H1 + b;
    H2 = H2 + c;
    H3 = H3 + d;
}

QString md5(char *name)
{
    //Открываем файл
    QFile file(name);
    file.open(QIODevice::ReadWrite);

    //Запоминаем размер файла
    qint64 file_size = file.size();
    file.close();

    //Считаем сколько сколько байт дописать
    int last_size = file_size % SIZE_OF_BLOCK;

    int zero_size;
    if (last_size < 56) zero_size = 56 - last_size;
    else zero_size = SIZE_OF_BLOCK - last_size + 56;

    //Считаем количество блоков
    qint64 num_of_blocks = (file_size + zero_size + 8) / SIZE_OF_BLOCK;

    //Сколько последних блоков должны быть модифицированы
    int blocks_mod = 1;
    if (last_size >= 56)
        blocks_mod++;

    //Начинаем преобразования

    //Начальные значения констант
     unsigned int H0 = 0x67452301;   //A
     unsigned int H1 = 0xefcdab89;   //B
     unsigned int H2 = 0x98badcfe;   //C
     unsigned int H3 = 0x10325476;   //D

    //Читаем из файла блоками
    FILE *ff = fopen(name, "rb");
    unsigned int R[16];

    for(qint64 i = 0 ; i < num_of_blocks - blocks_mod; i++) {
        fread(R, 4, 16, ff);
        hash_once(R, H0, H1, H2, H3);
    }

    //Оставшиеся блоки по ситуации
    if (last_size < 56)
    {
        //Последний блок модифицируются
        unsigned char last[64];
        //Читаем остатки файла и закрываем его
        fread(last, 1, last_size, ff);
        fclose(ff);

        //Дописываем биты заполнители
        int it = last_size;
        last[it++] = 0x80;
        for(int i = 0; i < zero_size - 1; last[it++] = 0, i++);

        //Дописываем длину в битах
        qint64 bit_file_size = file_size*8;
        for(int i = 0; i < 8; i++) {
            last[it++] = bit_file_size & 0xFF;
            bit_file_size /= 256;
        }

        //Хешируем последний блок - представляем его как массив int значений
        for(int i = 0; i < 16; i++) {
            R[i] = 256*256*256*last[4*i+3] + 256*256*last[4*i+2] + 256*last[4*i+1] + last[4*i];
        }
        hash_once(R, H0, H1, H2, H3);
    }
    else
    {
        //Последние 2 блока модифицируются
        unsigned char last[128];
        //Читаем остатки файла и закрываем его
        fread(last, 1, last_size, ff);
        fclose(ff);

        //Дописываем биты заполнители
        int it = last_size;
        last[it++] = 0x80;
        for(int i = 0; i < zero_size - 1; last[it++] = 0, i++);

        //Дописываем длину в битах
        qint64 bit_file_size = file_size*8;
        for(int i = 0; i < 8; i++) {
            last[it++] = bit_file_size & 0xFF;
            bit_file_size /= 256;
        }

        //Хешируем 1-й из последних блоков - представляем его как массив int значений
        for(int i = 0; i < 16; i++) {
            R[i] = 256*256*256*last[4*i+3] + 256*256*last[4*i+2] + 256*last[4*i+1] + last[4*i];
        }
        hash_once(R, H0, H1, H2, H3);

        //Хешируем 2-й из последних блоков - представляем его как массив int значений
        for(int i = 16; i < 32; i++) {
            R[i - 16] = 256*256*256*last[4*i+3] + 256*256*last[4*i+2] + 256*last[4*i+1] + last[4*i];
        }
        hash_once(R, H0, H1, H2, H3);
    }

    H0 = qToBigEndian(H0);
    H1 = qToBigEndian(H1);
    H2 = qToBigEndian(H2);
    H3 = qToBigEndian(H3);

    //Выводим хеш
    QString str = QString ("%1%2%3%4").arg(H0,-1,16).arg(H1,-1,16).arg(H2,-1,16).arg(H3,-1,16);
    return str;
}
