// === Inclusion de la bibliothèque Adafruit Motor Shield ===
#include <AFMotor.h>  
// Cette bibliothèque permet de contrôler facilement des moteurs CC, pas à pas ou servos
// via le shield moteur Adafruit (L293D ou équivalent).

// === Création d’un objet moteur ===
AF_DCMotor motor(1);  
// Crée un moteur CC connecté sur la sortie M1 du shield (1 = M1, 2 = M2, etc.)

// === Fonction d’initialisation ===
void setup() {
    // Définit la vitesse initiale du moteur à 200 (sur une échelle de 0 à 255)
    motor.setSpeed(200);
    
    // Libère le moteur (aucune rotation, état neutre)
    motor.run(RELEASE);
}

// === Boucle principale ===
void loop() {
    uint8_t i;  // Variable utilisée pour les boucles d’accélération/décélération
    
    // === Étape 1 : Rotation avant ===
    motor.run(FORWARD);  // Le moteur tourne dans le sens avant
    
    // --- Accélération progressive ---
    for (i = 0; i < 255; i++) {
        motor.setSpeed(i);  // Incrémente la vitesse
        delay(10);          // Attente pour rendre l’accélération visible
    }
    
    // --- Décélération progressive ---
    for (i = 255; i != 0; i--) {
        motor.setSpeed(i);  // Réduit progressivement la vitesse
        delay(10);
    }
    
    // === Étape 2 : Changement de direction ===
    motor.run(BACKWARD);   // Le moteur tourne maintenant en sens inverse (arrière)
    
    // --- Accélération progressive ---
    for (i = 0; i < 255; i++) {
        motor.setSpeed(i);
        delay(10);
    }
    
    // --- Décélération progressive ---
    for (i = 255; i != 0; i--) {
        motor.setSpeed(i);
        delay(10);
    }
    
    // === Étape 3 : Arrêt du moteur ===
    motor.run(RELEASE);  // Coupe toute alimentation vers le moteur
    delay(1000);         // Petite pause avant de recommencer le cycle
}
