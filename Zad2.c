#include <stdio.h>

int romanToArabic(const char *numeral) {
    int sum = 0;
    for (int i = 0; numeral[i]; i++) {
        if (numeral[i] == 'M') sum += 1000;
        else if (numeral[i] == 'D') sum += 500;
        else if (numeral[i] == 'C') sum += (numeral[i + 1] == 'M' || numeral[i + 1] == 'D') ? -100 : 100;
        else if (numeral[i] == 'L') sum += 50;
        else if (numeral[i] == 'X') sum += (numeral[i + 1] == 'C' || numeral[i + 1] == 'L') ? -10 : 10;
        else if (numeral[i] == 'V') sum += 5;
        else if (numeral[i] == 'I') sum += (numeral[i + 1] == 'X' || numeral[i + 1] == 'V') ? -1 : 1;
    }
    return sum;
}

void arabicToRoman(int num, char* roman) {
    char *p = roman;
    while (num >= 1000) { *p++ = 'M'; num -= 1000; }
    if (num >= 900) { *p++ = 'C'; *p++ = 'M'; num -= 900; }
    if (num >= 500) { *p++ = 'D'; num -= 500; }
    if (num >= 400) { *p++ = 'C'; *p++ = 'D'; num -= 400; }
    while (num >= 100) { *p++ = 'C'; num -= 100; }
    if (num >= 90) { *p++ = 'X'; *p++ = 'C'; num -= 90; }
    if (num >= 50) { *p++ = 'L'; num -= 50; }
    if (num >= 40) { *p++ = 'X'; *p++ = 'L'; num -= 40; }
    while (num >= 10) { *p++ = 'X'; num -= 10; }
    if (num >= 9) { *p++ = 'I'; *p++ = 'X'; num -= 9; }
    if (num >= 5) { *p++ = 'V'; num -= 5; }
    if (num >= 4) { *p++ = 'I'; *p++ = 'V'; num -= 4; }
    while (num >= 1) { *p++ = 'I'; num -= 1; }
    *p = 0;
}

int main() {
    char roman1[16], roman2[16], romanSum[16];
    
    printf("Podaj dwie liczby rzymskie (po spacji)\n");
    scanf("%s %s", roman1, roman2);

    int arabic1 = romanToArabic(roman1);
    int arabic2 = romanToArabic(roman2);

    int sum = arabic1 + arabic2;

    arabicToRoman(sum, romanSum);
    
    printf("Wynik: \n");
    printf("%s + %s = %s", roman1, roman2, romanSum);

    return 0;
}
