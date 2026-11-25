/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d30i_scheme_two_pass_list_fill_8011307c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
_._19Descriptor_80178474 = 0x80178474;
__6String = 0x803426b8;
__6StringPCc = 0x8020bb54;
array_lock_801ef048 = 0x801ef048;
as_table_80341584 = 0x80341584;
class_80419e68 = 0x80419e68;
create_8020b680 = 0x8020b680;
definition_801797b4 = 0x801797b4;
list_append_801ef174 = 0x801ef174;
list_begin_801ef380 = 0x801ef380;
locked_8028496c = 0x8028496c;
n_8039a5f0 = 0x8039a5f0;
n_8039a604 = 0x8039a604;
n_8039a614 = 0x8039a614;
n_8039a620 = 0x8039a620;
read_key2_800fc2b0 = 0x800fc2b0;
read_setting_800fc1b0 = 0x800fc1b0;
strcmp = 0x802ef234;
string_assign_8020bd38 = 0x8020bd38;
string_finish_8020c5c4 = 0x8020c5c4;
string_header_80341884 = 0x80341884;
string_init_8020c5c0 = 0x8020c5c0;
string_release_8020bb2c = 0x8020bb2c;
string_release_80341588 = 0x80341588;
table_get_80179598 = 0x80179598;
SECTIONS {
  .text.d30i_scheme_two_pass_list_fill_8011307c 0x8011307c : { *(.text.d30i_scheme_two_pass_list_fill_8011307c) }
  .sdata 0x804abbac (NOLOAD) : {
    . = 0x0; lbl_804abbac = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
