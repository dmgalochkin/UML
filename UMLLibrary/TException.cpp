#include "TException.h"
TException::TException(const char* msg, const char* f, unsigned int l) : message(msg), file(f), line(l)
{
  std::cerr << "[ERROR] " << file << ":" << line << " | " << message << "\n";
}