// Required includes
#include "FS.h"
#include "SD_MMC.h"
#include "SPI.h"

void listDir(fs::FS &fs, const char * dirname, uint8_t levels);
char * readFile(fs::FS &fs, const char * path);
