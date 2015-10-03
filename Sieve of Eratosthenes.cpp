#include <stdio.h>

//declarations go here

void zap (int data[], int divisor);


void display (int data[]);
/////////////////////////////////////////////////////////////////////////////////////////////////
int main( )

{

        int data[900];
		

		//right now this goes up to 10, change that to 900

		//fill in your array with numbers here
        for(int i=0;i<900;i=i+1)
			data[i]=i;
      

		for(int divisor = 2; divisor<33; divisor++)
			zap(data, divisor);

       //call display here

		display(data);

}
////////////////////////////////////////////////////////////////////////////////////////////////

//definitions go here

void zap (int data[], int divisor){
	for(int i = divisor+1; i<900; i++){
		if(data[i]%divisor == 0)
			data[i] = 0;
	}
}

void display (int data[]){

int counter = 0;


        for(int i=0;i<900;i=i+1){
			if (data[i] != 0){
				printf("%d ",data[i]);//leave this line as is
				counter++;
				if (counter%12 == 0)
					printf("\n");
			}//end if

		}//for
}//end function diplay