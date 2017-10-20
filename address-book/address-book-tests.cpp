#include "address-book.h"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

TEST_CASE("Copy Constructed Object Does Not Share State With Original")
{
	Person person1("Jonny",20);
	Person person2("Sally",50);
	
	AddressBookEntry address1(person1,"person1 image");
	AddressBookEntry address2(address1);

	address1.setPerson(person2);
	address1.setImageName("person2 image");

	CHECK_FALSE(address1.getImageName() == address2.getImageName());
}

/*TEST_CASE("Object Copy Created Through Assignment Does Not Share State With Original")
{
	Person person1("Jonny",20);
	Person person2("Sally",50);
	
	AddressBookEntry address1(person1,"person1 image");
	AddressBookEntry address2 = address1;

	address1.setPerson(person2);
	address1.setImageName("person2 image");

	CHECK_FALSE(address1.getImageName() == address2.getImageName());
}*/