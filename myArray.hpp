#ifndef MYARRAY_HPP
#define MYARRAY_HPP

template <typename T>
class MyArray {
private:
    T* data;        // Указатель на массив элементов
    int capacity;   // Текущая емкость массива
    int length;     // Текущая длина массива

public:
    // Конструктор по умолчанию
    MyArray(int size = 1) : capacity(10), length(0) {
        data = new T[capacity];  // Инициализация массива с начальной емкостью
    }

    // Деструктор
    ~MyArray() {
        delete[] data; // Освобождение выделенной памяти
    }

    // Метод для добавления элемента в конец массива
    void MPUSH(const T& element) {
        if (length == capacity) {
            resize(); // Увеличение емкости, если массив полон
        }
        data[length++] = element; // Добавление элемента и увеличение длины
    }

    // Метод для добавления элемента по индексу
    void MPUSH(int index, const T& element) {
        if (index < 0 || index > length) {
            throw std::out_of_range("Index out of range");
        }
        if (length == capacity) {
            resize(); // Увеличение емкости, если массив полон
        }
        // Сдвиг элементов вправо, чтобы освободить место
        for (int i = length; i > index; --i) {
            data[i] = data[i - 1];
        }
        data[index] = element; // Вставка элемента
        length++; // Увеличение длины
    }

    // Метод для удаления элемента по индексу
    void MDEL(int index) {
        if (index < 0 || index >= length) {
            throw std::out_of_range("Index out of range");
        }
        // Сдвиг элементов влево, чтобы заполнить пробел
        for (int i = index; i < length - 1; ++i) {
            data[i] = data[i + 1];
        }
        length--; // Уменьшение длины
    }

    // Метод для получения элемента по индексу (неконстантная версия)
    T& MGET(int index) {
        if (index < 0 || index >= length) {
            throw std::out_of_range("Index out of range");
        }
        return data[index]; // Возвращаем элемент
    }

    // Константная версия метода MGET
    const T& MGET(int index) const {
        if (index < 0 || index >= length) {
            throw std::out_of_range("Index out of range");
        }
        return data[index]; // Возвращаем элемент
    }

    // Метод для замены элемента по индексу
    void MRESET(int index, const T& element) {
        if (index < 0 || index >= length) {
            throw std::out_of_range("Index out of range");
        }
        data[index] = element; // Замена элемента
    }

    // Увеличение емкости массива
    void resize() {
        capacity *= 2; // Увеличиваем емкость в два раза
        T* newData = new T[capacity]; // Создаем новый массив с новой емкостью
        for (int i = 0; i < length; i++) {
            newData[i] = data[i]; // Копируем старые данные в новый массив
        }
        delete[] data; // Освобождаем старый массив
        data = newData; // Перенаправляем указатель на новый массив
    }

    // Метод для получения текущей длины массива
    int lengtharr() const {
        return length; // Возвращаем длину
    }

    // Сохранение массива в файл
    void saveToFile(const std::string& filename) const {
        std::ofstream file(filename);
        if (!file) {
            throw std::runtime_error("Unable to open file for writing");
        }
        for (size_t i = 0; i < length; ++i) {
            file << data[i] << "\n";
        }
        file.close();
    }

    // Очистка массива
    void clear() {
        length = 0; // Просто сбрасываем размер
    }

    // Загрузка массива из файла
    void loadFromFile(const std::string& filename) {
        std::ifstream file(filename);
        if (!file) {
            throw std::runtime_error("Unable to open file for reading");
        }
        clear(); // Очищаем текущий массив перед загрузкой
        T value;
        while (file >> value) {
            MPUSH(value); // Добавляем элементы в массив
        }
        file.close();
    }

    // Метод для чтения всех элементов массива
    void print() const {
        for (int i = 0; i < length; i++) {
            std::cout << data[i] << " "; // Выводим каждый элемент
        }
        std::cout << std::endl; // Переход на новую строку
    }
};

#endif