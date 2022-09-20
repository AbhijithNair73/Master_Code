#ifndef ABSTRACT_EXAMPLE
#define ABSTRACT_EXAMPLE
#include <iostream>
#include <string>
using namespace std;
enum PHONE_FACTORIES { SAMSUNG, HTCC, NOKIA };

// Abstract Product
class AbstractPhone {
public:
	virtual string getName() = 0;
	virtual void makeCall() = 0;
	virtual bool isSmartPhone() = 0;
	virtual ~AbstractPhone() = default;
};

// Interface products
class DumbPhoneFactory : public AbstractPhone {
public:
	virtual bool isSmartPhone() {
		return false;
	}
};

class SmartPhoneFactory : public AbstractPhone {
public:
	virtual bool isSmartPhone() {
		return true;
	}
};

// concrete products
class GalaxyS2 : public SmartPhoneFactory {
	string name;

public:
	GalaxyS2() : name("Galaxy S2") {
	}
	string getName() override {
		return name;
	};
	virtual void makeCall() override {
		cout << "Making call from Galaxy S2 smartPhone " << endl;
	}
};

class Lumia : public SmartPhoneFactory {
	string name;

public:
	Lumia() : name("Lumia") {
	}
	string getName() override {
		return name;
	};
	virtual void makeCall() override {
		cout << "Making call from Lumia smartPhone " << endl;
	}
};

class HTCOne : public SmartPhoneFactory {
	string name;

public:
	HTCOne() : name("HTCOne") {
	}
	string getName() override {
		return name;
	};
	virtual void makeCall() override {
		cout << "Making call from HTCOne smartPhone " << endl;
	}
};

class Corby : public DumbPhoneFactory {
	string name;

public:
	Corby() : name("Corby") {
	}
	string getName() override {
		return name;
	};
	virtual void makeCall() override {
		cout << "Making call from Corby dumbPhone " << endl;
	}
};

class XpressMusic : public DumbPhoneFactory {
	string name;

public:
	XpressMusic() : name("XpressMusic") {
	}
	string getName() override {
		return name;
	};
	virtual void makeCall() override {
		cout << "Making call from XpressMusic dumbPhone " << endl;
	}
};

class Ozone : public DumbPhoneFactory {
	string name;

public:
	Ozone() : name("Ozone") {
	}
	string getName() override {
		return name;
	};
	virtual void makeCall() override {
		cout << "Making call from Ozone dumbPhone " << endl;
	}
};

// abstract factory
class AbstractManufacturer {
private:
	/* data */
public:
	AbstractManufacturer() = default;
	virtual ~AbstractManufacturer() = default;
	virtual AbstractPhone *createSmartPhone() = 0;  // this and below can be considered as factory methods
	virtual AbstractPhone *createDumbPhone() = 0;  // because they create concreteProducts. Factory method is responsible for creating concrete products.
	static AbstractManufacturer *createFactory(PHONE_FACTORIES factory); // this is factory creater
	// This abstract factory class creates different factories using above method, and each factory 
	// is a factory pattern and they have their own factory methods(above mentioned) to create concrete product(phone) classes
};

class Samsung : public AbstractManufacturer {
public:
	AbstractPhone *createSmartPhone() override {
		return new GalaxyS2();
	}
	AbstractPhone *createDumbPhone() override {
		return new Corby();
	}
};
class Nokia : public AbstractManufacturer {
public:
	AbstractPhone *createSmartPhone() override {
		return new Lumia();
	}
	AbstractPhone *createDumbPhone() override {
		return new XpressMusic();
	}
};
class HTC : public AbstractManufacturer {
private:
public:
	AbstractPhone *createSmartPhone() override {
		return new HTCOne();
	}
	AbstractPhone *createDumbPhone() override {
		return new Ozone();
	}
};

#endif // ABSTRACT_EXAMPLE