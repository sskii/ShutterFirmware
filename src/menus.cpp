/**
 * menus.cpp
 *
 *  Created on: 27/10/2020
 *     @author Sam
 */

/* Handles menus.
 *
 * Relies on UIDs. Retrieves values from, and sends update
 * notices to, the settings exchange.
 */

#include "menus.h"
#include <Arduino.h>


/* The routine that provides the logic to draw menus.
 * Called to start a new menu session. Terminates when all menus closed.
 */
void MenuLogic::open() {

	// start us off in the right place
	hover = 0;			// start on first item
	menu = M_Main;		// start at main menu

	close = false;		// reset flag to avoid instant termination

	// menu control loop
	while(!close) {
		// while the menu is open

		change = false;				// reset the change flag

		// TODO draw the menu from scratch now

		// monitor the menu until it needs to exit
		while(!change) {
			
			// housekeepingFunction() TODO
			if(close) break;			// check if we need to jump out.

			// TODO check for scrolling
			// TODO check for selections
			if(false /* button press logged */) {
				// select the item

				if(hover > 128) {
					// menu is selected, change menu
					
					// save state
					pushStack(hover);		// push hover first
					pushStack(menu);		// push menu above

					// update state
					menu = menuClaims[menusClaim[menu - M_Main] + hover];
						// look up the UID of the selected item, set as menu
					hover = 0;
						// zero the hover for the new menu

					change = true;	// make note that we need to change menus.

				} else {
					// menu item is selected

				}
			}

			// TODO check for exits
			if(false /* exit button pressed */) {
				// the current 'exit' behaviour is to back up a menu
				// we'll see if that prooves too annoying.

				if(stackEmpty()) {
					// if we cannot go back any further
					close = true;
					break;		// terminate the menuing process
				} else {
					// restore a previous menu
					menu = popStack();	// menu comes first
					hover = popStack();	// hover follows
					change = true;		// ask to change menus
				}
			} 
		}
	}
}

/* Pop the top data from the stack
 * @returns The top data
 */
uint8_t MenuLogic::popStack() {
	if(stackEmpty()) return M_Default;	// this is undefined behaviour. [Debug note]
							// ^ returning M_Default is just damage control.
	return stack[top--];	// return element at top, decrementing index
}

/* Push the provided data to the stack
 * @param data The data to stack
 * @returns The current stack height
 */
int8_t MenuLogic::pushStack(uint8_t data) {
	if(!stackFull()) stack[++top] = data;	// increment top, stack data
	return top;								// return new top
}

/* Peek at the top data. No change is made to the stack.
 * @returns the top data
 */
uint8_t MenuLogic::peekStack() {
	return stack[top];			// just return the top data. Don't change stack
}

/* Check if stack is empty
 * @returns true if empty, false otherwise
 */
bool MenuLogic::stackEmpty() {
	if(top < 0) top = 0;		// out of bounds, fix that issue
	return (top == 0);			// return the verdict
}

/* Check if stack is full
 * @returns true if stack is full, false otherwise.
 */
bool MenuLogic::stackFull() {
	if(top > STACK_HEIGHT) top = STACK_HEIGHT;
									// uh, that's a problem (fix it).
	return (top == STACK_HEIGHT);	// check, return verdict.
}

/*
 * Get the title of the menu/menu item.
 * @param UID the UID of the requested item
 * @returns its title string
 */
String MenuLogic::getTitle(uint8_t UID) {

	if(UID <= 127) {
		// search menu items list
		return menuNames[UID];
	} else if(UID == 128) {
		// homescreen
		return "cocking state tip";
	} else {
		// seach menu names register
		return menuNames[UID-129];
	}

}
