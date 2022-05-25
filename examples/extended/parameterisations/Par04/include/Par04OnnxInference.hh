//
// ********************************************************************
// * License and Disclaimer                                           *
// *                                                                  *
// * The  Geant4 software  is  copyright of the Copyright Holders  of *
// * the Geant4 Collaboration.  It is provided  under  the terms  and *
// * conditions of the Geant4 Software License,  included in the file *
// * LICENSE and available at  http://cern.ch/geant4/license .  These *
// * include a list of copyright holders.                             *
// *                                                                  *
// * Neither the authors of this software system, nor their employing *
// * institutes,nor the agencies providing financial support for this *
// * work  make  any representation or  warranty, express or implied, *
// * regarding  this  software system or assume any liability for its *
// * use.  Please see the license in the file  LICENSE  and URL above *
// * for the full disclaimer and the limitation of liability.         *
// *                                                                  *
// * This  code  implementation is the result of  the  scientific and *
// * technical work of the GEANT4 collaboration.                      *
// * By using,  copying,  modifying or  distributing the software (or *
// * any work based  on the software)  you  agree  to acknowledge its *
// * use  in  resulting  scientific  publications,  and indicate your *
// * acceptance of all terms of the Geant4 Software license.          *
// ********************************************************************
//

#ifdef USE_INFERENCE_ONNX
#ifndef PAR04ONNXINFERENCE_HH
#define PAR04ONNXINFERENCE_HH

#include "Par04InferenceInterface.hh"
#include "CLHEP/Units/SystemOfUnits.h"
#include "G4ThreeVector.hh"
#include "globals.hh"
#include "core/session/onnxruntime_cxx_api.h"

/**
 * @brief Inference using the ONNX runtime.
 *
 * Creates an enviroment whcih manages an internal thread pool and creates an
 * inference session for the model saved as an ONNX file.
 * Runs the inference in the session using the input vector from Par04InferenceSetup.
 *
 **/

class Par04OnnxInference : public Par04InferenceInterface
{
 public:
  Par04OnnxInference(G4String, G4int, G4int, G4int);
  Par04OnnxInference();

  /// Run inference
  /// @param[in] aGenVector Input latent space and conditions
  /// @param[out] aEnergies Model output = generated shower energies
  /// @param[in] aSize Size of the output
  void RunInference(vector<float> aGenVector, std::vector<G4double>& aEnergies, int aSize);

 private:
  /// Pointer to the ONNX enviroment
  std::unique_ptr<Ort::Env> fEnv;
  /// Pointer to the ONNX inference session
  std::unique_ptr<Ort::Session> fSession;
  /// ONNX settings
  Ort::SessionOptions fSessionOptions;
  /// ONNX memory info
  const OrtMemoryInfo* fInfo;
  struct MemoryInfo;
  /// the input names represent the names given to the model
  /// when defining  the model's architecture (if applicable)
  /// they can also be retrieved from model.summary()
  std::vector<const char*> fInames;
};

#endif /* PAR04ONNXINFERENCE_HH */
#endif