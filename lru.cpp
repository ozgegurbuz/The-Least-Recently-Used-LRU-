#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
using namespace std;

int y, x, z, h;
int size;

class lru {
  public:
  int * k;
  int * d;
  lru();
  void remove(int);
  void add(int);
  void list();
  void deleted();
  void plus(int);
};
lru::lru() {
  y = z = size = h = 0;
  x = 1;
}

void lru::add(int random) {
  if (size >= 5) {
    lru::remove(random);
  } else if (size < 5) {
    z = 0;
    for (int i = 0; i < 5; i++) {
      if (k[i] == random) {
        z++;
      }
    }
    if (z != 0) {
      for (int j = 0; j < 9; j++) {
        if ((d[j] > d[random]) || (d[j] != 0)) {
          d[j]--;
        }
      }
      x--;
      d[random] = x;
      x++;
    } else if (z == 0) {
      k[y] = random;
      y++;
      d[random] = x;
      x++;
    }
  }
  z = 0;
}

void lru::remove(int random) {
  if (size >= 5) {
    if (size == 5) {
      if (h == 0) {
        k[y] = random;
        d[random] = x;
        h++;
      }
    }
    z = 0;
    for (int i = 0; i < 5; i++) {
      if (k[i] == random) {
        z++;
      }
    }
    if (z != 0) {
      for (int j = 0; j < 9; j++) {
        if (d[j] > d[random])
          d[j]--;
      }
      d[random] = 5;
    } else {
      int m = 1;
      for (int r = 0; r < 9; r++) {
        if (d[r] == 1) {
          while (m) {
            for (int b = 0; b < 5; b++) {
              if (k[b] == r) {
                k[b] = random;
                d[r] = 0;
              }
            }
            for (int t = 0; t < 9; t++) {
              if (d[t] != 0) {
                d[t]--;
              }
            }
            d[random] = 5;
            m = 0;
          }
        }
      }
    }
  }
  z = 0;
}

void lru::list() {
  for (int i = 0; i < 5; i++)
    cout << * (k + i) << " ";
  cout << endl;
}

void lru::deleted() {
  for (int i = 0; i < 5; i++) {
    k[i] = 0;
  }
  for (int j = 0; j < 9; j++) {
    d[j] = 0;
  }
}

void lru::plus(int random) {
  z = 0;
  for (int i = 0; i < 5; i++) {
    if (k[i] == random) {
      z++;
    }
  }
  if (z == 0) size++;
  z = 0;
}

int main(int argc, char ** argv) {
  srand(time(0));
  int random;
  int dongu = 0;
  lru * obj = new lru();
  obj -> k = new int[5];
  obj -> d = new int[9];
  obj -> deleted();
  cout << "Least Recently Used " << endl << endl;
  do {
    random = rand() % 8 + 1;
    cout << "Eklenen sayi = " << random << " ->  ";
    obj -> plus(random);
    obj -> add(random);
    dongu++;
    obj -> list();
  } while (dongu < 15);

  return 0;
}
