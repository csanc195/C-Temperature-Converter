/*****************************************************************************/
/* Disclaimer:*/
/* Author: Carlos L Sanchez Vila   */
/* INSTRUCTIONS/HOW TO USE:*/
/* To compile:*/
/* gcc tempComverter.c -o CandFconverter.out*/
/* To execute:*/
/*  enter ./CandFconverter.out and follow on screen INSTRUCTIONS             */
/*****************************************************************************/

#include <stdio.h>
#define ASCII_DIGIT_ZERO 48         /*ASCII value of digit '0'*/
#define ASCII_LOW_DIGIT 49          /*ASCII value of lowest digit allowed '1'*/
#define ASCII_HIGH_DIGIT 57         /*ASCII value of highest digit '9'*/
#define MEASURE_START -20.0         /*Starting lowest value for temperatures*/
#define MEASURE_END 280.0           /*Max allowed value for the temperature*/
#define NO_PROGRAM_ERRORS 0         /*Signal a correct program execution*/
typedef enum { FALSE, TRUE } bool;  /*Allow the use of boolean type*/

/* Function Prototypes declarations:*/
int validateUserInput();
float convertToCelsius(float);
float convertToFahrenheit(float);
void printTableData(float,float,int);

/**
 * The following program creates a table exposing conversions from fahrenheit 
 * to celsius and from celsius to fahrenheit. The program takes only one imput
 * from the user which dictates the increments in temperature that is used to 
 * generate the table, this imput must be a number between 1 and 9.
 * 
 * @return: returns the value zero if there are no program errors.
 */
int main(){

	/*Capture the user's input, and validate it.*/
	printf("%s\n", "Please enter a single digit from 1 to 9: ");
	int userIncrement = validateUserInput();

	/*Print the table according to the user's entered specifications.*/
	printf("%s", "Alright, building  a temperature table using ");
	printf("%s %d %s","increments of ", userIncrement, " units ");
	printf("%s \n", "per row:");

	printTableData(MEASURE_START, MEASURE_END, userIncrement);

	return NO_PROGRAM_ERRORS;
}

/**
 * validateUserInput: This function ensures that the user entry is limmited 
 * to only digits from 1 to 9. If any other character is entered, the user 
 * is notified and the program readies and prompts a message to catch and 
 * validate the new input.
 * 
 * @return: This function returns a valid user inputed number, which is a 
 * validated digit n where (1 <= n <= 9).
 */
int validateUserInput(){
	/* Capture the ASCII value of the User's entered first character */
	int numValue = getchar();
	bool okDigit = TRUE;
	char aux;

	/* Detect if there are any trailing characters other than white spaces*/
	while((aux=getchar()) != '\n'){
		if(aux != ' '){
			okDigit = FALSE;
		}
	}
	//Detect if the character is valid.
	if(okDigit == FALSE || numValue < ASCII_LOW_DIGIT 
	 	|| numValue > ASCII_HIGH_DIGIT){
		printf("%s\n", "Input is not within the valid parameters!");
		printf("%s\n", "Please enter a single digit from 1 to 9: ");
		return validateUserInput();
	}else{ 
		/* Character is valid therefore return it's numerical value*/
		return numValue - ASCII_DIGIT_ZERO;
	}
}

/**
 * convertToFahrenheit: This method takes a temperature value expressed in 
 * celsius degrees and converts it to its equivalent fahrenheit value.
 * 
 * @param  valCelsius: This number is  a floting point value that represents 
 * a temperature in celsius degrees. Notice that this uses the standard 
 * international temperature conversion formula: [F]=[C]*9/5 + 32. Where F and 
 * C stand for temperature values represented as Fahrenheit(F), and temperature 
 * values represented as Celsius(C).
 * 
 * @return: The equivalent value of the temperature provided in celsius as a 
 * temperature expressed in fahrenheit.
 */
float convertToFahrenheit(float valCelsius){
	return valCelsius * 9/5 + 32;
}

/**
 * convertToCelsius: This method takes a temperature value expressed in 
 * fahrenehit degrees and converts it to its equivalent celsius value.
 * 
 * @param  valCelsius: This number is  a floting point value that represents 
 * a temperature in fahrenheit degrees. Notice that this uses the standard 
 * international temperature conversion formula: [C]=([F]-32)*5/9.
 * Where F and C stand for temperature values represented as Fahrenheit(F), and
 * temperature values represented as Celsius(C).
 * 
 * @return: The equivalent value of the temperature provided in fahrenheit
 *  as a temperature expressed in celsius.
 */
float convertToCelsius(float valFahrenheit){
	return (valFahrenheit - 32) * 5/9;
}

/**
 * printTableData: The following method uses several defined methods to compute
 * a dual table of conversions. There are two main colums which are tables on 
 * their own. The first column has a table showing conversions from fahrenheit
 *  to celsius, while the second colum has a table showing the conversions from 
 * celsius to fahrenheit. The function is capable of generating both tables 
 * simoultaneously while using a user's provided increment which is used to 
 * compute the table values.
 * 
 * @param start: This parameter sets the origin value of the temperatures to 
 * be generated by both tables.
 * @param end:   This parameter sets the last value to be generated by both
 *  tables.
 *  
 * @param increment This parameter defines the diference in value of every 
 * temperature entry being dynamically generated in both tables.
 */
void printTableData(float start, float end, int increment){
	float meter = start;
	int rowCount = 0;

	printf("+-------------------------------------------------+\n");
	printf("| Fahrenheit   Celsius   |   Celsius  Fahrenheit  |\n");
	printf("+-------------------------------------------------+\n");
	/* While any of the meters is under +280.0, genereate rows.*/
	/* eaach row is generated as:                              */
	/* <fahrenheit>  <celsius> | <celsius>  <fahrenheit>       */
	while(meter <= end){
		printf("|%10.1f %10.1f   |%10.1f %10.1f   |\n", 
			meter, convertToCelsius(meter),
			meter, convertToFahrenheit(meter)
		);
		/* Increment the meters and the row counter.*/
		meter+=increment;
		rowCount++;
	}
	printf("+-------------------------------------------------+\n");
	printf(" %s %26d %s\n","done ", rowCount, " rows generated ");
	
}