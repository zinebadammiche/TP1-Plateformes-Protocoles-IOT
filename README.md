# README - TP1 Plateformes et Protocoles IoT

📋 **Description du projet**
Ce repository contient l'ensemble des travaux pratiques réalisés dans le cadre du module *Initiation à Arduino & Capteurs/Actionneurs*, portant sur les plateformes et protocoles de l'Internet des Objets (IoT). Le projet est structuré en trois exercices progressifs couvrant la communication série, l'intégration de capteurs et le contrôle d'actionneurs.

---

🎓 **Informations académiques**
- **Institut** : Institut National des Postes et Télécommunications (INPT) - Rabat
- **Formation** : Master M2 IoT & Big Data
- **Année universitaire** : 2025-2026
- **Encadrant** : Pr. Benmaissa Yann

---

👥 **Contributeurs**
- Zineb Saraoui
- Zineb Adammiche
- Amine Benali
- Sana Bakrim

---

📚 **Structure du projet**

### **Exercice 1 : Communication série et contrôle de LEDs**
**Objectif** : Maîtriser la communication bidirectionnelle UART entre Arduino UNO et PC.
**Compétences développées** :
- Configuration de la communication série (baud rate, protocole UART)
- Conversion USB-UART via ATmega16U2
- Contrôle de LEDs avec résistances de limitation
- Implémentation de temporisations non-bloquantes avec `millis()`
- Gestion d'entrées utilisateur et filtrage de caractères parasites

**Programmes inclus** :
- Communication série basique
- Contrôle LED via commandes série (a/e)
- Contrôle avancé avec modes multiples (allumer, éteindre, clignoter, inverser)
- Contrôle de deux LEDs avec périodes variables

---

### **Exercice 2 : Capteurs et détection de mouvement**
**Objectif** : Explorer le capteur PIR HC-SR501 et les systèmes d'alarme.
**Compétences développées** :
- Détection pyroélectrique passive
- Modes de déclenchement (single/repeatable trigger)
- Gestion d'états et anti-spam
- Intégration buzzer actif et LED

**Programmes inclus** :
- Détection PIR avec visualisation LED
- Système d'alarme intelligent avec buzzer
- Commandes série pour armement/désarmement (A/D)

---

### **Exercice 3 : Actionneurs et moteurs**
**Objectif** : Piloter différents types de moteurs avec Arduino et Motor Shield.
**Compétences développées** :
- Modulation PWM pour moteurs DC
- Contrôle de servomoteurs (position angulaire)
- Pilotage de moteurs pas-à-pas
- Utilisation du shield Adafruit Motor Shield V2
- Interaction capteur-actionneur (LDR + Servo)

**Programmes inclus** :
- Contrôle moteur DC avec accélération/décélération
- Mini ventilateur à vitesse variable
- Contrôle servomoteur par commandes série
- Pilotage moteur pas-à-pas (avant/arrière/stop)
- Système automatique LDR-Servo

---

🛠️ **Matériel utilisé**

| Composant                | Quantité | Description                                      |
|--------------------------|----------|--------------------------------------------------|
| Arduino UNO R3           | 1        | Microcontrôleur ATmega328P                       |
| Capteur PIR HC-SR501     | 1        | Détecteur de mouvement infrarouge               |
| Shield moteur L293D      | 1        | Pont en H pour pilotage moteurs                   |
| Moteur DC 6V             | 1        | Moteur à courant continu                         |
| Servomoteur SG90         | 1        | Servo 180°                                       |
| Moteur pas-à-pas 28BYJ-48| 1        | Moteur unipolaire 5V                            |
| Buzzer actif 5V          | 1        | Générateur de son                                |
| LEDs (rouge, verte, bleue)| 10       | Diodes électroluminescentes                      |
| Résistances (220Ω, 330Ω, 10kΩ) | 20 | Limitation de courant                     |
| Breadboard 830 points    | 1        | Plaque d'essai                                   |
| Câbles Dupont             | 40       | Connexions                                       |

---

🔧 **Installation et configuration**

### **Prérequis**
- Arduino IDE 2.3.2 ou supérieur
- Drivers CH340/FTDI pour reconnaissance USB
- Librairies Arduino :
  - `AFMotor.h` (Adafruit Motor Shield)
  - `Servo.h` (contrôle servomoteurs)

### **Configuration**
1. Installer l'IDE Arduino depuis [arduino.cc](https://www.arduino.cc)
2. Sélectionner la carte : `Tools → Board → Arduino UNO`
3. Sélectionner le port COM approprié
4. Installer les librairies nécessaires via le Library Manager

---

🚀 **Utilisation**

### **Compilation et téléversement**
```bash
# Ouvrir le fichier .ino dans Arduino IDE
# Vérifier la configuration (carte + port)
## Communication série
- **Ouvrir le moniteur série** : `Tools → Serial Monitor`
- **Configurer le baud rate** : **9600 bauds**
- **Format** : **8N1** (8 data bits, No parity, 1 stop bit)

```

## 📊 Méthodologie de travail

### Outils professionnels intégrés
- **Git/GitHub** : Versionnement du code avec messages de commit descriptifs, historique transparent, collaboration d'équipe.
- **Jira** : Gestion agile des tâches (Kanban), tickets par exercice/question, estimation en Story Points, suivi structuré.
- **Slack** : Communication professionnelle structurée, canaux thématiques, intégrations GitHub/Jira, notifications automatiques.

### Workflow intégré
 Jira (mise à jour ticket) → Slack (notification équipe)
GitHub (push/commit) →  Slack (notification équipe)

---

## 📖 Documentation
Le rapport complet (format LaTeX) est disponible dans le repository et couvre :
- Configuration matérielle et logicielle
- Codes sources commentés
- Schémas de montage
- Analyses techniques approfondies
- Résultats et validations
- Références bibliographiques

---

## 🎯 Compétences acquises

### Techniques
- Interfaçage matériel (câblage, calcul de résistances)
- Protocoles de communication (UART, GPIO, PWM, I2C, SPI)
- Programmation embarquée (machines d'états, temporisations non-bloquantes)
- Gestion de capteurs et actionneurs

### Méthodologiques
- Gestion de projet agile (Jira)
- Versionnement de code (Git/GitHub)
- Communication collaborative (Slack)
- Documentation technique rigoureuse

---

## 📝 Licence
Ce projet est réalisé dans un cadre académique à l'**Institut National des Postes et Télécommunications (INPT)**.

---

## 📧 Contact
Pour toute question concernant ce projet, veuillez contacter les contributeurs via le workspace Slack du projet ou par le biais des issues GitHub.

**Dernière mise à jour** : Octobre 2025

# Compiler avec Ctrl+R
# Téléverser avec Ctrl+U
