#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Fonction pour vérifier si une chaîne est un palindrome
int estPalindrome(const char *str) {
    int longueur = strlen(str);
    int debut = 0;
    int fin = longueur - 1;

    while (fin > debut) {
        // Ignorer les caractères non alphabétiques
        while (!isalpha(str[debut])) {
            debut++;
        }
        while (!isalpha(str[fin])) {
            fin--;
        }

        // Comparer les caractères, en ignorant la casse
        if (tolower(str[debut]) != tolower(str[fin])) {
            return 0; // Non palindrome
        }

        debut++;
        fin--;
    }

    return 1; // Palindrome
}

int main() {
    char str[100];

    // Titre du programme
    printf("=== Vérificateur de Palindrome ===\n");

    // Demander à l'utilisateur d'entrer une chaîne
    printf("Entrez une chaîne : ");
    fgets(str, sizeof(str), stdin);

    // Supprimer le caractère de nouvelle ligne ajouté par fgets
    if (str[strlen(str) - 1] == '\n') {
        str[strlen(str) - 1] = '\0';
    }

    // Vérifier si la chaîne est un palindrome
    if (estPalindrome(str)) {
        printf("La chaîne est un palindrome.\n");
    } else {
        printf("La chaîne n'est pas un palindrome.\n");
    }

    return 0;
}

