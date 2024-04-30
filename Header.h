//Name : Minahil Kashif
//Section: F
//ROll-no: 23i-0554
//Instructor: Marium Hida
//TA Name: Ariyan Chaudhary

#ifndef _Header_H_
#define _Header_H_

#include <iostream>
#include <string>
using namespace std;

class ComputerType {
public:
	string type;
	ComputerType(string typeNew = "PC")
	{
		while (typeNew != "PC" && typeNew != "Mac")
		{
			cout << "Invalid type" << endl;
			cin >> typeNew;
		}
		type = typeNew;
	}
	void operator=(const string in)
	{
		type = in;
	}
};
// ---ALU---
class ALU {
private:
	//declaring data members
	int noOfAdders;
	int noOfSubtractor;
	int noOfRegisters;
	int sizeOfRegisters;
public:
	//defaut constructor
	ALU();
	//parameterized constructor
	ALU(int add, int sub, int reg, int regSize);
	//setter and getters
	void setNoOfAdders(const int theAdders);
	int getNoOfAdders() const;
	void setNoOfSubtractor(const int theSubtractors);
	int getNoOfSubtractor() const;
	void setNoOfRegisters(const int theRegisters);
	int getNoOfRegisters()const;
	void setSizeOfRegisters(const int theSize);
	int getSizeOfRegisters()const;
	void displayALU();
};
// ---CU---
class ControlUnit {
private:
	float clock;
public:
	//default constructor
	ControlUnit();
	//parameterized constructor
	ControlUnit(float clockNew);
	//setter and getters
	float getClock() const;
	void setClock(const float clockNew);
	void displayControlUnit();
};
// ----CPU---
class CPU {
private:
	ALU alu;
	ControlUnit cu;
public:
	//default constructor
	CPU();
	//parameterized constructors
	CPU(ALU a, ControlUnit c);
	CPU(int add, int sub, int reg, int regSize, float clk);
	ALU getALU() const;
	ControlUnit getCU() const;
	void setALU(const ALU a);
	void setALU(int add, int sub, int reg, int regSize);
	void setCU(const ControlUnit c);
	void setCU(float clockNew);
	void displayCPU();
};
// ---MainMemory---
class MainMemory {
private:
	int capacity;
	string technologyType; //Possible values : Semiconductor, Silicon
	ComputerType comp;
public:
	MainMemory();
	MainMemory(int newCapacity, string techType, ComputerType comp);
	int getCapacity() const;
	void setCapacity(const int newCapacity);
	string getTechType() const;
	void setTechType(const string tech);
	void displayMainMemory();
};
//---Port---
class Port {
private:
	string type;
	int baud_rate;
	ComputerType comp;
public:
	Port();
	Port(string newType, int rate,ComputerType comp);
	string getType()const;
	int getRate()const;
	void setType(const string newType);
	void setRate(const int newRate);
	void displayPort();
};
class MotherBoard {
private:
	Port ports[5];
	MainMemory mm;
	ComputerType comp;
public:
	MotherBoard(int mmCapacity = 16, string mmTechType = "Semiconductor", ComputerType compType = ComputerType("PC"),
		string port1Type = "null", int port1Rate = 0, string port2Type = "null", int port2Rate = 0,
		string port3Type = "null", int port3Rate = 0, string port4Type = "null", int port4Rate = 0,
		string port5Type = "null", int port5Rate = 0);
	void addPort(const string& type, int rate);
	void setMainMemory(const  MainMemory &newMM);
	const Port* getPorts()const;
	MainMemory getMainMemory() const;
	void displayMotherBoard();
};

class PhysicalMemory {
private:
	int capacity;
public:
	PhysicalMemory();
	PhysicalMemory(int capacity);
	void setCapacity(int cap);
	int getCapacity()const;
	void displayPhysicalMemory();
};
class Computer {
private:
	PhysicalMemory pm;
	CPU cpu;
	MotherBoard mb;
public:
	Computer(const PhysicalMemory& pmNew, const CPU& cpuNew, const MotherBoard& mbNew) : pm(pmNew), cpu(cpuNew), mb(mbNew) {}
	void setPM(const PhysicalMemory& pmNew);
	void setCPU(const CPU& cpuNew);
	void setMB(const MotherBoard& mbNew);
	const PhysicalMemory& getPM() const;
	const CPU& getCPU()const;
	const MotherBoard& getMB()const;
	void displayComputer();
};
class GraphicsCard {
private:
	string brand;
	int memorySize;
	double price;
	ComputerType comp;
public:
	GraphicsCard(string name = "Nvidia", int size = 2, double money = 100, ComputerType compType = ComputerType("PC"))
		:brand(name), memorySize(size), price(money), comp(compType)
	{
		if (comp.type == "PC")
		{
			int validSizes[] = { 2,4,8 };
			bool validInput = false;
			while (!validInput)
			{
				if (size < 2 || size > 8)
				{
					cout << "Invalid graphic size. Please enter a size between 2 and 8: ";
					cin >> size;
				}
				else
				{
					for (int i = 0; i < 3; i++)
					{
						if (size == validSizes[i])
						{
							validInput = 1;
							break;
						}

					}
					if (!validInput)
					{
						cout << "Invalid graphic size. Please choose from the valid sizes (8, 16, 32): ";
						cin >> size;
					}
				}

			}
			memorySize = size;
		}
		else if (comp.type == "Mac")
		{
			int validSizes[] = { 4,8,16 };
			bool validInput = false;
			while (!validInput)
			{
				if (size < 4 || size > 16)
				{
					cout << "Invalid graphic size. Please enter a size between 4 and 16: ";
					cin >> size;
				}
				else
				{
					for (int i = 0; i < 3; i++)
					{
						if (size == validSizes[i])
						{
							validInput = 1;
							break;
						}

					}
					if (!validInput)
					{
						cout << "Invalid graphic size. Please choose from the valid sizes (4,8,16): ";
						cin >> size;
					}
				}

			}
			memorySize = size;
		}
		price = money;
	}
	string getBrand() const;
	int getMemory()const;
	double getPrice()const;
	void setBrand(string name);
	void setMemory(int size);
	void setPrice(double money);
	void displayGraphicsCard();
};
class StorageDevice {
private:
	string type; // HDD, SSD
	int capacity; //128 GB to 2 TB
	double price;
	ComputerType comp;
public:
	StorageDevice(string newType, int cap, double newPrice, ComputerType compType = ComputerType("PC")) : type(newType), capacity(cap),
		price(newPrice) , comp(compType)
	{
		if (comp.type == "PC")
		{
			int validSizes[] {128, 256, 384, 512, 640, 768, 896, 1024, // 1 TB
						1152, 1280, 1408, 1536, 1664, 1792, 1920, 2048 // 2 TB
			};
			bool validInput = false;
			while (!validInput)
			{
				if (cap < 128 || cap > 2048)
				{
					cout << "Invalid Capacity size. Please enter a size between 128 and 2TB: ";
					cin >> cap;
				}
				else
				{
					for (int i = 0; i < 16; i++)
					{
						if (cap == validSizes[i])
						{
							validInput = 1;
							break;
						}

					}
					if (!validInput)
					{
						cout << "Invalid capacity. Please choose from the valid sizes {128, 256, 384, 512, 640, 768, 896, 1024, 1152, 1280, 1408, 1536, 1664, 1792, 1920, 2048 // 2 TB}";
						cin >> cap;
					}
				}

			}
			capacity = cap;
		}
		else if (comp.type == "Mac")
		{
			int validSizes[]{256, 384, 512, 640, 768, 896, 1024, // 1 TB
						1152, 1280, 1408, 1536, 1664, 1792, 1920, 2048 // 2 TB
			};
			bool validInput = false;
			while (!validInput)
			{
				if (cap < 256 || cap > 2048)
				{
					cout << "Invalid Capacity size. Please enter a size between 256 and 2TB: ";
					cin >> cap;
				}
				else
				{
					for (int i = 0; i < 15; i++)
					{
						if (cap == validSizes[i])
						{
							validInput = 1;
							break;
						}

					}
					if (!validInput)
					{
						cout << "Invalid capacity. Please choose from the valid sizes {256, 384, 512, 640, 768, 896, 1024, 1152, 1280, 1408, 1536, 1664, 1792, 1920, 2048 // 2 TB}";
						cin >> cap;
					}
				}

			}
			capacity = cap;
		}
		price = newPrice;
	}
	string getType() const;
	int getCapacity()const;
	double getPrice()const;
	void setType(string newType);
	void setCapacity(int cap);
	void setPrice(double money);
	void displayStorageDevice();
};
class NetworkCard {
private:
	string type;
	int speed;
	double price;
public:
	NetworkCard(string newType, int newSpeed, double money) : type(newType),
		speed(newSpeed), price(money) {}
	string getType()const;
	int getSpeed()const;
	double getPrice() const;
	void setType(string newType);
	void setSpeed(int newSpeed);
	void setPrice(int money);
	void displayNetworkCard();
};
class PowerSupply {
private:
	int wattage;
	string efficiencyRating; //80 Plus Bronze, 80 Plus Gold
	double price;
public:
	PowerSupply(int watt, string rate, double money) : wattage(watt), 
		efficiencyRating(rate),price(money) {}
	int getWattage()const;
	string getRate()const;
	double getPrice()const;
	void setWattage(int watt);
	void setRate(string rate);
	void setPrice(double money);
	void displayPowerSupply();
};
class Battery {
private:
	int capacity;
public:
	Battery(int cap = 5000) : capacity(cap) {}

	int getCapacity() const;
	void setCapacity(int cap);
	void displayBattery();
};
class Case {
private:
	string formFactor;
	string color;
	double price;
public:
	Case(const string& form = "ATX", const string& col = "Black", double pr = 50.0)
		: formFactor(form), color(col), price(pr) {}
	const string& getFormFactor() const;
	void setFormFactor(const string& form);
	const string& getColor() const;
	void setColor(const string& col);
	double getPrice() const;
	void setPrice(double pr);
	void displayCase();
};
class ComputerAssembly {
private:
	Computer computer;
	GraphicsCard graphicsCard;
	StorageDevice storageDevice;
	NetworkCard networkCard;
	PowerSupply powerSupply;
	Battery battery;
	Case computerCase;
public:
	ComputerAssembly(const PhysicalMemory& pm, const CPU& cpu, const MotherBoard& mb,
		const GraphicsCard& gc, const StorageDevice& sd, const NetworkCard& nc,
		const PowerSupply& ps, const Battery& bat, const Case& compCase)
		: computer(pm, cpu, mb), graphicsCard(gc), storageDevice(sd), networkCard(nc),
		powerSupply(ps), battery(bat), computerCase(compCase) {}

	const Computer& getComputer() const;
	const PhysicalMemory& getPhysicalMemory() const;
	const CPU& getCPU() const;
	const MotherBoard& getMotherBoard() const;
	const GraphicsCard& getGraphicsCard() const;
	const StorageDevice& getStorageDevice() const;
	const NetworkCard& getNetworkCard() const;
	const PowerSupply& getPowerSupply() const;
	const Battery& getBattery() const;
	const Case& getComputerCase() const;
	void displayComputerAssembly();
};

#endif // !_Header_H_