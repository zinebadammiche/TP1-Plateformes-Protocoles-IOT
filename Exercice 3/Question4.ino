#include <Servo.h>  
// Inclusion de la bibliothèque Servo pour contrôler un servomoteur

Servo monServo;  
// Création d’un objet 'monServo' pour piloter le servo

int ldrPin = A0;   // Broche analogique où est branchée la LDR (capteur de lumière)
int valeurLDR;     // Variable pour stocker la valeur lue du capteur

void setup() {
  Serial.begin(9600);
  // Démarrage de la communication série à 9600 bauds pour afficher les mesures

  monServo.attach(9);
  // Connexion du servomoteur à la broche numérique 9
}

void loop() {
  valeurLDR = analogRead(ldrPin);
  // Lecture de la tension envoyée par la LDR (valeur comprise entre 0 et 1023)
  // 0 → obscurité totale, 1023 → forte luminosité

  int positionServo = map(valeurLDR, 0, 1023, 0, 180);
  // Conversion de la valeur lumineuse en angle de rotation du servo
  // map() adapte la plage de 0–1023 à une plage de 0–180 degrés

  monServo.write(positionServo);
  // Envoie la nouvelle position au servomoteur : le servo tourne proportionnellement à la lumière

  Serial.print("LDR: ");
  Serial.print(valeurLDR);
  Serial.print(" -> Position Servo: ");
  Serial.println(positionServo);
  // Affiche la valeur lue par la LDR et la position correspondante du servo dans le moniteur série

  delay(200);
  // Petite pause de 200 ms pour éviter des changements trop rapides
}
