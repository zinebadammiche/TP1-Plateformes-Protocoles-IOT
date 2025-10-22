// === Déclaration des constantes et variables globales ===
const int LED1 = 13;     // LED1 connectée à la broche numérique 13
const int LED2 = 12;     // LED2 connectée à la broche numérique 12

unsigned long prev1 = 0; // Enregistre le dernier moment où LED1 a changé d’état
unsigned long prev2 = 0; // Enregistre le dernier moment où LED2 a changé d’état
unsigned long p1 = 0;    // Période de clignotement pour LED1 (en millisecondes)
unsigned long p2 = 0;    // Période de clignotement pour LED2 (en millisecondes)

// === Fonction d’initialisation ===
void setup() {
  pinMode(LED1, OUTPUT);   // Définit LED1 comme sortie
  pinMode(LED2, OUTPUT);   // Définit LED2 comme sortie
  Serial.begin(9600);      // Démarre la communication série à 9600 bauds
  
  Serial.println("Saisir P1 (ms): "); // Invite l’utilisateur à saisir la première période
}

// === Boucle principale ===
void loop() {
  // --- Lecture des valeurs entrées par l'utilisateur ---
  if (Serial.available()) {             // Si des données sont disponibles sur le port série
    String input = Serial.readString(); // Lecture de la chaîne entrée par l’utilisateur
    input.trim();                       // Supprime les espaces et retours à la ligne
    
    if (isValid(input)) {               // Vérifie si la saisie est valide (nombre entre 10 et 10000)
      unsigned long val = input.toInt();  // Convertit la chaîne en entier
      
      if (p1 == 0) {  // Si P1 n’a pas encore été défini
        p1 = val;
        Serial.print("P1 = ");
        Serial.println(p1);
        Serial.println("Saisir P2 (ms): ");  // Demande à l’utilisateur la deuxième période
      } else {  // Sinon, on définit P2
        p2 = val;
        Serial.print("P2 = ");
        Serial.println(p2);
        Serial.println("LEDs actives!");    // Indique que les deux LED vont maintenant clignoter
      }
    } else {
      // Si la saisie n’est pas valide
      Serial.println("Erreur! Saisir un nombre entre 10 et 10000:");
    }
  }
  
  // --- Contrôle du clignotement des LEDs ---
  unsigned long now = millis();  // Temps actuel depuis le démarrage de la carte
  
  // Gestion de la LED1
  if (p1 > 0 && now - prev1 >= p1) { // Si la période p1 est définie et écoulée
    prev1 = now;                     // Met à jour le temps de référence
    digitalWrite(LED1, !digitalRead(LED1));  // Inverse l’état de LED1
  }
  
  // Gestion de la LED2
  if (p2 > 0 && now - prev2 >= p2) { // Même principe pour la LED2
    prev2 = now;
    digitalWrite(LED2, !digitalRead(LED2));
  }
}

// === Fonction utilitaire pour vérifier la validité d’une saisie ===
bool isValid(String s) {
  if (s.length() == 0) return false;  // Vérifie qu’il y a au moins un caractère
  
  // Vérifie que tous les caractères sont des chiffres
  for (int i = 0; i < s.length(); i++) {
    if (!isDigit(s[i])) return false;
  }
  
  // Convertit la chaîne en nombre entier
  unsigned long val = s.toInt();
  // Vérifie que le nombre est compris entre 10 et 10000 ms
  return (val >= 10 && val <= 10000);
}
