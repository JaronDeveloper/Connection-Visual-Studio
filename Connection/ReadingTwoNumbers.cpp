#include <iostream>
#include <fstream>

int main() {
    int N;
    int M;
    int *array;
    int *array2;
    int str = 0,index=0;

    setlocale(LC_ALL, "Russian");
    std::fstream fileIn("in.txt");  

    if (fileIn) {
        while (0==str) {
            fileIn >> N;
            str++;
          if (fileIn.eof()) {
            break;
          }           
        }
    }
    str = 0;
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
    if (fileIn) {
        while (0==str) {
            fileIn >> M;
            str++;
            if (fileIn.eof()) {
                break;
            }
        }
    }

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