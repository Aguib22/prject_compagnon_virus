import customtkinter as ctk
import time
import threading
import pyperclip

ctk.set_appearance_mode("dark")
ctk.set_default_color_theme("green")

class CleanerApp(ctk.CTk):
    def __init__(self):
        super().__init__()

        # Fenêtre format "Dashboard" : 1400x900
        self.title("Cleaner v1.0")
        self.geometry("1400x900")

        # Titre Imposant
        self.label = ctk.CTkLabel(self, text="UNITÉ DE MAINTENANCE SYSTÈME", 
                                 font=ctk.CTkFont(size=38, weight="bold"))
        self.label.pack(pady=60)

        # Zone de statut dynamique
        self.status_label = ctk.CTkLabel(self, text="Système en attente d'analyse...", 
                                        font=ctk.CTkFont(size=20, slant="italic"),
                                        text_color="#95a5a6")
        self.status_label.pack(pady=20)

        # Grosse barre de progression
        self.progress = ctk.CTkProgressBar(self, width=1000, height=25)
        self.progress.set(0)
        self.progress.pack(pady=40)

        # Log de sortie géant pour le "réalisme"
        self.log_box = ctk.CTkTextbox(self, width=1100, height=400, 
                                     font=ctk.CTkFont(family="Courier", size=14),
                                     state="disabled", border_width=2)
        self.log_box.pack(pady=20)

        # Frame pour les boutons en bas
        self.button_frame = ctk.CTkFrame(self, fg_color="transparent")
        self.button_frame.pack(pady=10)

        self.btn_start = ctk.CTkButton(self.button_frame, text="LANCER L'OPTIMISATION", 
                                      command=self.start_cleaning,
                                      width=400, height=70,
                                      font=ctk.CTkFont(size=20, weight="bold"))
        self.btn_start.grid(row=0, column=0, padx=20)

        self.btn_copy = ctk.CTkButton(self.button_frame, text="Copier le rapport d'analyse", 
                                     command=self.copy_log,
                                     width=300, height=70,
                                     fg_color="#34495e",
                                     font=ctk.CTkFont(size=16))
        self.btn_copy.grid(row=0, column=1, padx=20)

    def add_log(self, text):
        self.log_box.configure(state="normal")
        self.log_box.insert("end", f"[{time.strftime('%H:%M:%S')}] {text}\n")
        self.log_box.see("end")
        self.log_box.configure(state="disabled")

    def start_cleaning(self):
        self.btn_start.configure(state="disabled", text="NETTOYAGE EN COURS...")
        threading.Thread(target=self.run_simulation, daemon=True).start()

    def run_simulation(self):
        steps = [
            "Initialisation du moteur d'analyse...",
            "Scan des résidus de paquets APT...",
            "Vérification de l'intégrité du répertoire /tmp...",
            "Analyse des journaux système (journald)...",
            "Identification des caches de navigateurs .....",
            "Calcul de l'espace disque récupérable...",
            "Suppression sécurisée des fichiers temporaires...",
            "---------------------------------------------------------",
            "Rapport final : 1.42 Go libérés. Système optimisé."
        ]
        
        for i, step in enumerate(steps):
            self.status_label.configure(text=step, text_color="#2ecc71")
            self.add_log(step)
            # Progression plus lente pour laisser le virus MediaPlayer agir
            self.progress.set((i + 1) / len(steps))
            time.sleep(2.0) 
        
        self.btn_start.configure(state="normal", text="NOUVELLE ANALYSE")

    def copy_log(self):
        content = self.log_box.get("1.0", "end")
        if content.strip():
            pyperclip.copy(content)
            self.btn_copy.configure(text="RAPPORT COPIÉ !", fg_color="#27ae60")
            self.after(2000, lambda: self.btn_copy.configure(text="Copier le rapport d'analyse", fg_color="#34495e"))

if __name__ == "__main__":
    app = CleanerApp()
    app.mainloop()