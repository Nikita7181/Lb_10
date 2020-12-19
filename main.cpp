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
    fs::path cur_p, copy, new_p;
    std::string new_dir, file, del_dir, c, new1, dir;
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
            for(auto& p: fs::directory_iterator(fs::current_path()))
            {
                cur_p = p.path();
               cout << cur_p.filename() << endl;
            }
            break;
    }
    //Создание каталога (папки) с предварительной проверкой на существование одноимённого каталога
    switch (key)
    {
        case 3:
            cout << "enter a name :";
            std::getline(std::cin, new_dir);
            if (fs::exists(new_dir))
            {
                cout << "this directory already exists" << endl;
            }
            else
            {
                fs::create_directory(new_dir);
                cout << "Yes";
            }
            break;
    }
    //Вывод на экран размера файла
    switch (key)
    {
        case 4:
            cout << "enter a file name: ";
            std::getline(std::cin, file);
            cur_p = fs::current_path() / file;
            std::ofstream(cur_p).put('a');
            std::cout << "File size = " << fs::file_size(cur_p) << endl;
            break;
    }
    // Копирование файла
    switch (key)
    {
        case 5:
            //сначала ввод файла, который копируем, потом ввод названия нового файла
            cout << "enter a file name:";
            std::getline(cin, file);
            cur_p = fs::current_path() / file;
            copy = fs::current_path();
            std::getline(cin,c);
            c = copy;
            fs::copy_file(cur_p, c);
            for(auto& p: fs::directory_iterator("nik")){
                std::cout << p.path() << endl;}
            break;
    }
    // Удаление файла
    switch (key)
    {
        case 6:
            std::getline(cin,file);
            cur_p = fs::current_path() / file;
            remove(cur_p);
            break;
        
    }
    // Удаление каталога с файлами
    switch (key)
    {
        case 7:
           std::getline(cin, del_dir);
           cur_p = fs::current_path() / del_dir;
           fs::remove_all(cur_p);
            break;
        
    }
    // Перемещение по каталогам
    switch (key)
    {
        case 8:
            int key2 ;
            cout  << "1) вверх" << endl << "2) вниз" << endl;
            cin>>key2;
            switch (key2)
            {
                case 1:
                    std::getline(cin,dir);
                    cur_p = fs::current_path() /dir;
                    fs::create_directory(dir);
                    fs::current_path(cur_p);
                    cout << fs::current_path() << endl;
                    
            }
            switch (key2)
            {
                case 2:
                    cur_p = fs::current_path().remove_filename();
                    fs::current_path(cur_p);
                    cout << fs::current_path() << endl;
            }
            
            break;
    }
    // Переиминование файлов и каталогов
    switch (key)
    {
        case 9:
            // сначала ввод нового имени
            // потом старого
            int key1 ;
            cout  << "1) file" << endl << "2) dir" << endl;
            cin>>key1;
            switch (key1)
            {
                case 1:
                std::getline(cin, file);
                std::getline(cin, new1);
                cur_p = fs::current_path() / file;
                new1 = fs::current_path() / new1;
                fs::rename(cur_p, new1);
            }
            switch (key1)
            {
                case 2:
                    std::getline(cin,dir);
                    std::getline(cin, new1);
                    cur_p = fs::current_path() / dir;
                    cur_p = fs::current_path() / new1;
                    fs::rename(cur_p, new1);
            }
    }
    //Перемещиние файлов и каталогов
            switch (key)
            {
                case 10:
                   // 1) вводим файл
                   // 2) вводим папку
                   cur_p = fs::current_path();
                   std::getline(cin, file);
                   std::getline(cin, dir);
                   cur_p /= file;
                   new_p = fs::current_path();
                   new_p /= dir;
                   new_p /= file;
                   fs::rename(cur_p, new_p);
                    break;
            }
    return 0;
    }
