#include "TUML.h"

TUML::TUML()
{

}

TUML::TUML(const TString& name_, const TString& caption_)
{
  name = name_;
  caption = caption_;
}

TUML::TUML(const TUML& p)
{
  name = p.name;
  caption = p.caption;
}

TUML::~TUML()
{

}

TString TUML::GetName()
{
  return name;
}

TString TUML::GetCaption()
{
  return caption;
}

void TUML::SetName(const TString& name_)
{
  name = name_;
}

void TUML::SetCaption(const TString& caption_)
{
  caption = caption_;
}
