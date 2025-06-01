#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

// ������� ��� �������� ���� ���������� �� �������
template <typename T>
void removeDuplicates(std::vector<T>& vec)
{
    // ������� ��������� ��� ������������ ���������� ���������
    std::unordered_set<T> seen;

    // ���������� ������ erase-remove � ������-��������
    vec.erase(
        std::remove_if(
            vec.begin(),
            vec.end(),
            [&seen](const T& value)
            {
                // ���� ������� ��� ����������, ������� ��� (���������� true)
                if (seen.count(value) > 0)
                {
                    return true;
                }

                // ����� ��������� � ��������� � ��������� � �������
                seen.insert(value);
                return false;
            }
        ),
        vec.end()
    );
}

int main()
{
    // ������� � ��������� �������� ������
    std::vector<int> numbers = { 1, 1, 2, 5, 6, 1, 2, 4 };

    // ������� �������� ������
    std::cout << "[IN]: ";
    for (const auto& num : numbers)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // ������� ���������
    removeDuplicates(numbers);

    // ��������� ��������� (�� ������� ������ ����� ������ ���� ������������)
    std::sort(numbers.begin(), numbers.end());

    // ������� ���������
    std::cout << "[OUT]: ";
    for (const auto& num : numbers)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}