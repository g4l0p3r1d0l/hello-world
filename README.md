# Отчёт по лабораторной работе №2

**Репозиторий:** https://github.com/g4l0p3r1d0l/hello-world

## Домашнее задание (Parts I, II, III)

### Part I – Создание репозитория и первый коммит

#### 1.1 Создать пустой репозиторий на GitHub
На сайте GitHub создан новый репозиторий с именем `hello-world` (без README, .gitignore, лицензии).

#### 1.2 Клонировать репозиторий локально
```bash
git clone https://github.com/g4l0p3r1d0l/hello-world.git
cd hello-world
```

#### 1.3 Создать файл `hello_world.cpp` с плохим стилем (`using namespace std;`)
Содержимое `hello_world.cpp`:
```cpp
#include <iostream>
using namespace std;

int main() {
    cout << "Hello world!" << endl;
    return 0;
}
```

#### 1.4 Добавить файл и сделать первый коммит
```bash
git add hello_world.cpp
git commit -m "added hello-world.cpp using namespace std"
```

#### 1.5 Изменить программу – добавить запрос имени пользователя
Новое содержимое `hello_world.cpp`:
```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string name;
    cout << "Enter your name: ";
    cin >> name;
    cout << "Hello world from " << name << "!" << endl;
    return 0;
}
```

#### 1.6 Закоммитить новую версию без `git add` (используя `-am`)
```bash
git commit -am "Add user input and personalized greeting"
```
> Пояснение: флаг `-a` автоматически добавляет все изменённые отслеживаемые файлы.

#### 1.7 Отправить изменения в удалённый репозиторий
```bash
git push origin main
```

#### 1.8 Проверить историю коммитов на GitHub
На вкладке `Commits` репозитория отображаются два коммита.

---

### Part II – Ветка `patch1`, pull request и слияние

#### 2.1 Создать локальную ветку `patch1`
```bash
git checkout -b patch1
```

#### 2.2 Удалить `using namespace std;` (явно указать `std::`)
Содержимое `hello_world.cpp` после правки:
```cpp
#include <iostream>
#include <string>

int main() {
    std::string name;
    std::cout << "Enter your name: ";
    std::cin >> name;
    std::cout << "Hello world from " << name << "!" << std::endl;
    return 0;
}
```

#### 2.3 Закоммитить и запушить ветку `patch1` в удалённый репозиторий
```bash
git commit -am "Remove using namespace std, use std:: prefix"
git push origin patch1
```
**Вывод:**
```
[patch1 8ae6744] Remove using namespace std, use std:: prefix
 1 file changed, 4 insertions(+), 5 deletions(-)
...
remote: Create a pull request for 'patch1' on GitHub...
To https://github.com/g4l0p3r1d0l/hello-world.git
 * [new branch]      patch1 -> patch1
```

#### 2.4 Создать pull request `patch1 → main` на GitHub
Через веб-интерфейс: `Pull requests` → `New pull request` → `base: main` ← `compare: patch1` → `Create pull request`.

#### 2.5 Добавить комментарии в код (в ветке `patch1`)
```cpp
#include <iostream>
#include <string>

// Основная функция программы
int main() {
    std::string name;                           // Переменная для имени
    std::cout << "Enter your name: ";           // Запрос имени
    std::cin >> name;                           // Ввод имени
    std::cout << "Hello world from " << name << "!" << std::endl;
    return 0;
}
```

#### 2.6 Закоммитить и запушить обновления (PR обновится автоматически)
```bash
git commit -am "Add comments"
git push origin patch1
```
**Вывод:**
```
[patch1 4b60133] Add comments
 1 file changed, 4 insertions(+), 3 deletions(-)
...
To https://github.com/g4l0p3r1d0l/hello-world.git
   8ae6744..4b60133  patch1 -> patch1
```

#### 2.7 Выполнить слияние PR `patch1 → main` на GitHub и удалить ветку `patch1` в удалённом репозитории
На странице PR нажата кнопка `Merge pull request` → `Confirm merge`, после слияния – `Delete branch`.

**Сообщение на GitHub:**  
`Pull request successfully merged and closed. patch1 branch can be safely deleted.`

#### 2.8 Локально переключиться на `main`, обновить её и удалить локальную ветку `patch1`
```bash
git checkout main
git pull origin main
git branch -d patch1
```
**Вывод:** `Deleted branch patch1 (was 4b60133).`

#### 2.9 Просмотреть историю коммитов
```bash
git log --oneline --graph
```

---

### Part III – Ветка `patch2`, `clang-format`, конфликт и `rebase`

#### 3.1 Создать локальную ветку `patch2` от актуального `main`
```bash
git checkout -b patch2
```

#### 3.2 Применить стиль кода Mozilla с помощью `clang-format`
```bash
clang-format -style=Mozilla -i hello_world.cpp
```

#### 3.3 Закоммитить и запушить ветку `patch2`
```bash
git commit -am "Apply Mozilla code style"
git push origin patch2
```
**Вывод:**
```
Enumerating objects: 5, done.
...
To https://github.com/g4l0p3r1d0l/hello-world.git
 * [new branch]      patch2 -> patch2
```

#### 3.4 Создать pull request `patch2 → main` на GitHub
Через веб-интерфейс создан PR `patch2 → main`.

#### 3.5 Изменить комментарии в ветке `main` на GitHub (для создания конфликта)
В файле `hello_world.cpp` ветки `main` комментарии переведены на русский язык:
```cpp
// Основная функция программы
int main() {
    std::string name;                           // Переменная для имени
    ...
}
```
Коммит сделан напрямую в `main`.

#### 3.6 Убедиться, что в PR появились конфликты
На странице PR отображается сообщение:  
`This branch has conflicts that must be resolved`.

#### 3.7 Локально выполнить `rebase` и разрешить конфликт
```bash
git checkout main
git pull origin main
git checkout patch2
git rebase main
```
**Вывод:**  
```
Auto-merging hello_world.cpp
CONFLICT (content): Merge conflict in hello_world.cpp
error: could not apply b88094f... Apply Mozilla code style
```

Файл `hello_world.cpp` отредактирован вручную: оставлены русские комментарии из `main` и форматирование (стиль Mozilla) из `patch2`.  

После разрешения конфликта:
```bash
git add hello_world.cpp
git rebase --continue
```
**Вывод:**
```
[detached HEAD 1ed2cc2] Apply Mozilla code style
 1 file changed, 8 insertions(+), 8 deletions(-)
Successfully rebased and updated refs/heads/patch2.
```

#### 3.8 Сделать `force push` в ветку `patch2`
```bash
git push --force-with-lease origin patch2
```
**Вывод:**
```
Enumerating objects: 5, done.
...
To https://github.com/g4l0p3r1d0l/hello-world.git
 + b88094f...1ed2cc2 patch2 -> patch2 (forced update)
```

#### 3.9 Убедиться, что конфликты в PR исчезли
При обновлении страницы PR отображается:  
`This branch has no conflicts with the base branch`.

#### 3.10 Вмержить PR `patch2 → main` на GitHub и удалить ветку `patch2` в удалённом репозитории
Нажата кнопка `Merge pull request` → `Confirm merge`, затем `Delete branch`.

#### 3.11 Локально обновить `main` и удалить ветку `patch2`
```bash
git checkout main
git pull origin main
git branch -d patch2
```

#### 3.12 Финальная проверка истории
```bash
git log --oneline --graph
```
Ветка `main` содержит все изменения: коммиты из `patch1` и `patch2` (после слияний).

---

## Выводы

- Освоены основные команды Git: `clone`, `add`, `commit`, `push`, `pull`, `branch`, `checkout`, `rebase`, `merge`, `log`.
- Изучен процесс создания pull request и разрешения конфликтов с помощью `rebase` и `force push`.
- Применён автоматический форматировщик кода `clang-format` для приведения к единому стилю.
- Получен практический опыт работы с ветками и удалёнными репозиториями на примере GitHub.

**Репозиторий:** https://github.com/g4l0p3r1d0l/hello-world
