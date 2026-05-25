#include <iostream>
#include <string>

// Основная функция программы
int
main()
{
  std::string name;                 // Переменная для имени
  std::cout << "Enter your name: "; // Запрос имени
  std::cin >> name;                 // Ввод имени
  std::cout << "Hello world from " << name << "!" << std::endl;
  return 0;
}
