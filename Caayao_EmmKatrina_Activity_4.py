import tkinter as tk

def split_len(seq, length):
    return [seq[i:i + length] for i in range(0, len(seq), length)]

def encode(key, plaintext):
    order = {int(val): num for num, val in enumerate(key)}
    ciphertext = ''

    for index in sorted(order.keys()):
        for part in split_len(plaintext, len(key)):
            try:
                ciphertext += part[order[index]]
            except IndexError:
                continue

    return ciphertext

def encrypt():
    key = key_entry.get()
    plaintext = plaintext_entry.get()
    result_label.config(text="Ciphered text: " + encode(key, plaintext))

root = tk.Tk()
root.title("Transposition Cipher Program")

# Welcome Sign
tk.Label(root, text="Welcome to the Transposition Cipher Program!", font=("Helvetica", 14)).grid(row=0, column=0, columnspan=2, pady=10)

tk.Label(root, text="Enter the arrangement of your word:").grid(row=1, column=0, padx=10, pady=5)
key_entry = tk.Entry(root)
key_entry.grid(row=1, column=1, padx=10, pady=5)

tk.Label(root, text="Enter the word you want to cipher:").grid(row=2, column=0, padx=10, pady=5)
plaintext_entry = tk.Entry(root)
plaintext_entry.grid(row=2, column=1, padx=10, pady=5)

encrypt_button = tk.Button(root, text="Encrypt", command=encrypt)
encrypt_button.grid(row=3, column=0, columnspan=2, pady=10)

result_label = tk.Label(root, text="")
result_label.grid(row=4, column=0, columnspan=2, pady=5)

root.mainloop()
