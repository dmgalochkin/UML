#pragma once
#include "TString.h"
class TUML
{
protected:
  TString caption;
public:
  TUML();
  TUML(const TString& caption_ = TString());
  TUML(const TUML& p);
  ~TUML();

  TString GetCaption();

  void SetCaption(const TString& caption_);
};