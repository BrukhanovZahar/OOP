# Лабораторная работа 01

___

## Оглавление
1. [Цель](#цель)
2. [Задание](#задание)
3. [Вариант задания](#вариант-задания)
4. [Сборка программы](#сборка-программы)
5. [Тесты](#тесты)
___

## Цель

* Изучение системы сборки на языке C++, изучение систем контроля версий.
* Изучение работы с памятью в языке C++.
* Изучение работы с вводом/выводом в стандартный поток.

___

## Задание

* Установить компилятор C++
* Установить систему сборки cmake
* Установить систему управления версиями git
* Установить систему unit-тестирования Google Test
* Установить и настроить CLion
* Написать программу согласно варианта задания
* Написать тесты согласно варианта задания
* Запушить задание на репозиторий
* Отправить ссылку на репозиторий в lms.mai.ru

___

### Вариант задания

Тролли атакуют ваш раздел комментариев!<br>
Обычный способ решения этой ситуации - удаление всех гласных из комментариев троллей, что нейтрализует угрозу.<br>
Ваша задача - написать функцию, которая принимает строку и возвращает новую строку с удаленными гласными.

*Например: строка* 
```
"This website is for losers LOL!"
```
*превратится в*
```
"Ths wbst s fr lsrs LL!"
```

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
   * task01
   * tests
5. Чтобы запустить программу:
   ```
   ./task01
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

После компиляции программы (используя ```make```) необходимо запустить *tests*, после выполнения программы в терминале отобразиться подробная информация о test-case.