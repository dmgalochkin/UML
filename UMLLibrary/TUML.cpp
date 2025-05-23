#include "TUML.h"

TUML::TUML()
{

}

TUML::TUML(const TString& caption_)
{
  caption = caption_;
}

TUML::TUML(const TUML& p)
{
  caption = p.caption;
}

TUML::~TUML()
{

}

void TUML::SetCaption(const TString& caption_)
{
  caption = caption_;
}
