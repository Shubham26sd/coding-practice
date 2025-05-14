import tkinter as tk
from tkinter import ttk, messagebox, filedialog
import requests
from bs4 import BeautifulSoup
import os
import re
import threading


# Global variable to manage download cancellation
cancel_download_event = threading.Event()

def search_book():
    book_name = entry.get()
    if not book_name:
        messagebox.showwarning("Input Error", "Please enter a book name")
        return
    
    cancel_download_event.clear()
    threading.Thread(target=download_book_pdf, args=(book_name,)).start()

def cancel_download():
    cancel_download_event.set()

def download_book_pdf(book_name):
    log_text.delete(1.0, tk.END)
    log_text.insert(tk.END, f"Searching for '{book_name}'...\n")
    
    search_urls = [
        f"https://www.google.com/search?q={book_name.replace(' ', '+')}+filetype:pdf",
        f"https://www.bing.com/search?q={book_name.replace(' ', '+')}+filetype:pdf",
        f"https://www.duckduckgo.com/?q={book_name.replace(' ', '+')}+filetype:pdf"
    ]
    
    headers = {
        "User-Agent" : "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/91.0.4472.124 Safari/537.36"
    }
    
    pdf_url = None
    for url in search_urls:
        log_text.insert(tk.END, f"Searching on {url}...\n")
        try:
            response = requests.get(url, headers=headers)
            soup = BeautifulSoup(response.text, "html.parser")
            
            for link in soup.find_all("a", href=True):
                href = link["href"]
                if ".pdf" in href:
                    pdf_url = href
                    break
            if pdf_url:
                break
        except Exception as e:
            log_text.insert(tk.END, f"Error while searching: {str(e)}\n")
            messagebox.showerror("Error", f"Error while searching: {str(e)}")
            return
    
    if not pdf_url:
        log_text.insert(tk.END, "No PDF found for the given book name\n")
        messagebox.showerror("Error", "No PDF found for the given book name")
        return
    
    
    log_text.insert(tk.END, f"PDF found at: {pdf_url}\n")
    
    save_path = filedialog.askdirectory()
    if not save_path:
        return

    pdf_name = re.sub(r'[\\/*?:"<>|]', "", book_name) + ".pdf"
    file_path = os.path.join(save_path, pdf_name)

    log_text.insert(tk.END, f"Downloading PDF to: {file_path}\n")
    
    try:
        response = requests.get(pdf_url, stream=True)
        total_size = int(response.headers.get('content-length', 0))
        
        progress_bar['value'] = 0
        progress_bar['maximum'] = total_size
        
        with open(file_path, 'wb') as pdf_file:
            for data in response.iter_content(chunk_size=4096):
                if cancel_download_event.is_set():
                    log_text.insert(tk.END, "Download cancelled\n")
                    messagebox.showinfo("Download Cancelled", "The download has been cancelled.")
                    return
                
                pdf_file.write(data)
                progress_bar['value'] += len(data)
                root.update_idletasks()
                
        log_text.insert(tk.END, "Download successful\n")
        messagebox.showinfo("Success", f"PDF downloaded successfully as {file_path}")

        try:
            os.startfile(file_path)
        except Exception as e:
            log_text.insert(tk.END, f"Failed to open PDF: {str(e)}\n")
            messagebox.showerror("Error", f"Failed to open PDF: {str(e)}")
        

    except Exception as e:
        log_text.insert(tk.END, f"Failed to download PDF: {str(e)}\n")
        messagebox.showerror("Error", f"Failed to download PDF: {str(e)}")

# Create the main application window
root = tk.Tk()
root.title("Book PDF Downloader")

# Maximize the window
root.state('zoomed') 

# Set window dimensions
root.geometry("800x500")

# Create a style
style = ttk.Style()
style.configure("TLabel", font=("Lobster", 14))
style.configure("TEntry", font=("Lobster", 12))
style.configure("TButton", font=("Lobster", 12), padding=6)

style.configure("TProgressbar", thickness=20)

# Left Frame for the Welcome Message
left_frame = tk.Frame(root, bg="#4C3BCF")
left_frame.place(relwidth=0.4, relheight=1)

# Right Frame for user input and controls
right_frame = tk.Frame(root, bg="white")
right_frame.place(relx=0.4, relwidth=0.6, relheight=1)

# Welcome Label
welcome_label = tk.Label(left_frame, text="Welcome to Book PDF Downloader", bg="#4C3BCF", fg="#F5EDED", font=("Times New Roman", 24, "bold"), justify=tk.LEFT, anchor="w")
welcome_label.pack(pady=20, padx=20)

# Info Label
info_text = ("Book PDF Downloader is a user-friendly application that simplifies the process\n\n"
             "of finding and downloading PDF versions of books. Just enter the name of the book\n\n"
             "you're looking for, and the app will search various online sources for PDF files.\n\n"
             "If a PDF is found, you can download it directly to your preferred location on your device.")

info_label = tk.Label(left_frame, text=info_text, bg="#4C3BCF", fg="#E2DAD6", font=("Helvetica ", 14), justify=tk.LEFT, wraplength=400, anchor="w")
info_label.pack(pady=10, padx=20)

# Right Frame for user input and controls
right_frame = tk.Frame(root, bg="white")
right_frame.place(relx=0.4, relwidth=0.6, relheight=1)

# Details Label
details_label = tk.Label(right_frame, text="Enter the details.", bg="white", fg="#4A4A4A", font=("Helvetica", 18))
details_label.pack(pady=20)

# Entry for Book Name
entry = ttk.Entry(right_frame, width=50)
entry.pack(pady=10)

# Search Button
search_button = ttk.Button(right_frame, text="Search and Download", command=search_book)
search_button.pack(pady=10)
search_button.configure(width=25)

# Cancel Button
cancel_button = ttk.Button(right_frame, text="Cancel Download", command=cancel_download)
cancel_button.pack(pady=10)
cancel_button.configure(width=25)

# Progress Bar
progress_bar = ttk.Progressbar(right_frame, orient='horizontal', length=400, mode='determinate')
progress_bar.pack(pady=10)

# Log Text Widget
log_text = tk.Text(right_frame, height=10, wrap=tk.WORD)
log_text.pack(pady=10, fill=tk.BOTH, expand=True)


# Run the application
root.mainloop()
