/*
 * errorstringifyFRresult.c
 *
 *  Created on: 14 Apr 2023
 *      Author: Javier
 */


#include "errorstringifyFRresult.h"
#include "usart.h"

  // print error trough uart
void printError(FRESULT errornumber){
	  HAL_UART_Transmit(&huart3, (const uint8_t *)("\n\r") ,sizeof("\n\r"), 100);
	  HAL_Delay(10);
	  switch (errornumber) {
		case FR_OK:
			HAL_UART_Transmit(&huart3,
					(const uint8_t *)("FR_OK = 0,/* (0) Succeeded */"),
					sizeof("FR_OK = 0,/* (0) Succeeded */"),
					100);
			break;
		case FR_DISK_ERR:
			HAL_UART_Transmit(&huart3,
					(const uint8_t *)("FR_DISK_ERR,/* (1) A hard error occurred in the low level disk I/O layer */"),
					sizeof("FR_DISK_ERR,/* (1) A hard error occurred in the low level disk I/O layer */"),
					100);
			break;
		case FR_INT_ERR:
			HAL_UART_Transmit(&huart3,
					(const uint8_t *)("FR_INT_ERR,/* (2) Assertion failed */"),
					sizeof("FR_INT_ERR,/* (2) Assertion failed */"),
					100);
			break;
		case FR_NOT_READY:
			HAL_UART_Transmit(&huart3,
					(const uint8_t *)("FR_NOT_READY,/* (3) The physical drive cannot work */"),
					sizeof("FR_NOT_READY,/* (3) The physical drive cannot work */"),
					100);
			break;
		case FR_NO_FILE:
			HAL_UART_Transmit(&huart3,
					(const uint8_t *)("FR_NO_FILE,/* (4) Could not find the file */"),
					sizeof("FR_NO_FILE,/* (4) Could not find the file */"),
					100);
			break;
		case FR_NO_PATH:
			HAL_UART_Transmit(&huart3,
					(const uint8_t *)("FR_NO_PATH,/* (5) Could not find the path */"),
					sizeof("FR_NO_PATH,/* (5) Could not find the path */"),
					100);
			break;
		case FR_INVALID_NAME:
			HAL_UART_Transmit(&huart3,
					(const uint8_t *)("FR_INVALID_NAME,/* (6) The path name format is invalid */"),
					sizeof("FR_INVALID_NAME,/* (6) The path name format is invalid */"),
					100);
			break;
		case FR_DENIED:
			HAL_UART_Transmit(&huart3,
					(const uint8_t *)("FR_DENIED,/* (7) Access denied due to prohibited access or directory full */"),
					sizeof("FR_DENIED,/* (7) Access denied due to prohibited access or directory full */"),
					100);
			break;
		case FR_EXIST:
			HAL_UART_Transmit(&huart3,
					(const uint8_t *)("FR_EXIST,/* (8) Access denied due to prohibited access */"),
					sizeof("FR_EXIST,/* (8) Access denied due to prohibited access */"),
					100);
			break;
		case FR_INVALID_OBJECT:
			HAL_UART_Transmit(&huart3,
					(const uint8_t *)("FR_INVALID_OBJECT,/* (9) The file/directory object is invalid */"),
					sizeof("FR_INVALID_OBJECT,/* (9) The file/directory object is invalid */"),
					100);
			break;
		case FR_WRITE_PROTECTED:
			HAL_UART_Transmit(&huart3,
					(const uint8_t *)("FR_WRITE_PROTECTED,/* (10) The physical drive is write protected */"),
					sizeof("FR_WRITE_PROTECTED,/* (10) The physical drive is write protected */"),
					100);
			break;
		case FR_INVALID_DRIVE:
			HAL_UART_Transmit(&huart3,
					(const uint8_t *)("FR_INVALID_DRIVE,/* (11) The logical drive number is invalid */"),
					sizeof("FR_INVALID_DRIVE,/* (11) The logical drive number is invalid */"),
					100);
			break;
		case FR_NOT_ENABLED:
			HAL_UART_Transmit(&huart3,
					(const uint8_t *)("FR_NOT_ENABLED,/* (12) The volume has no work area */"),
					sizeof("FR_NOT_ENABLED,/* (12) The volume has no work area */"),
					100);
			break;
		case FR_NO_FILESYSTEM:
			HAL_UART_Transmit(&huart3,
					(const uint8_t *)("FR_NO_FILESYSTEM,/* (13) There is no valid FAT volume */"),
					sizeof("FR_NO_FILESYSTEM,/* (13) There is no valid FAT volume */"),
					100);
			break;
		case FR_MKFS_ABORTED:
			HAL_UART_Transmit(&huart3,
					(const uint8_t *)("FR_MKFS_ABORTED,/* (14) The f_mkfs() aborted due to any problem */"),
					sizeof("FR_MKFS_ABORTED,/* (14) The f_mkfs() aborted due to any problem */"),
					100);
			break;
		case FR_TIMEOUT:
			HAL_UART_Transmit(&huart3,
					(const uint8_t *)("FR_TIMEOUT,/* (15) Could not get a grant to access the volume within defined period */"),
					sizeof("FR_TIMEOUT,/* (15) Could not get a grant to access the volume within defined period */"),
					100);
			break;
		case FR_LOCKED:
			HAL_UART_Transmit(&huart3,
					(const uint8_t *)("FR_LOCKED,/* (16) The operation is rejected according to the file sharing policy */"),
					sizeof("FR_LOCKED,/* (16) The operation is rejected according to the file sharing policy */"),
					100);
			break;
		case FR_NOT_ENOUGH_CORE:
			HAL_UART_Transmit(&huart3,
					(const uint8_t *)("FR_NOT_ENOUGH_CORE,/* (17) LFN working buffer could not be allocated */"),
					sizeof("FR_NOT_ENOUGH_CORE,/* (17) LFN working buffer could not be allocated */"),
					100);
			break;
		case FR_TOO_MANY_OPEN_FILES:
			HAL_UART_Transmit(&huart3,
					(const uint8_t *)("FR_TOO_MANY_OPEN_FILES,/* (18) Number of open files > _FS_LOCK */"),
					sizeof("FR_TOO_MANY_OPEN_FILES,/* (18) Number of open files > _FS_LOCK */"),
					100);
			break;
		case FR_INVALID_PARAMETER:
			HAL_UART_Transmit(&huart3,
					(const uint8_t *)("FR_INVALID_PARAMETER/* (19) Given parameter is invalid */"),
					sizeof("FR_INVALID_PARAMETER/* (19) Given parameter is invalid */"),
					100);
			break;
		default:
			HAL_UART_Transmit(&huart3,
					(const uint8_t *)("something else"),
					sizeof("something else"),
					100);
			break;
	}
}
