/*
 * sdTESTS.h
 *
 *  Created on: 14 Apr 2023
 *      Author: Javier
 */

#ifndef INC_SDTESTS_H_
#define INC_SDTESTS_H_

#include "fatfs.h"

FRESULT AppendToFile(char* path, size_t path_len, char* msg, size_t msg_len);


#endif /* INC_SDTESTS_H_ */
