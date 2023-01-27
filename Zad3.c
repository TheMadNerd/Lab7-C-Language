#include <stdio.h>
#include <string.h>

int main() {
  int t, s, i, j, k, m;
  int primes[5] ={127, 131, 137, 139, 149};
  printf("Podaj ilosc ciagow: \n");
  scanf("%d", &t);
  
  for (j=0; j<t; j++) {
    
    printf("Podaj ilosc liter w ciagu: \n");
    scanf("%d", &s);
    
    
    if (t > 25 || s > 25) {
      printf("Za duzy ciag");
      return 0;
    } 
  
  
     int cypher[s];
     int modulo[s];
     char ascii[s];
    printf("Podaj trzycyfrowe liczby do odkodowania: \n");
  
    for (i=0; i<s; i++){
      scanf("%d", &cypher[i]);
    }
  
    k=0;
    for (i=0; i<s; i++){
        
        modulo[i] = cypher[i] % primes[k];
           if (modulo[i] < 64 || modulo[i] > 91) {
                k++;
                i=0;
           } 
           modulo[0] = cypher[0] % primes[k];
      }
         
         for (i=0; i<s; i++) {
            ascii[i] = (char) modulo[i];
         }
      
     

    
  
  
    for (m=0; m<s; m++){
      printf("%d %d ",k, cypher[m]);
    }
   

    printf("\n\n");
    for (m=0; m<s; m++){
        printf("%c ", ascii[m]);
    }
    printf("\n\n");
  }
  
  
  return 0;
}
