// Avoid compiling the code if it is not going to be used
#if defined(_USE_SD) or defined(_USE_SD_MMC)

// Required includes
#include "FS.h"

// Use SD or SD_MMC
#if defined(_USE_SD)
#include "SD.h"
#else
#include "SD_MMC.h"
#endif

#include "SPI.h"

void listDir(fs::FS &fs, const char * dirname, uint8_t levels);
char * readFile(fs::FS &fs, const char * path);

#endif