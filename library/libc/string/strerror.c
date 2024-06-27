
#include <errorcode.h>

static char* error_string[] = {[-ERROR_INVAILD] = "Invaild arguments",
							   [-ERROR_NOT_EXIST] = "File does not exist",
							   [-ERROR_EXIST] = "File already exists",
							   [-ERROR_NOT_FILE] = "Not a file",
							   [-ERROR_NOT_DIRECTORY] = "Not a directory",
							   [-ERROR_READ_FAIL] = "Disk read fail",
							   [-ERROR_OUT_OF_SPACE] = "Filesystem out of space",
							   [-ERROR_WRITE_FAIL] = "Disk write fail",
							   [-ERROR_NO_PERM] = "Permission denied"

};

char* strerror(int errnum) {
	return error_string[-errnum];
}
