//
// ********************************************************************
// * DISCLAIMER                                                       *
// *                                                                  *
// * The following disclaimer summarizes all the specific disclaimers *
// * of contributors to this software. The specific disclaimers,which *
// * govern, are listed with their locations in:                      *
// *   http://cern.ch/geant4/license                                  *
// *                                                                  *
// * Neither the authors of this software system, nor their employing *
// * institutes,nor the agencies providing financial support for this *
// * work  make  any representation or  warranty, express or implied, *
// * regarding  this  software system or assume any liability for its *
// * use.                                                             *
// *                                                                  *
// * This  code  implementation is the  intellectual property  of the *
// * GEANT4 collaboration.                                            *
// * By copying,  distributing  or modifying the Program (or any work *
// * based  on  the Program)  you indicate  your  acceptance of  this *
// * statement, and all its terms.                                    *
// ********************************************************************
//
//
// $Id: GammaRayTelAnticoincidenceHit.hh,v 1.2 2001/07/11 09:56:56 gunter Exp $
// GEANT4 tag $Name: geant4-04-01 $
// ------------------------------------------------------------
//      GEANT 4 class header file
//      CERN Geneva Switzerland
//
//
//      ------------ GammaRayTelAnticoincidenceHit  ------
//           by R.Giannitrapani, F.Longo & G.Santin (13 nov 2000)
//
// ************************************************************
// This Class describe the hits on the Anticoincidence

#ifndef GammaRayTelAnticoincidenceHit_h
#define GammaRayTelAnticoincidenceHit_h 1

#include "G4VHit.hh"
#include "G4THitsCollection.hh"
#include "G4Allocator.hh"
#include "G4ThreeVector.hh"


//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

class GammaRayTelAnticoincidenceHit : public G4VHit
{
public:
  
  GammaRayTelAnticoincidenceHit();
  ~GammaRayTelAnticoincidenceHit();
  GammaRayTelAnticoincidenceHit(const GammaRayTelAnticoincidenceHit&);
  const GammaRayTelAnticoincidenceHit& operator=(const
						GammaRayTelAnticoincidenceHit&);
  int operator==(const GammaRayTelAnticoincidenceHit&) const;
  
  inline void* operator new(size_t);
  inline void  operator delete(void*);
  
  void Draw();
  void Print();

private:
  
  G4double EdepACD;  // Energy deposited on the ACD tile
  G4ThreeVector pos; // Position of the hit
  G4int ACDTileNumber; // Number of the ACD tile
  G4int IsACDPlane;    // Type of the plane (0 top, 1 L-R, 2 F-R)

public:
  
  inline void AddEnergy(G4double de) {EdepACD += de;};
  inline void SetACDTileNumber(G4int i) {ACDTileNumber = i;};
  inline void SetACDType(G4int i) {IsACDPlane = i;};
  inline void SetPos(G4ThreeVector xyz){ pos = xyz; }
  
  inline G4double GetEdepACD()     { return EdepACD; };
  inline G4int    GetACDTileNumber()   { return ACDTileNumber; };
  inline G4int    GetACDType()   {return IsACDPlane;};      
  inline G4ThreeVector GetPos() { return pos; };
  
};

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

typedef G4THitsCollection<GammaRayTelAnticoincidenceHit> GammaRayTelAnticoincidenceHitsCollection;

extern G4Allocator<GammaRayTelAnticoincidenceHit> GammaRayTelAnticoincidenceHitAllocator;

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

inline void* GammaRayTelAnticoincidenceHit::operator new(size_t)
{
  void* aHit;
  aHit = (void*) GammaRayTelAnticoincidenceHitAllocator.MallocSingle();
  return aHit;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

inline void GammaRayTelAnticoincidenceHit::operator delete(void* aHit)
{
  GammaRayTelAnticoincidenceHitAllocator.FreeSingle((GammaRayTelAnticoincidenceHit*) aHit);
}

#endif









