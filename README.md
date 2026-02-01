<h1 align="center">Документация URLFileDownloader</h1>
<h2>Введение</h2>
<span> URLFileDownloader — это консольная программа для скачивания файлов по URL. На вход программы поступает три параметра:</span>
<ul>
  <li>Относительная или абсолютная ссылка к файлу ИМЯ_ФАЙЛА.txt;</li>
  <li>Относительная или абсолютная ссылка папки для хранения файла;</li>
  <li>Кол-во используемых потоков;</li>
</ul>
<h2>Процесс установки</h2>
<h3>Windows</h3>
<h4>CMake</h4>
<span>Скачайте установщик с официального сайта <a href="https://github.com/Kitware/CMake/releases/download/v4.2.2/cmake-4.2.2-windows-x86_64.msi">CMake</a>. Проведите скачивание и настройку ПО.</span>
<h4>MSYS2</h4>
<span>Для начала необходимо скачать установщик <a href="https://github.com/msys2/msys2-installer/releases/download/2025-12-13/msys2-x86_64-20251213.exe">MSYS2</a> с официального репозитория GitHub и провести установку ПО. После завершения установки откройте MSYS2 UCRT64 и введите следующую команду для установки GCC и OpenSSL:</span>
<br> </br>

```MSYS2 UCRT64
pacman -S mingw-w64-ucrt-x86_64-gcc mingw-w64-ucrt-x86_64-openssl
```

<h4>URLFileDownloader</h4>
<span>Далее скачайте архив URLFileDownloader и распокуйте его в любое удобное для вас место.</span>

<h3>Linux (Debian)</h3>
<h4>Установка необходимых репозиториев</h4>
<span>Перейдите в интерпритатор командной строки и введите следующие команды для скачивания gcc, libssl-dev и CMake:</span>
<br> </br>

```terminal
sudo apt update & apt upgrade
```
```terminal
sudo apt install git gcc libssl-dev cmake
```

<h4>URLFileDownloader</h4>
<span>Для скачивания URLFileDownloader необходимо открыть интерпритатор командной строки и ввести следующую команду:</span>
<br> </br>

```terminal
git clone https://github.com/TofikIbragimov/URLFileDownloader.git
```

<h2>Процесс сборки проекта</h2>
<h3>Windows</h3>
<span>Откройте ранее установленный MSYS2 UCRT64 и перейдите в папку проекта:</span>
<br> </br>

```MSYS2 UCRT64
cd путь/к/папке/URLFileDownloader
```

<span>!!! ВНИМАНИЕ — ПУТЬ К ПАПКЕ НЕ ДОЛЖЕН СОДЕРЖАТЬ СИМВОЛЫ КИРИЛKИЦЫ !!!</span>

<span>Пропишите команду для создания папки build и перейдите в неё:</span>
<br> </br>

```MSYS2 UCRT64
mkdir build & cd build
```

<span>Переходим к сборки и компиляции проекта. Для этого вводим следующие команды:</span>
<br> </br>

```MSYS2 UCRT64
cmake -G "MinGW Makefiles" ..
```
```MSYS2 UCRT64
cmake --build .
```

<h3>Linux</h3>
<span>Откройте интерпритатор командной строки и перейдите в папку проекта, после чего создайте внутри него папку build и перейдите в неё:</span>
<br> </br>

```terminal
cd путь/к/папке/URLFileDownloader
```
```terminal
mkdir build & cd build
```

<span>!!! ВНИМАНИЕ — ПУТЬ К ПАПКЕ НЕ ДОЛЖЕН СОДЕРЖАТЬ СИМВОЛЫ КИРИЛKИЦЫ !!!</span>
<span>Переходим к сборки и компиляции проекта. Для этого вводим следующие команды:</span>
<br> </br>

```terminal
cmake ..
```
```terminal
cmake --build .
```

<h2>Как работает программа</h2>
<h3>Любая операционная система</h3>
<span>Программа на входе получает 3 агрумента: путь к файлу с URL, путь к папке для сохранения файлов скаченных по ULR из файла и количество одновременных скачиваний. Ниже приведён пример команды для запуска программы</span>
<br> </br>

```terminal
./URLFileDownloader путь/к/файлу/ИМЯ_ФАЙЛА.txt путь/к/папке/ИМЯ_ПАПКИ КОЛИЧЕСТВО_ПОТОКОВ
```
