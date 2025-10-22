// === Inclusion de la bibliothèque du shield moteur Adafruit ===
#include <AFMotor.h>  
// Cette bibliothèque permet de contrôler des moteurs CC via le shield Adafruit Motor Shield (L293D).

// === Création d’un objet moteur ===
AF_DCMotor ventilateur(1);  
// On crée un objet moteur appelé "ventilateur" connecté sur la sortie M1 du shield.

// === Déclaration d’une variable globale ===
int vitesse = 0;  
// Variable qui stocke la vitesse demandée par l’utilisateur (0 à 255).

// === Fonction d’initialisation ===
void setup() {
  Serial.begin(9600);        // Démarre la communication série à 9600 bauds.
  
  ventilateur.setSpeed(0);   // Définit la vitesse initiale du moteur à 0 (arrêté).
  ventilateur.run(RELEASE);  // Libère le moteur, il ne tourne pas.
  
  Serial.println("Entrez une vitesse (0-255):"); // Message d’invite sur le moniteur série.
}

// === Boucle principale ===
void loop() {
  // Vérifie si une donnée est disponible sur le port série (envoyée depuis le PC)
  if (Serial.available() > 0) {
    vitesse = Serial.parseInt();            // Lit un nombre entier envoyé par l’utilisateur
    vitesse = constrain(vitesse, 0, 255);   // Limite la valeur entre 0 (arrêt) et 255 (vitesse max)
    
    ventilateur.setSpeed(vitesse);          // Applique la vitesse au moteur
    ventilateur.run(FORWARD);               // Fait tourner le moteur dans le sens avant
    
    // Affiche la vitesse réglée dans le moniteur série
    Serial.print("Vitesse reglee: ");
    Serial.println(vitesse);
  }
}
