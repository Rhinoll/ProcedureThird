// Third.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <stdlib.h>;
#include <cmath>;
#include <fstream>;
#include <string>;
#include <sstream>


using namespace std;

//Первое задание

double zaem(double s, double p, double n) {
    double r = p / 100.0;
    double m = s*r*pow(1+r,n)/(12*(pow(1+r,n)-1));
    return(m);
}

 //Второе задание

double ssuda (double S, double m, int n) {
        for (double p = 0.01; p <= 100.0; p += 0.01) {
            double r = p / 100.0;
            r = round(r * 10000);
            r /= 10000;
            double mm = round((S * r * pow((1 + r), n)) / (12 * (pow((1 + r), n) - 1)) * 1000) / 1000;
            if (mm == m) return p;
        }
        return -1;
    }

//Третье задание

void CopyFile() {

    const string location = "C:\\Tasks\\hello_world.txt";
    const string desktop = "C:\\Users\\zenit\\Desktop\\hello_world.txt";

    string empty;
    ofstream file(location);
    file << "Hello world!";
    file.close();
    cout << "Файл создан" << endl;
    ofstream outFile(desktop);
    ifstream inFile(location);
    outFile << inFile.rdbuf();
    inFile.close();
    outFile.close();
    cout << "Файл скопирован на рабочий стол" << endl;
    system("C:\\Users\\zenit\\Desktop\\hello_world.txt");
}

//Четвертое задание

void Filter() {
    const string location = "C:\\Tasks\\filter.txt";
    stringstream streamText;
    ifstream file(location);
    streamText << file.rdbuf();
    string text = streamText.str();
    for (char c : text) 
        if (isdigit(c)) cout << c; 

}

//Пятое задание

string Sorter(string random) {
    int len = random.length();
    char c;
    for (int i = 0; i <= len; i++) {
        for (int j = len - 1; j > i; j--) {
            if (tolower(random[j - 1]) > tolower(random[j])) {
                c = random[j - 1];
                random[j - 1] = random[j];
                random[j] = c;
            }
        }
    }
    return(random);
}


int main()
{
    setlocale(LC_ALL, "RUS");

    
     double s, p, n;
     cout << "Вычисляем месячную зарплату, введите s, p, n" << endl;
     cin >> s >> p >> n;
     double m = zaem(s, p, n);
     cout << m << endl;
     
    
    double se, me;
    int ne;
    cout << "Вычисляем под какой процент p ввыдана ссуда" << endl;
    cout << "Введите s, m, n: " << endl;
    cin >> se >> me >> ne;
    double pe = ssuda(se, me, ne);
    cout << pe;
    
    cout << "При нажатии любой кнопки будет выполнено задание с копированием файла на рабочий стол" << endl;
    system("Pause");
    CopyFile();
    cout << "При нажатии любой кнопки будет выполнено задание с фильтрацией файла" << endl;
    system("Pause");
    Filter();

    
    string random;
    cout << "Введите случайную строку для сортировки букв в алфавитном порядке: " << endl;
    cin >> random;
    cout << "Отсортированная строка равна: " << endl;
    cout << Sorter(random);
    system("Pause");
}


// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
