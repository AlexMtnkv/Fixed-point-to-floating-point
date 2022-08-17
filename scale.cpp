#include "scale.h"
#include <iostream>
using namespace std;

double FromScale(unsigned long dwValue, int iHighBit, int iBitCount, int iSigned, double dScale) {
    int N = sizeof(long) * 8;       // N - количество бит в типах long и unsigned long
    if (iHighBit < 1 || iHighBit > N - 1)     // номер старшего (или знакового) бита в диапазоне 1...N-1
        return 0.0;                     
    if (iBitCount < 1 || iBitCount > N)     // количество значащих бит (включая знаковый) в диапазоне 1...N
        return 0.0;
    if (dScale < 0.0)   // некорректная цена старшего бита
        return 0.0;         

    if (iHighBit > 1) {     // выравниваем число по левому краю, поскольку представление в дополнительном коде
        dwValue <<= (N - 1) - iHighBit;     // будет совпадать с машинным представлением и для преобразования
    }                                       // будет достаточно простого приведения типов

    double result;
    int n = N - 1;      // n - степень 2 для цены старшего разряда
    if (iSigned) {      // если число со знаком, приводим в знаковое целое
        result = (double)((long)dwValue);   // и далее в вещественное
        n--;         // старший разряд правее знакового бита
    } else {
        result = (double)dwValue; // для беззнакового просто приведение типов
    }

    unsigned long e = 0b1;      // единичный бит с правого края
    if(dScale > 0.0) {          // если задана цена старшего разряда
        result *= dScale / (e << n);    // делим результат на степень двойки (старший разряд по умолчанию)
                                        // и умножаем на заданную цену, если цена по умолчанию, то
    } else {                            // младший значащий бит нужно сделать с ценой = 1, 
        result /= e << (N - iBitCount);  // для этого результат делим на двойку в степени
    }                                   // порядка старшего незначащего бита справа

    return result;
}

// Вывод на печать (в выходной поток) значений входов и результата преобразования
void print_FromScale(unsigned long dwValue, int iHighBit, int iBitCount, int iSigned, double dScale) {
    cout << "\n{\n";
    cout << "\t0x" << hex << dwValue << " ,\t // dwValue\n";
    cout << "\t" << dec << iHighBit << " ,\t\t // iHighBit\n";
    cout << "\t" << iBitCount << " ,\t\t // iBitCount\n";
    cout << "\t" << iSigned << " ,\t\t // iSigned\n";
    cout << "\t" << dScale << " ,\t\t // dScale \n";
    cout << "\t" << FromScale(dwValue, iHighBit, iBitCount, iSigned, dScale) << "\t\t // expandResult\n}";
}

