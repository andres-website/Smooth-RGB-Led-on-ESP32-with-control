const int RED_PIN = 5;    // Пин для красного цвета
const int GREEN_PIN = 18;  // Пин для зеленого цвета
const int BLUE_PIN = 19;   // Пин для синего цвета

const int TRANSITION_SPEED = 2000;  // Скорость смены цветов (в миллисекундах)
const int SMOOTHNESS = 100;         // Плавность перехода (количество шагов)

void setup() {
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
}

void loop() {
  // Плавная смена красного цвета
  smoothColorTransition(255, 0, 0, 0, 255, 0);

  // Плавная смена зеленого цвета
  smoothColorTransition(0, 255, 0, 0, 0, 255);

  // Плавная смена синего цвета
  smoothColorTransition(0, 0, 255, 255, 0, 0);
}

// Функция плавной смены цвета светодиода
void smoothColorTransition(int startRed, int startGreen, int startBlue, int endRed, int endGreen, int endBlue) {
  int steps = SMOOTHNESS;
  int delayTime = TRANSITION_SPEED / steps;

  for (int i = 0; i <= steps; i++) {
    int red = map(i, 0, steps, startRed, endRed);
    int green = map(i, 0, steps, startGreen, endGreen);
    int blue = map(i, 0, steps, startBlue, endBlue);

    analogWrite(RED_PIN, red);
    analogWrite(GREEN_PIN, green);
    analogWrite(BLUE_PIN, blue);

    delay(delayTime);
  }
}
