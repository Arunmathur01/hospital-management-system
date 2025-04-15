#include <iostream>
#include <fstream>  // For file handling
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Base class for a person (used by both patients and doctors)
class Person {
protected:
    string name;
    int age;
    string gender;

public:
    Person(string n, int a, string g) : name(n), age(a), gender(g) {}

    // Display basic information
    void displayPersonInfo() const {
        cout << "Name: " << name << "\nAge: " << age << "\nGender: " << gender << endl;
    }
};

// Class for managing doctor information
class Doctor : public Person {
private:
    string specialization;
    int doctorID;

public:
    Doctor(string n, int a, string g, string spec, int id) 
        : Person(n, a, g), specialization(spec), doctorID(id) {}

    void displayDoctorInfo() const {
        cout << "\nDoctor Information:\n";
        displayPersonInfo();
        cout << "Specialization: " << specialization << "\nDoctor ID: " << doctorID << endl;
    }

    int getDoctorID() const {
        return doctorID;
    }

    string getDoctorData() const {
        return name + " " + to_string(age) + " " + gender + " " + specialization + " " + to_string(doctorID);
    }
};

// Class for managing patient information
class Patient : public Person {
private:
    int patientID;
    string disease;
    int doctorAssigned;

public:
    Patient(string n, int a, string g, int id, string dis) 
        : Person(n, a, g), patientID(id), disease(dis), doctorAssigned(-1) {}

    void displayPatientInfo() const {
        cout << "\nPatient Information:\n";
        displayPersonInfo();
        cout << "Patient ID: " << patientID << "\nDisease: " << disease << "\nDoctor Assigned: " 
             << (doctorAssigned == -1 ? "None" : to_string(doctorAssigned)) << endl;
    }

    int getPatientID() const {
        return patientID;
    }

    void assignDoctor(int docID) {
        doctorAssigned = docID;
        cout << "Doctor with ID " << docID << " assigned to Patient " << patientID << endl;
    }

    string getPatientData() const {
        return name + " " + to_string(age) + " " + gender + " " + to_string(patientID) + " " + disease;
    }
};

// Hospital class that manages doctors and patients, and handles file operations
class Hospital {
private:
    vector<Doctor> doctors;
    vector<Patient> patients;

    // Helper function to write data to a file
    void writeDataToFile(const string& filename, const vector<string>& data) {
        ofstream outFile(filename);
        if (outFile.is_open()) {
            for (const string& line : data) {
                outFile << line << endl;
            }
            outFile.close();
            cout << filename << " saved successfully.\n";
        } else {
            cerr << "Error: Could not open " << filename << " for writing!\n";
        }
    }

public:
    // Add a new doctor
    void addDoctor() {
        string name, gender, specialization;
        int age, id;

        cout << "Enter Doctor's Name: "; cin >> name;
        cout << "Enter Doctor's Age: "; cin >> age;
        cout << "Enter Doctor's Gender: "; cin >> gender;
        cout << "Enter Doctor's Specialization: "; cin >> specialization;
        cout << "Enter Doctor ID: "; cin >> id;

        doctors.emplace_back(name, age, gender, specialization, id);
        cout << "Doctor added successfully!\n";
        saveDoctorsToFile();
    }

    // Add a new patient
    void addPatient() {
        string name, gender, disease;
        int age, id;

        cout << "Enter Patient's Name: "; cin >> name;
        cout << "Enter Patient's Age: "; cin >> age;
        cout << "Enter Patient's Gender: "; cin >> gender;
        cout << "Enter Patient's Disease: "; cin >> disease;
        cout << "Enter Patient ID: "; cin >> id;

        patients.emplace_back(name, age, gender, id, disease);
        cout << "Patient added successfully!\n";
        savePatientsToFile();
    }

    // Display all patients
    void displayPatients() const {
        for (const auto& patient : patients) {
            patient.displayPatientInfo();
        }
    }

    // Display all doctors
    void displayDoctors() const {
        for (const auto& doctor : doctors) {
            doctor.displayDoctorInfo();
        }
    }

    // Discharge a patient
    void dischargePatient() {
        int id;
        cout << "Enter Patient ID to discharge: "; cin >> id;

        auto it = find_if(patients.begin(), patients.end(),
                          [id](const Patient& p) { return p.getPatientID() == id; });

        if (it != patients.end()) {
            patients.erase(it);
            cout << "Patient with ID " << id << " has been discharged.\n";
            savePatientsToFile();
        } else {
            cout << "Patient not found!\n";
        }
    }

    // Save patient data to file
    void savePatientsToFile() {
        vector<string> data;
        for (const auto& patient : patients) {
            data.push_back(patient.getPatientData());
        }
        writeDataToFile("patients.txt", data);
    }

    // Save doctor data to file
    void saveDoctorsToFile() {
        vector<string> data;
        for (const auto& doctor : doctors) {
            data.push_back(doctor.getDoctorData());
        }
        writeDataToFile("doctors.txt", data);
    }
};

// Main function to run the hospital management system
int main() {
    Hospital hospital;
    int choice;

    do {
        cout << "\n--- Hospital Management System Menu ---\n";
        cout << "1. Add Doctor\n";
        cout << "2. Add Patient\n";
        cout << "3. Display All Patients\n";
        cout << "4. Display All Doctors\n";
        cout << "5. Discharge Patient\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                hospital.addDoctor();
                break;
            case 2:
                hospital.addPatient();
                break;
            case 3:
                hospital.displayPatients();
                break;
            case 4:
                hospital.displayDoctors();
                break;
            case 5:
                hospital.dischargePatient();
                break;
            case 6:
                cout << "Exiting the system...\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 6);

    return 0;
}
