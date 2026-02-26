#include <iostream>
#include <string>
using namespace std;

class MedicationEntry
{
public:
    string drugName;
    string dose;
    string timeGiven;

    MedicationEntry(string drug, string d, string t)
        : drugName(drug), dose(d), timeGiven(t) {}
};

class VitalSignsCheck
{
public:
    double temperature;
    int heartRate;
    string timeChecked;

    VitalSignsCheck(double temp, int hr, string t)
        : temperature(temp), heartRate(hr), timeChecked(t) {}
};

class DiagnosisNote
{
public:
    string noteText;
    string doctorName;
    string date;

    DiagnosisNote(string text, string doc, string d)
        : noteText(text), doctorName(doc), date(d) {}
};


class PatientRecord
{
private:
    int patientId;
    string name;
    string dob;

    MedicationEntry *medication;
    VitalSignsCheck *vitals;
    DiagnosisNote *diagnosis;

public:
    PatientRecord(int id, string n, string d) : patientId(id), name(n), dob(d)
    {
        medication = new MedicationEntry("Amoxicillin", "500mg", "08:00 AM");
        vitals = new VitalSignsCheck(37.2, 75, "08:15 AM");
        diagnosis = new DiagnosisNote("Bacterial Infection", "Dr. House", "2026-02-26");

        cout << "Record for " << name << " created.\n";
    }

    ~PatientRecord()
    {
        delete medication;
        delete vitals;
        delete diagnosis;
        cout << "Record for " << name << " and all associated entries deleted.\n";
    }

    void displayRecord()
    {
        cout << "Patient Record: " << name << " (ID: " << patientId << ")\n";
        cout << "DOB: " << dob << "\n\n";

        cout << "Medication: " << medication->drugName << " (" << medication->dose << ") at " << medication->timeGiven << "\n";
        cout << "Vitals: Temp: " << vitals->temperature << "C, HR: " << vitals->heartRate << " bpm\n";
        cout << "Diagnosis: " << diagnosis->noteText << " (By " << diagnosis->doctorName << ")\n";
    }
};

int main()
{
    PatientRecord *lilyRecord = new PatientRecord(101, "Lily Smith", "1995-05-12");

    lilyRecord->displayRecord();

    delete lilyRecord;

    return 0;
}