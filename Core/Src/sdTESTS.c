/*
 * sdTESTS.c
 *
 *  Created on: 14 Apr 2023
 *      Author: Javier
 */


#include "sdTESTS.h"



  // Append string to file given at path
  FRESULT AppendToFile(char* path, size_t path_len, char* msg, size_t msg_len) {

    FATFS fs;
    FIL myFILE;
    UINT testByte;
    FRESULT stat;

    // Bounds check on strings
    if ( (path[path_len] != 0) || (msg[msg_len] != 0) ) {
      return FR_INVALID_NAME;
    }

    // Re-initialize SD
    if ( BSP_SD_Init() != MSD_OK ) {
      return FR_NOT_READY;
    }

    // Re-initialize FATFS
    if ( FATFS_UnLinkDriver(SDPath) != 0 ) {
      return FR_NOT_READY;
    }
    if ( FATFS_LinkDriver(&SD_Driver, SDPath) != 0 ) {
      return FR_NOT_READY;
    }

    // Mount filesystem
    stat = f_mount(&fs, SDPath, 1);
    if (stat != FR_OK) {
      f_mount(0, SDPath, 0);
      return stat;
    }

    // Open file for appending
    stat = f_open(&myFILE, path, FA_WRITE | FA_OPEN_APPEND);
    if (stat != FR_OK) {
      f_mount(0, SDPath, 0);
      return stat;
    }

    // Write message to end of file
    stat = f_write(&myFILE, msg, msg_len, &testByte);
    if (stat != FR_OK) {
      f_mount(0, SDPath, 0);
      return stat;
    }

    // Sync, close file, unmount
    stat = f_close(&myFILE);
    f_mount(0, SDPath, 0);
    return stat;
  }
