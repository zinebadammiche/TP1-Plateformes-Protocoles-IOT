// Fonction d'initialisation : elle s’exécute une seule fois au démarrage
void setup() {
  // On initialise la communication série avec le PC à 9600 bauds
  Serial.begin(9600);
}

// Fonction principale : elle tourne en boucle infinie
void loop() {
  // Envoie un message sur le moniteur série (avec retour à la ligne)
  Serial.println("Salam alaykoum");

  // Envoie un autre message sur le moniteur série (avec retour à la ligne)
  Serial.println("Azul Fellawn");

  // Envoie un dernier message sur le moniteur série (avec retour à la ligne)
  Serial.println("Bonjour à tous");

  // Attend 1 seconde (1000 millisecondes) avant de recommencer la boucle
  delay(1000);
}
