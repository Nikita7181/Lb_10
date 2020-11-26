#include <iostream>
#include <filesystem>
#include <string>
#include <fstream>
using std::endl;
using std::cout;
using std::cin;
namespace fs=std::filesystem;
int main()
{
    int key;
    cout << "If you want to display the current folder, press 1\n" <<
    "If you want to display the contents of a folder, press 2\n" <<
    "If you want to create a folder (s) with a preliminary check "
    "for the existence of a folder of the same name, press 3\n"
    << "If you want to display the file size, press 4\n" <<
     "If you want to display the file size, press 5\n" <<
     "If you want to display the file size, press 6\n" <<
     "If you want to delete the file directory, click 7\n" <<
     "If you want to move down or down , press 8\n" <<
     "If you want to rename the file , press 9\n" <<
     "If you want to move a file or directory to a file , press 10\n" << endl;
    cout << "key = " ;
    cin >> key;
    // Вывод на экран текущего каталога
    switch (key)
    {
        case 1:
            auto cur_p=fs::current_path();
            cout<< "current path:" << cur_p <<endl;
            break;
    }
    //Вывод на экран содержимого каталога
    switch (key)
    {
        case 2:
            fs::create_directories("nik");
            std::ofstream("nik/file1.txt");
            std::ofstream("nik/file2.txt");
            for(auto& p: fs::directory_iterator("nik"))
                std::cout << p.path() << endl;
            fs::remove_all("nik");
            break;
    }
    //Создание каталога (папки) с предварительной проверкой на существование одноимённого каталога
    switch (key)
    {
        case 3:
            fs::create_directory("nik");
            fs::remove_all("nik");
            break;
    }
    //Вывод на экран размера файла
    switch (key)
    {
        case 4:
            std::ofstream("file1.txt").put('a');
            std::cout << "File size = " << fs::file_size("file1.txt") << endl;
            fs::remove("file1.txt");
            break;
    }
    // Копирование файла
    switch (key)
    {
        case 5:
            fs::create_directory("nik");
            std::ofstream("nik/file1.txt").put('a');
            fs::copy_file("nik/file1.txt", "nik/file2.txt");
            for(auto& p: fs::directory_iterator("nik")){
                std::cout << p.path() << endl;}
            fs::remove_all("nik");
            break;
    }
    // Удаление файла
    switch (key)
    {
        case 6:
            std::ofstream("file1.txt").put('a');
            fs::remove("file1.txt");
            break;
        
    }
    // Удаление каталога с файлами
    switch (key)
    {
        case 7:
            fs::create_directories("nik");
            fs::create_directories("nik1");
            std::ofstream("nik1/file3.txt");
            std::ofstream("nik1/file4.txt");
            std::ofstream("nik/file1.txt");
            std::ofstream("nik/file2.txt");
            fs::remove_all("nik");
            break;
        
    }
    // Перемещение по каталогам
    switch (key)
    {
        case 8:
            fs::create_directories("nik");
            std::ofstream ("nik/file.txt");
            std::ofstream ("nik/file1.txt");
            fs::remove_all("nik");
            break;
    }
    // Переиминование файлов и каталогов
    switch (key)
    {
        case 9:
            fs::create_directories("from");
            std::ofstream("from/file1.txt").put('a');
            fs::create_directory("to");
            fs::rename("from/file1.txt", "to/file2.txt");
            for (auto &p: fs::directory_iterator("to"))
            {
                std::cout << p.path() << endl;
            }
            fs::remove_all("from");
            break;
    }
    //Перемещиние файлов и каталогов
            switch (key)
            {
                case 10:
                    fs::create_directories("nik");
                    break;
            
            }
    return 0;
    }
