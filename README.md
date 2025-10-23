## 🏥 Hospital Management System

A simple **console-based hospital system** built in **C++** that manages patients across different specializations.  
It allows adding new patients, viewing all patients, and assigning the next patient to a doctor — based on urgency.

---

## ⚙️ Features Overview

1. **Add New Patient**
   - User inputs:
     - 🩺 **Specialization number**
     - 🧍 **Patient name**
     - 🚨 **Status (0 = Regular, 1 = Urgent)**
   - Urgent patients are inserted **at the front** of their specialization queue.
   - Regular patients are added **at the end**.
   - Each specialization can handle **up to 5 patients**.

2. **Print All Patients**
   - Displays all specializations that currently have patients.
   - Lists each patient with:
     - Their **name**
     - Their **status** → `URGENT` or `REGULAR`
   - Shows how many patients are in each specialization.

3. **Get Next Patient**
   - Prompts the user to enter a specialization.
   - The **first** patient in that specialization (urgent first) is sent to the doctor.
   - The patient is then **removed** from the queue.
   - If no patients exist, it shows:
     > “No patients at the time. Have some rest, doctor.”

4. **Exit**
   - Ends the program safely.

---

## 🧠 Program Flow

1. The user is shown a menu:
  1. Add new patient
  2. Print all patients
  3. Get next patient
  4. Exit

2. Based on the chosen option, the corresponding function is called:
- `addPatient()`
- `printAllPatients()`
- `getNextPatient()`


---

## 🧩 Technical Details

- **Language:** C++
- **Data Structures Used:**
  - `std::vector<int>` → Stores specialization numbers
  - `std::vector<bool>` → Stores patient status (urgent or regular)
  - `std::vector<string>` → Stores patient names
- **Core Functions:**
  - `addPatient()` – Adds a patient to the system
  - `printAllPatients()` – Displays all patients grouped by specialization
  - `getNextPatient()` – Retrieves and removes the next patient
  - `patientsNumberInSpecialization()` – Counts patients per specialization

---

## 📜 Notes

- Each specialization can hold **a maximum of 5 patients**.  
  If full, the system displays:  
  > “Sorry, we are FULL.”
- Urgent patients are always prioritized.


