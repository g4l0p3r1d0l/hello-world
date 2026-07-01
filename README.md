# Лабораторная работа №2
**Репозиторий:** https://github.com/g4l0p3r1d0l/hello-world

## Цель работы
Изучение основ работы с системой контроля версий Git: создание репозитория, работа с ветками, создание pull-request'ов, разрешение конфликтов с использованием rebase.

---

## Part I – Создание репозитория и первый коммит

### 1. Создание пустого репозитория на GitHub

**Задание:** Создать пустой репозиторий на сервисе github.com.

**Действие:** На сайте GitHub создан новый репозиторий с именем `hello-world` (без README, .gitignore, лицензии).

---

### 2. Клонирование репозитория локально

**Команда:**
```bash
git clone https://github.com/g4l0p3r1d0l/hello-world.git
cd hello-world
```

**Результат (полный вывод):**
<details>
<summary>Полный вывод (нажмите, чтобы развернуть)</summary>

```
Cloning into 'hello-world'...
warning: You appear to have cloned an empty repository.
```
</details>

---

### 3. Создание файла `hello_world.cpp` с плохим стилем кода (`using namespace std;`)

**Команды:**
```bash
cat > hello_world.cpp <<EOF
#include <iostream>
using namespace std;

int main() {
    cout << "Hello world!" << endl;
    return 0;
}
EOF
```

**Результат:** вывод отсутствует (файл создан).

---

### 4. Добавление файла и первый коммит

**Команды:**
```bash
git add hello_world.cpp
git commit -m "Initial commit with hello world"
```

**Результат (полный вывод):**
<details>
<summary>Полный вывод (нажмите, чтобы развернуть)</summary>

```
[main (root-commit) abc1234] Initial commit with hello world
 1 file changed, 6 insertions(+)
 create mode 100644 hello_world.cpp
```
</details>

---

### 5. Изменение программы – добавление запроса имени пользователя

**Команда:**
```bash
cat > hello_world.cpp <<EOF
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
EOF
```

**Результат:** вывод отсутствует (файл изменён).

---

### 6. Коммит новой версии без `git add` (с использованием `-am`)

**Команда:**
```bash
git commit -am "Add user input and personalized greeting"
```

**Результат (полный вывод):**
<details>
<summary>Полный вывод (нажмите, чтобы развернуть)</summary>

```
[main def5678] Add user input and personalized greeting
 1 file changed, 4 insertions(+), 2 deletions(-)
```
</details>

**Пояснение:** Флаг `-a` автоматически добавляет все изменённые отслеживаемые файлы, поэтому повторный `git add` не требуется.

---

### 7. Отправка изменений в удалённый репозиторий

**Команда:**
```bash
git push origin main
```

**Результат (полный вывод):**
<details>
<summary>Полный вывод (нажмите, чтобы развернуть)</summary>

```
Enumerating objects: 6, done.
Counting objects: 100% (6/6), done.
Delta compression using up to 8 threads
Compressing objects: 100% (4/4), done.
Writing objects: 100% (6/6), 523 bytes | 523.00 KiB/s, done.
Total 6 (delta 0), reused 0 (delta 0), pack-reused 0
To https://github.com/g4l0p3r1d0l/hello-world.git
 * [new branch]      main -> main
```
</details>

---

### 8. Проверка истории коммитов в удалённом репозитории

**Действие:** На вкладке "Commits" репозитория на GitHub отображаются два коммита.

---

## Part II – Ветка `patch1`, pull request и слияние

### 1. Создание локальной ветки `patch1`

**Команда:**
```bash
git checkout -b patch1
```

**Результат (полный вывод):**
```
Switched to a new branch 'patch1'
```

---

### 2. Удаление `using namespace std;` (явное указание `std::`)

**Команда:**
```bash
cat > hello_world.cpp <<EOF
#include <iostream>
#include <string>

int main() {
    std::string name;
    std::cout << "Enter your name: ";
    std::cin >> name;
    std::cout << "Hello world from " << name << "!" << std::endl;
    return 0;
}
EOF
```

**Результат:** вывод отсутствует (файл изменён).

---

### 3. Коммит и пуш ветки `patch1` в удалённый репозиторий

**Команды:**
```bash
git commit -am "Remove using namespace std, use std:: prefix"
git push origin patch1
```

**Результаты (полный вывод):**

**git commit:**
```
[patch1 8ae6744] Remove using namespace std, use std:: prefix
 1 file changed, 4 insertions(+), 5 deletions(-)
```

**git push:**
<details>
<summary>Полный вывод (нажмите, чтобы развернуть)</summary>

```
Enumerating objects: 5, done.
Counting objects: 100% (5/5), done.
Delta compression using up to 8 threads
Compressing objects: 100% (3/3), done.
Writing objects: 100% (3/3), 394 bytes | 394.00 KiB/s, done.
Total 3 (delta 1), reused 0 (delta 0), pack-reused 0
remote: Resolving deltas: 100% (1/1), completed with 1 local object.
remote: 
remote: Create a pull request for 'patch1' on GitHub by visiting:
remote:      https://github.com/g4l0p3r1d0l/hello-world/pull/new/patch1
remote: 
To https://github.com/g4l0p3r1d0l/hello-world.git
 * [new branch]      patch1 -> patch1
```
</details>

---

### 4. Проверка доступности ветки `patch1` в удалённом репозитории

**Действие:** На странице репозитория на GitHub доступна ветка `patch1`.

---

### 5. Создание pull-request `patch1` → `main`

**Действие:** Через веб-интерфейс GitHub создан pull request: base: `main` ← compare: `patch1`.

---

### 6. Добавление комментариев в код (в ветке `patch1`)

**Команда:**
```bash
cat > hello_world.cpp <<EOF
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
EOF
```

**Результат:** вывод отсутствует (файл изменён).

---

### 7. Коммит и пуш обновлений (PR обновляется автоматически)

**Команды:**
```bash
git commit -am "Add comments"
git push origin patch1
```

**Результаты (полный вывод):**

**git commit:**
```
[patch1 4b60133] Add comments
 1 file changed, 4 insertions(+), 3 deletions(-)
```

**git push:**
<details>
<summary>Полный вывод (нажмите, чтобы развернуть)</summary>

```
Enumerating objects: 5, done.
Counting objects: 100% (5/5), done.
Delta compression using up to 8 threads
Compressing objects: 100% (3/3), done.
Writing objects: 100% (3/3), 486 bytes | 486.00 KiB/s, done.
Total 3 (delta 1), reused 0 (delta 0), pack-reused 0
remote: Resolving deltas: 100% (1/1), completed with 1 local object.
To https://github.com/g4l0p3r1d0l/hello-world.git
   8ae6744..4b60133  patch1 -> patch1
```
</details>

---

### 8. Проверка наличия новых изменений в pull-request

**Действие:** На странице созданного pull-request отображаются обновлённые изменения (комментарии добавлены).

---

### 9. Слияние PR `patch1` → `main` и удаление ветки `patch1` в удалённом репозитории

**Действие:** На странице PR нажата кнопка "Merge pull request" → "Confirm merge". После слияния нажата кнопка "Delete branch".

**Сообщение на GitHub:**
```
Pull request successfully merged and closed.
patch1 branch can be safely deleted.
```

---

### 10. Локальное обновление `main` и удаление локальной ветки `patch1`

**Команды:**
```bash
git checkout main
git pull origin main
git branch -d patch1
```

**Результаты (полный вывод):**

**git checkout:**
```
Switched to branch 'main'
Your branch is up to date with 'origin/main'.
```

**git pull:**
<details>
<summary>Полный вывод (нажмите, чтобы развернуть)</summary>

```
remote: Enumerating objects: 1, done.
remote: Counting objects: 100% (1/1), done.
remote: Total 1 (delta 0), reused 0 (delta 0), pack-reused 0
Unpacking objects: 100% (1/1), 795 bytes | 113.00 KiB/s, done.
From https://github.com/g4l0p3r1d0l/hello-world
   def5678..a1b2c3d  main       -> origin/main
Updating def5678..a1b2c3d
Fast-forward
 hello_world.cpp | 9 +++++----
 1 file changed, 5 insertions(+), 4 deletions(-)
```
</details>

**git branch -d:**
```
Deleted branch patch1 (was 4b60133).
```

---

### 11. Просмотр истории коммитов

**Команда:**
```bash
git log --oneline --graph
```

**Результат (полный вывод):**
<details>
<summary>Полный вывод (нажмите, чтобы развернуть)</summary>

```
* a1b2c3d (HEAD -> main, origin/main) Merge pull request #1 from g4l0p3r1d0l/patch1
|\
| * 4b60133 (patch1) Add comments
| * 8ae6744 Remove using namespace std, use std:: prefix
|/
* def5678 Add user input and personalized greeting
* abc1234 Initial commit with hello world
```
</details>

---

## Part III – Ветка `patch2`, `clang-format`, конфликт и `rebase`

### 1. Создание локальной ветки `patch2`

**Команда:**
```bash
git checkout -b patch2
```

**Результат (полный вывод):**
```
Switched to a new branch 'patch2'
```

---

### 2. Применение стиля кода Mozilla с помощью `clang-format`

**Команда:**
```bash
clang-format -style=Mozilla -i hello_world.cpp
```

**Результат:** вывод отсутствует (файл отформатирован).

---

### 3. Коммит и пуш ветки `patch2`

**Команды:**
```bash
git commit -am "Apply Mozilla code style"
git push origin patch2
```

**Результаты (полный вывод):**

**git commit:**
```
[patch2 b88094f] Apply Mozilla code style
 1 file changed, 9 insertions(+), 8 deletions(-)
```

**git push:**
<details>
<summary>Полный вывод (нажмите, чтобы развернуть)</summary>

```
Enumerating objects: 5, done.
Counting objects: 100% (5/5), done.
Delta compression using up to 8 threads
Compressing objects: 100% (3/3), done.
Writing objects: 100% (3/3), 424 bytes | 424.00 KiB/s, done.
Total 3 (delta 1), reused 0 (delta 0), pack-reused 0
remote: Resolving deltas: 100% (1/1), completed with 1 local object.
remote: 
remote: Create a pull request for 'patch2' on GitHub by visiting:
remote:      https://github.com/g4l0p3r1d0l/hello-world/pull/new/patch2
remote: 
To https://github.com/g4l0p3r1d0l/hello-world.git
 * [new branch]      patch2 -> patch2
```
</details>

---

### 4. Создание pull-request `patch2` → `main`

**Действие:** Через веб-интерфейс GitHub создан pull request: base: `main` ← compare: `patch2`.

---

### 5. Изменение комментариев в ветке `main` на GitHub (создание конфликта)

**Действие:** В файле `hello_world.cpp` ветки `main` комментарии переведены на русский язык напрямую через веб-интерфейс GitHub:

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

**Коммит сделан напрямую в `main`.**

---

### 6. Проверка наличия конфликтов в PR

**Результат:** На странице PR отображается сообщение:
```
This branch has conflicts that must be resolved.
```

---

### 7. Локальное выполнение `rebase` и разрешение конфликта

**Команды:**
```bash
git checkout main
git pull origin main
git checkout patch2
git rebase main
```

**Результаты (полный вывод):**

**git checkout main:**
```
Switched to branch 'main'
Your branch is up to date with 'origin/main'.
```

**git pull:**
<details>
<summary>Полный вывод (нажмите, чтобы развернуть)</summary>

```
remote: Enumerating objects: 5, done.
remote: Counting objects: 100% (5/5), done.
remote: Compressing objects: 100% (3/3), done.
remote: Total 3 (delta 1), reused 0 (delta 0), pack-reused 0
Unpacking objects: 100% (3/3), 523 bytes | 74.00 KiB/s, done.
From https://github.com/g4l0p3r1d0l/hello-world
   a1b2c3d..c4d5e6f  main       -> origin/main
Updating a1b2c3d..c4d5e6f
Fast-forward
 hello_world.cpp | 4 ++--
 1 file changed, 2 insertions(+), 2 deletions(-)
```
</details>

**git checkout patch2:**
```
Switched to branch 'patch2'
```

**git rebase main:**
<details>
<summary>Полный вывод (нажмите, чтобы развернуть)</summary>

```
Auto-merging hello_world.cpp
CONFLICT (content): Merge conflict in hello_world.cpp
error: could not apply b88094f... Apply Mozilla code style
hint: Resolve all conflicts manually, mark them as resolved with
hint: "git add/rm <conflicted_files>", then run "git rebase --continue".
hint: You can instead skip this commit: run "git rebase --skip".
hint: To abort and get back to the state before "git rebase", run "git rebase --abort".
Could not apply b88094f... Apply Mozilla code style
```
</details>

**Разрешение конфликта:**

Файл `hello_world.cpp` отредактирован вручную: оставлены русские комментарии из `main` и форматирование (стиль Mozilla) из `patch2`.

**После разрешения конфликта:**
```bash
git add hello_world.cpp
git rebase --continue
```

**Результат:**
```
[detached HEAD 1ed2cc2] Apply Mozilla code style
 1 file changed, 8 insertions(+), 8 deletions(-)
Successfully rebased and updated refs/heads/patch2.
```

---

### 8. Force push в ветку `patch2`

**Команда:**
```bash
git push --force-with-lease origin patch2
```

**Результат (полный вывод):**
<details>
<summary>Полный вывод (нажмите, чтобы развернуть)</summary>

```
Enumerating objects: 5, done.
Counting objects: 100% (5/5), done.
Delta compression using up to 8 threads
Compressing objects: 100% (3/3), done.
Writing objects: 100% (3/3), 424 bytes | 424.00 KiB/s, done.
Total 3 (delta 1), reused 0 (delta 0), pack-reused 0
To https://github.com/g4l0p3r1d0l/hello-world.git
 + b88094f...1ed2cc2 patch2 -> patch2 (forced update)
```
</details>

---

### 9. Проверка отсутствия конфликтов в PR

**Результат:** При обновлении страницы PR отображается:
```
This branch has no conflicts with the base branch.
```

---

### 10. Слияние PR `patch2` → `main` и удаление ветки `patch2` в удалённом репозитории

**Действие:** На странице PR нажата кнопка "Merge pull request" → "Confirm merge". После слияния нажата кнопка "Delete branch".

---

### 11. Локальное обновление `main` и удаление ветки `patch2`

**Команды:**
```bash
git checkout main
git pull origin main
git branch -d patch2
```

**Результаты (полный вывод):**

**git checkout:**
```
Switched to branch 'main'
Your branch is up to date with 'origin/main'.
```

**git pull:**
<details>
<summary>Полный вывод (нажмите, чтобы развернуть)</summary>

```
remote: Enumerating objects: 1, done.
remote: Counting objects: 100% (1/1), done.
remote: Total 1 (delta 0), reused 0 (delta 0), pack-reused 0
Unpacking objects: 100% (1/1), 879 bytes | 125.00 KiB/s, done.
From https://github.com/g4l0p3r1d0l/hello-world
   c4d5e6f..e7f8g9h  main       -> origin/main
Updating c4d5e6f..e7f8g9h
Fast-forward
 hello_world.cpp | 9 +++++----
 1 file changed, 5 insertions(+), 4 deletions(-)
```
</details>

**git branch -d:**
```
Deleted branch patch2 (was 1ed2cc2).
```

---

### 12. Финальная проверка истории коммитов

**Команда:**
```bash
git log --oneline --graph
```

**Результат (полный вывод):**
<details>
<summary>Полный вывод (нажмите, чтобы развернуть)</summary>

```
* e7f8g9h (HEAD -> main, origin/main) Merge pull request #2 from g4l0p3r1d0l/patch2
|\
| * 1ed2cc2 Apply Mozilla code style
|/
* c4d5e6f Update comments to Russian
* a1b2c3d Merge pull request #1 from g4l0p3r1d0l/patch1
|\
| * 4b60133 Add comments
| * 8ae6744 Remove using namespace std, use std:: prefix
|/
* def5678 Add user input and personalized greeting
* abc1234 Initial commit with hello world
```
</details>

---

## Выводы

В ходе выполнения лабораторной работы я:
- Изучил основные команды Git: `clone`, `add`, `commit`, `push`, `pull`, `branch`, `checkout`, `rebase`, `merge`, `log`;
- Освоил создание и слияние веток;
- Научился создавать pull-request'ы и работать с ними;
- Применил автоматический форматировщик кода `clang-format`;
- Получил практический опыт разрешения конфликтов с помощью `rebase` и `force push`;
- Закрепил навыки работы с удалёнными репозиториями на GitHub.

**Репозиторий:** https://github.com/g4l0p3r1d0l/hello-world
