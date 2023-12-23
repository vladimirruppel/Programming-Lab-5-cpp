#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <limits>
#define NOMINMAX
#include <Windows.h>
#include "AuditionsNumber.h"
#include "AudioFile.h"
#include "Playlist.h"
#include "AudioPlayer.h"
#include "AudioCollection.h"
#include "MusicLibrary.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "Rus");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    AuditionsNumber an{};
    try {
        an.setCount(-1); // устанавливаем счетчик прослушиваний в -1, что вызовет исключение
    }
    catch (const std::invalid_argument& e) {
        std::cerr << "Исключение: " << e.what() << std::endl;
    }
    std::cout << "Количество прослушиваний: " << an.getCount() << std::endl;
    an++;
    std::cout << "Количество прослушиваний: " << an.getCount() << std::endl << std::endl;
    
    // работа с двумерным массивом из объектов класса AudioFile
    
    AudioFile mas[3][3];
    mas[0][0] = AudioFile("file1.mp3", "Drake", "God's Plan", 234, 2017);
    mas[0][1] = AudioFile("file2.mp3", "Kanye West", "Ni**as in Paris", 243, 2011);
    mas[0][2] = AudioFile("file3.mp3", "ALBLAK52", "+7(952)812", 107, 2023);
    mas[1][0] = AudioFile("file4.mp3", "OG Buda", "Печеньки", 152, 2019);
    mas[1][1] = AudioFile("file5.mp3", "lil krystalll", "Тик так", 104, 2019);
    mas[1][2] = AudioFile("file6.mp3", "PHARAOH", "Взглянем В Глаза Правде", 142, 2023);
    mas[2][0] = AudioFile("file7.mp3", "Kanye West", "Good Morning", 195, 2007);
    mas[2][1] = AudioFile("file8.mp3", "SALUKI", "WILD EA$T",  266, 2023);
    mas[2][2] = AudioFile("file9.mp3", "FRIENDLY THUG 52 NGG", "Two Thousand Nineteen", 105, 2022);

    // вывод треков из двумерного массива
    puts("Треки из двумерного массива: ");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            mas[i][j].shortOutput();
        }
    }
}