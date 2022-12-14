# <a name="general"></a>Fixed-point-to-floating-point
## Требования к программному модулю «Scale»
1. Модуль должен быть реализован на языке C/C++ в виде пары файлов «scale.h» и «scale.cpp»,
содержащих интерфейс модуля и его реализацию соответственно.
2. Модуль должен быть реализован без использования каких-либо библиотек.
3. Модуль должен быть реализован без использования языковых конструкций, поддерживаемых
и предлагаемых каким-то конкретным компилятором и не входящих в стандарт языка C/C++.
4. Модуль должен предоставлять вызывающей программе функцию преобразования числа с
фиксированной точкой, представленного в дополнительном коде, в число с плавающей точкой –
«FromScale».
5. Требования к функции «FromScale»
+   Функция должна иметь прототип:
    double FromScale( unsigned long dwValue, int iHighBit, int iBitCount, int iSigned, double dScale );
    где:
    
    dwValue – бинарное представление числа с фиксированной точкой,
    
    iHighBit – номер старшего бита числа с фиксированной точкой (если число со знаком, то номер
    знакового бита),
    
    iBitCount – кол-во бит занимаемых числом с фиксированной точкой (включая знаковый бит),
    
    iSigned – признак наличия знакового бита,
    
    dScale – цена старшего бита (если число со знаком, то цена бита следующего за знаковым),
    
    Результат функции – значение числа с фиксированной точкой, представленное в виде числа с
    плавающей точкой.
    
+  Функция должна автоматически определять цену старшего бита, если цена старшего бита
передаваемая в функцию равна нулю. Автоматически определяемая цена старшего бита должна
быть такой, чтобы цена младшего бита была равна единице.

+  Функция должна проверять передаваемые ей значения на корректность и возвращать ноль в
случае обнаружения некорректных значений.

6. Модуль должен содержать комментарии. В комментариях должно быть указано назначение
модуля, назначение функций модуля, способы вызова функций модуля и описание аргументов
функций.

___
## Тестирование
Результат выполнения тестового файла [`test.cpp`](https://github.com/AlexMtnkv/Fxied-point-to-floating-point/blob/2db268ed111a77ee1e90f7a952681c9d255cc5fd/test.cpp).

![image](https://user-images.githubusercontent.com/90116073/185224381-eb5d73db-8d98-478d-881a-28bf8cf68742.png)
![image](https://user-images.githubusercontent.com/90116073/185224528-34e08157-2636-4a7f-b6da-717a5289fabe.png)


[:arrow_up:Наверх](#general)
