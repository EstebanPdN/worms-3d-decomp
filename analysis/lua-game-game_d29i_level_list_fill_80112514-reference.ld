/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d29i_level_list_fill_80112514)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
_._19Descriptor_80178474 = 0x80178474;
__6String = 0x803426b8;
array_lock_801ef048 = 0x801ef048;
as_table_80341584 = 0x80341584;
class_80419e68 = 0x80419e68;
create_8020b680 = 0x8020b680;
definition_801797b4 = 0x801797b4;
f_8039a4ec = 0x8039a4ec;
list_append_801ef174 = 0x801ef174;
list_begin_801ef380 = 0x801ef380;
locked_8028496c = 0x8028496c;
n_8039a4d8 = 0x8039a4d8;
n_8039a4f0 = 0x8039a4f0;
name_find_80347194 = 0x80347194;
next_setting_800fc69c = 0x800fc69c;
read_key2_800fc2b0 = 0x800fc2b0;
string_assign_8020bd38 = 0x8020bd38;
string_finish_8020c5c4 = 0x8020c5c4;
string_format_8020c510 = 0x8020c510;
string_header_80341884 = 0x80341884;
string_init_8020c5c0 = 0x8020c5c0;
string_release_8020bb2c = 0x8020bb2c;
string_release_80341588 = 0x80341588;
table_get_80179598 = 0x80179598;
type_803667a8 = 0x803667a8;
SECTIONS {
  .text.d29i_level_list_fill_80112514 0x80112514 : { *(.text.d29i_level_list_fill_80112514) }
  .sdata 0x804abbac (NOLOAD) : {
    . = 0x0; lbl_804abbac = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
