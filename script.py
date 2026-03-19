import customtkinter as ctk
import pyperclip

ctk.set_appearance_mode("dark")
ctk.set_default_color_theme("blue")

def transformer_message(mode):
    message = entree_msg.get()
    try:
        cle = int(entree_cle.get())
    except ValueError:
        label_resultat.configure(text="Erreur: La clé doit être un nombre !", text_color="#e74c3c")
        return

    decalage_final = -cle if mode == "decrypt" else cle
    
    resultat = ""
    for char in message:
        if char.isalpha():
            base = 65 if char.isupper() else 97
            resultat += chr((ord(char) - base + decalage_final) % 26 + base)
        else:
            resultat += char
    
    label_resultat.configure(text=resultat, text_color="#2ecc71")

def copier_resultat():
    texte = label_resultat.cget("text")
    if texte and "Erreur" not in texte:
        pyperclip.copy(texte)
        btn_copy.configure(text="COPIÉ DANS LE PRESSE-PAPIER", fg_color="#27ae60")
        app.after(2000, lambda: btn_copy.configure(text="Copier le résultat", fg_color="#34495e"))

# Fenêtre doublée : 1200x1000
app = ctk.CTk()
app.title("CyberTool--de Chiffrement")
app.geometry("1200x1000")

# Titre géant
titre = ctk.CTkLabel(app, text="CYBER-CRYPTOR ", 
                     font=ctk.CTkFont(size=36, weight="bold"))
titre.pack(pady=60)

# Entrée du message (plus large et plus haute)
entree_msg = ctk.CTkEntry(app, placeholder_text="Entrez votre message ici...", 
                          width=800, height=60, font=ctk.CTkFont(size=18))
entree_msg.pack(pady=20)

# Entrée de la clé
entree_cle = ctk.CTkEntry(app, placeholder_text="Clé numérique", 
                          width=200, height=50, font=ctk.CTkFont(size=18), show="*")
entree_cle.pack(pady=20)

# Frame pour les boutons
frame_btns = ctk.CTkFrame(app, fg_color="transparent")
frame_btns.pack(pady=40)

btn_encrypt = ctk.CTkButton(frame_btns, text="CRYPTER", 
                            command=lambda: transformer_message("encrypt"), 
                            width=250, height=60, font=ctk.CTkFont(size=20, weight="bold"))
btn_encrypt.grid(row=0, column=0, padx=20)

btn_decrypt = ctk.CTkButton(frame_btns, text="DÉCRYPTER", 
                            command=lambda: transformer_message("decrypt"), 
                            width=250, height=60, font=ctk.CTkFont(size=20, weight="bold"),
                            fg_color="#d35400", hover_color="#e67e22")
btn_decrypt.grid(row=0, column=1, padx=20)

# Zone de résultat imposante
ctk.CTkLabel(app, text="RÉSULTAT DU TRAITEMENT :", 
             font=ctk.CTkFont(size=16, slant="italic")).pack(pady=(40, 0))

label_resultat = ctk.CTkLabel(app, text="", 
                              font=ctk.CTkFont(size=28, weight="bold"), 
                              wraplength=1000)
label_resultat.pack(pady=30)

# Bouton de copie
btn_copy = ctk.CTkButton(app, text="Copier le résultat", 
                         command=copier_resultat, 
                         width=400, height=70, font=ctk.CTkFont(size=18),
                         fg_color="#34495e")
btn_copy.pack(pady=50)

app.mainloop()