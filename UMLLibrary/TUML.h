#include "TString.h"
class TUML
{
protected:
  TString name;
  TString caption;
public:
  TUML();
  TUML(const TString& name_, const TString& caption_ = TString());
  TUML(const TUML& p);
  ~TUML();

  TString GetName();
  TString GetCaption();

  void SetName(const TString& name_);
  void SetCaption(const TString& caption_);
};