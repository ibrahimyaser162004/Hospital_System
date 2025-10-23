#include <iostream>
#include <vector>
using namespace std;

struct patientData{
    int specilalization;
    bool status;
    string name;
};

int patientsNumberInSpecialization(const vector<int>& specialization, int currentSpecialization){
    int patientNumber=0;
    for (int i = 0; i < (int)specialization.size(); i++) {
        if (specialization[i] == currentSpecialization) patientNumber++;
    }
    return patientNumber;
}

#1
void addPatient(vector <int> &specialization, vector <bool> &status, vector <string> &patients){
    patientData currentPatientData;
    cout << "Enter Specialization, name, status: ";
    cin >> currentPatientData.specilalization >> currentPatientData.name >> currentPatientData.status;
    if (patientsNumberInSpecialization(specialization, currentPatientData.specilalization) == 5){
        cout << endl << "Sorry, we are FULL" << endl;
        return;
    }
    
    if (currentPatientData.status == 0) {
        specialization.push_back(currentPatientData.specilalization);
        status.push_back(currentPatientData.status);
        patients.push_back(currentPatientData.name);
    } else {
        specialization.insert(specialization.begin(),currentPatientData.specilalization);
        status.insert(status.begin(),currentPatientData.status);
        patients.insert(patients.begin(),currentPatientData.name);
    }
}


#2 
void printAllPatients(vector <int> &specialization, vector <bool> &status, vector <string> &patients){
    for(int i = 0; i < 20; i++) {
        if (patientsNumberInSpecialization(specialization, i+1) > 0){
            cout << "\n___________________________________\n";
            cout << "\nThere are " << patientsNumberInSpecialization(specialization, i+1) << " in Specialization " << i+1 << endl;
            for (int j = 0; j < int(patients.size()); j++) {
                if (specialization[j] == i+1) {
                    cout << patients[j];
                    cout << (status[j] == 1? " --> URGENT": " --> REGULAR") << endl;
                }
            }
        }
    }
    cout << "\n___________________________________\n";

}

void getNextPatient(vector <int> &specialization, vector <bool> &status, vector <string> &patients){
    int specializationChosen;
    cout << "Enter Specialization: ";
    cin >> specializationChosen;
    for (int i = 0; i < (int) specialization.size(); i++){
        if (specialization[i] == specializationChosen) {
            cout << patients[i] << ", please, go with the doctor." << endl;
            specialization.erase(specialization.begin()+i);
            patients.erase(patients.begin()+i);
            status.erase(status.begin()+i);
            return;
        }
    }
    cout << "No patients at the time. Have some rest, doctor." << endl;
}

void printUserInterface(){
    cout << endl<< "Enter your choice:" << endl;
    cout << "1) Add new patients" << endl;
    cout << "2) Print all patients" << endl;
    cout << "3) Get next patient" << endl;
    cout << "4) Exit" << endl;
}

int main(){
    int output = 0;
    vector <int> specialization;
    vector <bool> status;
    vector <string> patients; 
    do {
        printUserInterface();
        cin >> output;
        switch (output){
            case 1: 
                addPatient(specialization, status, patients);
                break;
            case 2: 
                printAllPatients(specialization, status, patients);
                break;
            case 3: 
                getNextPatient(specialization, status, patients);
                break;
            case 4:
                return 0;
        }
    } while(true);
}