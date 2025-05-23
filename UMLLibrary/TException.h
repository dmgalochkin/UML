#pragma once
#include <iostream>
class TException {
private:
  const char *message;
  const char *file;
  unsigned int line;
public:
  TException(const char* msg, const char* f, unsigned int l);
};

