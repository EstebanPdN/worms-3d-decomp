/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d40k_temp_list_labels_80263e18)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
_._19Descriptor_80178474 = 0x80178474;
__12Str_803426b8 = 0x803426b8;
array_lock_801ef048 = 0x801ef048;
as_table_80341584 = 0x80341584;
class_80419e68 = 0x80419e68;
class_80419e88 = 0x80419e88;
create_8020b680 = 0x8020b680;
f_803cb23c = 0x803cb23c;
f_803cb24c = 0x803cb24c;
f_803cb258 = 0x803cb258;
f_803cb264 = 0x803cb264;
list_append_801ef174 = 0x801ef174;
n_803cb20c = 0x803cb20c;
read_setting_800fc1b0 = 0x800fc1b0;
string_finish_8020c5c4 = 0x8020c5c4;
string_format_8020c510 = 0x8020c510;
string_release_8020bb2c = 0x8020bb2c;
string_release_80341588 = 0x80341588;
table_get_80179598 = 0x80179598;
SECTIONS {
  .text.w3d_d40k_temp_list_labels_80263e18 0x80263e18 : { *(.text.w3d_d40k_temp_list_labels_80263e18) }
  .rodata 0x803cb278 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
