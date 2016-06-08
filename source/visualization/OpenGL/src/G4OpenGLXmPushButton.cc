// This code implementation is the intellectual property of
// the RD44 GEANT4 collaboration.
//
// By copying, distributing or modifying the Program (or any work
// based on the Program) you indicate your acceptance of this statement,
// and all its terms.
//
// $Id: G4OpenGLXmPushButton.cc,v 1.2 1999/01/09 16:23:40 allison Exp $
// GEANT4 tag $Name: geant4-00-01 $
//
//Push button class. Inherits from G4OpenGLXmVWidgetComponent

#ifdef G4VIS_BUILD_OPENGLXM_DRIVER

#include "G4OpenGLXmVWidgetComponent.hh"
#include "G4OpenGLXmVWidgetContainer.hh"
#include "G4OpenGLXmPushButton.hh"
#include <X11/Intrinsic.h>
#include "globals.hh"

G4OpenGLXmPushButton::G4OpenGLXmPushButton (char* n,
					    XtCallbackRec* c) 
{
  name = n;
  callback = c;
}

G4OpenGLXmPushButton::~G4OpenGLXmPushButton ()
{}

void G4OpenGLXmPushButton::SetName (char* n) 
{
  name = n;
  XmString button_string = XmStringCreateLocalized (name);
  XtVaSetValues (button,
		 XmNlabelString, button_string,
		 NULL);
  XmStringFree (button_string);
}

char* G4OpenGLXmPushButton::GetName () 
{
  return name;
}

void G4OpenGLXmPushButton::AddYourselfTo (G4OpenGLXmVWidgetContainer* container)
{

  pView = container->GetView ();
  ProcesspView ();
  parent = container->GetPointerToWidget ();

  XmString button_str = XmStringCreateLocalized (name);
  button = XtVaCreateManagedWidget 
    (name,
     xmPushButtonWidgetClass,
     *parent,
     XmNlabelString, button_str,
     XmNalignment, XmALIGNMENT_CENTER,
     XmNuserData, pView,

     XtNvisual, visual, 
     XtNdepth, depth, 
     XtNcolormap, cmap, 
     XtNborderColor, borcol,
     XtNbackground, bgnd,
     
     NULL);
  
  XtAddCallbacks (button,
		  XmNarmCallback,
		  callback);
  
  XmStringFree (button_str);
}

Widget* G4OpenGLXmPushButton::GetPointerToParent ()
{
  return parent;
}

Widget* G4OpenGLXmPushButton::GetPointerToWidget () 
{
  return &button;
}

#endif

