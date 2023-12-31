___

# Лабораторная работа 02

___

## Оглавление

1. [Цель](#цель)
2. [Порядок выполнения работы](#порядок-выполнения-работы)
3. [Требования к программе](#требования-к-программе)
4. [Вариант задания](#вариант-задания)
5. [Сборка программы](#сборка-программы)
6. [Тесты](#тесты)

___

## Цель

1. Закрепление навыков работы с классами.
2. Закрепление навыков работы с динамической памятью на «куче».
3. Закрепление навыков работы с массивами.

___

## Порядок выполнения работы

* Ознакомиться с теоретическим материалом.
* Получить у преподавателя вариант задания.
* Реализовать задание своего варианта в соответствии с поставленными требованиями.
* Написать Unit-тесты с использованием Google Test.
* Создать репозиторий на GitHub.
* Отправить файлы лабораторной работы в репозиторий.
* Отчитаться по выполненной работе путём демонстрации работающей программы на тестовых наборах данных (как подготовленных самостоятельно, так и предложенных пре- подавателем) и ответов на вопросы преподавателя (как из числа контрольных, так и по реализации программы).

___

## Требования к программе

Используя в качестве образца класс Array (см. ниже), реализовать динамические контейнеры с использова- нием
динамического массива.

* Каждый класс должен быть разделен на интерфейс и реализацию.
* Самостоятельно определить необходимые типы, поля и дополнительные методы.
* Реализовать генерацию исключений в конструкторах и методах при необходимости (использовать стандартные исключения).
* Реализовать арифметические операции: сложение, вычитание, копирование
* Реализовать операции сравнения: (больше, меньше, равно).
* Арифметические операции с присваиванием должны быть реализованы как методы класса.

```c++
class Array {
public:
   Array();
   Array(const size_t& n, unsigned char t = 0);
   Array(const std::initializer_list<unsigned char>& t);
   Array(const string& t);
   Array(const Array& other);
   Array(Array&& other) noexcept;
   virtual ~Array() noexcept;
};
```

___

### Вариант задания

Создать класс _Five_ для работы с беззнаковыми целыми пятиричными числами, используя для представления числа массив из элементов типа _unsigned char_, каждый элемент которого является пятеричной цифрой. Младшая цифра имеет меньший индекс (единицы — в нулевом элементе массива).

___

## Сборка программы

1. После того как вы клонировали репозиторий, необходимо провалиться в папку *build:*
    ```
    cd build
    ```
2. Далее необходимо настроить проект на основе CMakeLists.txt:
    ```
   cmake ..
   ```
3. После успешной настройки вы можете собрать проект:
    ```
   make
   ```
4. Теперь появились 2 скомпилированные программы:
    * task02
    * tests
5. Чтобы запустить программу:
   ```
   ./task02
   ```
   или
   ```
   ./tests
   ```
6. Можно удалить скомпилированные программы командой:
   ```
   make clean
   ```
7. Можно также удалить все содержимое папки build:
   ```
   make clean_all
   ```

___

## Тесты

После компиляции программы (используя ```make```) необходимо запустить *tests*, после выполнения программы в терминале
отобразиться подробная информация о test-case.
___
