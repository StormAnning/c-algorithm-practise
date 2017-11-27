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
	printf("%p\n", pointer); //prints pointer value - which is address of value!
	printf("%p\n", &value); //prints address of value  which will be the same as the pointer above

	printf("%p\n", &pointer); //prints the address of the pointer itself - whose value actually holds an address
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


	int *x; //will be allocated IN RAM
	int *y; //both point to nothing
	printf("%p\n", &x); //address of the pointer in RAM
	printf("x value: %p y value:%p\n", x , y); //will print the value in ram for this pointer x, at the address above - this will not be anything useufl because we haven't set it yet, will be whatever value was last in that ram cell
	//*x = 4; - would error
	x = malloc(sizeof(int));
	y = malloc(sizeof(int));
	printf("x value: %p y value:%p\n", x , y);
	*x = 5;
	y=x;
	printf("x value: %p y value:%p\n", x , y);
	printf("%d\n", *y); //will print 5
	return 0;
}