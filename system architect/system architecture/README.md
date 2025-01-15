 &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; <a href=""><img src="https://iili.io/JuFUWs2.md.png" alt="771" border="0"></a><br /><a target='' href='https://iili.io/JuFUWs2.md.png'>

[![MIT License](https://img.shields.io/badge/C%20FILES%20-7A5BE2)](https://github.com/omarsamy289/ES-omar-samy/tree/main/system%20architect/system%20architecture/all%20files/c%20code)

[![MIT License](https://img.shields.io/badge/snap%20shots%20-7A5BE2)](https://github.com/omarsamy289/ES-omar-samy/tree/main/system%20architect/system%20architecture/all%20files/snap%20shots)



[![MIT License](https://img.shields.io/badge/go%20back%20-7A5BE2)](https://github.com/omarsamy289/ES-omar-samy/tree/main)


# System architecture ( design for a basic collision avoidance system using TTool ) 

#  TTool : Block diagram 


<a href=""><img src="https://github.com/omarsamy289/ES-omar-samy/blob/main/system%20architect/system%20architecture/all%20files/snap%20shots/block%20diagram.png?raw=true" alt="771" border="0"></a><br /><a target=''>

>* US_sensor state machine 

<a href=""><img src="https://github.com/omarsamy289/ES-omar-samy/blob/main/system%20architect/system%20architecture/all%20files/snap%20shots/US_sensor%20%20stat%20machine.png?raw=true" alt="771" border="0"></a><br /><a target=' '>


>* DC_motor state machine 


<a href=""><img src="https://github.com/omarsamy289/ES-omar-samy/blob/main/system%20architect/system%20architecture/all%20files/snap%20shots/DC_motor%20%20stat%20machine.png?raw=true" alt="771" border="0"></a><br /><a target='_blank' href=''>


>* CA block state machine 


<a href=""><img src="https://github.com/omarsamy289/ES-omar-samy/blob/main/system%20architect/system%20architecture/all%20files/snap%20shots/CA_block%20%20stat%20machine.png?raw=true" alt="771" border="0"></a><br /><a target='_blank' href=''>


## the full output trace from interactive simulation ( sequance diagram )

> click button below to view the full output trace diagram

[![MIT License](https://img.shields.io/badge/full%20output%20trace%20-7A5BE2)](https://github.com/omarsamy289/ES-omar-samy/blob/main/system%20architect/system%20architecture/all%20files/snap%20shots/simulationtrace_fromttool.png)

>* explanation of two of the cycles from the full output trace diagram ( sequance diagram )

<a href=""><img src="https://github.com/omarsamy289/ES-omar-samy/blob/main/system%20architect/system%20architecture/all%20files/snap%20shots/simulationtrace_fromttool_explained.png?raw=true" alt="771" border="0"></a><br /><a target='' href=''>




# implementation in c code 

 

## state.h
> in this file we created state difintions to further use and implement in files 
> also added the prototype of signals function that connencts between the blocks 

```c code
/*
 * stat.h
 *
 *  Created on: Dec 12, 2023
 *      Author: omar
 */

#ifndef STATE_H_
#define STATE_H_
#include "stdio.h"
#include "stdlib.h"

// state definitio macros
#define state_definition(state_func) void SD_##state_func()
#define state_name(state_func) SD_##state_func

// connections between blocks
void US_set_distance (int di) ;
void DC_get_speed (int sp ) ;



#endif /* STATE_H_ */


```



## US.h 

> the prototype of the Ultra sonic sensor module
```c code
/*
 * US.h
 *
 *  Created on: Dec 12, 2023
 *      Author: omar
 */

#ifndef US_H_
#define US_H_
#include "state.h"



// prototype of the initialization function of the ultra-sonic
void US_init () ;

//prototype of the us_busy state
state_definition(US_busy);


//this pointer to function that takes nothing and rerurn void and it's extern to be seen in main.c
extern void (*US_state)() ;




#endif /* US_H_ */


```


## US.c

the implementation of the Ultra sonic sensor module

```c code
/*
 * US.c
 *
 *  Created on: Dec 12, 2023
 *      Author: omar
 */

#include "US.h"

int US_distance =  0 ;
// enum to describe the the state id
enum {
	US_busy,
}US_state_id;

// pointer to function that takes nothing and return void used to set the us state
void (*US_state)() ;
int US_get_rondom(int l , int r , int count ) ;


//the implementation of the  initialization function of the ultra-sonic
void US_init ()
{

printf(" US init ...... \n" ) ;
fflush(stdout) ; fflush(stdin) ;
}


// state us busy is the only state in us block used to set the distance and send it to CA block via
//US_set_distance function
state_definition(US_busy){

	// state id
	US_state_id =  US_busy;
	// state action

	US_distance =  US_get_rondom(45 , 55 ,  1 ) ;
	US_set_distance(US_distance) ;
//
	printf(">>> state US busy .........distance:%d \n" , US_distance) ;
	fflush(stdout) ; fflush(stdin) ;
	US_state = state_name(US_busy) ;
}


// function to generate rondom numbers within range
int US_get_rondom(int l , int r , int count ){

int i ;
for ( i = 0 ; i < count ; i++) {
	int rand_num  = ( rand() % (r - l + 1) ) + l;
	return rand_num ;

}


}
```


## DC.h 

the prototype of the DC motor module


```c code
/*
 * CA.h
 *
 *  Created on: Dec 12, 2023
 *      Author: omar
 */

#ifndef DC_H_
#define DC_H_
#include "state.h"


//prototype of the DC_busy and dc_idle states

state_definition(DC_idle);
state_definition(DC_busy);

// prototype of the initialization function of the DC motor

void DC_init () ;

//this pointer to function that takes nothing and rerurn void and it's extern to be seen in main.c
extern void (*DC_state)() ;




#endif /* CA_H_ */


```


## DC.c

the implementation of the DC motor module

```c code

/*
 * DC.c
 *
 *  Created on: Dec 12, 2023
 *      Author: omar
 */

#include "DC.h"

int DC_speed =  0 ;


// enum to describe the the state id

enum {
	DC_idle,
	DC_busy
}DC_state_id;

// pointer to function that takes nothing and return void
void (*DC_state)() ;


// function to get the speed from CA module to be sent to the DC motor module
void DC_get_speed (int sp ) {

	DC_speed = sp ;

	DC_state = state_name(DC_busy) ;

	printf("(CA ---> DC) DC get speed at : %d \n ", DC_speed ) ;
	fflush(stdout) ; fflush(stdin) ;

}


//the implementation of the  initialization function of DC motor

void DC_init () {

	printf(" DC init ...... \n" ) ;
	fflush(stdout) ; fflush(stdin) ;


}

// state DC idle : in this state speed should be idle

state_definition(DC_idle){

	// state id
	DC_state_id = DC_idle ;
	// state action
	// call PWM module to make speed = DC_speed
	printf(">>> stat DC idle .........speed:%d \n" , DC_speed) ;
	fflush(stdout) ; fflush(stdin) ;
}




// state DC busy means that the dc motor is in the driving mode and the speed should be at some value
state_definition(DC_busy){
// state id
 DC_state_id = DC_busy ;
 printf(">>> state DC busy .........speed:%d \n" , DC_speed) ;
 fflush(stdout) ; fflush(stdin) ;
// state action
 DC_state = state_name(DC_idle) ;

}
```




## CA.h 

the prototype of the Ultra sonic sensor states


```c code

/*
 * CA.h
 *
 *  Created on: Dec 12, 2023
 *      Author: omar
 */

#ifndef CA_H_
#define CA_H_
#include "state.h"


//prototype of the CA_waiting and CA_waiting states

state_definition(CA_waiting);
state_definition(CA_waiting);

//this pointer to function that takes nothing and rerurn void and it's extern to be seen in main.c

extern void (*CA_state)() ;

#endif /* CA_H_ */

```


## CA.c

the implementation of the Ultra sonic sensor states

```c code
/*
 * CA.c
 *
 *  Created on: Dec 12, 2023
 *      Author: omar
 */

#include "CA.h"
int CA_speed =  0 ;
int CA_distance =  0 ;
int CA_threshold =  50 ;

// enum to describe the the state id
enum {
	CA_waiting,
	CA_driving
}CA_state_id;

// pointer to function that takes nothing and return void
void (*CA_state)() ;

// the implementation of the connetion function between US module and the CA module to get distance
// the US module
void US_set_distance (int di) {

	CA_distance = di ;
// check if the distance set by the ultra sonic is less than or bigger than the threshold to further use
// to jump to the correct state
(CA_distance <= CA_threshold ) ? (CA_state = state_name(CA_waiting)) : (CA_state =state_name(CA_driving));



printf("(US ---> CA) US set distance at : %d \n ", CA_distance ) ;
fflush(stdout) ; fflush(stdin) ;

}


// state that sets the speed to 0 when CA_distance <= CA_threshold
state_definition(CA_waiting){
// state id
 CA_state_id = CA_waiting ;
 printf(">>> state CA waiting .....distance :%d....speed:%d \n" , CA_distance , CA_speed) ;
 		fflush(stdout) ; fflush(stdin) ;
// state action
CA_speed =  0;
DC_get_speed (CA_speed) ;

}


// state that sets the speed to 30 when CA_distance > CA_threshold

state_definition(CA_driving){

	// state id
	CA_state_id = CA_driving ;
	printf(">>> state CA driving .....distance :%d....speed:%d \n" , CA_distance , CA_speed) ;
		fflush(stdout) ; fflush(stdin) ;
	// state action
	CA_speed =  30;
	DC_get_speed (CA_speed) ;

}

```






## main.c

the main program to initialize the modules and the stat pointers and start the program
```c code
/*
 * main.c
 *
 *  Created on: Dec 12, 2023
 *      Author: omar
 */
#include "CA.h"
#include "DC.h"
#include "US.h"

void setup() {
// init all drivers
// init ISR
// init HAL (US, DC...)
// init block
	 US_init () ;
  	DC_init () ;
//init all of the state pointers
	CA_state = state_name(CA_waiting) ;
	US_state = state_name(US_busy) ;
	DC_state = state_name(DC_idle) ;

}

void main() {

	setup();
volatile int i ;
	while(1){
		US_state();
		CA_state();
		DC_state();
		for(i=0 ; i<1000 ; i++) ;
	}
}
```

## snap shot output 

[![JuFloLQ.md.png](https://iili.io/JuFloLQ.md.png)](https://freeimage.host/i/JuFloLQ)

## snap shot from the executable output

```text
US init ...... 
 DC init ...... 
(US ---> CA) US set distance at : 53 
 >>> state US busy .........distance:53 
>>> state CA driving .....distance :53....speed:0 
(CA ---> DC) DC get speed at : 30 
 >>> state DC busy .........speed:30 
(US ---> CA) US set distance at : 54 
 >>> state US busy .........distance:54 
>>> state CA driving .....distance :54....speed:30 
(CA ---> DC) DC get speed at : 30 
 >>> state DC busy .........speed:30 
(US ---> CA) US set distance at : 54 
 >>> state US busy .........distance:54 
>>> state CA driving .....distance :54....speed:30 
(CA ---> DC) DC get speed at : 30 
 >>> state DC busy .........speed:30 
(US ---> CA) US set distance at : 46 
 >>> state US busy .........distance:46 
>>> state CA waiting .....distance :46....speed:30 
(CA ---> DC) DC get speed at : 0 
 >>> state DC busy .........speed:0 
(US ---> CA) US set distance at : 52 
 >>> state US busy .........distance:52 
>>> state CA driving .....distance :52....speed:0 
(CA ---> DC) DC get speed at : 30 
 >>> state DC busy .........speed:30 
(US ---> CA) US set distance at : 50 
 >>> state US busy .........distance:50 
>>> state CA waiting .....distance :50....speed:30 
(CA ---> DC) DC get speed at : 0 
 >>> state DC busy .........speed:0 
(US ---> CA) US set distance at : 50 
 >>> state US busy .........distance:50 
>>> state CA waiting .....distance :50....speed:0 
```


[![MIT License](https://img.shields.io/badge/C%20FILES%20-7A5BE2)](https://github.com/omarsamy289/ES-omar-samy/tree/main/system%20architect/system%20architecture/all%20files/c%20code)

[![MIT License](https://img.shields.io/badge/snap%20shots%20-7A5BE2)](https://github.com/omarsamy289/ES-omar-samy/tree/main/system%20architect/system%20architecture/all%20files/snap%20shots)



[![MIT License](https://img.shields.io/badge/go%20back%20-7A5BE2)](https://github.com/omarsamy289/ES-omar-samy/tree/main)

&nbsp;
&nbsp;

&nbsp;

## 🔗 Links

[![linkedin](https://img.shields.io/badge/linkedin-0A66C2?style=for-the-badge&logo=linkedin&logoColor=white)](https://www.linkedin.com/in/omar-samy-69a7241b0/)
