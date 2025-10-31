
#define PINO_VERMELHO 6
#define PINO_VERDE    5
#define PINO_AMARELO  4

const unsigned long DURACAO_VERMELHO = 6000;
const unsigned long DURACAO_VERDE = 4000;
const unsigned long DURACAO_AMARELO = 2000;

class Semaforo {
  
  public:
    enum Estado { VERMELHO, VERDE, AMARELO };

  private:

    int _pinoVermelho;
    int _pinoVerde;
    int _pinoAmarelo;

    // Estado atual
    Estado _estadoAtual;
    
    unsigned long _tempoInicioEstado;

  public:
    /**
     * @brief 
     * @param pinoV Vermelho
     * @param pinoG Verde
     * @param pinoA Amarelo
     */
    Semaforo(int pinoV, int pinoG, int pinoA) {
      _pinoVermelho = pinoV;
      _pinoVerde = pinoG;
      _pinoAmarelo = pinoA;
    }

    void begin() {
      pinMode(_pinoVermelho, OUTPUT);
      pinMode(_pinoVerde, OUTPUT);
      pinMode(_pinoAmarelo, OUTPUT);

      // Começa no estado Vermelho
      _mudarEstado(VERMELHO);
    }

    void update() {

      unsigned long tempoAtual = millis();

      switch (_estadoAtual) {
        
        case VERMELHO:
          if (tempoAtual - _tempoInicioEstado >= DURACAO_VERMELHO) {
            _mudarEstado(VERDE);
          }
          break;

        case VERDE:
          if (tempoAtual - _tempoInicioEstado >= DURACAO_VERDE) {
            _mudarEstado(AMARELO);
          }
          break;

        case AMARELO:
          if (tempoAtual - _tempoInicioEstado >= DURACAO_AMARELO) {
            _mudarEstado(VERMELHO); // Volta ao início do ciclo
          }
          break;
      }
    }

  private:

    void _mudarEstado(Estado novoEstado) {
      _estadoAtual = novoEstado;
      _tempoInicioEstado = millis(); // Reseta o cronômetro

      // Atualiza as luzes físicas
      switch (novoEstado) {
        case VERMELHO:
          digitalWrite(_pinoVermelho, HIGH);
          digitalWrite(_pinoVerde, LOW);
          digitalWrite(_pinoAmarelo, LOW);
          break;
        case VERDE:
          digitalWrite(_pinoVermelho, LOW);
          digitalWrite(_pinoVerde, HIGH);
          digitalWrite(_pinoAmarelo, LOW);
          break;
        case AMARELO:
          digitalWrite(_pinoVermelho, LOW);
          digitalWrite(_pinoVerde, LOW);
          digitalWrite(_pinoAmarelo, HIGH);
          break;
      }
    }
};


Semaforo* meuSemaforo; 

void setup() {

  meuSemaforo = new Semaforo(PINO_VERMELHO, PINO_VERDE, PINO_AMARELO);

  meuSemaforo->begin();
}

void loop() {

  meuSemaforo->update();
}