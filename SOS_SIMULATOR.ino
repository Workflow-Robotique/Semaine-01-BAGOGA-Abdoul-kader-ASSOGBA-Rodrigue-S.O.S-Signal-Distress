int p = 10; // pin LED
int b = 11;  // buzzer
void setup() {
  pinMode(p, OUTPUT);
  pinMode(b, OUTPUT);
}

void loop() {
  String mot = "KADER";
  String morse = tM(mot);

  bM(morse);
}

// fonction texte -> morse
String tM(String s) {
  String m[26] = {
    ".-","-...","-.-.","-..",".","..-.","--.","....","..",".---",
    "-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-",
    "..-","...-",".--","-..-","-.--","--.."
  };

  String r = "";

  for (int i = 0; i < s.length(); i++) {
    char c = toupper(s[i]);

    if (c >= 'A' && c <= 'Z') {
      r += m[c - 'A'];
      r += " ";
    }
  }
  return r;
}

// fonction LED morse + buzzeur 
void bM(String s) {
  int d = 200; // durée de base

  for (int i = 0; i < s.length(); i++) {
    char c = s[i];

    if (c == '.') {
      digitalWrite(p, HIGH);
      tone(b,1000);
      delay(d);
      digitalWrite(p, LOW);
    }
    else if (c == '-') {
      digitalWrite(p, HIGH);
      tone(b,1500);
      delay(3 * d);
      digitalWrite(p, LOW);
    }

    delay(d); // pause entre symboles

    if (c == ' ') {
      delay(2 * d); // pause entre lettres
    }
  }
}