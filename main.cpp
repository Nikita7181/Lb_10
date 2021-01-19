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
    fs::path cur_p,cur_p1, copy, new_p;
    std::string new_dir, file, del_dir, c, new1, dir;
    int key;
    cout << "If you want to display the current folder, press 1\n" <<
         "If you want to display the contents of a folder, press 2\n" <<
         "If you want to create a folder (s) with a preliminary check "
         "for the existence of a folder of the same name, press 3\n"
         << "If you want to display the file size, press 4\n" <<
         "If you want to display the file size, press 5\n" <<
         "If you want to delete the file, click 6\n" <<
         "If you want to delete the file directory, click 7\n" <<
         "If you want to move up or down , press 8\n" <<
         "If you want to rename the file , press 9\n" <<
         "If you want to move a file or directory to a file , press 10\n" << endl;
    cout << "key = " ;
    cin >> key;
    cin.ignore(1);
    
    switch (key)
    {
        case 0:
        {
            // для создания текстовых файлов и тд (чтобы провреить функцию copy, size и тд)
            std::string filename;
            std::ofstream f1;
            cout << "enter name: ";
            std::getline(cin, filename);
            f1.open(filename);
            f1.put('a');
            f1.close();
            break;
        }
            // Вывод на экран текущего каталога
        case 1:
            {
            auto cur_p = fs::current_path();
            cout << "current path:" << cur_p << endl;
            break;
        }
        
            //Вывод на экран содержимого каталога
    
    
        case 2: {
            for (auto &p: fs::directory_iterator(fs::current_path()))
            {
                cur_p = p.path();
                cout << cur_p.filename() << endl;
            }
            break;
        }
        
            //Создание каталога (папки) с предварительной проверкой на существование одноимённого каталога
        case 3:
            {
            cout << "enter a name :";
            std::getline(cin, new_dir);
        
            if (fs::exists(new_dir)) {
                cout << "this directory already exists" << endl;
            } else {
                fs::create_directory(new_dir);
                cout << "Yes";
            }
            break;
        
        }
        
            //Вывод на экран размера файла
        case 4:
            {
            cout << "enter a file name: ";
            std::getline(cin, file);
            cur_p = fs::current_path() / file;
            if (fs::exists(cur_p))
            {cout << "File size = " << fs::file_size(cur_p) << endl;}
            break;
        }
        
            // Копирование файла
        case 5: {
    
            for (auto& p : fs::directory_iterator(fs::current_path()))
            {
                cout << p.path().filename() << endl;
            }
            cout << "enter a file name:";
            std::getline(cin, file);
            cur_p = fs::current_path() / file;
            cout << "enter a file name:";
            std::getline(cin, c);
           copy = fs::current_path() / c;
            fs::copy_file(cur_p, copy);
            break;
        }
        
            // Удаление файла
        case 6:
            {
                for (auto& p : fs::directory_iterator(fs::current_path()))
                {
                    cout << p.path().filename() << endl;
                }
            cout << "enter file name: ";
            std::getline(cin, file);
            cur_p = fs::current_path() / file;
            remove(cur_p);
            break;
        
        }
        
            // Удаление каталога с файлами
        case 7: {
            cout<< "enter file name: ";
            std::getline(cin, del_dir);
            cur_p = fs::current_path() / del_dir;
            fs::remove_all(cur_p);
            break;
        
        }
        
            // Перемещение по каталогам
        case 8:
            {
            int key2;
            cout << "1) up" << endl << "2) down" << endl;
            cin >> key2;
                for (auto& p : fs::directory_iterator(fs::current_path()))
                {
                    cout << p.path().filename() << endl;
                }
            cin.ignore(1);
            switch (key2)
            {
                case 1:
                    {
                        cout << "enter filename: ";
                    std::getline(cin, dir);
                    fs::current_path(dir);
                    cout << fs::current_path() << endl;
                    break;
                }
    
                case 2:
                    {
                    cur_p = fs::current_path().remove_filename();
                    fs::current_path(cur_p);
                    cout << fs::current_path() << endl;
                    break;
                }
            }
        
            break;
        }
        
            // Переиминование файлов и каталогов
        case 9:
            {
            // сначала ввод старого имени
            // потом нового
            int key1;
            cout << "1) file" << endl << "2) dir" << endl;
            cin >> key1;
                for (auto& p : fs::directory_iterator(fs::current_path()))
                {
                    cout << p.path().filename() << endl;
                }
            cin.ignore(1);
            switch (key1)
            {
                case 1:
                    {
                    cout << "enter the current name: ";
                    std::getline(cin, file);
                    cout << "enter the new  name: ";
                    std::getline(cin, new1);
                    cur_p = fs::current_path() / file;
                    new_p = fs::current_path() / new1;
                    fs::rename(cur_p, new_p);
                    break;
            }
    
            case 2:
                {
                    cout << "enter the current name: ";
                std::getline(cin, dir);
                cout << "enter the new  name: ";
                std::getline(cin, new1);
                cur_p /= dir;
                cur_p /= new1;
                fs::rename(dir, new1);
                break;
            }
        }
            break;
        }
        
            //Перемещиние файлов и каталогов
        case 10:
            {
            // 1) вводим файл
            // 2) вводим папку
                for (auto& p : fs::directory_iterator(fs::current_path()))
                {
                    cout << p.path().filename() << endl;
                }
            cur_p = fs::current_path();
            new_p = fs::current_path();
            cout << "enter file name: ";
            std::getline(cin, file);
            cout << "enter the folder name: ";
            std::getline(cin, dir);
            cur_p /= file;
            new_p /= dir;
            new_p /= file;
            fs::rename(cur_p, new_p);
            break;
    }
    }
    
    return 0;
}
