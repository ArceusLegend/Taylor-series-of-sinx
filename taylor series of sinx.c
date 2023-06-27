#include<stdio.h>
#include<math.h> //include math.h for M_PI, which is just a const that contains the value of pi

double sintaylor(double x) { //declare the function as double to return the most accurate real number that the calculation will give us
    double value = x; //pass the parameter x to 2 variables; value caches the calculation of each new loop
    double sum = x; //this will be the final product that the function will return, initialize it as x as the loop immediately calculates the next term
    int i; //the version of C my compiler uses doesn't support the declaration of a new variable within the for() arguments
    
    for (i = 0; i < 100; i++) { //we want to calculate the series up to the 100th term
    	//the taylor series of sin()x is the sum of all terms of the sequence [(-1)^n]*[(x^(2n+1))/(2n+1)!], starting from n = 0, up to infinity
        value = -value*x*x/(2*i+2)/(2*i+3); //this may not look like the equation from above, but it still works the same
        //this is simply a way to represent the expansion series to in a way that a computer can calculate it
        //you can always calculate the actual value of sin(x) up to the same number of decimals and you'll see that it produces the same result
        sum += value; //add the current term to the sum that'll be returned by the function
    }
    
    return sum; //returns the final value of the series up to the 100th term
}

int main(){
	double deg, rad, sum; //declare the variables as double in order to get the most accurate result we can with real numbers
	printf("Enter degrees: "); //we need a specific value of sin(x) to calculate a specific number
	scanf("%lf", &deg); //we can let the user enter a value
	rad = deg * M_PI/180; //convert degrees to radians
	sum = sintaylor(rad); //calls the function and passes the given angle in radians
	printf("%lf", sum); //prints the result on the console
	
	return 0;
}
