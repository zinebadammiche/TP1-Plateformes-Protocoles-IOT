// Déclaration d’une variable qui correspond à la broche où la LED est connectée
int led = 9;

// Variable pour stocker le caractère reçu depuis le port série
char octet_rx = 0;

void setup() {
  // Démarre la communication série à 9600 bauds
  Serial.begin(9600);

  // Définit la broche 9 comme une sortie (pour la LED)
  pinMode(led, OUTPUT);
}

void loop() {
  // Vérifie si un octet (caractère) a été reçu sur le port série
  if (Serial.available() > 0) {
    
    // Lis le caractère reçu et le stocke dans la variable octet_rx
    octet_rx = Serial.read();

    // Petite pause de 5 secondes (5000 millisecondes)
    delay(5000);

    // Si le caractère reçu est 'a' → allumer la LED
    if (octet_rx == 'a') { // 'a' comme "allumer"
      digitalWrite(led, HIGH); // Allume la LED
      Serial.println("LED allumee"); // Envoie un message de confirmation
    }

    // Si le caractère reçu est 'e' → éteindre la LED
    if (octet_rx == 'e') { // 'e' comme "eteindre"
      digitalWrite(led, LOW); // Éteint la LED
      Serial.println("LED eteinte"); // Envoie un message de confirmation
    }
  }
}
