/** @file
* @author Кучеренков А.С.
* @version 1.0
* @date 23.01.2024
* @copyright ИБСТ ПГУ
* @warning Тестовый
* @brief Заголовочный файл для модуля Маршрутной перестановки
*/

#pragma once
#include <vector>
#include <string>
#include <map>
#include <iostream>
#include <cctype>
#include <locale>
#include <codecvt>

/** @brief Шифрование методом Маршрутной перестановки
* @details Ключ устанавливается в конструкторе.
* Для зашифровывания и расшифровывания предназначены методы encrypt и decrypt.
* @warning Реализация только для русского языка
*/

class modBetaCipher
{
private:
    std::wstring_convert<std::codecvt_utf8<wchar_t>, wchar_t> codec; ///<Объект для конвертации между строками и широкими строками
    int key1; ///<Количество столбцов в шифре
public:
    modBetaCipher(std::wstring & ws_key); ///<Конструктор класса, принимающий ключ в виде широкой строки
    modBetaCipher()=delete; ///<Запрет конструктора без параметров
     /** @brief Метод проверки ключа
    * @details Преобразовывает строчные буквы в прописные
    * @param [in] s Строка ключа
    * @return Строка
    * @trow cipher_error, если ключ не соответствует требованиям
    */
    int getValidKey(std::wstring& ws_key); ///<Метод для проверки и получения корректного ключа
    modBetaCipher(const int& key) :key1(key) {}; ///<Конструктор класса, принимающий ключ в виде целого числа
    /** @brief Функция зашифрования
    * @details Функция шифрует строку методом Маршрутной перестановки
    * @param [in] open_text Строка с текстом
    * @trow cipher_error, если строка не соответсвует требованиям 
    */
    std::wstring encrypt(const std::wstring& open_text); ///<Метод для шифрования открытого текста
    /** @brief Функция зашифрования
    * @details Функция шифрует строку методом Маршрутной перестановки
    * @param [in] cipher_text Строка с текстом
    * @trow cipher_error, если строка не соответсвует требованиям 
    */
    std::wstring decrypt(const std::wstring& cipher_text); ///<Метод для дешифрования зашифрованного текста
};

/** @brief Класс исключений
* @details Класс исключений для того чтобы
* отслеживать исключения. Когда возникает ошибка в процессе шифрования или дешифрования, объект этого класса может быть создан с сообщением об ошибке, которое затем может быть обработано в программе
*/

class cipher_error: public std::invalid_argument
{
public:
	explicit cipher_error (const std::string& what_arg): ///<Конструктор с параметром типа std::string
		std::invalid_argument(what_arg) {} ///<Вызов конструктора базового класса с передачей параметра
	explicit cipher_error (const char* what_arg): ///<Конструктор с параметром типа const char*
		std::invalid_argument(what_arg) {} ///<Вызов конструктора базового класса с передачей параметра
};
