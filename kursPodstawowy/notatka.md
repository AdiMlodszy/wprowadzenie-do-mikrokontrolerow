# **Notatka z programowania w C**

## **Agenda:**

- Zmienne i typy danych
- Operatory
- Instrukcje warunkowe i pętle
- Tablice
- Funkcje
- Wskaźniki i dynamiczne zarządzanie pamięcią
- Struktury

### Notatka

#### **1. Zmienne i typy danych**

- **`int` (liczby całkowite)**

  - Służy do przechowywania liczb całkowitych.
  - Zajmuje zwykle 4 bajty w pamięci (32 bity).
    ```c
    int x = 42;
    printf("Liczba x: %d\n", x);  // Wydrukuje: Liczba x: 42
    ```

- **`float` (liczby zmiennoprzecinkowe)**

  - Przechowuje liczby zmiennoprzecinkowe z pojedynczą precyzją.
  - Zajmuje zwykle 4 bajty w pamięci.
    ```c
    float pi = 3.14;
    printf("Pi: %f\n", pi);  // Wydrukuje: Pi: 3.140000
    ```

- **`char` (znaki)**

  - Przechowuje pojedyncze znaki (np. 'A', 'b').
  - Zajmuje 1 bajt w pamięci.
    ```c
    char ch = 'A';
    printf("Znak: %c\n", ch);  // Wydrukuje: Znak: A
    ```

- **`double` (liczby zmiennoprzecinkowe z podwójną precyzją)**

  - Przechowuje liczby zmiennoprzecinkowe z podwójną precyzją.
  - Zajmuje 8 bajtów w pamięci.
    ```c
    double bigPi = 3.1415926535;
    printf("Big Pi: %f\n", bigPi);  // Wydrukuje: Big Pi: 3.141593
    ```

- **`unsigned int` (liczby bez znaku)**
  - Przechowuje liczby dodatnie o większym zakresie niż `int`.
  - Zajmuje 4 bajty w pamięci, ale przechowuje liczby z zakresu od 0 do około 4 miliardów.
    ```c
    unsigned int y = 4000000000;
    printf("Wartość y: %u\n", y);  // Wydrukuje: Wartość y: 4000000000
    ```

#### **2. Operatory w C**

- **Operatory arytmetyczne**:

  - `+`, `-`, `*`, `/`, `%`
    ```c
    int suma = a + b;
    int reszta = a % b;
    ```

- **Operatory porównania**:

  - `==`, `!=`, `>`, `<`, `>=`, `<=`
    ```c
    if (x == 5) { printf("x wynosi 5"); }
    ```

- **Operatory logiczne**:

  - `&&`, `||`, `!`
    ```c
    if (a && !b) { printf("a jest prawdziwe, a b jest fałszywe"); }
    ```

- **Operatory inkrementacji i dekrementacji**:
  - `++`, `--`
    ```c
    int x = 5;
    x++;  // x = 6
    ```

#### **3. Instrukcje warunkowe i pętle**

- **Instrukcja warunkowa `if-else`**:

  ```c
  if (a > 5)
  { printf("a jest większe niż 5"); }
  else
  { printf("a nie jest większe niż 5"); }
  ```

- **Instrukcja `switch-case`**:

  ```c
  switch(x) {
      case 1: printf("x wynosi 1"); break;
      case 2: printf("x wynosi 2"); break;
      default: printf("x ma inną wartość");
  }
  ```

- **Pętla `for`**:

  ```c
  for (int i = 0; i < 5; i++) { printf("i: %d\n", i); }
  ```

- **Pętla `while`**:

  ```c
  while (i < 5) { printf("i: %d\n", i); i++; }
  ```

- **Pętla `do-while`**:
  ```c
  do { printf("i: %d\n", i); i++; } while (i < 5);
  ```

#### **4. Tablice**

- **Tablice jednowymiarowe**:

  ```c
  int tablica[5] = {1, 2, 3, 4, 5};
  printf("Pierwszy element: %d\n", tablica[0]);
  ```

- **Tablice wielowymiarowe**:
  ```c
  int macierz[3][3] = { (1, 2, 3), (4, 5, 6), (7, 8, 9) };
  printf("Element [0][1]: %d\n", macierz[0][1]);
  ```

#### **5. Funkcje**

- **Funkcja z argumentami i zwracającą wartość**:

  ```c
  int suma(int a, int b) { return a + b; }
  ```

- **Funkcja typu `void`**:
  ```c
  void wypisz() { printf("To jest funkcja void"); }
  ```

#### **6. Wskaźniki i dynamiczne zarządzanie pamięcią**

- **Wskaźniki**:

  ```c
  int x = 5;
  int* ptr = &x;
  printf("Adres x: %p, Wartość x: %d\n", ptr, *ptr);
  ```

- **Dynamiczne przydzielanie pamięci**:
  ```c
  int* tab = (int*) malloc(5 * sizeof(int));
  tab[0] = 10;
  free(tab);
  ```

#### **7. Struktury**

- **Definicja i użycie struktur**:
  ```c
  struct Osoba { char imie[50]; int wiek; };
  struct Osoba osoba1;
  strcpy(osoba1.imie, "Jan");
  osoba1.wiek = 25;
  printf("Imię: %s, Wiek: %d\n", osoba1.imie, osoba1.wiek);
  ```
