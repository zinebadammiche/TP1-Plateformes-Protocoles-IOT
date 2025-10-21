/*
  Envoi et réception d'un message via le port série
  - 'a' : allume la LED
  - 'e' : éteint la LED
  - 'c' : fait clignoter la LED indéfiniment
  - 'i' : inverse l'état actuel de la LED
*/

int led = 9;            // Broche de la LED
char octet_rx = 0;      // Variable pour stocker le caractère reçu
bool clignoter = false; // Indique si la LED doit clignoter
bool etat_led = false;  // Mémorise l'état actuel de la LED (éteinte = false)

void setup() {
  Serial.begin(9600);      // Initialisation du port série
  pinMode(led, OUTPUT);    // Définir la broche LED comme sortie
  Serial.println("Commandes :");
  Serial.println(" 'a' = allumer");
  Serial.println(" 'e' = éteindre");
  Serial.println(" 'c' = clignoter");
  Serial.println(" 'i' = inverser l'état");
}

void loop() {
  // Vérifie si un caractère est reçu
  if (Serial.available() > 0) {
    octet_rx = Serial.read();

    // Si on reçoit 'a' → allumer
    if (octet_rx == 'a') {
      clignoter = false;
      etat_led = true;
      digitalWrite(led, HIGH);
      Serial.println("LED allumée");
    }
    // Si on reçoit 'e' → éteindre
    else if (octet_rx == 'e') {
      clignoter = false;
      etat_led = false;
      digitalWrite(led, LOW);
      Serial.println("LED éteinte");
    }
    // Si on reçoit 'c' → commencer à clignoter
    else if (octet_rx == 'c') {
      clignoter = true;
      Serial.println("Clignotement activé (tapez 'a' ou 'e' pour arrêter)");
    }
    // Si on reçoit 'i' → inverser l'état
    /*else if (octet_rx == 'i') {
      clignoter = false; // stoppe le clignotement si actif
      etat_led = !etat_led; // inverse l’état
      digitalWrite(led, etat_led ? HIGH : LOW);
      Serial.print("État inversé → LED ");
      Serial.println(etat_led ? "allumée" : "éteinte");
    }*/
    else if (octet_rx == 'i'){
      if (etat_led == false){
        digitalWrite(led, HIGH);
        etat_led = true;
        Serial.print("dkhlat");
      }
       
      else{
        digitalWrite(led, LOW);
        Serial.print("dkhlat1");
        etat_led = false;
      }
    }
  }

  // Si le mode clignotement est actif
  if (clignoter) {
    digitalWrite(led, HIGH);
    delay(500);
    digitalWrite(led, LOW);
    delay(500);
  if (octet_rx == 'i'){
      if (etat_led == false){
        digitalWrite(led, HIGH);
        etat_led = true;
        Serial.print("dkhlat");
      }
       
      else{
        digitalWrite(led, LOW);
        Serial.print("dkhlat1");
        etat_led = false;
      }
    }
  }
 } 

