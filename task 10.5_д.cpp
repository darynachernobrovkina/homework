#include <iostream>

template <typename T>
void swap(T *xp, T *yp)
{
    T temp = *xp;
    *xp = *yp;
    *yp = temp;
}

template <typename T>
class MyArray
{
private:
    T *arr;
    int size;

public:
    MyArray();
    MyArray(T arr[], int len)
    {
        this->arr = new T[len];
        for (size_t i = 0; i < len; i++)
        {
            this->arr[i] = arr[i];
        }
        this->size = len;
    }

    void sort()
    {
        for (size_t i = 0; i < this->size - 1; i++)
            for (size_t j = 0; j < this->size - i - 1; j++)
                if (std::hash<T>{}(this->arr[j]) > std::hash<T>{}(this->arr[j + 1]))
                    swap(&this->arr[j], &this->arr[j + 1]);
    }

    static T *sort(T arr[], int len)
    {
        for (size_t i = 0; i < len - 1; i++)
            for (size_t j = 0; j < len - i - 1; j++)
                if (std::hash<T>{}(arr[j]) > std::hash<T>{}(arr[j + 1]))
                    swap(&arr[j], &arr[j + 1]);
        return arr;
    }

    void show()
    {
        for (size_t i = 0; i < this->size; i++)
        {
            std::cout << this->arr[i] << " ";
        }
        std::cout << std::endl;
    }
};

template <typename T>
void print(T arr[], int len)
{
    for (size_t i = 0; i < len; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main()
{

    int ints[] = {1, 6, 12, -3, 3, 2};
    double doubles[] = {4.12, 5.16, 1.45, 1, 56.00923, -41.4, -1.6};
    std::string strings[] = {"hello", "Dima", "Vova", "135", "Masha", "magazine", "12", "@"};

    MyArray<int> *first = new MyArray<int>(ints, 6);
    MyArray<double> *second = new MyArray<double>(doubles, 7);
    MyArray<std::string> *third = new MyArray<std::string>(strings, 8);

    std::cout << "Self methods: " << std::endl;

    first->show();
    first->sort();
    first->show();

    std::cout << std::endl;

    second->show();
    second->sort();
    second->show();

    std::cout << std::endl;

    third->show();
    third->sort();
    third->show();

    std::cout << std::endl;

    int ints2[] = {1, 6, 12, -3, 3, 2};
    double doubles2[] = {4.12, 5.16, 1.45, 1, 56.00923, -41.4, -1.6};
    std::string strings2[] = {"hello", "Dima", "Vova", "135", "Masha", "magazine", "12", "@"};

    std::cout << "Class static methods: " << std::endl;

    print<int>(ints2, 6);
    MyArray<int>::sort(ints2, 6);
    print<int>(ints2, 6);

    std::cout << std::endl;

    print<double>(doubles2, 7);
    MyArray<double>::sort(doubles2, 7);
    print<double>(doubles2, 7);

    std::cout << std::endl;

    print<std::string>(strings2, 8);
    MyArray<std::string>::sort(strings2, 8);
    print<std::string>(strings2, 8);
    return 0;
}
