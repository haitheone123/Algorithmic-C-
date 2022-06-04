#include <iostream> 
int numTest; 
char a[26][26]; 
int R, C; 

int main () {
  std::cin >> numTest; 
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> R >> C; 
    for (int i = 1; i <= R; i++) {
      for (int j = 1; j <= C; j++) {
        std::cin >> a[i][j]; 
      }
    }
    for (int i = 1; i <= R; i++) {
      for (int j = 1; j <= C; j++) {
        if (a[i][j] != '?') {
          int x = j - 1; 
          while (a[i][x] == '?') {
            a[i][x] = a[i][j];
            x--;  
          }
          x = j + 1; 
          while (a[i][x] == '?') {
            a[i][x] = a[i][j]; 
            x++; 
          }
        }
      }
    }
    for (int i = 1; i <= R; i++) {
      for (int j = 1; j <= C; j++) {
        if (a[i][j] != '?') {
          int x = i - 1; 
          while (a[x][j] == '?') {
            a[x][j] = a[i][j];
            x--;  
          }
          x = i + 1; 
          while (a[x][j] == '?') {
            a[x][j] = a[i][j]; 
            x++; 
          }
        }
      }
    }
    for (int i = 1; i <= R; i++) {
      for (int j = 1; j <= C; j++) {
        std::cout << a[i][j]; 
      }
      std::cout << std::endl; 
    }
  }
  return 0; 
}