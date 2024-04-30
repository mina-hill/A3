//Name : Minahil Kashif
//Section: F
//ROll-no: 23i-0554
//Instructor: Marium Hida
//TA Name: Ariyan Chaudhary

#include <iostream>
#include <string>
#include "Header.h"
using namespace std;



//---------AlU---------
//defaut constructor
ALU::ALU()
{
	noOfAdders = 1; //64
	noOfSubtractor = 1; //64
	noOfRegisters = 8;  //8
	sizeOfRegisters = 64; //64
}
//parameterized constructor
ALU::ALU(int add, int sub, int reg, int regSize) : noOfAdders(add), noOfSubtractor(sub), noOfRegisters(reg), sizeOfRegisters(regSize)
{
	while(add<1 && add>16)
	{
		cout << "Invalid number of adders." << endl;
		cin >> add;
	}
	while (sub < 1 && sub>16)
	{
		cout << "Invalid number of subtractors." << endl;
		cin >> sub;
	}
	while (reg<8 && reg>64)
	{
		cout << "Invalid number of Registers." << endl;
		cin >> reg;
	}
	while (regSize < 1 && add>16)
	{
		cout << "Invalid number of adders." << endl;
		cin >> add;
	}
	int validSizes[] = { 8, 16, 32, 64, 128, 256 };
	bool validInput = false;
	while(!validInput)
	{
		if (regSize < 8 || regSize > 64) 
		{
			cout << "Invalid register size. Please enter a size between 8 and 64: ";
			cin >> regSize;
		}
		else
		{
			for (int i = 0; i < 6; i++)
			{
				if (regSize == validSizes[i])
				{
					validInput = 1;
					break;
				}
					
			}
			if (!validInput)
			{
				cout << "Invalid register size. Please choose from the valid sizes (8, 16, 32, 64, 128, 256): ";
				cin >> regSize;
			}
		}
		
	}
	noOfAdders = add;
	noOfSubtractor = sub;
	noOfRegisters = reg;
	sizeOfRegisters = regSize;
}
//setter and getters
void ALU::setNoOfAdders(int add)
{
	while (add < 1 && add>16)
	{
		cout << "Invalid number of adders." << endl;
		cin >> add;
	}
	noOfAdders = add;
}
int ALU::getNoOfAdders() const
{
	return noOfAdders;
}
void ALU::setNoOfSubtractor(int sub)
{
	while (sub < 1 && sub>16)
	{
		cout << "Invalid number of subtractors." << endl;
		cin >> sub;
	}
	noOfSubtractor = sub;
}
int ALU::getNoOfSubtractor() const
{
	return noOfSubtractor;
}
void ALU::setNoOfRegisters(int reg)
{
	while (reg < 8 && reg>64)
	{
		cout << "Invalid number of Registers." << endl;
		cin >> reg;
	}
	noOfRegisters = reg;
}
int ALU::getNoOfRegisters()const
{
	return noOfRegisters;
}
void ALU::setSizeOfRegisters(int regSize)
{
	int validSizes[] = { 8, 16, 32, 64, 128, 256 };
	bool validInput = false;
	while (!validInput)
	{
		if (regSize < 8 || regSize > 64)
		{
			cout << "Invalid register size. Please enter a size between 8 and 64: ";
			cin >> regSize;
		}
		else
		{
			for (int i = 0; i < 6; i++)
			{
				if (regSize == validSizes[i])
				{
					validInput = 1;
					break;
				}

			}
			if (!validInput)
			{
				cout << "Invalid register size. Please choose from the valid sizes (8, 16, 32, 64, 128, 256): ";
				cin >> regSize;
			}
		}

	}
	sizeOfRegisters = regSize;
}
int ALU::getSizeOfRegisters()const
{
	return sizeOfRegisters;
}
void ALU::displayALU()
{
	cout << "Number of Adders: " << noOfAdders << endl;
	cout << "Number of Subtractors: " << noOfSubtractor << endl;
	cout << "Number of Registers: " << noOfRegisters << endl;
	cout << "Size of Registers: " << sizeOfRegisters << endl;
}
// ---------CU---------
ControlUnit::ControlUnit()
{
	clock = 1;
}
//parameterized constructor
ControlUnit::ControlUnit(float clockNew)
{
	while (clockNew < 1 || clockNew>5)
	{
		cout << "Invalid inputs. Choose from 1-5" << endl;
		cin >> clockNew;
	}
	clock = clockNew;
}
//setter and getters
float ControlUnit::getClock() const
{
	return clock;
}
void ControlUnit::setClock(float clockNew)
{
	while (clockNew < 1 && clockNew>5)
	{
		cout << "Invalid inputs. Choose from 1-5" << endl;
		cin >> clockNew;
	}
	clock = clockNew;
}
void ControlUnit::displayControlUnit() 
{
	cout << "Clock: " << clock << endl;
}
// ---------CPU---------
//default constructor
CPU::CPU() : alu(), cu() {}
//parameterized constructors
CPU::CPU(ALU a, ControlUnit c) : alu(a), cu(c) {}
CPU::CPU(int add, int sub, int reg, int regSize, float clk)
{
	alu.setNoOfAdders(add);
	alu.setNoOfSubtractor(sub);
	alu.setNoOfRegisters(reg);
	alu.setSizeOfRegisters(regSize);

	cu.setClock(clk);
}
ALU CPU::getALU() const
{
	return alu;
}
ControlUnit CPU::getCU() const
{
	return cu;
}
void CPU::setALU(const ALU a)
{
	alu = a;
}
void CPU::setALU(int add, int sub, int reg, int regSize)
{
	alu.setNoOfAdders(add);
	alu.setNoOfSubtractor(sub);
	alu.setNoOfRegisters(reg);
	alu.setSizeOfRegisters(regSize);
}
void CPU::setCU(const ControlUnit c)
{
	cu = c;
}
void CPU::setCU(float clockNew)
{
	cu.setClock(clockNew);
}
void CPU::displayCPU()
{
	cout << "ALU Details:" << endl;
	alu.displayALU();
	cout << "Control Unit Details:" << endl;
	cu.displayControlUnit();
}

// ---------MainMemory---------
MainMemory::MainMemory() : capacity(8),technologyType("SemiConductor"), comp("PC"){}
MainMemory::MainMemory(int newCapacity, string techType, ComputerType compNew)
{
	comp = compNew;
	if (comp.type == "PC")
	{
		//capacity: 4 GB to 64 GB
		int validSizes[] = {4, 8, 16, 32, 64};
		bool validInput = false;
		while (!validInput)
		{
			if (newCapacity < 4 || newCapacity > 64)
			{
				cout << "Invalid Capacity of Main Memory. Please enter a size between 4 and 64: ";
				cin >> newCapacity;
			}
			else
			{
				for (int i = 0; i < 5; i++)
				{
					if (newCapacity == validSizes[i])
					{
						validInput = 1;
						break;
					}

				}
				if (!validInput)
				{
					cout << "Invalid register size. Please choose from the valid sizes (8, 16, 32, 64, 128, 256): ";
					cin >> newCapacity;
				}
			}

		}
		capacity = newCapacity;
		//technologyType : "Semiconductor" or "Silicon"
		while (techType != "Semiconductor" && techType != "Silicon")
		{
			cout << "Invalid technology type. Enter from 'Semiconductor'' or 'Silicon'";
			cin >> techType;
		}
		technologyType = techType;

	}
	else if(comp.type == "Mac")
	{
		//capacity: 8 GB to 64 GB
		int validSizes[] = {8, 16, 32, 64 };
		bool validInput = false;
		while (!validInput)
		{
			if (newCapacity < 8 || newCapacity > 64)
			{
				cout << "Invalid Capacity of Main Memory. Please enter a size between 8 and 64: ";
				cin >> newCapacity;
			}
			else
			{
				for (int i = 0; i < 4; i++)
				{
					if (newCapacity == validSizes[i])
					{
						validInput = 1;
						break;
					}

				}
				if (!validInput)
				{
					cout << "Invalid register size. Please choose from the valid sizes (8, 16, 32, 64): ";
					cin >> newCapacity;
				}
			}

		}
		capacity = newCapacity;
		//technologyType : "Silicon"
		while (techType != "Semiconductor")
		{
			cout << "Invalid technology type. Enter from 'Silicon'";
			cin >> techType;
		}
		technologyType = techType;
	}
	capacity = newCapacity;
}
int MainMemory::getCapacity() const
{
	return capacity;
}
void MainMemory::setCapacity(const int newCapacity)
{
	capacity = newCapacity;
}
string MainMemory::getTechType() const
{
	return technologyType;
}
void MainMemory::setTechType(const string tech)
{
	technologyType = tech;
}
void MainMemory::displayMainMemory() 
{
	cout << "Capacity: " << capacity << " GB" << endl;
	cout << "Technology Type: " << technologyType << endl;
}

//---------Port---------
Port::Port()
{
	type = "null";
	baud_rate = 0;
}
Port::Port(string newType, int rate, ComputerType compNew)
{
	comp = compNew;
	string portTypes[6] = {"USB","HDMI","Ethernet","VGI","Display", "I/O"};
	bool valid = false;
	while (!valid)
	{
		for (int i = 0; i < 6; i++)
		{
			if (newType == portTypes[i])
			{
				valid = true;
				type = newType;
			}
		}
		if (!valid)
		{
			cout << "Invalid Port entry. Choose from {'USB','HDMI','Ethernet','VGI', 'Display', 'I / O' }" << endl;
			cin >> newType;
		}
	}
	while (rate < 4800 || rate >115200)//4800 to 115200
	{
		cout << "Invalid Baud rate. Input from 4800 to 115200";
		cin >> rate;
	}
	 //VGI Port,I/O Port,USB Port,HDMI Port
	baud_rate = rate;

}
string Port::getType()const
{
	return type;
}
int Port::getRate()const
{
	return baud_rate;
}
void Port::setType(const string newType)
{
	type = newType;
}
void Port::setRate(const int newRate)
{
	baud_rate = newRate;
}
void Port::displayPort() 
{
	cout << "Type: " << type << endl;
	cout << "Baud Rate: " << baud_rate << endl;
}
//---------MotherBoard---------
MotherBoard::MotherBoard(int mmCapacity, string mmTechType,ComputerType compType, string port1Type, int port1Rate,
	string port2Type, int port2Rate,string port3Type,int port3Rate, string port4Type, 
	int port4Rate,string port5Type, int port5Rate) : mm(mmCapacity, mmTechType, compType)
{
	ports[0].setType(port1Type);
	ports[0].setRate(port1Rate);

	ports[1].setType(port2Type);
	ports[1].setRate(port2Rate);

	ports[2].setType(port3Type);
	ports[2].setRate(port3Rate);

	ports[3].setType(port4Type);
	ports[3].setRate(port4Rate);

	ports[4].setType(port5Type);
	ports[4].setRate(port5Rate);
	comp = compType;
	
}
void MotherBoard::addPort(const string& type, int rate)
{
	int i = 0;
	for (; i < 5; i++)
	{
		if (ports[i].getType() == "null")
		{
			ports[i] = Port(type, rate,comp);
			break;
		}
	}
	if(i==5)
	{
		cout << "No more space to add ports!" << endl;
	}
}
void MotherBoard::setMainMemory(const  MainMemory &newMM)
{
	mm = newMM;
}
const Port* MotherBoard::getPorts()const
{
	return ports;
}
MainMemory MotherBoard::getMainMemory() const
{
	return mm;
}
void MotherBoard::displayMotherBoard() 
{
	cout << "Ports:" << endl;
	for (int i = 0; i < 5; ++i) {
		cout << "Port " << i + 1 << ":" << endl;
		ports[i].displayPort();
	}
	cout << "Main Memory Details:" << endl;
	mm.displayMainMemory();
}

//---------PhysicalMemory---------
PhysicalMemory::PhysicalMemory()
{
	capacity = 8;
}
PhysicalMemory::PhysicalMemory(int cap)
{
	int validSizes[] = { 8, 16, 32};
	bool validInput = false;
	while (!validInput)
	{
		if (cap < 8 || cap > 32)
		{
			cout << "Invalid capacity size. Please enter a size between 8 and 32: ";
			cin >> cap;
		}
		else
		{
			for (int i = 0; i < 3; i++)
			{
				if (cap == validSizes[i])
				{
					validInput = 1;
					break;
				}

			}
			if (!validInput)
			{
				cout << "Invalid capacity size. Please choose from the valid sizes (8, 16, 32): ";
				cin >> cap;
			}
		}

	}

	capacity = cap;
}
void PhysicalMemory::setCapacity(int cap)
{
	capacity = cap;
}
int PhysicalMemory::getCapacity()const
{
	return capacity;
}
void PhysicalMemory::displayPhysicalMemory() 
{
	cout << "Capacity: " << capacity << " GB" << endl;
}
//---------Computer---------
void Computer::setPM(const PhysicalMemory& pmNew)
{
	pm = pmNew;
}
void Computer::setCPU(const CPU& cpuNew)
{
	cpu = cpuNew;
}
void Computer::setMB(const MotherBoard& mbNew)
{
	mb = mbNew;
}
const PhysicalMemory& Computer::getPM() const
{
	return pm;
}
const CPU& Computer::getCPU()const
{
	return cpu;
}
const MotherBoard& Computer::getMB()const
{
	return mb;
}
void Computer::displayComputer() 
{
	cout << "Physical Memory Details:" << endl;
	pm.displayPhysicalMemory();
	cout << "CPU Details:" << endl;
	cpu.displayCPU();
	cout << "Motherboard Details:" << endl;
	mb.displayMotherBoard();
}
//---------GraphicCard---------
string GraphicsCard::getBrand() const
{
	return brand;
}
int GraphicsCard::getMemory()const
{
	return memorySize;
}
double GraphicsCard::getPrice()const
{
	return price;
}
void GraphicsCard::setBrand(string name)
{
	brand = name;
}
void GraphicsCard::setMemory(int size)
{
	memorySize = size;
}
void GraphicsCard::setPrice(double money)
{
	price = money;
}
void GraphicsCard::displayGraphicsCard() 
{
	cout << "Brand: " << brand << endl;
	cout << "Memory Size: " << memorySize << " GB" << endl;
	cout << "Price: $" << price << endl;
}
//---------StorageDevice---------
string StorageDevice::getType() const
{
	return type;
}
int StorageDevice::getCapacity()const
{
	return capacity;
}
double StorageDevice::getPrice()const
{
	return price;
}
void StorageDevice::setType(string newType)
{
	type = newType;
}
void StorageDevice::setCapacity(int cap)
{
	capacity = cap;
}
void StorageDevice::setPrice(double money)
{
	price = money;
}
void StorageDevice::displayStorageDevice() 
{
	cout << "Type: " << type << endl;
	cout << "Capacity: " << capacity << " GB" << endl;
	cout << "Price: $" << price << endl;
}

//---------NetworkCard---------
string NetworkCard::getType()const
{
	return type;
}
int NetworkCard::getSpeed()const
{
	return speed;
}
double NetworkCard::getPrice() const
{
	return price;
}
void NetworkCard::setType(string newType)
{
	type = newType;
}
void NetworkCard::setSpeed(int newSpeed)
{
	speed = newSpeed;
}
void NetworkCard::setPrice(int money)
{
	price = money;
}
void NetworkCard::displayNetworkCard()
{
	cout << "Type: " << type << endl;
	cout << "Speed: " << speed << " Mbps" << endl;
	cout << "Price: $" << price << endl;
}
//---------PowerSupply------
int PowerSupply::getWattage()const
{
	return wattage;
}
string PowerSupply::getRate()const
{
	return efficiencyRating;
}
double PowerSupply::getPrice()const
{
	return price;
}
void PowerSupply::setWattage(int watt)
{
	wattage = watt;
}
void PowerSupply::setRate(string rate)
{
	efficiencyRating = rate;
}
void PowerSupply::setPrice(double money)
{
	price = money;
}
void PowerSupply::displayPowerSupply() 
{
	cout << "Wattage: " << wattage << " W" << endl;
	cout << "Efficiency Rating: " << efficiencyRating << endl;
	cout << "Price: $" << price << endl;
}
//---------Battery---------
int Battery::getCapacity() const
{ 
	return capacity; 
}
void Battery::setCapacity(int cap)
{
	capacity = cap; 
}
void Battery::displayBattery() 
{
	cout << "Capacity: " << capacity << " mAh" << endl;
}
//--------Case-----------
const string& Case::getFormFactor() const 
{
	return formFactor; 
}
void Case::setFormFactor(const string& form) 
{
	formFactor = form; 
}
const string& Case::getColor() const
{
	return color; 
}
void Case::setColor(const string& col) 
{
	color = col; 
}
double Case::getPrice() const 
{
	return price; 
}
void Case::setPrice(double pr) 
{
	price = pr; 
}
void Case::displayCase()
{
	cout << "Form Factor: " << formFactor << endl;
	cout << "Color: " << color << endl;
	cout << "Price: $" << price << endl;
}
//---------ComputerAssembly--------
const Computer& ComputerAssembly::getComputer() const
{
	return computer; 
}
const PhysicalMemory& ComputerAssembly::getPhysicalMemory() const 
{
	return computer.getPM();
}
const CPU& ComputerAssembly::getCPU() const 
{
	return computer.getCPU();
}
const MotherBoard& ComputerAssembly::getMotherBoard() const 
{
	return computer.getMB();
}
const GraphicsCard& ComputerAssembly::getGraphicsCard() const 
{
	return graphicsCard;
}
const StorageDevice& ComputerAssembly::getStorageDevice() const 
{
	return storageDevice;
}
const NetworkCard& ComputerAssembly::getNetworkCard() const 
{
	return networkCard;
}
const PowerSupply& ComputerAssembly::getPowerSupply() const 
{
	return powerSupply;
}
const Battery& ComputerAssembly::getBattery() const 
{
	return battery;
}
const Case& ComputerAssembly::getComputerCase() const 
{
	return computerCase;
}
void ComputerAssembly::displayComputerAssembly() 
{
	cout << "Computer Details:" << endl;
	computer.displayComputer();
	cout << "Graphics Card Details:" << endl;
	graphicsCard.displayGraphicsCard();
	cout << "Storage Device Details:" << endl;
	storageDevice.displayStorageDevice();
	cout << "Network Card Details:" << endl;
	networkCard.displayNetworkCard();
	cout << "Power Supply Details:" << endl;
	powerSupply.displayPowerSupply();
	cout << "Battery Details:" << endl;
	battery.displayBattery();
	cout << "Computer Case Details:" << endl;
	computerCase.displayCase();
}