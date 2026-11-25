/* SN's strerror, adapted from the vendored newlib 1.10.0 strerror.c: same switch shape, with the
 * smaller error table the DOL contains. Case values and messages are decoded from the original
 * decision tree; the strings stay external at their original addresses. */
extern char *d24z_user_strerror_802efe6c(int);
extern const char d24z_empty_803dbc6c[];
extern const char d24z_err_803db648[]; /* "Not owner" */
extern const char d24z_err_803db654[]; /* "No such file or directory" */
extern const char d24z_err_803db670[]; /* "No such process" */
extern const char d24z_err_803db680[]; /* "Interrupted system call" */
extern const char d24z_err_803db698[]; /* "I/O error" */
extern const char d24z_err_803db6a4[]; /* "No such device or address" */
extern const char d24z_err_803db6c0[]; /* "Arg list too long" */
extern const char d24z_err_803db6d4[]; /* "Exec format error" */
extern const char d24z_err_803db6e8[]; /* "Bad file number" */
extern const char d24z_err_803db6f8[]; /* "No children" */
extern const char d24z_err_803db704[]; /* "No more processes" */
extern const char d24z_err_803db718[]; /* "Not enough space" */
extern const char d24z_err_803db72c[]; /* "Permission denied" */
extern const char d24z_err_803db740[]; /* "Bad address" */
extern const char d24z_err_803db74c[]; /* "Block device required" */
extern const char d24z_err_803db764[]; /* "Device or resource busy" */
extern const char d24z_err_803db77c[]; /* "File exists" */
extern const char d24z_err_803db788[]; /* "Cross-device link" */
extern const char d24z_err_803db79c[]; /* "No such device" */
extern const char d24z_err_803db7ac[]; /* "Not a directory" */
extern const char d24z_err_803db7bc[]; /* "Is a directory" */
extern const char d24z_err_803db7cc[]; /* "Invalid argument" */
extern const char d24z_err_803db7e0[]; /* "Too many open files in system" */
extern const char d24z_err_803db800[]; /* "Too many open files" */
extern const char d24z_err_803db814[]; /* "Not a character device" */
extern const char d24z_err_803db82c[]; /* "Text file busy" */
extern const char d24z_err_803db83c[]; /* "File too large" */
extern const char d24z_err_803db84c[]; /* "No space left on device" */
extern const char d24z_err_803db864[]; /* "Illegal seek" */
extern const char d24z_err_803db874[]; /* "Read-only file system" */
extern const char d24z_err_803db88c[]; /* "Too many links" */
extern const char d24z_err_803db89c[]; /* "Broken pipe" */
extern const char d24z_err_803db8a8[]; /* "Math argument" */
extern const char d24z_err_803db8b8[]; /* "Result too large" */
extern const char d24z_err_803db8cc[]; /* "No message of desired type" */
extern const char d24z_err_803db8e8[]; /* "Identifier removed" */
extern const char d24z_err_803db8fc[]; /* "Deadlock" */
extern const char d24z_err_803db908[]; /* "No lock" */
extern const char d24z_err_803db910[]; /* "Not a stream" */
extern const char d24z_err_803db920[]; /* "Stream ioctl timeout" */
extern const char d24z_err_803db938[]; /* "No stream resources" */
extern const char d24z_err_803db94c[]; /* "Machine is not on the network" */
extern const char d24z_err_803db96c[]; /* "No package" */
extern const char d24z_err_803db978[]; /* "Resource is remote" */
extern const char d24z_err_803db98c[]; /* "Virtual circuit is gone" */
extern const char d24z_err_803db9a4[]; /* "Advertise error" */
extern const char d24z_err_803db9b4[]; /* "Srmount error" */
extern const char d24z_err_803db9c4[]; /* "Communication error" */
extern const char d24z_err_803db9d8[]; /* "Protocol error" */
extern const char d24z_err_803db9e8[]; /* "Multihop attempted" */
extern const char d24z_err_803db9fc[]; /* "Bad message" */
extern const char d24z_err_803dba08[]; /* "Cannot access a needed shared library" */
extern const char d24z_err_803dba30[]; /* "Accessing a corrupted shared library" */
extern const char d24z_err_803dba58[]; /* ".lib section in a.out corrupted" */
extern const char d24z_err_803dba78[]; /* "Attempting to link in more shared libraries than system limit" */
extern const char d24z_err_803dbab8[]; /* "Cannot exec a shared library directly" */
extern const char d24z_err_803dbae0[]; /* "Function not implemented" */
extern const char d24z_err_803dbafc[]; /* "No more files" */
extern const char d24z_err_803dbb0c[]; /* "Directory not empty" */
extern const char d24z_err_803dbb20[]; /* "File or path name too long" */
extern const char d24z_err_803dbb3c[]; /* "Too many symbolic links" */
extern const char d24z_err_803dbb54[]; /* "No buffer space available" */
extern const char d24z_err_803dbb70[]; /* "Address family not supported by protocol family" */
extern const char d24z_err_803dbba0[]; /* "Protocol wrong type for socket" */
extern const char d24z_err_803dbbc0[]; /* "Socket operation on non-socket" */
extern const char d24z_err_803dbbe0[]; /* "Protocol not available" */
extern const char d24z_err_803dbbf8[]; /* "Can't send after socket shutdown" */
extern const char d24z_err_803dbc1c[]; /* "Connection refused" */
extern const char d24z_err_803dbc30[]; /* "Address already in use" */
extern const char d24z_err_803dbc48[]; /* "Software caused connection abort" */
const char *w3d_d24z_strerror_802ef3f0(int errnum)
{
    const char *error;
    switch (errnum) {
    case 1: error = d24z_err_803db648; break;
    case 2: error = d24z_err_803db654; break;
    case 3: error = d24z_err_803db670; break;
    case 4: error = d24z_err_803db680; break;
    case 5: error = d24z_err_803db698; break;
    case 6: error = d24z_err_803db6a4; break;
    case 7: error = d24z_err_803db6c0; break;
    case 8: error = d24z_err_803db6d4; break;
    case 9: error = d24z_err_803db6e8; break;
    case 10: error = d24z_err_803db6f8; break;
    case 11: error = d24z_err_803db704; break;
    case 12: error = d24z_err_803db718; break;
    case 13: error = d24z_err_803db72c; break;
    case 14: error = d24z_err_803db740; break;
    case 15: error = d24z_err_803db74c; break;
    case 16: error = d24z_err_803db764; break;
    case 17: error = d24z_err_803db77c; break;
    case 18: error = d24z_err_803db788; break;
    case 19: error = d24z_err_803db79c; break;
    case 20: error = d24z_err_803db7ac; break;
    case 21: error = d24z_err_803db7bc; break;
    case 22: error = d24z_err_803db7cc; break;
    case 23: error = d24z_err_803db7e0; break;
    case 24: error = d24z_err_803db800; break;
    case 25: error = d24z_err_803db814; break;
    case 26: error = d24z_err_803db82c; break;
    case 27: error = d24z_err_803db83c; break;
    case 28: error = d24z_err_803db84c; break;
    case 29: error = d24z_err_803db864; break;
    case 30: error = d24z_err_803db874; break;
    case 31: error = d24z_err_803db88c; break;
    case 32: error = d24z_err_803db89c; break;
    case 33: error = d24z_err_803db8a8; break;
    case 34: error = d24z_err_803db8b8; break;
    case 35: error = d24z_err_803db8cc; break;
    case 36: error = d24z_err_803db8e8; break;
    case 45: error = d24z_err_803db8fc; break;
    case 46: error = d24z_err_803db908; break;
    case 60: error = d24z_err_803db910; break;
    case 62: error = d24z_err_803db920; break;
    case 63: error = d24z_err_803db938; break;
    case 64: error = d24z_err_803db94c; break;
    case 65: error = d24z_err_803db96c; break;
    case 66: error = d24z_err_803db978; break;
    case 67: error = d24z_err_803db98c; break;
    case 68: error = d24z_err_803db9a4; break;
    case 69: error = d24z_err_803db9b4; break;
    case 70: error = d24z_err_803db9c4; break;
    case 71: error = d24z_err_803db9d8; break;
    case 74: error = d24z_err_803db9e8; break;
    case 77: error = d24z_err_803db9fc; break;
    case 83: error = d24z_err_803dba08; break;
    case 84: error = d24z_err_803dba30; break;
    case 85: error = d24z_err_803dba58; break;
    case 86: error = d24z_err_803dba78; break;
    case 87: error = d24z_err_803dbab8; break;
    case 88: error = d24z_err_803dbae0; break;
    case 89: error = d24z_err_803dbafc; break;
    case 90: error = d24z_err_803dbb0c; break;
    case 91: error = d24z_err_803dbb20; break;
    case 92: error = d24z_err_803dbb3c; break;
    case 105: error = d24z_err_803dbb54; break;
    case 106: error = d24z_err_803dbb70; break;
    case 107: error = d24z_err_803dbba0; break;
    case 108: error = d24z_err_803dbbc0; break;
    case 109: error = d24z_err_803dbbe0; break;
    case 110: error = d24z_err_803dbbf8; break;
    case 111: error = d24z_err_803dbc1c; break;
    case 112: error = d24z_err_803dbc30; break;
    case 113: error = d24z_err_803dbc48; break;
    default:
        if ((error = d24z_user_strerror_802efe6c(errnum)) == 0)
            error = d24z_empty_803dbc6c;
        break;
    }
    return error;
}
