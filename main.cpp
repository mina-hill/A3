//Name : Minahil Kashif
//Section: F
//ROll-no: 23i-0554
//Instructor: Marium Hida
//TA Name: Ariyan Chaudhary

#include <iostream>
#include <string>
#include "Header.h"
using namespace std;

int main()
{
    // Variables to store user inputs
    int adders, subtractors, registers, registerSize, mmCapacity, portRate, pmCapacity;
    float clock;
    string mmTechType, portType, brand, storageType, networkType, efficiencyRating, formFactor, color;
    string CompType;

    cout << "Enter the type of Computer. PC or Mac";
    cin >> CompType;
    ComputerType comp(CompType);
    //ALU
    cout << "Enter number of adders: ";
    cin >> adders;
    cout << "Enter number of subtractors: ";
    cin >> subtractors;
    cout << "Enter number of registers: ";
    cin >> registers;
    cout << "Enter size of registers: ";
    cin >> registerSize;

    //ALU
    ALU alu(adders, subtractors, registers, registerSize);

    //Control Unit
    cout << "Enter clock speed for Control Unit: ";
    cin >> clock;

    //ControlUnit
    ControlUnit cu(clock);

    //CPU
    CPU cpu(alu, cu);

    //Main Memory
    cout << "Enter capacity of Main Memory: ";
    cin >> mmCapacity;
    cout << "Enter technology type of Main Memory (e.g., Semiconductor, Silicon): ";
    cin >> mmTechType;

    //MainMemory
    MainMemory mm(mmCapacity, mmTechType,CompType);

    //MotherBoard
    MotherBoard mb;

    //Ports
    for (int i = 0; i < 5; ++i) {
        cout << "Enter type of Port " << (i + 1) << ": ";
        cin >> portType;
        cout << "Enter baud rate of Port " << (i + 1) << ": ";
        cin >> portRate;
        mb.addPort(portType, portRate);
    }

    //Physical Memory
    cout << "Enter capacity of Physical Memory: ";
    cin >> pmCapacity;

    PhysicalMemory pm(pmCapacity);

    //GraphicsCard
    cout << "Enter brand of Graphics Card: ";
    cin >> brand;
    int memorySize;
    cout << "Enter memory size of Graphics Card: ";
    cin >> memorySize;
    double price;
    cout << "Enter price of Graphics Card: ";
    cin >> price;
    GraphicsCard gc(brand, memorySize, price);

    //Storage Device
    cout << "Enter type of Storage Device (e.g., HDD, SSD): ";
    cin >> storageType;
    int capacity;
    cout << "Enter capacity of Storage Device: ";
    cin >> capacity;
    cout << "Enter price of Storage Device: ";
    cin >> price;
    StorageDevice sd(storageType, capacity, price);

    //Network Card
    cout << "Enter type of Network Card: ";
    cin >> networkType;
    int speed;
    cout << "Enter speed of Network Card: ";
    cin >> speed;
    cout << "Enter price of Network Card: ";
    cin >> price;
    NetworkCard nc(networkType, speed, price);

    //Power Supply
    int wattage;
    cout << "Enter wattage of Power Supply: ";
    cin >> wattage;
    cout << "Enter efficiency rating of Power Supply: ";
    cin >> efficiencyRating;
    cout << "Enter price of Power Supply: ";
    cin >> price;
    PowerSupply ps(wattage, efficiencyRating, price);

    //Battery
    int batteryCapacity;
    cout << "Enter capacity of Battery: ";
    cin >> batteryCapacity;
    Battery bat(batteryCapacity);

    //Case
    cout << "Enter form factor of Case: ";
    cin >> formFactor;
    cout << "Enter color of Case: ";
    cin >> color;
    cout << "Enter price of Case: ";
    cin >> price;
    Case compCase(formFactor, color, price);

    // Creating ComputerAssembly object with all components
    ComputerAssembly assembly(pm, cpu, mb, gc, sd, nc, ps, bat, compCase);

    cout << "Displaying details." << endl;
    assembly.displayComputerAssembly();

    return 0;
}
