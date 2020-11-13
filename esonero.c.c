#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main(void) {
  char M[128];
  char K[128];
  char C[128];
  char M2[128];
  int i, lunghezza_K;
  int scelta, ch;
  time_t t;

  puts("Inserisci un messaggio:");              //richiedo il messaggio
  fgets( M, 128, stdin);
  while((ch = getchar()) != '\n' && ch != EOF);
  puts("Scegliere tra due opzioni");           //scegliere tra l'opzione 1 e 2
  puts("Digitare 1 se si vuole inserire la chiave manualmente o digitare 2 se la si vuole generare casualmente:");
  scanf("\n%d", &scelta );
  getchar();

  switch(scelta){
    case 1:                                       //scelta 1
    printf("Inserisci una chiave:\n");
    fgets(K, 128, stdin);
    fflush(stdin);

   while (strlen(K) < strlen(M)){                 //nel caso K fosse troppo corta
    printf("Chiave troppo corta.\n");
    printf("Inserisci una chiave:\n");
    fgets(K, 128, stdin);
    fflush(stdin);
    }

    lunghezza_K = strlen(K);
    for (i = 0; i < lunghezza_K; i++) {           //cifratura di M
      C[i] = M[i] ^ K[i];
    }
    puts("Il messaggio cifrato:\n");
    printf("%s", C);

    for (i = 0; i < 128; i++) {                   //messaggio iniziale
        M2[i] = C[i] ^ K[i];
    }
    puts("Il messaggio iniziale:\n");
    printf("%s", M2);
    break;

  case 2 :                                        //scelta 2
  srand((unsigned) time(&t));
  puts("La chiave del messaggio:\n");
  for ( i = 0; i < 128; i++) {                    //generazione della chiave
    K[i] = rand() %128;
  }
    printf("%s\n", K );
    lunghezza_K = strlen(K);
  for (i = 0; i < 128; i++) {                     //cifratura di M
    C[i] = M[i] ^ K[i];
  }

  puts("Il messaggio cifrato:\n");
  printf("%s", C);

  for (i = 0; i < lunghezza_K; i++) {             //messaggio iniziale
      M2[i] = C[i] ^ K[i];
  }
  puts("Il messaggio iniziale:\n");
  printf("%s", M2);
  break;

  case '\n':
  case '\t':
  break;
  default:
  printf("chiave non corretta.\n");               //nel caso la scelta non fosse 1 e 2
    }
  return 0;
}
