/*********************************************************************
*                SEGGER MICROCONTROLLER SYSTEME GmbH                 *
*        Solutions for real time microcontroller applications        *
*                           www.segger.com                           *
**********************************************************************
*
* C-file generated by
*
*        �C/GUI-BitmapConvert V3.90.
*        Compiled Aug 19 2004, 09:07:56
*          (c) 2002  Micrium, Inc.
  www.micrium.com

  (c) 1998-2002  Segger
  Microcontroller Systeme GmbH
  www.segger.com
*
**********************************************************************
*
* Source file: fengshi2
* Dimensions:  50 * 50
* NumColors:   2
*
**********************************************************************
*/

#include "stdlib.h"

#include "fengshi2.h"

#ifndef GUI_CONST_STORAGE
  #define GUI_CONST_STORAGE const
#endif

/*   Palette
The following are the entries of the palette table.
Every entry is a 32-bit value (of which 24 bits are actually used)
the lower   8 bits represent the Red component,
the middle  8 bits represent the Green component,
the highest 8 bits (of the 24 bits used) represent the Blue component
as follows:   0xBBGGRR
*/

static GUI_CONST_STORAGE GUI_COLOR Colorsfengshi2[] = {
     0x000000,0xFFFFFF
};

static GUI_CONST_STORAGE GUI_LOGPALETTE Palfengshi2 = {
  2,	/* number of entries */
  1, 	/* Has transparency */
  &Colorsfengshi2[0]
};

static GUI_CONST_STORAGE unsigned char acfengshi2[] = {
  XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, ________, ________, ________,
  X_______, ________, ________, _______X, ___XXXXX, XXXXX___, ________,
  X_______, ________, ________, _______X, ___X____, ____X___, ________,
  X_______, ________, ________, _______X, ___X____, ____X___, ________,
  X_______, ________, ________, _______X, ___X_X__, __X_X___, ________,
  X_______, ____X_XX, XXX_X___, _______X, ___X__X_, __X_X___, ________,
  X_______, ____X_XX, XXX_X___, _______X, ___X___X, _X__X___, ________,
  X_______, ____X_XX, XXX_X___, _______X, ___X___X, _X__X___, ________,
  X_______, ___XX_XX, XXX_XX__, _______X, ___X____, X___X___, ________,
  X_______, __XX__XX, XXX__XXX, _______X, ___X____, X___X___, ________,
  X_______, _XX__XXX, XXXX___X, X______X, ___X___X, _X__X___, ________,
  X_______, XX__XXXX, XXXXX___, _X_____X, ___X___X, _X__X__X, ________,
  X______X, X__XXXXX, XXXXXX__, _X_____X, ___X__X_, __X__X_X, ________,
  X______X, ___XXXXX, XXXXXX__, _X_____X, __X__X__, __X__X_X, ________,
  X______X, _____XXX, XXX_____, _X_____X, __X_____, ______XX, ________,
  X______X, __XX___X, X___XX__, XX_____X, _X______, _______X, ________,
  X_______, X__XXX__, __XXX__X, X______X, ________, ________, ________,
  X_______, _X___XXX, XXXX_XX_, _______X, ___X__XX, XXXXXX__, ________,
  X_______, __XX_XXX, XXX_XX__, _______X, ____X_X_, _____X__, ________,
  X_______, ___XX_XX, XXX_X___, _______X, ____X_X_, _____X__, ________,
  X_______, ____X_XX, XXX_X___, _______X, _X____XX, XXXXXX__, ________,
  X_______, ____X_XX, XXX_X___, _______X, __X___X_, _____X__, ________,
  X_______, ____X_XX, XXX_X___, _______X, __X___X_, _____X__, ________,
  X_______, ____X_XX, XXX_X___, _______X, ____X_XX, XXXXXX__, ________,
  X_______, ____X_XX, XXX_X___, _______X, ____X___, X__X____, ________,
  X_______, ____X_XX, XXX_X___, _______X, ___X____, X__X____, ________,
  X_______, ____X_XX, XXX_X___, _______X, _XXX_X__, X__X__X_, ________,
  X_______, ____X_XX, XXX_X___, _______X, ___X__X_, X__X_X__, ________,
  X_______, ________, ________, _______X, ___X___X, X__XX___, ________,
  X_______, ________, ________, _______X, ___X____, X__X____, ________,
  X_______, ________, ________, _______X, ___X_XXX, XXXXXXXX, ________,
  XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, ________, ________, ________,
  ________, ________, ________, ________, ________, ________, ________,
  ________, ________, ________, ________, ________, ________, ________,
  ________, ________, ________, ________, ________, ________, ________,
  ________, ________, ________, ________, ________, ________, ________,
  ________, ________, ________, ________, ________, ________, ________,
  ________, ________, ________, ________, ________, ________, ________,
  ________, ________, ________, ________, ________, ________, ________,
  ________, ________, ________, ________, ________, ________, ________,
  ________, ________, ________, ________, ________, ________, ________,
  ________, ________, ________, ________, ________, ________, ________,
  ________, ________, ________, ________, ________, ________, ________,
  ________, ________, ________, ________, ________, ________, ________,
  ________, ________, ________, ________, ________, ________, ________,
  ________, ________, ________, ________, ________, ________, ________,
  ________, ________, ________, ________, ________, ________, ________,
  ________, ________, ________, ________, ________, ________, ________,
  ________, ________, ________, ________, ________, ________, ________,
  ________, ________, ________, ________, ________, ________, ________
};

GUI_CONST_STORAGE GUI_BITMAP bmfengshi2 = {
  50, /* XSize */
  50, /* YSize */
  7, /* BytesPerLine */
  1, /* BitsPerPixel */
  acfengshi2,  /* Pointer to picture data (indices) */
  &Palfengshi2  /* Pointer to palette */
};

/* *** End of file *** */