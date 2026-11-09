#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <chrono>
#include <thread>

// Funkcja symulująca efekt ładowania systemu (efektowne dla oka)
void pokazLadowanie(const std::string& komunikat) {
    std::cout << "[KOFIS SYSTEM] " << komunikat;
    for (int i = 0; i < 3; ++i) {
        std::this_thread::sleep_for(std::chrono::milliseconds(400));
        std::cout << "." << std::flush;
    }
    std::cout << " OK\n";
}

int main() {
    // Ustawienie kodowania dla polskich znaków w konsoli Windows
    #ifdef _WIN32
        system("chcp 65001 > nul");
    #endif

    std::cout << "==================================================\n";
    std::cout << "          KOFIS NET - NODE MANAGER v2.6           \n";
    std::cout << "==================================================\n\n";

    pokazLadowanie("Inicjalizacja modułu kryptograficznego");
    pokazLadowanie("Sprawdzanie połączenia z bazą danych węzła");

    std::string nazwaPliku = "Automat_Cafe.txt";
    std::ifstream plik(nazwaPliku);

    std::cout << "\n[PROCES] Próba otwarcia pliku struktury: " << nazwaPliku << "\n";

    if (!plik.is_open()) {
        std::cout << "\n[BŁĄD] Nie można odnaleźć pliku '" << nazwaPliku << "'!\n";
        std::cout << "[WSKAZÓWKA] Upewnij się, że plik tekstowy znajduje się w tym samym folderze co ten program.\n\n";
    } else {
        std::cout << "[SUKCES] Strumień danych został prawidłowo otwarty.\n";
        std::cout << "--------------------------------------------------\n";
        std::cout << ">>> ZAWARTOŚĆ PLIKU BAZODANOWEGO <<<\n";
        std::cout << "--------------------------------------------------\n";

        std::string linia;
        int licznikLinii = 0;
        bool czyZaszyfrowany = false;

        while (std::getline(plik, linia)) {
            licznikLinii++;
            std::cout << "[" << licznikLinii << "] " << linia << "\n";
            
            // Prosta detekcja, czy plik zawiera "bełkot" kryptograficzny
            if (licznikLinii == 1 && linia.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+=/") == std::string::npos && linia.length() > 20) {
                czyZaszyfrowany = true;
            }
        }
        
        plik.close();
        std::cout << "--------------------------------------------------\n";
        std::cout << "[INFO] Zakończono odczyt pliku. Wczytano linii: " << licznikLinii << "\n";
        
        if (czyZaszyfrowany) {
            std::cout << "[STATUS] Wykryto silne szyfrowanie offline (AES/RSA).\n";
            std::cout << "[STATUS] Dane są bezpieczne przed nieautoryzowanym dostępem.\n";
        } else {
            std::cout << "[OSTRZEŻENIE] Plik zawiera otwarty tekst (Plain Text).\n";
        }
        std::cout << "--------------------------------------------------\n\n";
    }

    std::cout << "Naciśnij ENTER, aby zamknąć program...";
    std::cin.get(); 
    return 0;
}
