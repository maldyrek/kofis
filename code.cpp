#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main() {
    // Lista dostępnych produktów (Krok 6)
    std::vector<std::string> products = {
        "A1. Small Chocolate", "B2. Small Shake Dark", "C3. Small Shake White",
        "D4. Small Machiato", "E5. Small Capucino", "F6. Small Latté",
        "G7. Small Tea", "H8. Small Soup"
    };

    // Lista poprawnych kodów (Krok 4)
    std::vector<std::string> valid_codes = {
        "2168", "2334", "8900", "7656", "0012", "5644", "1238", "0756",
        "1112", "2346", "7611", "9992", "9878", "0234", "8787", "0002", "5547", "0924"
    };

    std::cout << "=== AUTOMAT INITIALIZED ===\n\n";

    // KROK 1: Wybór produktu
    std::cout << "[Krok 1] Dostepne produkty:\n";
    for (const auto& prod : products) {
        std::cout << "  " << prod << "\n";
    }
    
    std::string selected_product;
    std::cout << "\nProszę wybrać produkt (np. A1): ";
    std::cin >> selected_product;
    std::cout << "Wybrano: " << selected_product << "\n\n";

    // KROK 2: Płatność terminalem (Logowanie)
    std::cout << "[Krok 2] Connecting to terminal (192.168.1.50)...\n";
    std::string username, password;
    
    while (true) {
        std::cout << "Username: ";
        std::cin >> username;
        std::cout << "Password: ";
        std::cin >> password;

        if (username == "admin" && password == "5678mald") {
            std::cout << "Payment successful!\n\n";
            break;
        } else {
            std::cout << "Bledne dane logowania. Sprobuj ponownie.\n";
        }
    }

    // KROK 3: Skanowanie karty RFID
    std::cout << "[Krok 3] scan your id card\n";
    std::string rfid_scan;
    
    while (true) {
        std::cout << "Zbliz karte RFID (rfid-8787-0009): ";
        std::cin >> rfid_scan;
        
        if (rfid_scan == "rfid-8787-0009") {
            std::cout << "Card verified.\n\n";
            break;
        } else {
            std::cout << "Nieznana karta. Sprobuj ponownie.\n";
        }
    }

    // KROK 4: Weryfikacja kodu z listy w pętli while
    std::cout << "[Krok 4] write XXXX Code\n";
    std::string user_code;
    bool code_correct = false;

    while (!code_correct) {
        std::cout << "Wprowadz kod autoryzacyjny: ";
        std::cin >> user_code;

        // Sprawdzenie czy wprowadzony kod znajduje się na liście CODES
        auto it = std::find(valid_codes.begin(), valid_codes.end(), user_code);
        if (it != valid_codes.end()) {
            std::cout << "Kod poprawny! Autoryzacja zakonczona sukcesem.\n\n";
            code_correct = true;
        } else {
            std::cout << "Nieprawidlowy kod. Dostep odmowiony. Sprobuj ponownie.\n";
        }
    }

    // KROK 5: Koniec
    std::cout << "[Krok 5] Sukces! Odbierz swoj produkt. Milego dnia!\n";
    std::cout << "=== END OF TRANSACTION ===\n";

    return 0;
}
