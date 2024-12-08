# Łańcuchy formatujące

## Kilka przydatnych łańcuchów formatujących:

- **%d – liczba całkowita**  
  `printf("%d + %d = %d\n", num1, num2, num1+num2);`
  `2 + 2 = 4`
- **%02d – liczba całkowita uzupełniona zerami tak, aby zajmowała {x} cyfr**
  (np. liczba 3 zostanie wypisana jako 03, a 13 - jako 13);
  `printf("%02d + %02d = %04d\n", num1, num2, num1+num2);`
  `03 + 03 = 0006`
- **%f – liczba niecałkowita**
  `printf("%f + %f = %f\n", num1, num2, num1+num2);`
  `2.000000 + 2.000000 = 4.000000`
- **%.3f – liczba niecałkowita wypisana z dokładnością do {x} miejsc po przecinku**
  `printf("%.3f + %.2f = %.5f\n", num1, num2, num1+num2);`
  `2.000 + 2.00 = 4.00000`
- **%e – liczba niecałkowita w zapisie inżynierskim**
  `printf("%.3f + %.2f = %e\n", num1, num2, num1+num2);`
  `12.00 + 240.000 = 2.520000e+002`
- **%c – znak**
