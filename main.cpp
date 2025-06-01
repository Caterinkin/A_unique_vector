#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

// Функция для удаления всех дубликатов из вектора
template <typename T>
void removeDuplicates(std::vector<T>& vec)
{
    // Создаем множество для отслеживания уникальных элементов
    std::unordered_set<T> seen;

    // Используем идиому erase-remove с лямбда-функцией
    vec.erase(
        std::remove_if(
            vec.begin(),
            vec.end(),
            [&seen](const T& value)
            {
                // Если элемент уже встречался, удаляем его (возвращаем true)
                if (seen.count(value) > 0)
                {
                    return true;
                }

                // Иначе добавляем в множество и оставляем в векторе
                seen.insert(value);
                return false;
            }
        ),
        vec.end()
    );
}

int main()
{
    // Создаем и заполняем тестовый вектор
    std::vector<int> numbers = { 1, 1, 2, 5, 6, 1, 2, 4 };

    // Выводим исходный вектор
    std::cout << "[IN]: ";
    for (const auto& num : numbers)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Удаляем дубликаты
    removeDuplicates(numbers);

    // Сортируем результат (по условию задачи вывод должен быть отсортирован)
    std::sort(numbers.begin(), numbers.end());

    // Выводим результат
    std::cout << "[OUT]: ";
    for (const auto& num : numbers)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
