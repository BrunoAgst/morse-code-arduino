const int ledPin = 13;
const int dotDelay = 200;

char *letters[] = {
  ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", // A - I
  ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", // J - R
  "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", //S - Z
};

char *numbers[] = {
  "-----", ".----", "..---", "...--", "....-", // 0 - 4
  ".....", "-....", "--...", "---..", "----.", // 5 - 9
};

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);

}

void loop() {
  char ch;
  if (Serial.available() > 0) {
    ch = Serial.read();
    Serial.println(ch);
    if (ch >= 'a' && ch <= 'z') {
      flashSequence(letters[ch - 'a']);
    }
    else if (ch >= 'A' && ch <= 'Z') {
      flashSequence(letters[ch - 'A']);
    }
    else if (ch >= '0' && ch <= '9') {
      flashSequence(letters[ch - '0']);
    }
    if (ch == ' ') {
      delay(dotDelay * 4);
    }
  }
}

void flashSequence(char *sequence) {
  int i = 0;
  while (sequence[i] != '\0') {
    flashDotOrDash(sequence[i]);
    i++;
  }
  delay(dotDelay * 3); // intervalo de tempo entre as letras
}

void flashDotOrDash(char dotOrDash) {
  digitalWrite(ledPin, HIGH);
  if (dotOrDash == '.') {
    delay(dotDelay);
  }
  else {
    delay(dotDelay * 3);
  }
  digitalWrite(ledPin, LOW);
  delay(dotDelay);
}
