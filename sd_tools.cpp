// Avoid compiling the code if it is not going to be used
#if defined(_USE_SD) or defined(_USE_SD_MMC)

#include "sd_tools.h"

void listDir(fs::FS &fs, const char * dirname, uint8_t levels){
  Serial.printf("Listing directory: %s\n", dirname);

  File root = fs.open(dirname);
  if(!root){
    Serial.println("Failed to open directory");
    return;
  }
  if(!root.isDirectory()){
    Serial.println("Not a directory");
    return;
  }

  File file = root.openNextFile();
  while(file){
    if(file.isDirectory()){
      Serial.print("  DIR : ");
      Serial.println(file.name());
      if(levels){
        listDir(fs, file.path(), levels -1);
      }
    } else {
      Serial.print("  FILE: ");
      Serial.print(file.name());
      Serial.print("  SIZE: ");
      Serial.println(file.size());
    }
    file.close();
    file = root.openNextFile();
  }
  root.close();
}

char * readFile(fs::FS &fs, const char * path){
  File file = fs.open(path);
  if(!file){
    return NULL;
  }

  unsigned long fileSize = file.size();
  char * data = (char *)malloc(fileSize + 1);
  file.read((uint8_t*)data, fileSize);
  data[fileSize] = 0;
  file.close();
  return data;
}
#endif
