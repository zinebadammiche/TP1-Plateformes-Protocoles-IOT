// === Déclaration des broches ===
const int pinPIR = 12;       // Capteur PIR connecté à la broche numérique 12
const int pinLED = 9;        // LED connectée à la broche 9 (indique l’alarme active)
const int pinBuzzer = 8;     // Buzzer connecté à la broche 8

// === Variables de contrôle ===
bool alarmeArmee = false;    // Indique si l’alarme est armée (activée)
bool buzzerActif = false;    // Indique si le buzzer est actuellement en marche
unsigned long finBuzzer = 0; // Moment (en ms) où le buzzer doit s’arrêter

// === Fonction d’initialisation ===
void setup() {
    pinMode(pinPIR, INPUT);      // Capteur PIR configuré en entrée
    pinMode(pinLED, OUTPUT);     // LED configurée en sortie
    pinMode(pinBuzzer, OUTPUT);  // Buzzer configuré en sortie
    Serial.begin(9600);          // Initialisation du port série
    Serial.println("Système alarme simple - A=Armer, D=Désarmer");
}

// === Boucle principale ===
void loop() {
    // --- Lecture des commandes depuis le moniteur série ---
    if (Serial.available()) {          // Si une donnée est disponible sur le port série
        char c = Serial.read();        // Lecture du caractère envoyé
        
        // Commande 'A' ou 'a' → Armer le système
        if (c == 'A' || c == 'a') {
            alarmeArmee = true;
            Serial.println("Alarme ARMÉE");
        } 
        // Commande 'D' ou 'd' → Désarmer le système
        else if (c == 'D' || c == 'd') {
            alarmeArmee = false;
            digitalWrite(pinLED, LOW);   // Éteindre LED
            noTone(pinBuzzer);           // Arrêter le buzzer
            Serial.println("Alarme DÉSARMÉE");
        }
    }

    // --- Si l’alarme est armée et qu’un mouvement est détecté ---
    if (alarmeArmee && digitalRead(pinPIR) == HIGH) {
        activerAlarme(); // Appel de la fonction qui déclenche l’alarme
    }

    // --- Gestion de la durée du buzzer ---
    if (buzzerActif && millis() >= finBuzzer) {  // Si le temps est écoulé
        noTone(pinBuzzer);           // Arrête le buzzer
        buzzerActif = false;         // Indique qu’il n’est plus actif
        digitalWrite(pinLED, LOW);   // Éteint la LED
        Serial.println("Buzzer désactivé (timeout)");
    }

    delay(100); // Pause de 100 ms pour limiter la fréquence de boucle
}

// === Fonction d’activation de l’alarme ===
void activerAlarme() {
    if (!buzzerActif) {                    // Si le buzzer n’est pas déjà en marche
        buzzerActif = true;                // Active le buzzer
        finBuzzer = millis() + 5000;       // Fixe la durée à 5 secondes
        digitalWrite(pinLED, HIGH);        // Allume la LED
        tone(pinBuzzer, 1000);             // Fait sonner le buzzer à 1000 Hz
        Serial.println("ALARME! Buzzer activé pour 5 secondes");
    }
}
