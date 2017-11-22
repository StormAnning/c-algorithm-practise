#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	char name[] = "STORM"; //variable is a pointer that points to a memory address, the first character of the array
	char *startChar = name; //startChar pointer set to same pointer of array
	startChar++;//increments address say is was 0x01 -> 0x02
	printf("%s\n",startChar); //This will now print the string "TORM" cause it'll print till string terminator
	
	printf("%s\n",startChar++); //This will print the same as the above
	printf("%s\n",startChar); //this was incremented above and so will print "ORM"
	printf("%s\n",++startChar); //increments before evaulation so prints "RM"
	int value = 12;
	int *pointer;
	pointer = &value;

	printf("%d\n", *pointer); //dereferences pointer prints value
	printf("%d\n", pointer); //prints pointer value - which is address of value!
	printf("%d\n", &value); //prints address of value  which will be the same as the pointer above

	printf("%d\n", &pointer); //prints the address of the pointer itself - whose value actually holds an address
	printf("%d\n", **&pointer); //prints the value 12
	printf("%d\n", **&*&*&pointer); //prints the value 12
	*pointer = 23;
	printf("%d\n", *pointer); //prints the value 23
	
	int **pointerPointer;
	pointerPointer = &pointer; //want the pointer to point to adress of other pointer
	printf("%d\n", **pointerPointer); //prints the value 23

	int value2 = 33;
	*pointerPointer = &value2; //*pointerPointer == pointer
	printf("%d\n", *pointer); //prints the value 33

	int *pointer2 = &value;

	return 0;
}