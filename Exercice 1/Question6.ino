// Déclaration des variables globales
int led = 9;                      // La LED est connectée à la broche numérique 9
char cmd = 0;                     // Variable pour stocker la commande reçue via le port série
bool blinkMode = false;           // Variable indiquant si le mode clignotement est activé ou non
unsigned long previousMillis = 0; // Stocke le dernier instant où la LED a changé d’état
const long blinkInterval = 500;   // Intervalle de clignotement en millisecondes (500 ms = 0,5 s)

// Fonction d’initialisation — exécutée une seule fois au démarrage
void setup() {
  Serial.begin(9600);             // Initialisation de la communication série à 9600 bauds
  pinMode(led, OUTPUT);           // Définit la broche LED comme une sortie
  digitalWrite(led, LOW);         // Éteint la LED au démarrage

  // Messages d’instructions affichés dans le moniteur série
  Serial.println("=== Systeme de controle LED ===");
  Serial.println("Commandes disponibles:");
  Serial.println("  a - Allumer");
  Serial.println("  e - Eteindre");
  Serial.println("  c - Clignoter");
  Serial.println("  i - Inverser etat");
  Serial.println("================================");
}

// Boucle principale — s’exécute en continu
void loop() {
  // === Gestion du mode clignotement ===
  if (blinkMode) {  // Si le mode clignotement est activé
    unsigned long currentMillis = millis();  // Temps actuel depuis le démarrage
    // Vérifie si l’intervalle de clignotement est écoulé
    if (currentMillis - previousMillis >= blinkInterval) {
      previousMillis = currentMillis;         // Met à jour le dernier instant
      digitalWrite(led, !digitalRead(led));   // Inverse l’état de la LED (ON/OFF)
    }
  }
  
  // === Lecture des commandes série ===
  if (Serial.available() > 0) {  // Si une donnée est reçue sur le port série
    cmd = Serial.read();          // Lecture du caractère envoyé
    
    // Filtrage des caractères inutiles (retours chariot, etc.)
    if (cmd == '\r' || cmd == '\n') {
      return;  // Ignore et retourne au début de loop()
    }
    
    blinkMode = false;  // Désactive le mode clignotement quand une nouvelle commande arrive
    
    // === Traitement des différentes commandes ===
    switch(cmd) {
      case 'a':
      case 'A':  // Allumer la LED
        digitalWrite(led, HIGH);
        Serial.println("[OK] LED allumee");
        break;
        
      case 'e':
      case 'E':  // Éteindre la LED
        digitalWrite(led, LOW);
        Serial.println("[OK] LED eteinte");
        break;
        
      case 'c':
      case 'C':  // Activer le mode clignotement
        blinkMode = true;
        previousMillis = millis();  // Réinitialise le minuteur
        Serial.println("[OK] Mode clignotement active");
        break;
        
      case 'i':
      case 'I':  // Inverser l’état actuel de la LED
        digitalWrite(led, !digitalRead(led));
        Serial.print("[OK] Etat inverse - LED ");
        // Affiche l’état actuel de la LED (allumée ou éteinte)
        Serial.println(digitalRead(led) ? "allumee" : "eteinte");
        break;
        
      default:  // Commande inconnue
        Serial.print("[ERREUR] Commande inconnue: ");
        Serial.println(cmd);
        break;
    }
  }
}
