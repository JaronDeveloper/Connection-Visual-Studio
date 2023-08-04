#include <iostream>
#include <fstream>

int main() {
    int N;
    int M;
    int *array;
    int *array2;
    int index=0;

    setlocale(LC_ALL, "Russian");
    std::fstream fileIn("in.txt");  
    
    if (!fileIn) {
        std::cout << "Файл не открыт" << std::endl;
        return-1;
    }
    else
    {
        std::cout << "Все ОК! Файл открыт In.txt!" << std::endl;
    }

    fileIn >> N;   

    array = new int[N];   
  
    if (fileIn) {
        while (N > index) {
            fileIn >> array[index];
            index++;           
            if (fileIn.eof()) {
                break;
            }
        }
    }
    index = 0;

    fileIn >> M;    

    array2 = new int[M];
    if (fileIn) {
      while (M > index) {
          fileIn >> array2[index];
          index++;
          if (fileIn.eof()) {
              break;
          }
      }
    }
    fileIn.close();
  
    std::ofstream fileOut("out.txt");
    if (!fileOut) {
        std::cout << "Файл не открыт" << std::endl;
        return-1;
    }
    else
    {
        std::cout << "Все ОК! Файл открыт Out.txt!" << std::endl;
    }

    fileOut << M;
    fileOut << std::endl;
    fileOut << array2[M-1];

    for (int i = 0;i < M-1;i++) {
       
        fileOut << " ";
        fileOut << array2[i];
    }
    fileOut << std::endl;

    fileOut << N;
    fileOut << std::endl;    

    for (int i = 1;i < N;i++) {
       
        fileOut << " ";
        fileOut << array[i];
    } 
    fileOut << " ";
    fileOut << array[0];

    delete[] array, array2;
    fileOut.close();   
    
    std::cout << "Данные были успешни записаны из Входной в Выходной файл" << std::endl;

    return 0;
}