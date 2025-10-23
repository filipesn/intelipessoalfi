// Define notas musicais
#define NOTE_G4 392
#define NOTE_A4 440
#define NOTE_B4 494
#define NOTE_C5 523
#define NOTE_D5 587
#define NOTE_E5 659
#define NOTE_F5 698
#define NOTE_G5 784
class Melodia {
  int* notas;
  int* duracoes;
  int tamanho;
  int pino;
public:
  Melodia(int* n, int* d, int t, int p) : notas(n), duracoes(d), tamanho(t), pino(p) {}
  void tocar() {
    for (int i = 0; i < tamanho; i++) {
      int duracao = 1000 / duracoes[i];
      tone(pino, notas[i], duracao);
      delay(duracao * 1.3);
      noTone(pino);
    }
  }
};

// Dados da melodia
int notas[] = {
  NOTE_G4, NOTE_G4, NOTE_A4, NOTE_G4, NOTE_C5, NOTE_B4,
  NOTE_G4, NOTE_G4, NOTE_A4, NOTE_G4, NOTE_D5, NOTE_C5,
  NOTE_G4, NOTE_G4, NOTE_G5, NOTE_E5, NOTE_C5, NOTE_B4, NOTE_A4,
  NOTE_F5, NOTE_F5, NOTE_E5, NOTE_C5, NOTE_D5, NOTE_C5,
  NOTE_G4, NOTE_G4, NOTE_A4, NOTE_G4, NOTE_C5, NOTE_B4,
  NOTE_G4, NOTE_G4, NOTE_A4, NOTE_G4, NOTE_D5, NOTE_C5
};
int duracoes[] = {
  4, 4, 4, 4, 4, 4,
  4, 4, 4, 4, 4, 4,
  4, 4, 4, 8, 8, 4, 4,
  4, 4, 8, 8, 4, 4,
  4, 4, 4, 4, 4, 4,
  4, 4, 4, 4, 4, 4
};
Melodia melodia(notas, duracoes, sizeof(notas) / sizeof(notas[0]), 8);
void setup() {

}
void loop() {
  melodia.tocar();
  delay(2000);
}
