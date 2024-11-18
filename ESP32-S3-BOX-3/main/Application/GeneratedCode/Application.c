/*******************************************************************************
*
* E M B E D D E D   W I Z A R D   P R O J E C T
*
*                                                Copyright (c) TARA Systems GmbH
*                                    written by Paul Banach and Manfred Schweyer
*
********************************************************************************
*
* This file was generated automatically by Embedded Wizard Studio.
*
* Please do not make any modifications of this file! The modifications are lost
* when the file is generated again by Embedded Wizard Studio!
*
* The template of this heading text can be found in the file 'head.ewt' in the
* directory 'Platforms' of your Embedded Wizard installation directory. If you
* wish to adapt this text, please copy the template file 'head.ewt' into your
* project directory and edit the copy only. Please avoid any modifications of
* the original template file!
*
* Version  : 13.05
* Profile  : ESP32
* Platform : Espressif.ESP32.RGB565
*
*******************************************************************************/

#include "ewlocale.h"
#include "_ApplicationApplication.h"
#include "_CoreSimpleTouchHandler.h"
#include "_CoreView.h"
#include "_ResourcesBitmap.h"
#include "_ResourcesFont.h"
#include "_ViewsImage.h"
#include "_ViewsRectangle.h"
#include "_ViewsText.h"
#include "Application.h"
#include "Views.h"

/* Strings for the language 'Default'. */
EW_CONST_STRING_PRAGMA static const unsigned short _StringsDefault0[] =
{
  0xFFFF, 0xFFFF, 0xC557, 0x0048, 0x0065, 0x006C, 0x006C, 0x006F, 0x0020, 0x0057,
  0x006F, 0x0072, 0x006C, 0x0064, 0x0021, 0x0000, 0xC557, 0x0054, 0x0068, 0x0069,
  0x0073, 0x0020, 0x0069, 0x0073, 0x0020, 0x0061, 0x0020, 0x0073, 0x0069, 0x006D,
  0x0070, 0x006C, 0x0065, 0x0020, 0x0055, 0x0049, 0x0020, 0x0061, 0x0070, 0x0070,
  0x006C, 0x0069, 0x0063, 0x0061, 0x0074, 0x0069, 0x006F, 0x006E, 0x002C, 0x0020,
  0x0063, 0x006F, 0x006E, 0x0074, 0x0061, 0x0069, 0x006E, 0x0069, 0x006E, 0x0067,
  0x0020, 0x0073, 0x006F, 0x006D, 0x0065, 0x0020, 0x0074, 0x0065, 0x0078, 0x0074,
  0x0020, 0x0076, 0x0069, 0x0065, 0x0077, 0x0073, 0x0020, 0x0061, 0x006E, 0x0064,
  0x0020, 0x0061, 0x0020, 0x006C, 0x006F, 0x0067, 0x006F, 0x0020, 0x0069, 0x006D,
  0x0061, 0x0067, 0x0065, 0x002E, 0x0000, 0xC557, 0x004A, 0x0075, 0x0073, 0x0074,
  0x0020, 0x0074, 0x006F, 0x0075, 0x0063, 0x0068, 0x0020, 0x006F, 0x006E, 0x0020,
  0x0074, 0x0068, 0x0065, 0x0020, 0x0073, 0x0063, 0x0072, 0x0065, 0x0065, 0x006E,
  0x002E, 0x002E, 0x002E, 0x0000, 0xC557, 0x0077, 0x0077, 0x0077, 0x002E, 0x0065,
  0x006D, 0x0062, 0x0065, 0x0064, 0x0064, 0x0065, 0x0064, 0x002D, 0x0077, 0x0069,
  0x007A, 0x0061, 0x0072, 0x0064, 0x002E, 0x0064, 0x0065, 0x0000
};

/* Constant values used in this 'C' module only. */
static const XRect _Const0000 = {{ 0, 0 }, { 320, 240 }};
static const XPoint _Const0001 = { 0, 0 };
static const XPoint _Const0002 = { 320, 0 };
static const XPoint _Const0003 = { 320, 240 };
static const XPoint _Const0004 = { 0, 240 };
static const XColor _Const0005 = { 0x56, 0x56, 0x56, 0xFF };
static const XRect _Const0006 = {{ 210, 10 }, { 306, 106 }};
static const XRect _Const0007 = {{ 10, 40 }, { 200, 80 }};
static const XStringRes _Const0008 = { _StringsDefault0, 0x0003 };
static const XColor _Const0009 = { 0xFF, 0xFF, 0xFF, 0xFF };
static const XRect _Const000A = {{ 5, 115 }, { 315, 165 }};
static const XStringRes _Const000B = { _StringsDefault0, 0x0011 };
static const XRect _Const000C = {{ 5, 165 }, { 315, 200 }};
static const XStringRes _Const000D = { _StringsDefault0, 0x0060 };
static const XRect _Const000E = {{ 50, 200 }, { 260, 230 }};
static const XStringRes _Const000F = { _StringsDefault0, 0x007D };

/* Initializer for the class 'Application::Application' */
void ApplicationApplication__Init( ApplicationApplication _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  CoreRoot__Init( &_this->_.Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_.XObject._.GCT = EW_CLASS_GCT( ApplicationApplication );

  /* ... then construct all embedded objects */
  CoreSimpleTouchHandler__Init( &_this->SimpleTouchHandler, &_this->_.XObject, 0 );
  ViewsRectangle__Init( &_this->Rectangle, &_this->_.XObject, 0 );
  ViewsImage__Init( &_this->Image, &_this->_.XObject, 0 );
  ViewsText__Init( &_this->Caption, &_this->_.XObject, 0 );
  ViewsText__Init( &_this->Text1, &_this->_.XObject, 0 );
  ViewsText__Init( &_this->Text2, &_this->_.XObject, 0 );
  ViewsText__Init( &_this->Text3, &_this->_.XObject, 0 );

  /* Setup the VMT pointer */
  _this->_.VMT = EW_CLASS( ApplicationApplication );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( _this, _Const0000 );
  CoreQuadView_OnSetPoint4((CoreQuadView)&_this->SimpleTouchHandler, _Const0001 );
  CoreQuadView_OnSetPoint3((CoreQuadView)&_this->SimpleTouchHandler, _Const0002 );
  CoreQuadView_OnSetPoint2((CoreQuadView)&_this->SimpleTouchHandler, _Const0003 );
  CoreQuadView_OnSetPoint1((CoreQuadView)&_this->SimpleTouchHandler, _Const0004 );
  CoreRectView__OnSetBounds( &_this->Rectangle, _Const0000 );
  ViewsRectangle_OnSetColor( &_this->Rectangle, _Const0005 );
  CoreRectView__OnSetBounds( &_this->Image, _Const0006 );
  ViewsImage_OnSetAutoSize( &_this->Image, 1 );
  CoreRectView__OnSetBounds( &_this->Caption, _Const0007 );
  ViewsText_OnSetAlignment( &_this->Caption, ViewsTextAlignmentAlignHorzLeft | ViewsTextAlignmentAlignVertTop );
  ViewsText_OnSetString( &_this->Caption, EwLoadString( &_Const0008 ));
  ViewsText_OnSetColor( &_this->Caption, _Const0009 );
  CoreRectView__OnSetBounds( &_this->Text1, _Const000A );
  ViewsText_OnSetWrapText( &_this->Text1, 1 );
  ViewsText_OnSetAlignment( &_this->Text1, ViewsTextAlignmentAlignHorzJustified 
  | ViewsTextAlignmentAlignVertCenter );
  ViewsText_OnSetString( &_this->Text1, EwLoadString( &_Const000B ));
  ViewsText_OnSetColor( &_this->Text1, _Const0009 );
  CoreRectView__OnSetBounds( &_this->Text2, _Const000C );
  ViewsText_OnSetWrapText( &_this->Text2, 1 );
  ViewsText_OnSetAlignment( &_this->Text2, ViewsTextAlignmentAlignHorzJustified 
  | ViewsTextAlignmentAlignVertCenter );
  ViewsText_OnSetString( &_this->Text2, EwLoadString( &_Const000D ));
  ViewsText_OnSetColor( &_this->Text2, _Const0009 );
  CoreRectView__OnSetBounds( &_this->Text3, _Const000E );
  ViewsText_OnSetWrapText( &_this->Text3, 1 );
  ViewsText_OnSetAlignment( &_this->Text3, ViewsTextAlignmentAlignHorzCenter | ViewsTextAlignmentAlignVertCenter );
  ViewsText_OnSetString( &_this->Text3, EwLoadString( &_Const000F ));
  ViewsText_OnSetColor( &_this->Text3, _Const0009 );
  CoreGroup_Add((CoreGroup)_this, ((CoreView)&_this->SimpleTouchHandler ), 0 );
  CoreGroup_Add((CoreGroup)_this, ((CoreView)&_this->Rectangle ), 0 );
  CoreGroup_Add((CoreGroup)_this, ((CoreView)&_this->Image ), 0 );
  CoreGroup_Add((CoreGroup)_this, ((CoreView)&_this->Caption ), 0 );
  CoreGroup_Add((CoreGroup)_this, ((CoreView)&_this->Text1 ), 0 );
  CoreGroup_Add((CoreGroup)_this, ((CoreView)&_this->Text2 ), 0 );
  CoreGroup_Add((CoreGroup)_this, ((CoreView)&_this->Text3 ), 0 );
  _this->SimpleTouchHandler.OnDrag = EwNewSlot( _this, ApplicationApplication_OnTouch );
  _this->SimpleTouchHandler.OnPress = EwNewSlot( _this, ApplicationApplication_OnTouch );
  ViewsImage_OnSetBitmap( &_this->Image, EwLoadResource( &ApplicationLogo, ResourcesBitmap ));
  ViewsText_OnSetFont( &_this->Caption, EwLoadResource( &ApplicationFontLarge, ResourcesFont ));
  ViewsText_OnSetFont( &_this->Text1, EwLoadResource( &ApplicationFontSmall, ResourcesFont ));
  ViewsText_OnSetFont( &_this->Text2, EwLoadResource( &ApplicationFontSmall, ResourcesFont ));
  ViewsText_OnSetFont( &_this->Text3, EwLoadResource( &ApplicationFontSmall, ResourcesFont ));
}

/* Re-Initializer for the class 'Application::Application' */
void ApplicationApplication__ReInit( ApplicationApplication _this )
{
  /* At first re-initialize the super class ... */
  CoreRoot__ReInit( &_this->_.Super );

  /* ... then re-construct all embedded objects */
  CoreSimpleTouchHandler__ReInit( &_this->SimpleTouchHandler );
  ViewsRectangle__ReInit( &_this->Rectangle );
  ViewsImage__ReInit( &_this->Image );
  ViewsText__ReInit( &_this->Caption );
  ViewsText__ReInit( &_this->Text1 );
  ViewsText__ReInit( &_this->Text2 );
  ViewsText__ReInit( &_this->Text3 );
}

/* Finalizer method for the class 'Application::Application' */
void ApplicationApplication__Done( ApplicationApplication _this )
{
  /* Finalize this class */
  _this->_.Super._.VMT = EW_CLASS( CoreRoot );

  /* Finalize all embedded objects */
  CoreSimpleTouchHandler__Done( &_this->SimpleTouchHandler );
  ViewsRectangle__Done( &_this->Rectangle );
  ViewsImage__Done( &_this->Image );
  ViewsText__Done( &_this->Caption );
  ViewsText__Done( &_this->Text1 );
  ViewsText__Done( &_this->Text2 );
  ViewsText__Done( &_this->Text3 );

  /* Don't forget to deinitialize the super class ... */
  CoreRoot__Done( &_this->_.Super );
}

/* This is a slot method connected with the touch handler. Each time the user touches 
   on the screen, this method is called. As a result, the position of the logo image 
   will be changed. */
void ApplicationApplication_OnTouch( ApplicationApplication _this, XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  CoreRectView__OnSetBounds( &_this->Image, EwSetRectOrigin( _this->Image.Super1.Bounds, 
  EwMovePointNeg( _this->SimpleTouchHandler.CurrentPos, EwNewPoint( EwGetRectW( 
  _this->Image.Super1.Bounds ) / 2, EwGetRectH( _this->Image.Super1.Bounds ) / 2 ))));
}

/* Variants derived from the class : 'Application::Application' */
EW_DEFINE_CLASS_VARIANTS( ApplicationApplication )
EW_END_OF_CLASS_VARIANTS( ApplicationApplication )

/* Virtual Method Table (VMT) for the class : 'Application::Application' */
EW_DEFINE_CLASS( ApplicationApplication, CoreRoot, SimpleTouchHandler, _.VMT, _.VMT, 
                 _.VMT, _.VMT, _.VMT, "Application::Application" )
  CoreRoot_GetRoot,
  CoreRoot_Draw,
  CoreGroup_GetClipping,
  CoreView_HandleEvent,
  CoreGroup_CursorHitTest,
  CoreGroup_AdjustDrawingArea,
  CoreRectView_ArrangeView,
  CoreRectView_MoveView,
  CoreRectView_GetExtent,
  CoreRoot_ChangeViewState,
  CoreGroup_OnSetBounds,
  CoreRoot_OnSetFocus,
  CoreRoot_DispatchEvent,
  CoreRoot_BroadcastEvent,
  CoreRoot_InvalidateArea,
EW_END_OF_CLASS( ApplicationApplication )

/* Include a file containing the font resource : 'Application::FontLarge' */
#include "_ApplicationFontLarge.h"

/* Table with links to derived variants of the font resource : 'Application::FontLarge' */
EW_RES_WITHOUT_VARIANTS( ApplicationFontLarge )

/* Include a file containing the bitmap resource : 'Application::Logo' */
#include "_ApplicationLogo.h"

/* Table with links to derived variants of the bitmap resource : 'Application::Logo' */
EW_RES_WITHOUT_VARIANTS( ApplicationLogo )

/* Include a file containing the font resource : 'Application::FontSmall' */
#include "_ApplicationFontSmall.h"

/* Table with links to derived variants of the font resource : 'Application::FontSmall' */
EW_RES_WITHOUT_VARIANTS( ApplicationFontSmall )

/* Embedded Wizard */
