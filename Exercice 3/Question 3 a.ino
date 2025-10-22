#include <Servo.h>  
// Inclusion de la bibliothèque Servo pour contrôler un servomoteur

Servo monServo;  
// Création d’un objet 'monServo' pour manipuler le servomoteur

int position = 90;  
// Variable pour stocker la position actuelle du servomoteur (en degrés)
// On initialise à 90° (position centrale)

void setup() {
  Serial.begin(9600);
  // Démarrage de la communication série à 9600 bauds pour communiquer avec le moniteur série

  monServo.attach(9);
  // Connexion du servomoteur à la broche numérique 9 de l’Arduino

  monServo.write(position);
  // Positionnement initial du servo à 90°

  Serial.println("Commandes: '0'(0°), '90'(90°), '180'(180°)");
  // Affichage des instructions dans le moniteur série
}

void loop() {
  // Boucle principale : s’exécute indéfiniment

  if (Serial.available() > 0) {
    // Si une donnée est reçue depuis le moniteur série

    char commande = Serial.read();
    // Lecture d’un caractère envoyé par l’utilisateur

    switch(commande) {
      // Test de la commande reçue

      case '0': 
        monServo.write(0);
        // Si l’utilisateur envoie '0', le servo se met à 0°
        Serial.println("Position: 0°");
        break;

      case '90':
        monServo.write(90);
        // Si l’utilisateur envoie '90', le servo se met à 90°
        Serial.println("Position: 90°");
        break;

      case '180':
        monServo.write(180);
        // Si l’utilisateur envoie '180', le servo se met à 180°
        Serial.println("Position: 180°");
        break;
    }
  }
}
