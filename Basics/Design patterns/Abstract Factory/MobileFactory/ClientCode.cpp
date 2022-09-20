#include "AbstractExample2.h"
#include <memory>
AbstractManufacturer *
AbstractManufacturer::createFactory(PHONE_FACTORIES factory) {
	if (factory == PHONE_FACTORIES::SAMSUNG) {
		return new Samsung();
	} else if (factory == PHONE_FACTORIES::HTCC) {
		return new HTC();
	} else if (factory == PHONE_FACTORIES::NOKIA) {
		return new Nokia();
	}
	return nullptr;
}

int main() {
	unique_ptr<AbstractManufacturer> brand(
		AbstractManufacturer::createFactory(PHONE_FACTORIES::HTCC));
	if (brand) {
		unique_ptr<AbstractPhone> phone(brand->createDumbPhone());
		cout << phone->getName() << endl;
		cout << (phone->isSmartPhone() ? "Yes, Its a smartPhone"
									   : "Its a dumbPhone")
			 << endl;
		phone->makeCall();
	}
	return 0;
}