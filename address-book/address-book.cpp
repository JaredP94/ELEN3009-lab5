// address_book.cpp
// Implementation of the AddressBookEntry class
#include "address-book.h"
#include <memory>
using std::make_shared;

// AddressBookEntry Constructor
AddressBookEntry::AddressBookEntry(	const Person& person,
								   const string& image_filename)
								   :_person(person)
{
	// dynamically allocate memory for the image
	if (image_filename != "") {
		// ignore (for now) what will happen if there is a memory allocation failure
        _image_ptr = make_unique<Image>(image_filename);
	}
}

AddressBookEntry::AddressBookEntry(const AddressBookEntry& rhs) : _person(rhs._person)
{
	if (rhs.getImageName() != "") {
        _image_ptr = make_unique<Image>(rhs.getImageName());
	}
}

AddressBookEntry& AddressBookEntry::operator=(const AddressBookEntry& rhs)
{
	AddressBookEntry temp(rhs);
	swap(temp);
	return *this;
}

void AddressBookEntry::swap(const AddressBookEntry& rhs)
{
	_person = rhs._person;
	if (rhs.getImageName() != "") {
        _image_ptr = make_unique<Image>(rhs.getImageName());
	}
}

string AddressBookEntry::getImageName() const
{
	if (_image_ptr != nullptr)
		return _image_ptr->name();
	else return "No image!";
}

void AddressBookEntry::setImageName(string newname)
{
	if (_image_ptr != nullptr) _image_ptr->name(newname);
}
