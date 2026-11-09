# kofis
(C) 2025 KOFIS NET
# KOFIS NET - Node Management & Configuration Systems

Oficjalne, publiczne repozytorium operacyjne przeznaczone do rozwoju i wsparcia modułów oprogramowania dla infrastruktury sieciowej oraz systemów sprzedażowych pod szyldem KOFIS NET.

## 🛠️ Zawartość projektu
Repozytorium łączy kod źródłowy aplikacji z bazą danych konfiguracji i parametrów operacyjnych:
* **Warstwa aplikacyjna (`code.cpp`):** Moduł sterujący oraz parser logiczny odpowiedzialny za przetwarzanie struktur danych.
* **Warstwa danych (`.txt`):** Pliki tekstowe (np. `Automat_Cafe.txt`) zawierające zrzuty konfiguracyjne urządzeń, cenniki automatów, rejestry logistyczne oraz schematy połączeń.

## 🔒 Polityka bezpieczeństwa i szyfrowania danych
Zgodnie z wewnętrznymi procedurami bezpieczeństwa KOFIS NET, publicznie dostępne pliki bazodanowe o rozszerzeniu `.txt` zawierające parametry techniczne są poddawane **kryptograficznej kompresji offline** przed ich synchronizacją z repozytorium. 

Dane tekstowe w repozytorium są przechowywane w formie niejawnych pakietów kryptograficznych. Dostęp do kluczy deszyfrujących (zarządzanych zewnętrznie) posiadają wyłącznie uprawnieni administratorzy sieci.

---
*(C) 2025-2026 KOFIS NET. Projekt rozwijany na licencji open-source GPL-3.0.*
