// Native runtime diagnostic formatting. All heap metadata remains external.
typedef unsigned int Word;
typedef char *(*Append)(char *, const char *, int);
typedef const char *(*FormatAddress)(const void *, int);
typedef const char *(*FormatInteger)(int, int);
struct DiagnosticCallbacks { void *slots[3]; Append append; FormatAddress format; };
extern DiagnosticCallbacks callbacks_80400768[];
extern Append append_80400774[];
extern FormatAddress format_80400778[];
extern int initialized_804aba80;
extern "C" void fn_802156c8();
extern "C" int fn_802156f8(void *, const char *, int);
extern "C" int fn_802ef9c0(const char *);
extern const char alloc_803b36cc[];
extern const char free_803b36d8[];
extern const char resize_803b36e4[];
extern const char corrupt_803b36f4[];
extern const char alert_803b3704[];
extern const char region_803b370c[];
extern const char block_803b3714[];
extern const char no_memory_803b371c[];
extern const char locked_803b3730[];
extern const char unallocated_803b3744[];
extern const char freed_803b3758[];
extern const char size_803b3768[];
extern const char allocated_803b3770[];
extern const char freeing_803b3780[];
extern const char resizing_803b378c[];
extern const char resized_803b379c[];
extern const char bad_byte_803b37ac[];
extern const char allocated_at_803b37b8[];
extern const char detected_at_803b37c8[];
inline void formatDiagnostic(void *region, char *block, int detail, const char *file, int line, int operation, char *buffer, char *end) {
    char *cursor = buffer;
    if (operation == 1) cursor = append_80400774[0](cursor, alloc_803b36cc, ':');
    else if (operation == 2) cursor = append_80400774[0](cursor, free_803b36d8, ':');
    else if (operation == 3) cursor = append_80400774[0](cursor, resize_803b36e4, ':');
    else if (operation == 0) cursor = append_80400774[0](cursor, corrupt_803b36f4, ':');
    else if (operation == 4) cursor = callbacks_80400768[0].append(cursor, alert_803b3704, ':');
    cursor = callbacks_80400768[0].append(cursor, region_803b370c, '=');
    cursor = callbacks_80400768[0].append(cursor, callbacks_80400768[0].format(region, 0), ':');
    if (block) {
        cursor = callbacks_80400768[0].append(cursor, block_803b3714, '=');
        cursor = callbacks_80400768[0].append(cursor, callbacks_80400768[0].format(block, 0), ':');
        if ((Word)(operation - 2) < 2) {
            if (!detail) cursor = callbacks_80400768[0].append(cursor, unallocated_803b3744, ':');
            else cursor = callbacks_80400768[0].append(cursor, freed_803b3758, ':');
        } else if (operation == 4) {
            cursor = callbacks_80400768[0].append(cursor, size_803b3768, '=');
            cursor = callbacks_80400768[0].append(cursor, ((FormatInteger)callbacks_80400768[0].format)(*(int *)(block-12), -1), ':');
            if (detail == 1) cursor = callbacks_80400768[0].append(cursor, allocated_803b3770, ':');
            else if (detail == 2) cursor = callbacks_80400768[0].append(cursor, freeing_803b3780, ':');
            else if (detail == 3) cursor = callbacks_80400768[0].append(cursor, resizing_803b378c, ':');
            else if (detail == 5) cursor = callbacks_80400768[0].append(cursor, resized_803b379c, ':');
        } else if (operation == 0) {
            cursor = callbacks_80400768[0].append(cursor, bad_byte_803b37ac, '=');
            cursor = callbacks_80400768[0].append(cursor, ((FormatInteger)callbacks_80400768[0].format)(detail, -1), ':');
            const char *allocationFile = *(const char **)(block-16);
            if (allocationFile && cursor + fn_802ef9c0(allocationFile) + 64 < end) {
                cursor = callbacks_80400768[0].append(cursor, allocated_at_803b37b8, '=');
                cursor = callbacks_80400768[0].append(cursor, allocationFile, ',');
                int allocationLine = *(int *)(block + (*(Word *)(block-20) & ~7U) -20);
                Word sign = allocationLine >> 31;
                cursor = callbacks_80400768[0].append(cursor, ((FormatInteger)callbacks_80400768[0].format)((sign ^ allocationLine) - sign, -1), ':');
            }
        }
    } else {
        if (detail == 1) cursor = callbacks_80400768[0].append(cursor, no_memory_803b371c, ':');
        else cursor = callbacks_80400768[0].append(cursor, locked_803b3730, ':');
    }
    if (file && *file && line > 0 && cursor + fn_802ef9c0(file) + 64 < end) {
        cursor = callbacks_80400768[0].append(cursor, detected_at_803b37c8, '=');
        cursor = callbacks_80400768[0].append(cursor, file, ',');
        cursor = callbacks_80400768[0].append(cursor, ((FormatInteger)callbacks_80400768[0].format)(line, -1), ':');
    }
    *cursor = '\n'; *++cursor = 0;
    fn_802156f8(region, buffer, cursor - buffer);
}

extern "C" void g6b_diagnostic_8021573c(void *region, char *block, int detail, const char *file, int line, int operation) {
 char buffer[1024];
    if (!initialized_804aba80) { fn_802156c8(); initialized_804aba80 = 1; }

 formatDiagnostic(region,block,detail,file,line,operation,buffer,buffer+sizeof(buffer));
}
