#include <AFMotor.h>  
// Inclusion de la bibliothèque Adafruit Motor Shield
// Elle permet de contrôler facilement des moteurs (DC, pas à pas, servo) via le shield

AF_Stepper moteurPas(200, 2);  
// Déclaration d’un moteur pas à pas : 200 pas par tour, connecté au port M3-M4 (port n°2 sur le shield)

void setup() {
  Serial.begin(9600);
  // Démarrage de la communication série à 9600 bauds pour dialoguer avec le moniteur série

  moteurPas.setSpeed(30);  
  // Réglage de la vitesse du moteur en tours par minute (RPM)

  Serial.println("Commandes: 'A'(Avant), 'R'(Arriere), 'S'(Stop)");
  // Message d’instructions affiché dans le moniteur série
}

void loop() {
  // Boucle principale qui tourne indéfiniment

  if (Serial.available() > 0) {
    // Vérifie si une commande a été envoyée depuis le moniteur série

    char cmd = Serial.read();
    // Lit le caractère reçu ('A', 'R' ou 'S')

    if (cmd == 'A') {
      // Si la commande est 'A', le moteur tourne vers l’avant
      moteurPas.step(100, FORWARD, SINGLE);
      // Fait tourner le moteur de 100 pas en avant, en mode "SINGLE" (une bobine activée à la fois)
      Serial.println("Direction: Avant");
    }
    else if (cmd == 'R') {
      // Si la commande est 'R', le moteur tourne vers l’arrière
      moteurPas.step(100, BACKWARD, SINGLE);
      // Fait tourner le moteur de 100 pas en arrière
      Serial.println("Direction: Arriere");
    }
    else if (cmd == 'S') {
      // Si la commande est 'S', le moteur est libéré (plus de courant dans les bobines)
      moteurPas.release();
      Serial.println("Moteur arrete");
    }
  }
}
