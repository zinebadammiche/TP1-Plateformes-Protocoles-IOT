// === Déclaration des constantes et variables ===
const int pinPIR = 12;     // Broche de connexion du capteur PIR (détecteur de mouvement)
const int pinLED = 9;      // Broche de la LED (indicateur visuel)
int valPIR = 0;            // Valeur lue sur le capteur PIR (HIGH = mouvement détecté)
int etatPirPrecedent = LOW;// Sauvegarde de l’état précédent du capteur PIR
unsigned long debutMouvement = 0; // Temps où le mouvement a été détecté
bool mouvementEnCours = false;    // Indique si un mouvement est actuellement détecté

// === Fonction d’initialisation ===
void setup() {
    pinMode(pinPIR, INPUT);   // Configure la broche du capteur PIR comme entrée
    pinMode(pinLED, OUTPUT);  // Configure la broche de la LED comme sortie
    Serial.begin(9600);       // Initialise la communication série à 9600 bauds
    Serial.println("Visualisation modes PIR - LED");
}

// === Boucle principale ===
void loop() {
    valPIR = digitalRead(pinPIR);  // Lecture de l’état du capteur PIR (HIGH ou LOW)
    
    // --- Détection du début de mouvement ---
    if (valPIR == HIGH && etatPirPrecedent == LOW) {
        mouvementEnCours = true;           // Indique qu’un mouvement vient d’être détecté
        debutMouvement = millis();         // Sauvegarde le temps du début du mouvement
        digitalWrite(pinLED, HIGH);        // Allume la LED
        Serial.print("Mouvement détecté à: ");
        Serial.println(millis());          // Affiche le moment de détection dans le moniteur série
        etatPirPrecedent = HIGH;           // Mémorise le nouvel état du capteur
    }

    // --- Détection de la fin du mouvement ---
    if (valPIR == LOW && etatPirPrecedent == HIGH) {
        mouvementEnCours = false;          // Indique qu’il n’y a plus de mouvement
        digitalWrite(pinLED, LOW);         // Éteint la LED
        Serial.println("Mouvement terminé");
        etatPirPrecedent = LOW;            // Mémorise le nouvel état du capteur
    }

    delay(100); // Petite pause pour éviter une lecture trop rapide du capteur (anti-rebond)
}
