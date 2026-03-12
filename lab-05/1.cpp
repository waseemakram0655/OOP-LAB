#include <iostream>
#include <string>

using namespace std;

class MedicationEntry {
public:
    string drugName;
    string dose;
    string timeGiven;

    MedicationEntry(string drug, string d, string t) 
        : drugName(drug), dose(d), timeGiven(t) {}
};

class VitalSignsCheck {
public:
    double temperature;
    int heartRate;
    string timeChecked;

    VitalSignsCheck(double temp, int hr, string t) 
        : temperature(temp), heartRate(hr), timeChecked(t) {}
};

class DiagnosisNote {
public:
    string noteText;
    string doctorName;
    string date;

    DiagnosisNote(string text, string doc, string d) 
        : noteText(text), doctorName(doc), date(d) {}
};

class PatientRecord {
private:
    int patientId;
    string name;
    string dob;

    MedicationEntry* medication;
    VitalSignsCheck* vitals;
    DiagnosisNote* diagnosis;

public:
    PatientRecord(int id, string n, string d) : patientId(id), name(n), dob(d) {
        medication = new MedicationEntry("Amoxicillin", "500mg", "08:00 AM");
        vitals = new VitalSignsCheck(98.6, 72, "09:30 AM");
        diagnosis = new DiagnosisNote("Bacterial Infection", "Dr. Wilson", "2026-03-12");
        cout << "[System] Record and medical entries created for " << name << endl;
    }

    ~PatientRecord() {
        delete medication;
        delete vitals;
        delete diagnosis;
        cout << "[System] Record and all medical entries for " << name << " have been deleted." << endl;
    }

    void displayRecord() {
        cout << "\n========== PATIENT RECORD ==========" << endl;
        cout << "ID: " << patientId << " | Name: " << name << " | DOB: " << dob << endl;
        cout << "------------------------------------" << endl;
        cout << "Medication: " << medication->drugName << " (" << medication->dose << ") at " << medication->timeGiven << endl;
        cout << "Vitals: Temp " << vitals->temperature << "F, HR " << vitals->heartRate << " bpm at " << vitals->timeChecked << endl;
        cout << "Diagnosis: " << diagnosis->noteText << " (by " << diagnosis->doctorName << " on " << diagnosis->date << ")" << endl;
        cout << "====================================\n" << endl;
    }
};

int main() {
    PatientRecord* lilyRecord = new PatientRecord(101, "Lily Smith", "1995-05-15");
    
    lilyRecord->displayRecord();

    delete lilyRecord; 

    return 0;
}