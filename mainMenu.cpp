#include <iostream>
#include <stdexcept>
#include <fstream>
#include "myListKV.hpp"
#include "myVector.hpp"
#include "myArray.hpp"
#include "mySinglyLinkedList.hpp"
#include "myDoublyLinkedList.hpp"
#include "myQueue.hpp"
#include "myStack.hpp"
#include "myHashMap.hpp"
#include "myFullBinaryTree.hpp"

// Меню для работы с массивом
static void arrayMenu() {
    char choice;
    std::string value;
    int key;
    MyArray<std::string> array;
    do {
        std::cout << "[M] Массив\n1. MPUSH\n2. MPUSH(по индексу)\n3. MDEL\n4. MGET\n5. MRESET\n6. LOADFROMFILE\n7. SAVETOFILE\n8. Назад\nВаш выбор: ";
        std::cin >> choice;
        switch (choice) {
        case '1':
            std::cout << "Введите значение для добавления: ";
            std::cin >> value;
            array.MPUSH(value);
            break;
        case '2':
            std::cout << "Введите индекс значение для добавления: ";
            std::cin >> key >> value;
            array.MPUSH(key, value);
            break;
        case '3':
            std::cout << "Введите индекс для удаления: ";
            std::cin >> key;
            array.MDEL(key);
            break;
        case '4':
            std::cout << "Введите индекс для вывода значения: ";
            std::cin >> key;
            std::cout << array.MGET(key) << std::endl;
            break;
        case '5':
            std::cout << "Введите индекс и значение для добавления: ";
            std::cin >> key >> value;
            array.MRESET(key, value);
            break;
        case '6':
            std::cout << "Введите название файла: ";
            std::cin >> value;
            array.loadFromFile(value);
            break;
        case '7':
            std::cout << "Введите название файла: ";
            std::cin >> value;
            array.saveToFile(value);
            break;
        case '8':
            return;
        default:
            std::cout << "Неверный выбор!\n";
        }
    } while (choice != '8');
}

// Меню для работы со списком
static void SinglelistMenu() {
    char choice;
    std::string value;
    int key;
    MySinglyLinkedList<std::string> singleList;
    do {
        std::cout << "[L] Список\n1. LPUSHHEAD\n2. LPUSHTEIL\n3. LDELHEAD\n4. LDELTAIL\n5. LDEL\n6. LGET\n\n7. LOADFROMFILE\n8. SAVE2FILE\n9. Назад\nВаш выбор: ";
        std::cin >> choice;
        switch (choice) {
        case '1':
            std::cout << "Введите значение для добавления: ";
            std::cin >> value;
            singleList.LPUSHHEAD(value);
            break;
        case '2':
            std::cout << "Введите значение для добавления: ";
            std::cin >> value;
            singleList.LPUSHTAIL(value);
            break;
        case '3':
            singleList.LDELHEAD();
            break;
        case '4':
            singleList.LDELTAIL();
            break;
        case '5':
            std::cout << "Введите индекс для удаления: ";
            std::cin >> key;
            singleList.LDEL(key);
            break;
        case '6':
            std::cout << "Введите ключ для вывода: ";
            std::cin >> key;
            std::cout << singleList.LGET(key) << std::endl;
            break;
        case '7':
            std::cout << "Введите название файла: ";
            std::cin >> value;
            singleList.loadFromFile(value);
            break;
        case '8':
            std::cout << "Введите название файла: ";
            std::cin >> value;
            singleList.saveToFile(value);
            break;
        case '9':
            return;
        default:
            std::cout << "Неверный выбор!\n";
        }
    } while (choice != '9');
}

// Меню для работы со списком
static void DoublylistMenu() {
    char choice;
    std::string value;
    int key;
    MyDoublyLinkedList<std::string> doublyList;
    do {
        std::cout << "[L] Список\n1. LPUSHHEAD\n2. LPUSHTAIL\n3. LDELHEAD\n4. LDELTAIL\n5. LDEL\n6. LGET\n7. LOADFROMFILE\n8. SAVETOFILE\n9. Назад\nВаш выбор: ";
        std::cin >> choice;
        switch (choice) {
        case '1':
            std::cout << "Введите значение для добавления: ";
            std::cin >> value;
            doublyList.LPUSHHEAD(value);
            break;
        case '2':
            std::cout << "Введите значение для добавления: ";
            std::cin >> value;
            doublyList.LPUSHTAIL(value);
            break;
        case '3':
            doublyList.LDELHEAD();
            break;
        case '4':
            doublyList.LDELTAIL();
            break;
        case '5':
            std::cout << "Введите индекс для удаления: ";
            std::cin >> key;
            doublyList.LDEL(key);
            break;
        case '6':
            std::cout << "Введите индекс для вывода: ";
            std::cin >> key;
            std::cout << doublyList.LGET(key) << std::endl;
            break;
        case '7':
            std::cout << "Введите название файла: ";
            std::cin >> value;
            doublyList.loadFromFile(value);
            break;
        case '8':
            std::cout << "Введите название файла: ";
            std::cin >> value;
            doublyList.saveToFile(value);
            break;
        case '9':
            return;
        default:
            std::cout << "Неверный выбор!\n";
        }
    } while (choice != '9');
}

// Меню для работы с очередью
static void queueMenu() {
    char choice;
    std::string value;
    Queue<std::string> queue;
    do {
        std::cout << "[Q] Очередь\n1. QPUSH\n2. QPOP\n3. QGET\n4. LOADFROMFILE\n5. SAVETOFILE\n6. Назад\nВаш выбор: ";
        std::cin >> choice;
        switch (choice) {
        case '1':
            std::cout << "Введите значение для добавления: ";
            std::cin >> value;
            queue.Q_PUSH(value);
            break;
        case '2':
            queue.Q_DEL();
            break;
        case '3':
            std::cout << queue.Q_POP() << std::endl;
            break;
        case '4':
            std::cout << "Введите название файла: ";
            std::cin >> value;
            queue.loadFromFile(value);
            break;
        case '5':
            std::cout << "Введите название файла: ";
            std::cin >> value;
            queue.saveToFile(value);
            break;
        case '6':
            return;
        default:
            std::cout << "Неверный выбор!\n";
        }
    } while (choice != '6');
}

// Меню для работы с деревом
static void treeMenu() {
    char choice;
    int value;
    std::string filename;
    FullBinaryTree<int> tree;
    do {
        std::cout << "[T] Дерево\n1. TINSERT\n2. TDEL\n3. TGET\n4. LOADFROMFILE\n5. SAVETOFILE\n6. Назад\nВаш выбор: ";
        std::cin >> choice;
        switch (choice) {
        case '1':
            std::cout << "Введите значение для вставки: ";
            std::cin >> value;
            tree.TINSERT(value);
            break;
        case '2':
            std::cout << "Введите значение для удаления: ";
            std::cin >> value;
            tree.TDEL(value);
            break;
        case '3':
            std::cout << "Введите значение для вывода: ";
            std::cin >> value;
            std::cout << "Есть ли этот элемент в дереве: " << tree.TGET(value) << std::endl;
            std::cout << "Дерево полное: " << tree.isFull() << std::endl;
            tree.print();
            break;
        case '4':
            std::cout << "Введите название файла: ";
            std::cin >> filename;
            tree.loadFromFile(filename);
            break;
        case '5':
            std::cout << "Введите название файла: ";
            std::cin >> filename;
            tree.saveToFile(filename);
            break;
        case '6':
            return;
        default:
            std::cout << "Неверный выбор!\n";
        }
    } while (choice != '6');
}

// Меню для работы с хеш-таблицей
static void hashTableMenu() {
    char choice;
    std::string key;
    std::string value;
    std::string filename;
    MyHashMap<std::string, std::string> hashTable;
    do {
        std::cout << "[H] Хеш-таблица\n1. HSET\n2. HDEL\n3. HGET\n4. LOADFROMFILE\n5. SAVETOFILE\n6. Назад\nВаш выбор: ";
        std::cin >> choice;
        switch (choice) {
        case '1':
            std::cout << "Введите ключ: ";
            std::cin >> key;
            std::cout << "Введите значение: ";
            std::cin >> value;
            hashTable.HSET(key, value);
            break;
        case '2':
            std::cout << "Введите ключ для удаления: ";
            std::cin >> key;
            hashTable.HDEL(key);
            break;
        case '3':
            std::cout << "Введите ключ для получения значения: ";
            std::cin >> key;
            std::cout << hashTable.HGET(key) << std::endl;
            hashTable.print();
            break;
        case '4':
            std::cout << "Введите название для загрузки данных из файла: ";
            std::cin >> filename;
            hashTable.loadFromFile(filename);
            break;
        case '5':
            std::cout << "Введите название для выгрузки данных в файл: ";
            std::cin >> filename;
            hashTable.saveToFile(filename);
            break;
        case '6':
            return;
        default:
            std::cout << "Неверный выбор!\n";
        }
    } while (choice != '6');
}

// Меню для работы со стеком
static void stackMenu() {
    char choice;
    std::string value;
    MyStack<std::string> stack;
    do {
        std::cout << "[S] Стек\n1. SPUSH\n2. SPOP\n3. SGET\n4. LOADFROMFILE\n5. SAVETOFILE\n6. Назад\nВаш выбор: ";
        std::cin >> choice;
        switch (choice) {
        case '1':
            std::cout << "Введите значение для добавления: ";
            std::cin >> value;
            stack.SPUSH(value);
            break;
        case '2':
            stack.SDEL();
            break;
        case '3':
            stack.SPOP();
            break;
        case '4':
            std::cout << "Введите название для загрузки данных из файла: ";
            std::cin >> value;
            stack.loadFromFile(value);
            break;
        case '5':
            std::cout << "Введите название для выгрузки данных в файл: ";
            std::cin >> value;
            stack.saveToFile(value);
            break;
        case '6':
            return;
        default:
            std::cout << "Неверный выбор!\n";
        }
    } while (choice != '6');
}

// Главное меню программы
static void mainMenu() {
    char choice;
    do {
        std::cout << "=========================================\n";
        std::cout << "            МЕНЮ СТРУКТУР ДАННЫХ\n";
        std::cout << "=========================================\n";
        std::cout << "[M] Массив\n[X] ОдСписок\n[D] ДвСписок\n[Q] Очередь\n[S] Стек\n[H] Хеш-таблица\n[T] Дерево\n[E] Выход\n";
        std::cout << "Ваш выбор: ";
        std::cin >> choice;

        switch (choice) {
        case 'M':
            arrayMenu();
            break;
        case 'X':
            SinglelistMenu();
            break;
        case 'D':
            DoublylistMenu();
            break;
        case 'Q':
            queueMenu();
            break;
        case 'S':
            stackMenu();
            break;
        case 'H':
            hashTableMenu();
            break;
        case 'T':
            treeMenu();
            break;
        case 'E':
            std::cout << "Завершение работы...\n";
            break;
        default:
            std::cout << "Неверный выбор!\n";
        }
    } while (choice != 'E');
}

int main() {
    system("chcp 65001");
    mainMenu();
}