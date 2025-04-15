
# 🏥 Hospital Management System

A console-based Hospital Management System built using **C++** that allows efficient management of doctors, patients, rooms, beds, and insurance information. The system is designed to automate routine hospital administrative tasks and ensure optimal use of hospital resources.

---

## 📌 Features

- ✅ **User Authentication** – Secure login system using stored credentials.
- 👨‍⚕️ **Doctor Management** – Add and display doctors with specialization and ID.
- 👩‍⚕️ **Patient Management** – Register patients with details like disease, room type, and insurance status.
- 🛏 **Room and Bed Allocation** – Assign patients to private rooms or general ward beds with availability tracking.
- 🔄 **Doctor Assignment** – Link patients to specific doctors by ID.
- 💳 **Insurance Handling** – Track and process insurance claims for eligible patients.
- 💾 **Data Persistence** – All records are saved to text files for persistence between sessions.

---

## 🧱 System Architecture

- **Classes Used:**
  - `Person` – Base class for shared attributes (name, age, gender)
  - `Doctor` – Inherits `Person`, adds specialization and doctor ID
  - `Patient` – Inherits `Person`, includes disease, room type, insurance, doctor assignment
  - `Hospital` – Manages doctors, patients, room/bed allocation, and insurance workflows

---

## 📂 File Structure

```plaintext
├── main.cpp                # Main program logic
├── users.txt               # Stores user credentials
├── doctors.txt             # Stores doctor records
├── patients.txt            # Stores patient records
├── README.md               # Project description (this file)
```

---


