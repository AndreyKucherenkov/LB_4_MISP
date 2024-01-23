/** @file
* @author Кучеренков А.С.
* @version 1.0
* @date 23.01.2024
* @copyright ИБСТ ПГУ
* @warning Тестовый
* @brief Заголовочный файл для модуля Гронсфельда
*/

#pragma once
#include <vector>
#include <string>
#include <map>
#include <iostream>
#include <cctype>
#include <locale>
#include <codecvt>

/** @brief Шифрование методом Гронсфельда
* @details Ключ устанавливается в конструкторе.
* Для зашифровывания и расшифровывания предназначены методы encrypt и decrypt.
* @warning Реализация только для русского языка
*/

class modBetaCipher
{
private:
    // Объявление приватных членов класса
    std::wstring_convert<std::codecvt_utf8<wchar_t>, wchar_t> codec; ///< Используется для конвертации между std::wstring и UTF-8
    std::wstring numAlpha = L"АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ"; ///<Алфавит
    std::map <wchar_t,int> alphaNum; ///<Сопоставление символов алфавита и их числовых значений
    std::vector <int> key; ///<Ключ шифрования/дешифрования
    /** @brief Метод преобразования вектора в строку
    * @details Каждой букве присваивается номер 
    * согласно алфавиту по порядку
    * @param [in] ws Строка
    * @return Вектор букв со своими позициями
    */
    std::vector<int> convert(const std::wstring& ws); ///<Приватный метод для конвертации строки в вектор чисел
    /** @brief Метод преобразования строки в вектор
    * @details Каждой букве присваивается номер 
    * согласно алфавиту по порядку
    * @param [in] v Вектор позиций букв
    * @return Строка
    */
    std::wstring convert(const std::vector<int>& v); ///<Приватный метод для конвертации вектора чисел в строку
     /** @brief Метод проверки ключа
    * @details Преобразовывает строчные буквы в прописные
    * @param [in] s Строка ключа
    * @return Строка
    * @trow cipher_error, если ключ не соответствует требованиям
    */
    std::wstring getValidKey(const std::wstring & ws); ///<Приватный метод для проверки ключа на валидность
     /** @brief Метод проверки текста
    * @details Преобразовывает строчные буквы в прописные
    * @param [in] ws Строка ключа
    * @return Строка
    * @trow cipher_error, если текст не соответствует требованиям
    */
    std::wstring getValidOpenText(const std::wstring & ws); ///<Приватный метод для проверки открытого текста на валидность
     /** @brief Метод проверки зашифрованного текста
    * @details Преобразовывает строчные буквы в прописные
    * @param [in] ws Строка ключа
    * @return Строка
    * @trow cipher_error, если текст не соответствует требованиям
    */
    std::wstring getValidCipherText(const std::wstring & ws); ///<Приватный метод для проверки зашифрованного текста на валидность
public:
    modBetaCipher()=delete; ///<Удаляем конструктор по умолчанию
    /** @brief Конструктор для установки ключа 
    * @details Записывает в переменную класса 
    * вектор позиции букв полученные из строки с помощью convert
    * @param [in] wskey Строка-ключ
    * @trow cipher_error, если ключ не соответствует требованиям
    */
    modBetaCipher(const std::wstring& wskey); ///<Конструктор с параметром - устанавливает ключ шифрования/дешифрования
    /** @brief Функция зашифрования
    * @details Функция шифрует строку методом Гронсфельда
    * @param [in] open_text Строка с текстом
    * @trow cipher_error, если строка не соответсвует требованиям 
    */
    std::wstring encrypt(const std::wstring& open_text); ///<Метод для шифрования открытого текста
    /** @brief Функция расшифрования 
    * @details Функция расшифровывает строку методом Гронсфельда
    * @param [in] cipher_text cipher_text
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
