/*
 * menu.h
 *
 *  Created on: 27/10/2020
 *      Author: Sam
 */

#ifndef MENUS_H_
#define MENUS_H_

#include <Arduino.h>


String menuGetTitle(uint8_t UID);


// general defines
#define STACK_HEIGHT 10


/* define the UIDs of every menu item and menu */
// menu items corresponding to settings, sorted by kind
#define M_BaseExp 0			// base exposure
#define M_RecipMin 1		// min time for reciprocity failure correction
#define M_DlyT 2			// pre-exposure delay duration
#define M_MetZone 3			// metered zone
#define M_FocalL 4			// lens focal length
#define M_FocusL 5			// focus length (= focal length if focused to infty)
#define M_RecipP 6			// reciprocity failure correction factor

// major menus / screens
#define M_Default 128		// default (no menu) screen
#define M_Main 129			// the main menu

// submenus
#define M_BellowsComp 130	// bellows compensation menu
#define M_ExpDly 131		// exposure delay menu
#define M_Recip	132			// reciprocity failure correction menu
#define M_General 133		// the general menu


/* define the menu layouts */
// the UIDs of items appearing in menus, one long list
const uint8_t menuClaims[] = {
	M_BellowsComp, M_ExpDly, M_Recip, M_General,		// main menu
	M_FocalL, M_FocusL,									// bellows menu
	M_DlyT,												// exp. dly. menu
	M_RecipP, M_RecipMin								// reciprocity menu
};

// the indexes to split the above at to find individual menu lists
const uint8_t menusClaim[] = {0, 4, 6, 7};

/* name the menus and their items */
// the names of each menu
const String menuNames[] = {"main", "bellows comp."};
// the names of each menu item
const String menuItems[] = {"base exposure", ""};


/* menu logic */
class MenuLogic {
public:
	uint8_t stack[STACK_HEIGHT];	// menu history stack
	int8_t top = 0;					// stack height

	uint8_t menu;	// the current menu UID
	int8_t hover;	// hovered item index
	/* zero hover indicates first item, -1 is the state switch. */

	bool change,	// flag indicating whether menu should change next cycle
		 close;		// flag indicating whether menu process should terminate

	void open();
	String getTitle(uint8_t UID);
	uint8_t popStack();
	int8_t pushStack(uint8_t data);
	uint8_t peekStack();
	bool stackEmpty();
	bool stackFull();
};

#endif /* MENUS_H_ */
